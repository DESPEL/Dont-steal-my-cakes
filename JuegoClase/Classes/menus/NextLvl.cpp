#include "menus/NextLvl.h"
#include "Scenes/DebugScene.h"
#include "MainMenu.h"
#include "Scenes/HistoriaMotherScene.h"
//#include "SelectMenuLayer.h"
//#include "OptionsLayer.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"

USING_NS_CC;
using namespace ui;

Scene* NextMenu::createScene() {
	auto scene = Scene::create();
	auto layer = NextMenu::create();
	scene->addChild(layer);
	return scene;
}


bool NextMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}

	std::vector<std::function <void(cocos2d::Ref*)>> functions;
	//inicializamos un vector de funciones. Cada funcion lanza un nivel
	initFunctions(functions);

	//lanza automaticamente el siguiente nivel a jugar
	auto startButton = Button::create("menus/Botones/SalirMenu0.png", "menus/Botones/SalirMenu1.png", "menus/Botones/SalirMenu0.png", Widget::TextureResType::LOCAL);
	startButton->setAnchorPoint(Point(0.5, 1));
	startButton->setScale(3, 1.5);
	startButton->setPosition(Vec2(_visibleSize.width * 0.5, _visibleSize.height - (90 * getScaleY())));
	if (GameManager::getInstance()->getNextLevel() == GameManager::NUM_LEVELS) {
		//startButton->addClickEventListener(functions.at(GameManager::NUM_LEVELS - 1));
		startButton->addClickEventListener(CC_CALLBACK_0(NextMenu::actionButton1, this));
	} // std::function <void (cocos2d::Ref *)>
	else {
		//startButton->addClickEventListener(functions.at(GameManager::getInstance()->getNextLevel()));
		startButton->addClickEventListener(CC_CALLBACK_0(NextMenu::actionButton1, this));
	}
	addChild(startButton);

	//lanza el menu de seleccion de nivel
	if (wrapper->actualLevel < TOTAL_LEVELS) {
		int num;
		std::ofstream archivo;
		archivo.open("LevelSave.txt");
		num = wrapper->getlvl();
		archivo << 1;
		archivo.close();


		auto nextHeight = startButton->getPositionY() - startButton->getBoundingBox().size.height - (30 * getScaleY());
		auto selectButton = Button::create("menus/Botones/NXT0.png", "menus/Botones/NXT1.png", "menus/Botones/NXT0.png", Widget::TextureResType::LOCAL);
		selectButton->setAnchorPoint(Point(0.5, 1));
		selectButton->setScale(3, 1.5);
		selectButton->addClickEventListener(CC_CALLBACK_0(NextMenu::selectMenuButton, this));
		selectButton->setPosition(Point(startButton->getPositionX(), nextHeight));
		addChild(selectButton);
	}
	else {
		if (GameManager::getInstance()->getDifficulty() >= 2) {
			GameManager::getInstance()->unlockRapidin();
		}
		/// aqui significa que termino el modo historia, por lo tanto hay que desbloquear la nave esa
	}

	return true;
}



void NextMenu::selectMenuButton() {
	experimental::AudioEngine::stopAll();
	if (wrapper->actualLevel >= 3) {
		cocos2d::Director::getInstance()->pushScene(cocos2d::TransitionCrossFade::create(0.1f, DebugScene::createScene(1, false, 3, 4)));
	}
	else
		Director::getInstance()->pushScene(TransitionFadeBL::create(1, HistoriaMotherScene::createScene(wrapper->p1TipoNave, wrapper->coop, wrapper->p2TipoNave, wrapper->actualLevel + 1)));
}

void NextMenu::optionsButton() {
	//Director::getInstance()->replaceScene(TransitionFlipX::create(1, OptionsLayer::createScene()));
}



void NextMenu::initFunctions(std::vector<std::function <void(cocos2d::Ref*)>> functions) {
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton1, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton2, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton3, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton4, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton5, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton6, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton7, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton8, this));
	functions.push_back(CC_CALLBACK_0(NextMenu::actionButton9, this));
}

void NextMenu::actionButton1() { Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene())); }
void NextMenu::actionButton2() { 
	auto wrapper = GameWrapper::getInstance();

	if (wrapper->actualLevel >= 3) {
		cocos2d::Director::getInstance()->pushScene(cocos2d::TransitionCrossFade::create(0.1f, DebugScene::createScene(1, false, 3, 4)));
	}
	else
		Director::getInstance()->pushScene(TransitionFadeBL::create(1, HistoriaMotherScene::createScene(wrapper->p1TipoNave, wrapper->coop, wrapper->p2TipoNave, wrapper->actualLevel + 1))); 
}
void NextMenu::actionButton3() {  /*TODO*/ }
void NextMenu::actionButton4() {  /*TODO*/ }
void NextMenu::actionButton5() {  /*TODO*/ }
void NextMenu::actionButton6() {  /*TODO*/ }
void NextMenu::actionButton7() {  /*TODO*/ }
void NextMenu::actionButton8() {  /*TODO*/ }
void NextMenu::actionButton9() {  /*TODO*/ }