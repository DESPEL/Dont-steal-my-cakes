#pragma once

#include "MovementPattern.h"

class MovementPatterns {
	static std::map<std::string, MovementPattern> patterns;
public:
	static MovementPattern create(std::string name) {
		if (patterns.find(name) != patterns.end())
			return patterns[name];

		if (name == "test") {
			patterns[name] = MovementPattern(
				std::make_tuple(1.0f, cocos2d::Vec2(100, 0)),
				std::make_tuple(10.0f, cocos2d::Vec2(0, 0))
			);
			return patterns[name];
		}

		if (name == "test1") {
			patterns[name] = MovementPattern(
				std::make_tuple(1.0f, cocos2d::Vec2(0, -100)),
				std::make_tuple(1.0f, cocos2d::Vec2(30, -100))
			);
			return patterns[name];
		}

		if (name == "up-100") {
			patterns[name] = MovementPattern(
				std::make_tuple(1.0f, cocos2d::Vec2{0, 100})
			);
			return patterns[name];
		}

		if (name == "static") {
			patterns[name] = MovementPattern(
				std::make_tuple(1.0f, cocos2d::Vec2(0, 0))
			);
			return patterns[name];
		}

		if (name == "linear") {
			patterns[name] = MovementPattern(
				std::make_tuple(5.0f, cocos2d::Vec2(0, 500))
			);
			return patterns[name];
		}

		if (patterns.find(name) != patterns.end())
			return patterns[name];

		throw "pattern not found";
	}
};
std::map<std::string, MovementPattern> MovementPatterns::patterns;