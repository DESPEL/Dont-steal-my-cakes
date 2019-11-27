#pragma once

#include "cocos2d.h"

class Player;
class Player2;
class DeathMenu;

class GameWrapper {
	static GameWrapper *instance;
	Player* _player;
	//Player2* _player2;
	GameWrapper(){}

public:
	static GameWrapper* getInstance();

	void death();
	
	void setPlayer(Player* pl) noexcept;
	//void setPlayer2(Player2* p2);
	Player* getPlayer();
	
	bool coop = 0;
};

