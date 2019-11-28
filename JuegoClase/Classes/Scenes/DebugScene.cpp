#include "DebugScene.h"
#include "SimpleAudioEngine.h"
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
	button4->setScaleX(1.5);
	button4->setVisible(false);
	addChild(button4, 3);
	

	//Crea al jugador
	_player = Player::create(naveP1);
	if(!this->two)
		_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	else
		_player->setPosition(_visibleSize.width / 2 + 100, _visibleSize.height / 2 - 100);
	
	_player->setScale(2);
	addChild(_player);

	if (this->two) {
		_player2 = Player2::create(naveP2);
		_player2->setPosition(_visibleSize.width / 2 - 100, _visibleSize.height / 2 - 100);
		_player2->setScale(2);
		addChild(_player2);
	}

	GameWrapper::getInstance()->setPlayer(_player);
	GameWrapper::getInstance()->coop = this->two;
	//Crea al enemigo
	/*auto enemy = BasicEnemy::create();
	enemy->setPosition(_visibleSize.width /2, _visibleSize.height /2 + 100);
	enemy->setScale(2);
	_enemyPool.pushBack(enemy);
	addChild(enemy);
	
	enemy->run();*/

	//Agrega el update al updater mas grande
	this->schedule(schedule_selector(DebugScene::update));

	//Aparece enemigos de manera aleatoria y automatica
	DelayTime* delayAction = DelayTime::create(5.0f);
	CallFunc* callSelectorAction = CallFunc::create(CC_CALLBACK_0(DebugScene::createEnemy, this));
	auto shootSequence = Sequence::create(delayAction, callSelectorAction, NULL);
	runAction(RepeatForever::create(shootSequence));

	// Musica
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music\\Mantis.mp3", true);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.02);

	return true;
}

void DebugScene::createEnemy() {
	auto _visibleSize = Director::getInstance()->getWinSize();

	auto enemy = BasicEnemy::create();
	float maxX = _visibleSize.width - 40;
	float minX = 40;
	float maxY = _visibleSize.height - 20;
	float minY = _visibleSize.height/2;
	enemy->setPosition(random(minX, maxX),random(minY, maxY));
	enemy->setScale(2);
	_enemyPool.pushBack(enemy);
	addChild(enemy);
	enemy->run();
};

void DebugScene::update(float delta) {
		if (_player->isVisible() || two && (_player2->isVisible() )) {// (wrapper->coop) ? (_player2->isVisible()) : ())
			_bg->update(delta);
		}

	_player->update(delta);

	for (auto e : _enemyPool) {
		
		// Colision Enemigo vs Balas
		for (auto b : _player->Balas) {
			if (b->activa) {
				if (b->getBoundingBox().intersectsRect(e->getBoundingBox())) {
					e->explode();
					b->colision();
					_player->kills++;
				}
			}
		}
		
		if (this->two) {
			for (auto b : _player2->Balas) {
				if (b->activa) {
					if (b->getBoundingBox().intersectsRect(e->getBoundingBox())) {
						e->explode();
						b->colision();
						_player->kills++;
					}
				}
			}
		}

		// Colision Enemigo - Jugador
		if (!e->exploded) {
			if (e->getBoundingBox().intersectsRect(_player->getBoundingBox())) {
				_player->setCurrentAnimation(Player::EXPLOSION);
				e->explode();
			}
		}

		if (this->two) {
			if (!e->exploded) {
				if (e->getBoundingBox().intersectsRect(_player2->getBoundingBox())) {
					_player2->setCurrentAnimation(Player2::EXPLOSION);
					e->explode();
				}
			}
		}
		

		// Colision balas enemigo vs Jugador
		for (auto b : e->Balas) {
			if (b->activa) {
				if (b->getBoundingBox().intersectsRect(_player->getBoundingBox())) {
					_player->setCurrentAnimation(Player::EXPLOSION);
				}
			}
		}

		/*if (two) {
			for (auto bala : e->Balas) {
				if (bala->getBoundingBox().intersectsRect(_player2->getBoundingBox())) {
					_player2->setCurrentAnimation(Player2::EXPLOSION);
				}
			}
		}*/

		//if (two != false) {
			/*for (auto b : e->Balas) {
				if (b->activa) {
					if (b->getBoundingBox().intersectsRect(_player2->getBoundingBox())) {
						_player2->setCurrentAnimation(Player2::EXPLOSION);
					}
				}
			}*/
		//}
	}

	if ((_player->get_currentAnimation() == Player::EXPLOSION && !two) || (_player->get_currentAnimation() == Player::EXPLOSION && two && (_player2->get_currentAnimation() == Player2::EXPLOSION))) {
		for (auto e : _enemyPool) {
			e->stopActionByTag(20);
		}
		
		this->wrapper->death();
	}
}
void DebugScene::pauseButtonAction()
{
	button->setVisible(false);
	button2->setVisible(true);
	button3->setVisible(true);
	button4->setVisible(true);
	pause();
	this->pausado = 1;
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	cocos2d::Director::getInstance()->stopAnimation();
	
}

void DebugScene::playButtonAction()
{
	button->setVisible(true);
	button2->setVisible(false);
	button3->setVisible(false);
	button4->setVisible(false);
	resume();
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	
	cocos2d::Director::getInstance()->startAnimation();

}

void DebugScene::saveButtonAction() {

}

void DebugScene::salirButtonAction() {
	cocos2d::Director::getInstance()->startAnimation();
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}

