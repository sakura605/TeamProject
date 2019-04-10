#pragma once
#include <vector>
#include <time.h>
#include "PlayerInfo.h"
using namespace std;

class Card
{
	string m_pattern;					//Å¬·Î¹ö ´ÙÀÌ¾Æ ½ºÆäÀÌµå ÇÏÆ®
	string m_cardNum;
	string m_pnCard;					
	PlayerInfo* _playerInfo;

public:
	Card()
	{
		_playerInfo = new PlayerInfo();
	}
	~Card();

	void SettingCard(vector<Card*>*);							//»çºó´Ô
	void SortingCard(vector<Card*>*, map<int, PlayerInfo*>*);	//µ¿¹ü´Ô
	void ShowPlayerlist(vector<Card*>*, map<int, PlayerInfo*>*);//ÅÂÇü´Ô
	void RankedPlayer(vector<Card*>*, map<int, PlayerInfo*>*);	//È¿¼·´Ô
};

