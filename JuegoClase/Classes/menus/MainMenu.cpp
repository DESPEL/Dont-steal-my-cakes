#include "MainMenu.h"
#include "Scenes/DebugScene.h"
//#include "SelectMenuLayer.h"
//#include "OptionsLayer.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"

USING_NS_CC;
using namespace ui;

Scene* MainMenu::createScene()
{
	auto scene = Scene::create();
	auto layer = MainMenu::create();
	scene->addChild(layer);
	return scene;
}


bool MainMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}
	
	std::vector<std::function <void(cocos2d::Ref*)>> functions;
	//inicializamos un vector de funciones. Cada funcion lanza un nivel
	initFunctions(functions);

	//lanza automaticamente el siguiente nivel a jugar
	auto startButton = Button::create("menus/Botones/start0.png", "menus/Botones/start1.png", "menus/Botones/start0.png", Widget::TextureResType::LOCAL);
	startButton->setAnchorPoint(Point(0.5, 1));
	startButton->setScale(3, 1.5);
	startButton->setPosition(Vec2(_visibleSize.width * 0.5, _visibleSize.height - (90 * getScaleY())));
	if (GameManager::getInstance()->getNextLevel() == GameManager::NUM_LEVELS) {
		//startButton->addClickEventListener(functions.at(GameManager::NUM_LEVELS - 1));
		startButton->addClickEventListener(CC_CALLBACK_0(MainMenu::actionButton1, this));
	} // std::function <void (cocos2d::Ref *)>
	else {
		//startButton->addClickEventListener(functions.at(GameManager::getInstance()->getNextLevel()));
		startButton->addClickEventListener(CC_CALLBACK_0(MainMenu::actionButton1, this));
	}
	addChild(startButton);

	//lanza el menu de seleccion de nivel
	auto nextHeight = startButton->getPositionY() - startButton->getBoundingBox().size.height - (30 * getScaleY());
	auto selectButton = Button::create("menus/Botones/level0.png", "menus/Botones/level1.png", "menus/Botones/level0.png", Widget::TextureResType::LOCAL);
	selectButton->setAnchorPoint(Point(0.5, 1));
	selectButton->addClickEventListener(CC_CALLBACK_0(MainMenu::selectMenuButton, this));
	selectButton->setPosition(Point(startButton->getPositionX(), nextHeight));
	addChild(selectButton);

	//lanza las opciones para ajustar volumen y otras configuraciones
	nextHeight = selectButton->getPositionY() - selectButton->getBoundingBox().size.height - (30 * getScaleY());
	auto optionsButton = Button::create("menus/Botones/options0.png", "menus/Botones/options1.png", "menus/Botones/options0.png", Widget::TextureResType::LOCAL);
	optionsButton->setAnchorPoint(Point(0.5, 1));
	optionsButton->addClickEventListener(CC_CALLBACK_0(MainMenu::optionsButton, this));
	optionsButton->setPosition(Point(startButton->getPositionX(), nextHeight));
	addChild(optionsButton);

	return true;
}



void MainMenu::selectMenuButton() {
	//Director::getInstance()->replaceScene(TransitionFadeBL::create(1, SelectMenuLayer::createScene()));
}

void MainMenu::optionsButton() {
	//Director::getInstance()->replaceScene(TransitionFlipX::create(1, OptionsLayer::createScene()));
}



void MainMenu::initFunctions(std::vector<std::function <void(cocos2d::Ref*)>> functions) {
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton1, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton2, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton3, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton4, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton5, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton6, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton7, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton8, this));
	functions.push_back(CC_CALLBACK_0(MainMenu::actionButton9, this));
}

void MainMenu::actionButton1() { Director::getInstance()->pushScene(DebugScene::createScene()); }
void MainMenu::actionButton2() {  /*TODO*/ }
void MainMenu::actionButton3() {  /*TODO*/ }
void MainMenu::actionButton4() {  /*TODO*/ }
void MainMenu::actionButton5() {  /*TODO*/ }
void MainMenu::actionButton6() {  /*TODO*/ }
void MainMenu::actionButton7() {  /*TODO*/ }
void MainMenu::actionButton8() {  /*TODO*/ }
void MainMenu::actionButton9() {  /*TODO*/ }

