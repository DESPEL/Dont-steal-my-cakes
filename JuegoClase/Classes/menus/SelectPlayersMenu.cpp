#include "SelectPlayersMenu.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene* SelectPlayersMenu::createScene() {
	auto scene = Scene::create();
	auto layer = SelectPlayersMenu::create();
	scene->addChild(layer);
	return scene;
}


bool SelectPlayersMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}

	initButtons();


	//boton de ir hacia atras
	auto backBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->setScale(2);
	backBt->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButtonBack, this));
	backBt->setPosition(Point(30 * getScaleX(), 30 * getScaleY()));
	addChild(backBt);

	return true;
}

void SelectPlayersMenu::initButtons() {
/*
	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);

	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);

	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);

	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);

	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);

	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);
	
	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);
	*/
}

void SelectPlayersMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, SelectPlayersMenu::createScene()));
}
