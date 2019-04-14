#pragma once
#include <vector>
#include <time.h>
#include "PlayerInfo.h"
using namespace std;

class Card
{
	string m_pattern;					//클로버 다이아 스페이드 하트
	string m_cardNum;
	string m_pnCard;					// 패턴 + 숫자
	PlayerInfo* _playerInfo;

public:
	Card()
	{
		_playerInfo = new PlayerInfo();
	}
	~Card();

	void SettingCard(vector<Card*>*);							//사빈님
	void SortingCard(vector<Card*>*, map<int, PlayerInfo*>*);	//동범님
	void ShowPlayerlist(vector<Card*>*, map<int, PlayerInfo*>*);//태형님
	void RankedPlayer(vector<Card*>*, map<int, PlayerInfo*>*);	//효섭님
};

