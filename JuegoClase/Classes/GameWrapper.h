#pragma once

#include "cocos2d.h"

#include "Player.h"

#include "ui/CocosGUI.h"

#include "Background.h"

class Player;

class GameWrapper
{
	static GameWrapper *instance;

	Player* _player;
	
	GameWrapper(){}

public:
	
	static GameWrapper* getInstance();
	
	void setPlayer(Player* pl) noexcept;
	Player* getPlayer();

};

