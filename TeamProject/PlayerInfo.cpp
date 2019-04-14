#include "PlayerInfo.h"
#include <iostream>
#include <stdio.h>

#pragma warning(disable:4996)

int g_PlayerKey = 0;

PlayerInfo::PlayerInfo()
{
}


PlayerInfo::~PlayerInfo()
{
}


void PlayerInfo::AddPlayer(map<int, PlayerInfo*>* a_PlayerInfo)    //김탱님 끼엑 깃허브 하a
{
	std::map<int, PlayerInfo*> m_PlayerInfo;

	PlayerInfo* TempList = new PlayerInfo();

	while (1)
	{
		int a_Sel = 0;
		printf("\n신규 플레이어를 생성하시겠습니까?\n생성하기 : 1\n돌아가기 : 2\n번호를 선택해 주세요 : ");
		scanf("%d", &a_Sel, sizeof(a_Sel));
		getchar();

		if (a_Sel == 2)
		{
			printf("플레이어 추가를 취소합니다..\nEnter를 눌러주세요\n");
			break;
		}


		if (a_Sel == 1)
		{
			Restart:
			std::cout << "새로운 아이디를 입력해 주세요(숫자,대 소문자, 특수문자만 입력해 주세요) : ";
			std::cin >> User_ID;

			for (int ii = 0; ii < User_ID.length(); ii++)
			{
				if (User_ID[ii] >= '0' && User_ID[ii] <= '9')
				{
					continue;
				}

				else if (User_ID[ii] >= 'a' && User_ID[ii] <= 'z')
				{
					continue;
				}

				else if (User_ID[ii] >= 'A' && User_ID[ii] <= 'Z')
				{
					continue;
				}

				else if (User_ID[ii] == '!' || User_ID[ii] == '@' || User_ID[ii] == '#' ||
						 User_ID[ii] == '$' || User_ID[ii] == '%' || User_ID[ii] == '^' ||
						 User_ID[ii] == '&' || User_ID[ii] == '*' || User_ID[ii] == '(' ||
						 User_ID[ii] == ')' || User_ID[ii] == '_' || User_ID[ii] == '+' ||
						 User_ID[ii] == '-' || User_ID[ii] == '=')
				{
					continue;
				}
				else
				{
					printf("입력을 잘못하셨습니다.. 다시 입력해주세요\n");
					goto Restart;

				}
			}
			getchar();

			Restart2:
			std::cout << "비밀번호를 입력해 주세요(숫자,대 소문자, 특수문자만 입력해 주세요) : ";
			std::cin >> User_PW;

			for (int ii = 0; ii < User_PW.length(); ii++)
			{
				if (User_PW[ii] >= '0' && User_PW[ii] <= '9')
				{
					continue;
				}

				else if (User_PW[ii] >= 'a' && User_PW[ii] <= 'z')
				{
					continue;
				}

				else if (User_PW[ii] >= 'A' && User_PW[ii] <= 'Z')
				{
					continue;
				}

				else if (User_PW[ii] == '!' || User_PW[ii] == '@' || User_PW[ii] == '#' ||
						 User_PW[ii] == '$' || User_PW[ii] == '%' || User_PW[ii] == '^' ||
					   	 User_PW[ii] == '&' || User_PW[ii] == '*' || User_PW[ii] == '(' ||
					 	 User_PW[ii] == ')' || User_PW[ii] == '_' || User_PW[ii] == '+' ||
					     User_PW[ii] == '-' || User_PW[ii] == '=')
				{
					continue;
				}

				else
				{
					printf("입력을 잘못하셨습니다.. 다시 입력해주세요\n");
					goto Restart2;

				}
			}
			getchar();

			TempList->User_ID = User_ID;
			TempList->User_PW = User_PW;

			printf("새로운 플레이어가 추가되었습니다!!\n");
			(*a_PlayerInfo).insert(map<int, PlayerInfo*>::value_type(g_PlayerKey, TempList));
		
			printf("%d번 플레이어 ID : %s PW : %s\n",g_PlayerKey, User_ID.c_str(), User_PW.c_str());
	
			g_PlayerKey++;
			break;
		}

		else
		{
			printf("숫자를 잘못 입력하셨습니다.\nEnter키를 눌러주세요.\n");
			getchar();
			system("cls");
			break;
		}

	}

	//평소 하던대로 이름이랑 패스워드 입력받아서 플레이어 정보를 맵에 넣어주세요.
	//Key값으로 회원번호를 넣어주시고 Second값에 아이디랑 비밀번호를 넣어주세요.
	//string형식은 scanf가 안된다고 하니 입력시킬때 c++언어인 cin을 사용해주세요.
	SaveFile(a_PlayerInfo);
}

