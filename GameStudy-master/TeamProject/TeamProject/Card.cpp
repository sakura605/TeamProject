#include "Card.h"


Card::~Card()
{
}

string m_Cdpt[5] = { "♣", "◆", "♠", "♥", "조커" };
void Card::SettingCard(vector<Card*>* a_Cardlist)	//사빈님
{
	int num = 0;
	int _CardNum = 1;

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
		else
			_SetCard->m_pattern = m_Cdpt[4];

		_SetCard->m_cardNum = _CardNum;
		_CardNum++;
		if (13 < _CardNum)
			_CardNum = 1;

		a_Cardlist->push_back(_SetCard);
		printf("%s %d\n", _SetCard->m_pattern.c_str(), _SetCard->m_cardNum);	//출력 테스트용
	}
}

void Card::SortingCard(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)	//동범님
{
	//SettingCard에서 순서대로 셋팅해 놓은카드를 무작위로 섞어서
	//4명의 각 플레이어에게 13장씩 전달합니다.
}

void Card::ShowPlayerlist(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)//태형님
{
	// <n번 플레이어(아이디)>
	//  <보유 카드 목록>
	//		 ：
	//		 ：
}

void Card::RankedPlayer(vector<Card*>* a_Cardlist, map<int, PlayerInfo*>* a_PlayerInfo)	//효섭님
{
	// <n번 플레이어(아이디)> - n등 (카드 점수)
	//					：
	//					：
}