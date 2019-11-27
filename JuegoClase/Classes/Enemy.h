#pragma once

#include "cocos2d.h"

#include "BasicEnemy.h"
#include "AttackPattern.h"

class AttackPattern;

class Enemy : public BasicEnemy
{
public:
	bool exploded = false;

	enum Animations {
		IDLE = 0, EXPLOSION = 1
	};
	CC_SYNTHESIZE(Animations, currentAnimation, currentAnimation);

	/*void setCurrentAnimation(Animations anim);
	void explode();
	void scheduleShoot();
	void shoot();*/

	cocos2d::Sequence* sequence;
	AttackPattern attack;
	cocos2d::Node* p;

	bool init() {
		currentAnimation = IDLE;
		createIdleAnimation();
		createExplosionAnimation();
		return true;
	}

	static Enemy* create(std::string name, cocos2d::Sequence* seq, AttackPattern att, cocos2d::Vec2 pos) {
		
		Enemy* ret = Enemy::create();
		ret->initWithFile(name);
		ret->sequence = seq;
		ret->attack = att;
		ret->setPosition(pos);
		return ret;
	}

	static Enemy* create(Enemy* base) {
		Enemy* ret = Enemy::create();
		ret->initWithTexture(base->getTexture());
		ret->sequence = base->sequence;
		ret->attack = base->attack;
		ret->setPosition(base->getPosition());
		return ret;
	}

	static Enemy* create(Enemy* base, cocos2d::Node* parent) {
		Enemy* ret = Enemy::create();
		ret->initWithTexture(base->getTexture());
		ret->sequence = base->sequence;
		ret->attack = base->attack;
		ret->setPosition(base->getPosition());
		ret->p = parent;
		return ret;
	}

	void run(cocos2d::Node* parent) {
		runAction(sequence->clone());
		parent->getParent()->addChild(this);
		attack.get(sequence).run(this);
	}

	void run(float) {
		cocos2d::log("enemy running");
		runAction(sequence->clone());
		setVisible(true);
		attack.get(sequence).run(this);
		//p->getParent()->addChild(this);
	}

	void explode() {
		this->setCurrentAnimation(BasicEnemy::EXPLOSION);
		auto removeSelf = cocos2d::RemoveSelf::create();
		auto wait = cocos2d::DelayTime::create(0.90f);
		auto move = cocos2d::MoveTo::create(0, cocos2d::Vec2(this->getPosition().x, -500));
		this->runAction(cocos2d::Sequence::create(wait, move, removeSelf, NULL));
		exploded = true;
	}

	CREATE_FUNC(Enemy)
};

