#pragma once

#include "cocos2d.h"

#include "MovementPattern.h"
#include "AttackPattern.h"
#include "Level.h"

#include "MovementPatterns/MovementPatterns.h"
#include "AttackPatterns/AttackPatterns.h"

USING_NS_CC;

class Levels {
public:
	static std::map<std::string, Level> levels;

	static Level create(std::string name) {
		if (levels.find(name) != levels.end())
			return levels.at(name);

		Size sz = cocos2d::Director::getInstance()->getVisibleSize();

		if (name == "test") {
			auto test = MovementPatterns::create("test");
			auto test2 = AttackPatterns::create("test");

			Enemy* testenemy = Enemy::create("enemigo1.png", test.get(-90), test2.get(test.get(-90)), cocos2d::Vec2(400, 300));

			cocos2d::log("test created");
			levels[name] = Level(
				std::make_tuple(1.0f, testenemy->get(testenemy->getPosition(), test.get(-45))),
				std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(300, 400))),
				std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(400, 400))),
				std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(300, 400))),
				std::make_tuple(1.0f, testenemy)
			);
			return levels.at(name);
		}

		if (name == "level-1") {
			auto up100 = MovementPatterns::create("up-100");
			// 0.5f

			Enemy* down1 = Enemy::create("nave2.png");

			levels[name] = Level(
			//	std::make_tuple(0.5f, )
			);

			return levels.at(name);
		}

		throw "level not found";
	}
};

std::map<std::string, Level> Levels::levels;