#pragma once

#include "HelloWorldScene.h"
#include "Player/Player2.h"
#include "GameWrapper.h"

class DebugScene : public cocos2d::Layer {
private:

		bool two = 0;
		
		//Enemys
		int _numEnemies = 10;
		int _enemyIndex = 0;
		float delay = 0;

		Background* _bg;

		Player* _player;
		Player2* _player2;
		cocos2d::Vector<BasicEnemy*> _enemyPool;

		void createEnemy();

public:
		static cocos2d::Scene* createScene(bool = 0);

		DebugScene(bool);
		~DebugScene() {};

		virtual bool init();

		void update(float);


		GameWrapper* wrapper = GameWrapper::getInstance();

		// implement the "static create()" method manually
		//HelloWorld();
		//CREATE_FUNC(DebugScene);

};

