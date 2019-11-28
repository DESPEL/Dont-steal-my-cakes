#include "SelectPlayersMenu.h"
#include "GameManager.h"
#include "GameWrapper.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"

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

	auto startBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	startBt->setAnchorPoint(Point(0, 0.5));
	startBt->setScale(2);
	startBt->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::actionButton1, this));
	startBt->setPosition(Point((_visibleSize.width - 30) * getScaleX(), 30 * getScaleY()));
	addChild(startBt);

	return true;
}

void SelectPlayersMenu::initButtons() {

	P1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/level0.png", Widget::TextureResType::LOCAL);
	P1->setAnchorPoint(Point(0.5, 0.5));
	P1->setScale(0.4);
	P1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecP1, this));
	P1->setPosition(Vec2(_visibleSize.width / 4, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P1);

	P2 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/level0.png", Widget::TextureResType::LOCAL);
	P2->setAnchorPoint(Point(0.5, 0.5));
	P2->setScale(0.4);
	P2->setBright(false);
	P2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecP2, this));
	P2->setPosition(Vec2(3*_visibleSize.width / 4, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(P2);

	nave1 = Button::create("nave1.png", "menus/Botones/nave1.png", "menus/Botones/nave1.png", Widget::TextureResType::LOCAL);
	nave1->setAnchorPoint(Point(0.5, 0.5));
	nave1->setScale(2);
	nave1->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN1, this));
	nave1->setPosition(Vec2(1*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave1);

	nave2 = Button::create("nave2.png", "menus/Botones/nave2.png", "menus/Botones/nave2.png", Widget::TextureResType::LOCAL);
	nave2->setAnchorPoint(Point(0.5, 0.5));
	nave2->setScale(2);
	nave2->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN2, this));
	nave2->setPosition(Vec2(2*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave2);

	nave3 = Button::create("nave3.png", "menus/Botones/nave3.png", "menus/Botones/nave3.png", Widget::TextureResType::LOCAL);
	nave3->setAnchorPoint(Point(0.5, 0.5));
	nave3->setScale(2);
	nave3->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN3, this));
	nave3->setPosition(Vec2(3*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave3);

	nave4 = Button::create("nave4.png", "menus/Botones/nave4.png", "menus/Botones/nave4.png", Widget::TextureResType::LOCAL);
	nave4->setAnchorPoint(Point(0.5, 0.5));
	nave4->setScale(2);
	nave4->addClickEventListener(CC_CALLBACK_0(SelectPlayersMenu::selecN4, this));
	nave4->setPosition(Vec2(4*_visibleSize.width / 5, _visibleSize.height / 2));
	addChild(nave4);	


}

void SelectPlayersMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, SelectPlayersMenu::createScene()));
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