#include "cocos2d.h"
#include "GameWrapper.h"
#include "Player.h"
#include "Player/Player2.h"
#include "menus/DeathMenu.h"
#include "AudioEngine.h"
#include "ui/CocosGUI.h"
#include "Scenes/DebugScene.h"
#include "menus/MainMenu.h"
#include "menus/DeathMenu.h"
#include "menus/NextLvl.h"

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

void GameWrapper::setPlayer2(Player2* p2) noexcept {
	_player2 = p2;
}

Player* GameWrapper::getPlayer() {
	return _player;
}

Player2* GameWrapper::getPlayer2() {
	return _player2;
}

void GameWrapper::death() {
	if (playing == GAME_TYPE::HISTORIA || playing == GAME_TYPE::LIBRE) {
		DataEngine::getInstance()->add("deaths", 1);
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(0.3f, DeathMenu::createScene(playing)));
	}
	if (playing == GAME_TYPE::MINIJUEGO) {
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(0.3f, DeathMenu::createScene(playing)));
	}
	playing = GAME_TYPE::NONE;
}

void GameWrapper::next() {
	cocos2d::experimental::AudioEngine::stopAll();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionCrossFade::create(0.3f, NextMenu::createScene()));
}

