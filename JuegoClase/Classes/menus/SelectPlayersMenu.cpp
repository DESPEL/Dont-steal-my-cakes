#include "SelectPlayersMenu.h"
#include "GameManager.h"
#include "GameWrapper.h"
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

	auto P1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	P1->setAnchorPoint(Point(0.5, 0.5));
	P1->setScale(0.4);
	P1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	P1->setPosition(Vec2(_visibleSize.width / 4, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P1);

	auto P2 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	P2->setAnchorPoint(Point(0.5, 0.5));
	P2->setScale(0.4);
	P2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	P2->setPosition(Vec2(3*_visibleSize.width / 4, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P2);

	auto nave1 = Button::create("nave1.png", "nave1.png", "nave1.png", Widget::TextureResType::LOCAL);
	nave1->setAnchorPoint(Point(0.5, 0.5));
	nave1->setScale(2);
	nave1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	nave1->setPosition(Vec2(1*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave1);

	auto nave2 = Button::create("nave2.png", "nave2.png", "nave2.png", Widget::TextureResType::LOCAL);
	nave2->setAnchorPoint(Point(0.5, 0.5));
	nave2->setScale(2);
	nave2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	nave2->setPosition(Vec2(2*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave2);

	auto nave3 = Button::create("nave3.png", "nave3.png", "nave3.png", Widget::TextureResType::LOCAL);
	nave3->setAnchorPoint(Point(0.5, 0.5));
	nave3->setScale(2);
	nave3->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	nave3->setPosition(Vec2(3*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave3);

	auto nave4 = Button::create("nave4.png", "nave4.png", "nave4.png", Widget::TextureResType::LOCAL);
	nave4->setAnchorPoint(Point(0.5, 0.5));
	nave4->setScale(2);
	nave4->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	nave4->setPosition(Vec2(4*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave4);
}

void SelectPlayersMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, SelectPlayersMenu::createScene()));
}

//void seleccionar