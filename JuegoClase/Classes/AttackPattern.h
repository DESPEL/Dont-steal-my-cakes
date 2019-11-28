#pragma once

#include <array>

#include "cocos2d.h"

#include "BasicBullet.h"
#include "BasicEnemy.h"

class BasicBullet;
class BasicEnemy;

class AttackPattern
{
public:
	cocos2d::Vector<cocos2d::Sequence*> seqs;
	cocos2d::Vector<BasicBullet*> bullets;
	std::vector<float> times;

	template <typename ...Ts>
	AttackPattern(Ts... args) {
		std::array<std::tuple<float, BasicBullet*, cocos2d::Sequence*>, sizeof...(Ts)> temp = { args... };
		for (std::tuple<float, BasicBullet*, cocos2d::Sequence*>& v : temp) {
			times.push_back(std::get<0>(v));
			bullets.pushBack(std::get<1>(v));
			seqs.pushBack(std::get<2>(v));
		}
	}

	AttackPattern(cocos2d::Vector <cocos2d::Sequence*> ss, cocos2d::Vector<BasicBullet*> buls, std::vector<float> ts) {
		seqs = ss;
		for (BasicBullet* bul : buls) {
			bullets.pushBack(BasicBullet::create(bul));
		}
		for (BasicBullet* bul : bullets) {
			//bul->runAction(pseq->clone());
		}
		times = ts;
	}

	AttackPattern get() {
		return AttackPattern(seqs, bullets, times);
	}

	void run(BasicEnemy* parent) {

		//cocos2d::log("putting bullets init");
		float acc = 0;
		for (int i = 0; i < seqs.size(); i++) {
			//cocos2d::log("putting bullets");
			BasicBullet* bullet = bullets.at(i);
			acc += times.at(i);

			bullet->seq = seqs.at(i);
			bullet->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
			bullet->setScale(2.0f, 1.0f);
			bullet->parent = parent;
			bullet->setVisible(false);
			parent->getParent()->addChild(bullet);
			bullet->scheduleOnce(schedule_selector(BasicBullet::run), acc);
		}
	}
};

