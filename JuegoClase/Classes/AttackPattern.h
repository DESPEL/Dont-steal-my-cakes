#pragma once

#include "cocos2d.h"
#include "BasicBullet.h"

#include "MovementPattern.h"
#include "Bullet.h"
#include "BasicEnemy.h"

class BasicBullet;
class BasicEnemy;

template <size_t sz>
class AttackPattern
{
	std::array<std::tuple<float, BasicBullet*, cocos2d::Sequence*>, sz> arr;

	template <size_t i = 0, typename T, typename... Tp>
	void tupleApply(std::function<T>& modifier, std::tuple<Tp &...>& tup) {
		auto& val = std::get<i>(tup);
		modifier(val);
		if constexpr (i + 1 != sizeof...(Tp))
			tupleApply<i + 1>(modifier, tup);
	}

public:
	template <typename ...Ts>
	AttackPattern(Ts... args) noexcept {
		arr = { args... };
	}

	void run(BasicEnemy* parent) {
		float acc = 0;
		for (std::tuple<float, BasicBullet*, cocos2d::Sequence*>& v : arr) {
			acc += std::get<0>(v);
			BasicBullet* bullet = std::get<1>(v);
			bullet->seq = std::get<2>(v)->clone();
			bullet->seq->retain();
			bullet->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
			bullet->setPosition(parent->getPosition());
			bullet->initWithFile("redbullet.png");
			bullet->setScale(2.0f,1.0f);
			bullet->parent = parent;
			bullet->setVisible(false);
			parent->getParent()->addChild(bullet, -1);
			bullet->scheduleOnce(schedule_selector(BasicBullet::run), acc);
		}
	}
};

class AttackPatternPlus {

};

