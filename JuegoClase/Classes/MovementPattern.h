#pragma once

#include "cocos2d.h"

class MovementPattern {
public:
	std::vector<std::tuple<float, cocos2d::Vec2>> data;
	cocos2d::Vector<cocos2d::FiniteTimeAction*> moves;
	cocos2d::Map<std::string, cocos2d::Sequence*> memory;

	template <typename... Ts>
	MovementPattern(Ts... args) {
		data = { args... };
	}

	cocos2d::Sequence* get(float angle = 0, float speed = 1, float rem = true) {
		std::string key = std::to_string(angle) + ":" + std::to_string(speed);
		if (memory.find(key) != memory.end()) {
			return memory.at(key);
		}

		moves.clear();

		for (const std::tuple<float, cocos2d::Vec2>& m : data) {
			cocos2d::Vec2 deltaxy = std::get<1>(m);
			const float s = std::get<0>(m) / speed;
			deltaxy.rotate(cocos2d::Vec2(0, 0), angle * M_PI / 180);
			moves.pushBack(cocos2d::MoveBy::create(s, deltaxy));
		}
		if (rem) 
			moves.pushBack(cocos2d::RemoveSelf::create());
		memory.insert(key, cocos2d::Sequence::create(moves));
		memory.at(key)->retain();
		return memory.at(key);
	}
};
