#include "GameWrapper.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Player.h"

#include "ui/CocosGUI.h"
#include "Scenes/DebugScene.h"

#include "menus/MainMenu.h"
#include "menus/DeathMenu.h"

USING_NS_CC;


GameWrapper* GameWrapper::instance = nullptr;



GameWrapper* GameWrapper::getInstance() {
	if (instance == nullptr)
		instance = new GameWrapper();
	return instance;
}

void GameWrapper::setPlayer(Player* pl) noexcept {
	_player = pl;
}

Player* GameWrapper::getPlayer() {
	return _player;
}




