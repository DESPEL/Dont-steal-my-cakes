	#include "SelectPlayersMenu.h"
#include "GameManager.h"
#include "GameWrapper.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"

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
	backBt->setPosition(Point(20, 50));
	addChild(backBt);

	auto startBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	startBt->setAnchorPoint(Point(0, 0.5));
	startBt->setScale(2);
	startBt->setRotation(180);
	startBt->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	startBt->setPosition(Point(450, 50));
	addChild(startBt);

	return true;
}

void SelectPlayersMenu::initButtons() {

	P1 = Button::create("menus/Botones/Player1True.png", "menus/Botones/Player1False.png", "menus/Botones/Player1False.png", Widget::TextureResType::LOCAL);
	P1->setAnchorPoint(Point(0.5, 0.5));
	P1->setScale(4);
	P1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecP1, this));
	P1->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P1);

	P2 = Button::create("menus/Botones/Player2True.png", "menus/Botones/Player2False.png", "menus/Botones/Player2False.png", Widget::TextureResType::LOCAL);
	P2->setAnchorPoint(Point(0.5, 0.5));
	P2->setScale(4);
	P2->setBright(false);
	P2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecP2, this));
	P2->setPosition(Vec2(3*_visibleSize.width / 4 - 25, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P2);

	/*
	************
	Seleccion de Naves Primer Jugador
	************
	*/

	nave1 = Button::create("nave1.png", "menus/Botones/nave1.png", "menus/Botones/nave1.png", Widget::TextureResType::LOCAL);
	nave1->setAnchorPoint(Point(0.5, 0.5));
	nave1->setScale(2);
	nave1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN1, this));
	nave1->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 + 50));
	addChild(nave1);

	nave2 = Button::create("nave2.png", "menus/Botones/nave2.png", "menus/Botones/nave2.png", Widget::TextureResType::LOCAL);
	nave2->setAnchorPoint(Point(0.5, 0.5));
	nave2->setScale(2);
	nave2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN2, this));
	nave2->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 ));
	addChild(nave2);

	nave3 = Button::create("nave3.png", "menus/Botones/nave3.png", "menus/Botones/nave3.png", Widget::TextureResType::LOCAL);
	nave3->setAnchorPoint(Point(0.5, 0.5));
	nave3->setScale(2);
	nave3->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN3, this));
	nave3->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 - 50));
	addChild(nave3);

	nave4 = Button::create("nave4.png", "menus/Botones/nave4.png", "menus/Botones/nave4.png", Widget::TextureResType::LOCAL);
	nave4->setAnchorPoint(Point(0.5, 0.5));
	nave4->setScale(2);
	nave4->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN4, this));
	nave4->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 -100));
	addChild(nave4);	

	/*
	************
	Seleccion de Naves Segundo Jugador
	************
	*/
	

	P2nave1 = Button::create("nave1.png", "menus/Botones/nave1.png", "menus/Botones/nave1.png", Widget::TextureResType::LOCAL);
	P2nave1->setAnchorPoint(Point(0.5, 0.5));
	P2nave1->setScale(2);
	P2nave1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::P2selecN1, this));
	P2nave1->setPosition(Vec2(3 * _visibleSize.width / 4 - 25, _visibleSize.height / 2 + 50));
	addChild(P2nave1);

	P2nave2 = Button::create("nave2.png", "menus/Botones/nave2.png", "menus/Botones/nave2.png", Widget::TextureResType::LOCAL);
	P2nave2->setAnchorPoint(Point(0.5, 0.5));
	P2nave2->setScale(2);
	P2nave2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::P2selecN2, this));
	P2nave2->setPosition(Vec2(3 * _visibleSize.width / 4 - 25, _visibleSize.height / 2 ));
	addChild(P2nave2);

	P2nave3 = Button::create("nave3.png", "menus/Botones/nave3.png", "menus/Botones/nave3.png", Widget::TextureResType::LOCAL);
	P2nave3->setAnchorPoint(Point(0.5, 0.5));
	P2nave3->setScale(2);
	P2nave3->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::P2selecN3, this));
	P2nave3->setPosition(Vec2(3 * _visibleSize.width / 4 - 25, _visibleSize.height / 2 -50));
	addChild(P2nave3);

	P2nave4 = Button::create("nave4.png", "menus/Botones/nave4.png", "menus/Botones/nave4.png", Widget::TextureResType::LOCAL);
	P2nave4->setAnchorPoint(Point(0.5, 0.5));
	P2nave4->setScale(2);
	P2nave4->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::P2selecN4, this));
	P2nave4->setPosition(Vec2(3 * _visibleSize.width / 4 - 25, _visibleSize.height / 2 -100));
	addChild(P2nave4);

}

void SelectPlayersMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}

void SelectPlayersMenu::selecP1() { GameWrapper::getInstance()->coop = false; this->P1->setBright(true); this->P2->setBright(false); };
void SelectPlayersMenu::selecP2() { GameWrapper::getInstance()->coop = true; this->P1->setBright(false); this->P2->setBright(true);  };

void SelectPlayersMenu::selecN1() {

	GameWrapper::getInstance()->p1TipoNave = 1;
	
	this->nave1->setBright(false);
	this->nave2->setBright(true);
	this->nave3->setBright(true);
	this->nave4->setBright(true);

};

void SelectPlayersMenu::selecN2() {

	GameWrapper::getInstance()->p1TipoNave = 2;

	this->nave1->setBright(true);
	this->nave2->setBright(false);
	this->nave3->setBright(true);
	this->nave4->setBright(true);

};

void SelectPlayersMenu::selecN3() {

	GameWrapper::getInstance()->p1TipoNave = 3;

	this->nave1->setBright(true);
	this->nave2->setBright(true);
	this->nave3->setBright(false);
	this->nave4->setBright(true);

};

void SelectPlayersMenu::selecN4() {

	GameWrapper::getInstance()->p1TipoNave = 4;

	this->nave1->setBright(true);
	this->nave2->setBright(true);
	this->nave3->setBright(true);
	this->nave4->setBright(false);

};

void SelectPlayersMenu::P2selecN1() {

	GameWrapper::getInstance()->p2TipoNave = 1;

	this->P2nave1->setBright(false);
	this->P2nave2->setBright(true);
	this->P2nave3->setBright(true);
	this->P2nave4->setBright(true);

};

void SelectPlayersMenu::P2selecN2() {

	GameWrapper::getInstance()->p2TipoNave = 2;

	this->P2nave1->setBright(true);
	this->P2nave2->setBright(false);
	this->P2nave3->setBright(true);
	this->P2nave4->setBright(true);

};

void SelectPlayersMenu::P2selecN3() {

	GameWrapper::getInstance()->p2TipoNave = 3;

	this->P2nave1->setBright(true);
	this->P2nave2->setBright(true);
	this->P2nave3->setBright(false);
	this->P2nave4->setBright(true);

};

void SelectPlayersMenu::P2selecN4() {

	GameWrapper::getInstance()->p2TipoNave = 4;

	this->P2nave1->setBright(true);
	this->P2nave2->setBright(true);
	this->P2nave3->setBright(true);
	this->P2nave4->setBright(false);

};