#include "DebugScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

#include "Level.h"

USING_NS_CC;

Scene* DebugScene::createScene() {
	auto scene = Scene::create();
	auto layer = DebugScene::create();
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
	_player->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 - 100);
	_player->setScale(2);
	addChild(_player);
	
	//Crea al enemigo
	//auto enemy = BasicEnemy::create();
	//enemy->setPosition(_visibleSize.width / 2, _visibleSize.height / 2 + 100);
	//enemy->setScale(2);
	//_enemyPool.pushBack(enemy);

	//addChild(enemy);

	MovementPattern test(
		std::make_tuple(1.0f, Vec2(100, 0)),
		std::make_tuple(10.0f, Vec2(0, 0))
	);

	MovementPattern test1(
		std::make_tuple(1.0f, Vec2(0, -100)),
		std::make_tuple(1.0f, Vec2(30, -100))
	);

	AttackPattern test2(
		std::make_tuple(0.0f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
		std::make_tuple(0.0f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
		std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f))
	);

	GameWrapper::getInstance()->setPlayer(_player);

	Enemy* testenemy = Enemy::create("enemigo1.png", test.get(-90), test2.get(test.get(-90)), Vec2(400, 300));

	Level prueba(
		std::make_tuple(1.0f, testenemy),
		std::make_tuple(1.0f, testenemy),
		std::make_tuple(1.0f, testenemy),
		std::make_tuple(1.0f, testenemy),
		std::make_tuple(1.0f, testenemy)
	);
	this->retain();
	prueba.get(this).run();


	//enemy->runAction(test.get(-90));
	//test2.get(test.get(-90)).run(enemy);
	//test2.get(test.get(90)).run(enemy);


	//Agrega el update al updater mas grande
	this->schedule(schedule_selector(DebugScene::update));

	// Musica
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Music\\get_lucky.mp3", true);

	return true;
}

void DebugScene::createEnemy() {

};

void DebugScene::update(float delta) {

}
