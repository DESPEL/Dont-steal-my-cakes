#pragma once

#include "cocos2d.h"

#include "Player.h"

#include "Bullet.h"

class Player;

class GameWrapper
{
	static GameWrapper *instance;

	Player* _player;

	GameWrapper(){}
public:

	int val = 0;
	static GameWrapper* getInstance();

	void setPlayer(Player* pl) noexcept;
	Player* getPlayer();

};

