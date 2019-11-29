#include "LevelSelectMenu.h"
#include "GameManager.h"
#include "GameWrapper.h"
#include "ui/CocosGUI.h"
#include "SelectPlayersMenu.h"

USING_NS_CC;
using namespace ui;

Scene* LevelSelectMenu::createScene() {
	auto scene = Scene::create();
	auto layer = LevelSelectMenu::create();
	scene->addChild(layer);
	return scene;
}


bool LevelSelectMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}

	initButtons();


	//boton de ir hacia atras
	auto backBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->setScale(2);
	backBt->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::actionButtonBack, this));
	backBt->setPosition(Point(20, 50));
	addChild(backBt);

	auto startBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	startBt->setAnchorPoint(Point(0, 0.5));
	startBt->setScale(2);
	startBt->setRotation(180);
	startBt->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::actionButton1, this));
	startBt->setPosition(Point(450, 50));
	addChild(startBt);

	return true;
}

void LevelSelectMenu::initButtons() {
	
	l1 = Button::create("menus/fondo_level1.png", "menus/fondo_level1s.png", "menus/fondo_level1s.png", Widget::TextureResType::LOCAL);
	l1->setAnchorPoint(Point(0.5, 0.5));
	l1->setScale(0.4);
	l1->setScaleX(0.6);
	l1->setBright(false);
	l1->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::selecl1, this));
	l1->setPosition(Vec2(_visibleSize.width / 2 - 100, _visibleSize.height / 2+ 50));
	addChild(l1);

	l2 = Button::create("menus/fondo_level2.png", "menus/fondo_level2s.png", "menus/fondo_level2s.png", Widget::TextureResType::LOCAL);
	l2->setAnchorPoint(Point(0.5, 0.5));
	l2->setScale(0.4);
	l2->setScaleX(0.6);
	l2->setBright(false);
	l2->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::selecl2, this));
	l2->setPosition(Vec2(_visibleSize.width / 2 + 100, _visibleSize.height / 2 + 50));
	addChild(l2);

	l3 = Button::create("menus/fondo_level3.png", "menus/fondo_level3s.png", "menus/fondo_level3s.png", Widget::TextureResType::LOCAL);
	l3->setAnchorPoint(Point(0.5, 0.5));
	l3->setScale(0.4);
	l3->setScaleX(0.6);
	l3->setBright(false);
	l3->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::selecl3, this));
	l3->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 -50));
	addChild(l3);

	
	
}

void LevelSelectMenu::actionButtonBack() {
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}

void LevelSelectMenu::selecl1() {

	GameWrapper::getInstance()->freemode = 1;

	this->l1->setBright(true);
	this->l2->setBright(false);
	this->l3->setBright(false);
};

void LevelSelectMenu::selecl2() {

	GameWrapper::getInstance()->freemode = 2;

	this->l1->setBright(false);
	this->l2->setBright(true);
	this->l3->setBright(false);
};

void LevelSelectMenu::selecl3() {

	GameWrapper::getInstance()->freemode = 3;

	this->l1->setBright(false);
	this->l2->setBright(false);
	this->l3->setBright(true);
};

void LevelSelectMenu::actionButton1() {
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, SelectPlayersMenu::createScene()));
};