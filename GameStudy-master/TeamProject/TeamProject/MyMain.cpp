#include <stdio.h>
#include "Card.h"


//1번 메뉴 - 실행할때마다 한명의 아이디와 패스워드를 입력받고 회원을 추가한다.

//2번 메뉴 - (애초에 회원수가 4명이 안되면 로그인 메뉴에 들어갈수없음)
//			 4명의 로그인을 성공 시킨다.

//3번 메뉴 - (로그인을 성공하지 못하면 메뉴에 들어갈 수 없음)
//			 1. 카드를 순서대로 셋팅한다 (클로버 1~10 JQK ,다이아 1~10 JQK .....)
//			 2. 카드를 섞는다.
//			 3. 플레이어 리스트/보유 카드목록 출력한다.
//			 4. 카드를 이용해서 점수를 더하고 등수를 출력한다.

//<<<<<<< HEAD

// 깃허브 마스터함ddddde


void main()
{
	PlayerInfo* _playerInfo = new PlayerInfo;//tyhtytyt
	Card* _card = new Card;
	map<int, PlayerInfo*> m_playerInfo;
	vector<Card*> v_card;

	_playerInfo->LoadFile(&m_playerInfo);		//파일 불러오기

	while (1)
	{
		printf("1.플레이어 추가 2.로그인 3.게임하기 4.나가기 : ");
		int a_Sel;
		scanf_s("%d", &a_Sel);
		getchar();

		if (a_Sel == 1)
		{
			_playerInfo->AddPlayer(&m_playerInfo);	//1번 김탱님 - 플레이어 추가(4명)
			getchar();
			system("cls");
		}

		else if (a_Sel == 2)
		{
			_playerInfo->Login(&m_playerInfo);		//2번 수현님 - 로그인기능								
			getchar();
			system("cls");
		}

		else if (a_Sel == 3)					//4명 로그인 시켜야 선택 가능
		{
			_card->SettingCard(&v_card);						//3번 사빈님 - 카드셋팅
			_card->SortingCard(&v_card, &m_playerInfo);			//4번 동범님 - 카드셔플
			_card->ShowPlayerlist(&v_card, &m_playerInfo);		//5번 태형님 - 플레이어 리스트 출력
			_card->RankedPlayer(&v_card, &m_playerInfo);		//6번 효섭님 - 플레이어 등수 출력
			getchar();
			system("cls");
		}

		else
			break;
	}
}