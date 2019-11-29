#pragma once

#include "cocos2d.h"

#include "Player.h"
#include "Bullet.h"
#include "Macros.h"
#include "DataEngine.h"

class Player;
class Player2;
class DeathMenu;

class GameWrapper {
	static GameWrapper *instance;
	Player* _player;
	Player2* _player2;
	GameWrapper(){}

public:
	GAME_TYPE playing = GAME_TYPE::NONE;
	int actualLevel = 1;
	int val = 0;
	static GameWrapper* getInstance();

	void death();
	
	// Información para iniciar escenas
	int p1TipoNave = 2;
	int p2TipoNave = 1;
	bool coop = 0;

	void next();

	void setPlayer(Player* pl) noexcept;
	void setPlayer2(Player2* p2) noexcept;
	Player* getPlayer();
	Player2* getPlayer2();

};

