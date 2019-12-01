#pragma once
//
#include "cocos2d.h"
//#include "Bullet.h"

#include "BasicBullet.h"

class BasicBullet;

class BasicEnemy : public cocos2d::Sprite {
public:
	//cocos2d::Vector<BasicBullet*> bullets;

	enum Animations {
		IDLE = 0,
		EXPLOSION = 1
	};
	bool exploded = false;
	bool boss = false;
	int hp = 100;
	cocos2d::Vec2 childPosition;

protected:

	cocos2d::Action* idleAnimation;
	cocos2d::Action* explosionAnimation;
	cocos2d::Action* shoot;

	void createIdleAnimation() {
		cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
		auto sprite1 = Sprite::create("enemigo1.png");
		auto size = sprite1->getContentSize();
		//for (int i = 0; i < 4; i++) {
			auto frame = cocos2d::SpriteFrame::create("animacion_enemigo.png", cocos2d::Rect(cocos2d::Vec2(0, 0), size));
			animFrames.pushBack(frame);
		//}
		

		this->setSpriteFrame(animFrames.at(0));

		auto animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.25f);
		auto animate = cocos2d::Animate::create(animation);

		idleAnimation = cocos2d::RepeatForever::create(animate);
		idleAnimation->setTag(BasicEnemy::Animations::IDLE);
		idleAnimation->retain();
	}

	void createExplosionAnimation() {
		cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
		auto sprite1 = cocos2d::Sprite::create("enemigo1.png");
		auto size = sprite1->getContentSize();
		for (int i = 0; i < 6; i++) {
			auto frame = cocos2d::SpriteFrame::create("animacion_enemigo_explotar.png", cocos2d::Rect(cocos2d::Vec2(size.width * i, 0), size));
			animFrames.pushBack(frame);
		}

		auto animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.15f);

		explosionAnimation = cocos2d::Animate::create(animation);
		explosionAnimation->setTag(BasicEnemy::Animations::EXPLOSION);
		explosionAnimation->retain();
	}

	void SetAnimation(Animations anim) {
		if (CurrentAnimation == anim) return;
		CurrentAnimation = anim;
		if (CurrentAnimation == IDLE) {
			stopActionByTag(EXPLOSION);
			runAction(idleAnimation);
		}
		if (CurrentAnimation == EXPLOSION) {
			stopActionByTag(IDLE);
			runAction(explosionAnimation);
		}
	}


	~BasicEnemy() {
		explosionAnimation->release();
	}


	CC_SYNTHESIZE(Animations, CurrentAnimation, CurrentAnimation);
	CC_SYNTHESIZE(float, speed, Speed);

	CREATE_FUNC(BasicEnemy);
};



//
//class Bullet;
//
//class BasicEnemy : public cocos2d::Sprite {
//private:
//	cocos2d::Action* _idleAnimation;
//	cocos2d::Action* _explosionAnimation;
//	cocos2d::Action* _shoot;
//
//
//	void createIdleAnimation();
//	void createExplosionAnimation();
//
//	float DyingTime = 0.90;
//	int _numbullets = 100;
//
//public:
//	enum Animations {
//		IDLE = 0, EXPLOSION = 1
//	};
//
//	void setCurrentAnimation(Animations anim);
//	void explode();
//	void scheduleShoot();
//	void shoot();
//
//	CC_SYNTHESIZE(Animations, _currentAnimation, _currentAnimation);
//	CC_SYNTHESIZE(float, _speed, Speed);
//	CREATE_FUNC(BasicEnemy);
//
//	virtual bool init();
//	void update(float);
//
//	int bulletsact = 0;
//	bool vuelta = 0;
//	cocos2d::Vector<Bullet*> Balas;
//	bool exploded = false;
//};