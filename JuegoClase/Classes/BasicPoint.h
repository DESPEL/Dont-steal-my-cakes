#pragma once

#include "cocos2d.h"
#include "Bullet.h"
#include "MovementPattern.h"
#include "AttackPattern.h"



class BasicPoint : public cocos2d::Sprite {
private:
	cocos2d::Action* _idleAnimation;
	cocos2d::Action* _explosionAnimation;
	cocos2d::Action* _shoot;


	void createIdleAnimation();
	void createExplosionAnimation();
	

	float DyingTime = 0.90;

public:
	int _numbullets = 100;
	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};

	void setCurrentAnimation(Animations anim);
	void explode();
	void scheduleShoot();
	void shoot();
	void erase();
	void run();

	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
	CC_SYNTHESIZE(float, _speed, Speed);
	CREATE_FUNC(BasicPoint);

	virtual bool init();
	void update(float);

	int bulletsact = 0;
	bool vuelta = 0;
	cocos2d::Vector<Bullet*> Balas;
	bool exploded = false;
};
