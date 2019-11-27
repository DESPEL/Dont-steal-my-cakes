#include "GameWrapper.h"
#include "Player.h"
#include "Player/Player2.h"
#include "menus/DeathMenu.h"

GameWrapper* GameWrapper::instance = nullptr;

GameWrapper* GameWrapper::getInstance() {
	if (instance == nullptr)
		instance = new GameWrapper();
	return instance;
}

void GameWrapper::setPlayer(Player* pl) noexcept {
	_player = pl;
}

/*void GameWrapper::setPlayer2(Player2* p2) {
	_player2 = p2;
}*/

Player* GameWrapper::getPlayer() {
	return _player;
}

void GameWrapper::death() {
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(1, DeathMenu::createScene())); 
}

