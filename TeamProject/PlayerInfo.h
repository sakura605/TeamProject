#pragma once
#include <string>
#include <map>
using namespace std;

class PlayerInfo
{
public: // 출력 확인차 잠시 public
	string User_ID;	//유저아이디
	string User_PW;	//유저비밀번호

public:
	PlayerInfo();
	~PlayerInfo();

	void AddPlayer(map<int, PlayerInfo*>* a_PlayerInfo);	//김
	void SaveFile(map<int, PlayerInfo*>* a_PlayerInfo);		//탱
	void LoadFile(map<int, PlayerInfo*>* a_PlayerInfo);		//님

	void Login(map<int, PlayerInfo*>* a_PlayerInfo);		//수현님
};

