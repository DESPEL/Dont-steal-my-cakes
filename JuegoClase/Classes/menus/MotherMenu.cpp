#include "MotherMenu.h"

USING_NS_CC;

Scene* MotherMenu::createScene() {
	auto scene = Scene::create();
	auto layer = MotherMenu::create();
	scene->addChild(layer);
	return scene;
}

MotherMenu::MotherMenu() {}

MotherMenu::~MotherMenu() {
	CC_SAFE_DELETE(_bg);
}

bool MotherMenu::init() {
	if (!Layer::init())
		return false;

	_visibleSize = Director::getInstance()->getWinSize();

	_bg = new BackGroundMenu();
	_bg->setSpeed(30.0f);
	this->addChild(_bg);
	
	scheduleUpdate();
	return true;
}

void MotherMenu::update(float delta) {
	_bg->update(delta);
}