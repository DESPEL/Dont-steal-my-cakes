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
	int freemode = 1;
	static GameWrapper* getInstance();

	void death();
	void SetLevel();
	// Información para iniciar escenas
	int p1TipoNave = 2;
	int p2TipoNave = 3;
	bool coop = 0;
	int getlvl();
	void next();

	void setPlayer(Player* pl) noexcept;
	void setPlayer2(Player2* p2) noexcept;
	Player* getPlayer();
	Player2* getPlayer2();

};

