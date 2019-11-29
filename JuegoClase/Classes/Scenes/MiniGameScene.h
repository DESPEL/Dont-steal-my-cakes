#pragma once

#include "HelloWorldScene.h"
#include "Player/Player2.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameWrapper.h"
#include "GameManager.h"
#include "BasicPoint.h"

class MiniGameScene : public cocos2d::Layer {
private:

	bool two = 0;
	int _puntos = 0;
	int highscore;
	float Tiempo = 60;
	int seg = Tiempo;
	float variar;
	int num;
	cocos2d::Label *label;
	cocos2d::Label* tiempo;
	std::string mensaje = "Puntos: " + std::to_string(_puntos);
	std::string mensajet = "Tiempo: " + std::to_string(seg);
	std::string mensajeHS = "High Score: ";
	
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
	cocos2d::Vector<BasicPoint*> _enemyPool;

	void createEnemy();

protected:
	virtual void pauseButtonAction();
	virtual void playButtonAction();
	virtual void saveButtonAction();
	virtual void salirButtonAction();
	virtual void Timer(float delta);
	virtual void Maspuntos();

public:
	static cocos2d::Scene* createScene(bool = 0);

	MiniGameScene(bool);
	~MiniGameScene() {};

	virtual bool init();

	void update(float);


	GameWrapper* wrapper = GameWrapper::getInstance();

	// implement the "static create()" method manually
	//HelloWorld();
	//CREATE_FUNC(DebugScene);

};

