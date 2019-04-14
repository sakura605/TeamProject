#include "Card.h"

#define SUFFLE	1


Card::~Card()
{
}

string m_Cdpt[5] = { "♣", "◆", "♠", "♥", "조커" };
string m_CdNum[15] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "ACE", "J", "Q", "K", "Black", "Color" };

//tytytyty

void Card::SettingCard(vector<Card*>* a_Cardlist)	//사빈님
{
	int _Joker = 13;
	int _CardNum = 0;
	for (int i = 0; i < 54; i++)
	{
		Card* _SetCard = new Card();
		if (i / 13 == 0)
			_SetCard->m_pattern = m_Cdpt[0];
		else if (i / 13 == 1)
			_SetCard->m_pattern = m_Cdpt[1];
		else if (i / 13 == 2)
			_SetCard->m_pattern = m_Cdpt[2];
		else if (i / 13 == 3)
			_SetCard->m_pattern = m_Cdpt[3];

		_CardNum = i % 13;
		_SetCard->m_cardNum = m_CdNum[_CardNum];

		if (i / 13 == 4)
		{
			_SetCard->m_pattern = m_Cdpt[4];
			_SetCard->m_cardNum = m_CdNum[_Joker];
			_Joker++;
		}
		_SetCard->m_pnCard = _SetCard->m_pattern + _SetCard->m_cardNum; // 섞기, 전달 위해 추가
		a_Cardlist->push_back(_SetCard);
	}

	//for (int i = 0; i < 54; i++)
	//{
	//	// printf("%s %s\n", (*a_Cardlist)[i]->m_pattern.c_str(), (*a_Cardlist)[i]->m_cardNum.c_str());//출력 테스트용
	//	printf("%s\n", (*a_Cardlist)[i]->m_pnCard.c_str()); // 출력 테스트 변경
	//}
}

void Card::SortingCard(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)	//동범님
{
	//SettingCard에서 순서대로 셋팅해 놓은카드를 무작위로 섞어서
	//4명의 각 플레이어에게 13장씩 전달합니다.

	srand(time(NULL));

	string temp = "";

	for (int i = 0; i < SUFFLE; i++)
	{
		int r = rand() % 54;
		temp = (*a_Cardlist)[0]->m_pnCard;
		(*a_Cardlist)[0]->m_pnCard = (*a_Cardlist)[r]->m_pnCard;
		(*a_Cardlist)[r]->m_pnCard = temp;
	}

	for (int i = 0; i < 54; i++) // 출력 테스트
	{
		printf("%s\n", (*a_Cardlist)[i]->m_pnCard.c_str());
	}

	map<int, PlayerInfo*>::iterator iter;

	for (int i = 0; i < 52; i++)
	{
		iter = a_PlayerInfo->begin();

		if (i % 4 == 1)
			advance(iter, 1);
		else if (i % 4 == 2)
			advance(iter, 2);
		else if (i % 4 == 3)
			advance(iter, 3);

		(*a_Cardlist)[i]->_playerInfo = (*iter).second;
	}

	//for (int i = 0; i < 54; i++) // 출력 테스트
	//{
	//	printf("%s %s\n", (*a_Cardlist)[i]->m_pnCard.c_str(), (*a_Cardlist)[i]->_playerInfo->User_ID.c_str());
	//}
}

void Card::ShowPlayerlist(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)//태형님
{
	// <n번 플레이어(아이디)>
	//  <보유 카드 목록>
	//		 ：
	//		 ：
	map<int, PlayerInfo*>::iterator iter;

	for (iter = (*a_PlayerInfo).begin(); iter != (*a_PlayerInfo).end(); iter++)
	{
		int a = 13;
		printf("<%d번 플레이어(%s)>\n", (*iter).first, (*iter).second->User_ID.c_str());

		for (int ii = a - 13; ii < a; ii++)
		{
			printf("<%s>\n", (*a_Cardlist)[ii]->m_pnCard.c_str());
		}

		a + 13;
	}

}

void Card::RankedPlayer(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)	//효섭님
{
	// <n번 플레이어(아이디)> - n등 (카드 점수)
	//					：
	//					：
}