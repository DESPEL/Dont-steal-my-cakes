#pragma once

#include "cocos2d.h"

#include "MovementPattern.h"
#include "AttackPattern.h"
#include "Level.h"

#include "MovementPatterns/MovementPatterns.h"
#include "AttackPatterns/AttackPatterns.h"

class Levels {
public:
	static std::map<std::string, Level> levels;

	static Level create(std::string name) {
		if (levels.find(name) != levels.end())
			return levels.at(name);

		if (name == "test") {
			auto test = MovementPatterns::create("test");
			auto test2 = AttackPatterns::create("test");

			Enemy* testenemy = Enemy::create("enemigo1.png", test.get(-90), test2.get(test.get(-90)), cocos2d::Vec2(400, 300));

			cocos2d::log("test created");
			levels[name] = Level(
				std::make_tuple(1.0f, testenemy),
				std::make_tuple(1.0f, testenemy),
				std::make_tuple(1.0f, testenemy),
				std::make_tuple(1.0f, testenemy),
				std::make_tuple(1.0f, testenemy)
			);
			return levels.at(name);
		}

		throw "level not found";
	}
};

std::map<std::string, Level> Levels::levels;