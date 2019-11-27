#pragma once

#include "AttackPattern.h"
#include "MovementPattern.h"

#include "BasicBullet.h"

#include "MovementPatterns/MovementPatterns.h"

class AttackPatterns {
	static std::map<std::string, AttackPattern> patterns;
public:
	static AttackPattern create(std::string name) {
		if (patterns.find(name) != patterns.end())
			return patterns[name];

		if (name == "test") {
			auto test1 = MovementPatterns::create("test1");

			patterns[name] = AttackPattern(
				std::make_tuple(0.0f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
				std::make_tuple(0.0f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(0.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(10.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(-20.0f)),
				std::make_tuple(0.2f, BasicBullet::create("redbullet.png"), test1.get(20.0f))
			);

			return patterns[name];
		}

		throw "pattern not found";
	}
};
std::map<std::string, AttackPattern> AttackPatterns::patterns;