#pragma once

#include "HelloWorldScene.h"

#include "Player.h"
#include "BasicEnemy.h"
#include "Player/Player2.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameWrapper.h"


class HistoriaMotherScene : public cocos2d::Layer {
private:

	bool two = 0;
	int naveP1;
	int naveP2;
	int estado=1;
	//Enemys
	int _numEnemies = 10;
	int _enemyIndex = 0;
	float delay = 0;
	cocos2d::ui::Button* button;
	cocos2d::ui::Button* button2;
	cocos2d::ui::Button* button3;
	cocos2d::ui::Button* button4;
	bool ingles = true;
	int historia = 2;

	Background* _bg;

	Player* _player;
	Player2* _player2;
	cocos2d::Vector<BasicEnemy*> _enemyPool;

protected:
	virtual void saveButtonAction();
	virtual void salirButtonAction();

public:
	int soundID;
	std::vector<std::string> Historia1;
	std::vector<std::string> Historia2;
	std::vector<std::string> Historia3;
	cocos2d::Label* Actual;
	
	virtual void PrevButtonAction();
	virtual void NextButtonAction();
	bool pausado = 0;
	
	static cocos2d::Scene* createScene(int tipoP1 = 1, bool two = 0, int tipoP2 = 0, int est = 1);
	HistoriaMotherScene(int tipoP1, bool two, int tipoP2, int est);
	HistoriaMotherScene() {};
	~HistoriaMotherScene() {};

	virtual bool init();

	void update(float);

	// implement the "static create()" method manually
	//HelloWorld();

	GameWrapper* wrapper = GameWrapper::getInstance();

	// implement the "static create()" method manually
	//HelloWorld();
	//CREATE_FUNC(DebugScene);

	CREATE_FUNC(HistoriaMotherScene);

};

