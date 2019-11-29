#pragma once

#include "cocos2d.h"
#include <map>
#include "keyboard.h"
#include "Bullet.h"

class Bullet;

class Player2 : public cocos2d::Sprite {
protected:

	// Customización
	std::string personaje_path;
	std::string animacion_path;



	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;

	// Controlador
	KeyBoard* _control;

	// Balas

	int _numbullets = 1000;
	void shoot(cocos2d::Vec2);
	float delay = 0;
	float delayvalue = 0.125;
	int change = 1;


	void createIdleAnimation();
	void createExplosionAnimation();

public:
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

	static Player2* create(int tipo = 0);
	Player2(int tipo);
	~Player2() {};


	virtual bool init();
	void update(float);

	// Variables para disparos
	int bulletsact = 0;
	bool vuelta = 0;
	cocos2d::Vector<Bullet*> Balas;

	int kills = 0;
	int hp = 2;
};


