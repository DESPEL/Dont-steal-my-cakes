#include "DebugScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#include "Levels/Levels.h"

#include "TranslationEngine.h"

USING_NS_CC;

Scene* DebugScene::createScene() {
	auto scene = Scene::create();
	auto layer = DebugScene::create();
	scene->addChild(layer);


	return scene;
}

bool DebugScene::init() {

	if (!Layer::init())
		return false;

	auto _visibleSize = Director::getInstance()->getWinSize();

	//Crea el background
	_bg = Background::create();
	addChild(_bg, -1);

	//Crea al jugador
	_player = Player::create();
	_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	_player->setScale(2);
	addChild(_player);

	GameWrapper::getInstance()->setPlayer(_player);
	this->retain();

	// ejecutar nivel
	Levels::create("test").get(this).run();

	// Testing translation engine
	/*
	auto lang = TranslationEngine::getInstance();

	cocos2d::log(lang->get("test").c_str());
	cocos2d::log(lang->get("test2").c_str());
	lang->setLanguage("EN_US");
	cocos2d::log(lang->get("test").c_str());
	cocos2d::log(lang->get("test2").c_str());*/

	

	this->schedule(schedule_selector(DebugScene::update));

	// Musica
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music\\get_lucky.mp3", true);

	return true;
}

void DebugScene::createEnemy() {

};

void DebugScene::update(float delta) {

}