void PlayerInfo::SaveFile(map<int, PlayerInfo*>* a_PlayerInfo)    //김탱님
{
	FILE* a_wFP = fopen("PlayerInfo.txt", "wt");
	if (a_wFP != NULL)
	{
		fprintf(a_wFP, "%d\n", g_PlayerKey);
		fprintf(a_wFP, "%d\n", (*a_PlayerInfo).size());
		if (0 < (*a_PlayerInfo).size())
		{
			map<int, PlayerInfo*>::iterator a_iter;
			for (a_iter = (*a_PlayerInfo).begin(); a_iter != (*a_PlayerInfo).end(); a_iter++)
			{
				fprintf(a_wFP, "%d %s %s\n",
					(*a_iter).first,
					(*a_iter).second->User_ID.c_str(),
					(*a_iter).second->User_PW.c_str());
			}
		}
		fclose(a_wFP);
	}	
}

void PlayerInfo::LoadFile(map<int, PlayerInfo*>* a_PlayerInfo)    //김탱님
{
	int size = 0;
	FILE* a_rFP = fopen("PlayerInfo.txt", "rt");
	if (a_rFP != NULL)
	{
		fscanf(a_rFP, "%d", &size);
		if (0 < size)
		{
			PlayerInfo* TempList = new PlayerInfo();
			map<int, PlayerInfo*>::iterator a_iter;
			for (int ii = 0; ii < size; ii++)
			{
				//TempList = new PlayerInfo();
				fscanf(a_rFP, "%d %s %s\n",
					&g_PlayerKey,
					TempList->User_ID.c_str(),
					TempList->User_PW.c_str());
				a_PlayerInfo->insert(map<int, PlayerInfo*>::value_type(g_PlayerKey, TempList));
			}
		}
		fclose(a_rFP);
		g_PlayerKey++;
	}
}



void PlayerInfo::Login(map<int, PlayerInfo*>* a_PlayerInfo)        //승현임미당ㅋㅋ
{
	//로그인 기능 4명 로그인 시키기
	//4명의 로그인에 성공해야 3번을 실행할 수 있으니
	//3번을 실행 시킬 수 있는 조건을 설정해주세요.

	map<int, PlayerInfo*>::iterator a_iter;
	int ii = 0;
	for (a_iter = a_PlayerInfo->begin(); a_iter != a_PlayerInfo->end(); a_iter++)
	{
		ii++;
		printf("%d 번 유저네임 : %s\n", ii, a_iter->second->User_ID.c_str());
	}

	while (1)
	{
		printf("\n로그인할 유저번호 선택 : ");
		int temp = 0;
		scanf("%d", &temp);
		getchar();

		if (temp <= 0 || a_PlayerInfo->size() < temp)
		{
			puts("다시입력!");
			getchar();
			continue;
		}

		a_iter = a_PlayerInfo->begin();
		for (int ii = 0; ii < temp - 1; ii++)
		{
			a_iter++;
		}

		printf("User ID : %s\n", a_iter->second->User_ID.c_str());
		printf("PassWord : ");
		string temp22 = "";
		cin >> temp;
		getchar();

		if (a_iter->second->User_PW.c_str() == temp22)
		{
			puts("로그인 성공!");
		}
		else if (a_iter->second->User_PW.c_str() != temp22)
		{
			puts("로그인 실패! 다시해주세요!");
		}
	}

}
