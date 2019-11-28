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
	
	// Información para iniciar escenas
	int p1TipoNave = 2;
	int p2TipoNave = 1;
	bool coop = 0;


	void setPlayer(Player* pl) noexcept;
	//void setPlayer2(Player2* p2);
	Player* getPlayer();
	

};

