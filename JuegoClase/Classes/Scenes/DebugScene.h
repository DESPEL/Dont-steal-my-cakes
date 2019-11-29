#pragma once

#include "HelloWorldScene.h"

#include "Player.h"
#include "BasicEnemy.h"
#include "Player/Player2.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameWrapper.h"
#include "MovementPattern.h"
#include "AttackPattern.h"

class DebugScene : public cocos2d::Layer {
private:
	bool ended = false;
	int level = 1;
	bool two = 0;
	int naveP1 = 1;
	int naveP2 = 1;

	//Enemys
	int _numEnemies = 10;
	int _enemyIndex = 0;
	float delay = 0;
	cocos2d::ui::Button* button;
	cocos2d::ui::Button* button2;
	cocos2d::ui::Button* button3;
	cocos2d::ui::Button* button4;

	Background* _bg;
		
	Player* _player;
	Player2* _player2;
	cocos2d::Vector<BasicEnemy*> _enemyPool;

protected:
	virtual void saveButtonAction();
	virtual void salirButtonAction();

public:
	int soundID;

	virtual void pauseButtonAction();
	virtual void playButtonAction();
	bool pausado = 0;
	
	static cocos2d::Scene* createScene(int tipoP1 = 1, bool two = 0, int tipoP2 = 0, int level = 1);
	DebugScene(int tipoP1, bool two, int tipoP2, int level);
	DebugScene() {};
	~DebugScene() {};

	virtual bool init();

	void update(float);

	// implement the "static create()" method manually
	//HelloWorld();

	GameWrapper* wrapper = GameWrapper::getInstance();

	// implement the "static create()" method manually
	//HelloWorld();
	//CREATE_FUNC(DebugScene);

	CREATE_FUNC(DebugScene);

};

