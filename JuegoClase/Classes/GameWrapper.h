#pragma once

#include "cocos2d.h"

#include "Player.h"
#include "Bullet.h"

class Player;
class Player2;
class DeathMenu;

class GameWrapper {
	static GameWrapper *instance;
	Player* _player;
	//Player2* _player2;
	GameWrapper(){}

public:
	int actualLevel = 1;
	int val = 0;
	static GameWrapper* getInstance();

	void death();
	
	// Información para iniciar escenas
	int p1TipoNave = 2;
	int p2TipoNave = 1;
	bool coop = false;

	void next();

	void setPlayer(Player* pl) noexcept;
	//void setPlayer2(Player2* p2);
	Player* getPlayer();
	

};

