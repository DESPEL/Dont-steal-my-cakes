#include "DebugScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;

DebugScene::DebugScene(bool jug) {
	this->two = jug;
	DebugScene::init();
}

Scene* DebugScene::createScene(bool jug) {
	auto scene = Scene::create();
	auto layer = new DebugScene(jug); //DebugScene::create(jug);
	scene->addChild(layer);

	return scene;
}

bool DebugScene::init() {

	if (!Layer::init())
		return false;

	auto _visibleSize = Director::getInstance()->getWinSize();

	//Crea el background
	_bg = Background::create();
	addChild(_bg, -1);

	//Crea al jugador
	_player = Player::create();
	if(!this->two)
		_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	else
		_player->setPosition(_visibleSize.width / 2 + 100, _visibleSize.height / 2 - 100);
	
	_player->setScale(2);
	addChild(_player);

	if (this->two) {
		_player2 = Player2::create();
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
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music\\get_lucky.mp3", true);

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
