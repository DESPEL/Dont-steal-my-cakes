#pragma once

#include "cocos2d.h"
#include <map>
#include "keyboard.h"
#include "Bullet.h"
#include "DataEngine.h"
#include "GameWrapper.h"
//#include "Player\Changuito.h"

class Bullet;

class Player : public cocos2d::Sprite {
protected:

	// Customización
	std::string personaje_path;
	std::string animacion_path;



	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	// Controlador
	KeyBoard* _control;

	// Balas
	
	int _numbullets = 100;
	void shoot(cocos2d::Vec2);
	float delay = 0;
	float delayvalue = 0.25;
	int change = 1;


	void createIdleAnimation();
	void createExplosionAnimation();

public:

	float hp = 3;
	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};

	enum Tipos {
		DEFAULT = 0, RAPIDIN = 1, NORMAL = 2, TANQUE = 3, MCDONALDS = 4
	};

	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
	CC_SYNTHESIZE(float, _speed, Speed);
//	CREATE_FUNC(Player);
	//Player();

	// Colision
	void setCurrentAnimation(Animations anim);

	static Player* create(int tipo = 0);
	Player(int tipo);
	~Player() {};
	
	
	virtual bool init();
	void update(float);

	// Variables para disparos
	int bulletsact = 0;
	bool vuelta = 0;
	cocos2d::Vector<Bullet*> Balas;

	int kills = 0;
	int points = 0;
};

