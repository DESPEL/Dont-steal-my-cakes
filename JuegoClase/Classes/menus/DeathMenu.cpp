#include "DeathMenu.h"
#include "Scenes/DebugScene.h"
#include "Scenes/MiniGameScene.h"
#include "MainMenu.h"
//#include "SelectMenuLayer.h"
//#include "OptionsLayer.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "GameWrapper.h"
#include "Macros.h"

USING_NS_CC;
using namespace ui;

Scene* DeathMenu::createScene(GAME_TYPE from) {
	auto scene = Scene::create();
	auto layer = DeathMenu::create();
	layer->caller = from;
	scene->addChild(layer);
	return scene;
}


bool DeathMenu::init() {
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
		startButton->addClickEventListener(CC_CALLBACK_0(DeathMenu::actionButton1, this));
	} // std::function <void (cocos2d::Ref *)>
	else {
		//startButton->addClickEventListener(functions.at(GameManager::getInstance()->getNextLevel()));
		startButton->addClickEventListener(CC_CALLBACK_0(DeathMenu::actionButton1, this));
	}
	addChild(startButton);

	//lanza el menu de seleccion de nivel
	auto nextHeight = startButton->getPositionY() - startButton->getBoundingBox().size.height - (30 * getScaleY());
	auto selectButton = Button::create("menus/Botones/Reiniciar0.png", "menus/Botones/Reiniciar1.png", "menus/Botones/Reiniciar0.png", Widget::TextureResType::LOCAL);
	selectButton->setAnchorPoint(Point(0.5, 1));
	selectButton->setScale(3, 1.5);
	selectButton->addClickEventListener(CC_CALLBACK_0(DeathMenu::selectMenuButton, this));
	selectButton->setPosition(Point(startButton->getPositionX(), nextHeight));
	addChild(selectButton);

	//lanza las opciones para ajustar volumen y otras configuraciones
	

	return true;
}



void DeathMenu::selectMenuButton() {
	if (caller == GAME_TYPE::HISTORIA || caller == GAME_TYPE::LIBRE) {
		Director::getInstance()->pushScene(TransitionFadeBL::create(1, DebugScene::createScene(wrapper->p1TipoNave, wrapper->coop, wrapper->p2TipoNave, wrapper->actualLevel)));
	}
	if (caller == GAME_TYPE::MINIJUEGO) {
		/// aqui hacer esa cosa si eso se queir ehacer
		Director::getInstance()->pushScene(TransitionCrossFade::create(1, MiniGameScene::createScene()));
	}
}

void DeathMenu::optionsButton() {
	//Director::getInstance()->replaceScene(TransitionFlipX::create(1, OptionsLayer::createScene()));
}



void DeathMenu::initFunctions(std::vector<std::function <void(cocos2d::Ref*)>> functions) {
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton1, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton2, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton3, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton4, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton5, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton6, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton7, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton8, this));
	functions.push_back(CC_CALLBACK_0(DeathMenu::actionButton9, this));
}

void DeathMenu::actionButton1() { Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene())); }
void DeathMenu::actionButton2() { 
	auto wrapper = GameWrapper::getInstance();
	std::stringstream s;
	s << "finished level is" << wrapper->actualLevel;
	cocos2d::log(s.str().c_str());
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, DebugScene::createScene(wrapper->p1TipoNave, wrapper->coop, wrapper->p2TipoNave, wrapper->actualLevel))); 
}
void DeathMenu::actionButton3() {  /*TODO*/ }
void DeathMenu::actionButton4() {  /*TODO*/ }
void DeathMenu::actionButton5() {  /*TODO*/ }
void DeathMenu::actionButton6() {  /*TODO*/ }
void DeathMenu::actionButton7() {  /*TODO*/ }
void DeathMenu::actionButton8() {  /*TODO*/ }
void DeathMenu::actionButton9() {  /*TODO*/ }

