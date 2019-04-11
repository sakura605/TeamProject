#include "Card.h"

Card::Card()
{
}


Card::~Card()
{
}
//tytytyty

void Card::SettingCard(vector<Card*>* a_Cardlist)	//사빈님
{
	//ㅇㅇ... 열심히해보겠습니다..
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