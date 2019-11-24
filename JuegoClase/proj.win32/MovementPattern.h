#pragma once

#include "cocos2d.h"

namespace MovementPattern {
	template <size_t i = 0, typename T, typename... Tp>
	void tupleApply(std::function<T>& modifier, std::tuple<Tp &...>& tup) {
		auto& val = std::get<i>(tup);
		modifier(val);
		if constexpr (i + 1 != sizeof...(Tp))
			tupleApply<i + 1>(modifier, tup);
	}

	cocos2d::MoveBy* tupToMoveBy(const std::tuple<float, cocos2d::Vec2>& val) {
		return cocos2d::MoveBy::create(std::get<0>(val), std::get<1>(val));
	}

	template <typename... Ts>
	cocos2d::Sequence* create(float angle, std::tuple<float, cocos2d::Vec2> arg1, Ts... args) {
		std::tuple<std::tuple<float, cocos2d::Vec2>&, Ts &...> tup = { arg1, args... };
		std::function<void(std::tuple<float, cocos2d::Vec2>&)> angleModifier = [&angle](std::tuple<float, cocos2d::Vec2>& val) {
			std::get<1>(val) = std::get<1>(val).rotateByAngle(cocos2d::Vec2(0, 0), angle);
		};
		tupleApply(angleModifier, tup);
		return cocos2d::Sequence::create(tupToMoveBy(arg1), tupToMoveBy(args)..., NULL);
	}
}