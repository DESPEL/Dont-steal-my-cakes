#include "DebugScene.h"
//#include "SimpleAudioEngine.h"
//using namespace CocosDenshion;
#include "AudioEngine.h"

#include "Levels/Levels.h"

#include "TranslationEngine.h"
#include "ui/CocosGUI.h"
#include "GameWrapper.h"
#include "menus/MainMenu.h"
using namespace CocosDenshion;

USING_NS_CC;

DebugScene::DebugScene(int tipoP1, bool two, int tipoP2) {
	this->two = two;
	this->naveP1 = tipoP1;
	this->naveP2 = tipoP2;
	DebugScene::init();
}

Scene* DebugScene::createScene(int tipoP1, bool two, int tipoP2) {
	auto scene = Scene::create();
	auto layer = new DebugScene(tipoP1, two, tipoP2); //DebugScene::create(jug);
	scene->addChild(layer);

	return scene;
}

bool DebugScene::init() {

	if (!Layer::init())
		return false;

	auto _visibleSize = Director::getInstance()->getWinSize();

	//Crea el background
	_bg = Background::create();
	 button = ui::Button::create("menus/Pausa.png", "menus/Pausa.png", "menus/Pausa.png");
		
	button->setAnchorPoint(Point(1, 0.5));
	button->setPosition(Point(_visibleSize.width - 20 * getScaleX(), 280));
	button->addClickEventListener(CC_CALLBACK_0(DebugScene::pauseButtonAction, this));
	button->setScale(.2);
	addChild(button, 3);
	addChild(_bg, -1);
	_bg->scheduleUpdate();

	this->retain();
	
	button2 = ui::Button::create("menus/Play.png", "menus/Play.png", "menus/Play.png");
	button2->setAnchorPoint(Point(1, 0.5));
	button2->setPosition(Point(_visibleSize.width - 20 * getScaleX(), 280));
	button2->addClickEventListener(CC_CALLBACK_0(DebugScene::playButtonAction, this));
	button2->setScale(.2);
	button2->setVisible(false);
	addChild(button2, 3);
	
	button3 = ui::Button::create("menus/save.png", "menus/save.png", "menus/save.png");
	button3->setAnchorPoint(Point(.5, .5));
	button3->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2));
	button3->addClickEventListener(CC_CALLBACK_0(DebugScene::playButtonAction, this));
	button3->setScale(.4);
	button3->setVisible(false);
	addChild(button3, 3);


	
	button4 = ui::Button::create("menus/Botones/SalirMenu0.png", "menus/Botones/SalirMenu1.png", "menus/Botones/SalirMenu0.png");
	button4->setAnchorPoint(Point(.5, .5));
	button4->setPosition(Point(_visibleSize.width / 2, 70));
	button4->addClickEventListener(CC_CALLBACK_0(DebugScene::salirButtonAction, this));
	button4->setScale(1);
	button4->setVisible(false);
	addChild(button4, 3);
	

	//Crea al jugador
	_player = Player::create(naveP1);
	if(!this->two)
		_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	else
		_player->setPosition(_visibleSize.width / 2 + 100, _visibleSize.height / 2 - 100);
	addChild(_player);

	if (this->two) {
		_player2 = Player2::create(naveP2);
		_player2->setPosition(_visibleSize.width / 2 - 100, _visibleSize.height / 2 - 100);
		addChild(_player2);
	}

	GameWrapper::getInstance()->setPlayer(_player);
	GameWrapper::getInstance()->coop = this->two;

	//Agrega el update al updater mas grande
	this->schedule(schedule_selector(DebugScene::update));

	//Levels::create("level-1").get(this).run();
	Levels::create("boss").get(this).run();
	// Musica
	this->soundID = cocos2d::experimental::AudioEngine::play2d("Music\\Mantis.mp3", true);
	return true;
}

void DebugScene::update(float delta) {
	std::stringstream s;
	s << "PUNTOS DEL JUEGO: " << this->wrapper->getInstance()->getPlayer()->points;
	cocos2d::log(s.str().c_str());

	if (_player->isVisible() || two && (_player2->isVisible() )) {// (wrapper->coop) ? (_player2->isVisible()) : ())
		_bg->update(delta);
	}

	_player->update(delta);


	if ((_player->get_currentAnimation() == Player::EXPLOSION && !two) || (_player->get_currentAnimation() == Player::EXPLOSION && two && (_player2->get_currentAnimation() == Player2::EXPLOSION))) {
		if (_player->getActionByTag(Player::Animations::EXPLOSION) == nullptr && (!two || (_player2->getActionByTag(Player::Animations::EXPLOSION) == nullptr))) {
			experimental::AudioEngine::stop(soundID);
			this->wrapper->death();
		}
	}
}
void DebugScene::pauseButtonAction()
{
	experimental::AudioEngine::pause(soundID);
	button->setVisible(false);
	button2->setVisible(true);
	button3->setVisible(true);
	button4->setVisible(true);
	pause();
	this->pausado = 1;
	cocos2d::Director::getInstance()->stopAnimation();
	
}

void DebugScene::playButtonAction()
{
	experimental::AudioEngine::resume(soundID);
	button->setVisible(true);
	button2->setVisible(false);
	button3->setVisible(false);
	button4->setVisible(false);
	resume();
	
	cocos2d::Director::getInstance()->startAnimation();

}

void DebugScene::saveButtonAction() {

}

void DebugScene::salirButtonAction() {
	experimental::AudioEngine::stop(soundID);
	cocos2d::Director::getInstance()->startAnimation();
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}

