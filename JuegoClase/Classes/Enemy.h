#pragma once

#include "cocos2d.h"

#include "BasicEnemy.h"
#include "AttackPattern.h"

#include "GameWrapper.h"

#include "Bullet.h"

class AttackPattern;

class Enemy : public BasicEnemy
{
public:

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
		//createIdleAnimation();
		createExplosionAnimation();
		//this->retain();
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

	static Enemy* create(Enemy* base, cocos2d::Vec2 pos) {
		Enemy* ret = Enemy::create();
		ret->initWithTexture(base->getTexture());
		ret->sequence = base->sequence;
		ret->attack = base->attack;
		ret->setPosition(pos);
		return ret;
	}

	static Enemy* create(Enemy* base, cocos2d::Sequence* seq) {
		Enemy* ret = Enemy::create();
		ret->initWithTexture(base->getTexture());
		ret->sequence = seq;
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

	Enemy* get(cocos2d::Vec2 pos = cocos2d::Vec2(-100000, -100000), cocos2d::Sequence* seq = nullptr, std::string img = "") {
		Enemy* ret = Enemy::create();
		if (pos == cocos2d::Vec2(-100000, -100000))
			pos = getPosition();
		if (seq == nullptr)
			seq = sequence;
		if (img == "")
			ret->initWithTexture(getTexture());
		else
			ret->initWithFile(img);
		ret->setPosition(pos);
		ret->sequence = seq;
		ret->attack = attack;
		return ret;
	}

	void run(float) {
		//cocos2d::log("enemy running");
		runAction(sequence->clone());
		setVisible(true);
		attack.get().run(this);
		scheduleUpdate();
		//p->getParent()->addChild(this);
	}

	void explode() {
		//this->setCurrentAnimation(BasicEnemy::EXPLOSION);
		this->SetAnimation(BasicEnemy::EXPLOSION);
		auto removeSelf = cocos2d::RemoveSelf::create();
		auto wait = cocos2d::DelayTime::create(0.90f);
		auto move = cocos2d::MoveTo::create(0, cocos2d::Vec2(this->getPosition().x, -500));
		//setVisible(false);
		this->runAction(cocos2d::Sequence::create(wait, move, cocos2d::Hide::create(), NULL));
		exploded = true;
	}

	void update(float) {
		for (Bullet* bullet : GameWrapper::getInstance()->getPlayer()->Balas) {
			if (bullet->getBoundingBox().intersectsRect(getBoundingBox())) {
				bullet->colision();
				explode();
			}
		}
		if (GameWrapper::getInstance()->getPlayer()->getBoundingBox().intersectsRect(getBoundingBox())) {
			GameWrapper::getInstance()->getPlayer()->setCurrentAnimation(Player::EXPLOSION);
			explode();
			//this->runAction(cocos2d::RemoveSelf::create());
		}
	}

	CREATE_FUNC(Enemy)
};

class EnemyPlus
{
public:
	static Enemy* create(std::string name, cocos2d::Vector<cocos2d::Sequence*> seqs, std::vector<std::tuple<float, AttackPattern>> atts, cocos2d::Vec2 pos = { 0, 0 }) {
		
		cocos2d::Vector<cocos2d::FiniteTimeAction*> act;
		for (cocos2d::Sequence* seq : seqs)
			act.pushBack(seq);
		auto seq = cocos2d::Sequence::create(act);
		seq->retain();
		AttackPattern attack = AttackPattern();
		for (std::tuple<float, AttackPattern>& at : atts) {
			std::get<1>(at).times[0] += std::get<0>(at);
			for (int i = 0; i < std::get<1>(at).times.size(); i++) {
				attack.times.push_back(std::get<1>(at).times.at(i));
				attack.seqs.pushBack(std::get<1>(at).seqs.at(i));
				attack.bullets.pushBack(BasicBullet::create(std::get<1>(at).bullets.at(i)));
			}
		}
		Enemy* ret = Enemy::create(name,  seq, attack, pos);
		return ret;
	}

};