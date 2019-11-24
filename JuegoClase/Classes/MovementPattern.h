#pragma once

#include <array>
#include <functional>
#include <cstdarg>

#include "cocos2d.h"

namespace detail
{
	template<int... Is>
	struct seq { };

	template<int N, int... Is>
	struct gen_seq : gen_seq<N - 1, N - 1, Is...> { };

	template<int... Is>
	struct gen_seq<0, Is...> : seq<Is...> { };
}

template <size_t sz>
class MovementPattern {
	std::array<std::tuple<float, cocos2d::Vec2>, sz> arr;
	std::array <std::tuple< float , cocos2d::Vec2 > , sz > buffer;
	std::map<std::string, cocos2d::Sequence*> memory;
	
	cocos2d::MoveBy* tupToMoveBy(const std::tuple<float, cocos2d::Vec2>& val) {
		return cocos2d::MoveBy::create(std::get<0>(val), std::get<1>(val));
	}

	template <int... Is>
	cocos2d::Sequence* getInside(detail::seq<Is...>) {
		return cocos2d::Sequence::create(tupToMoveBy(buffer.at(Is))..., cocos2d::RemoveSelf::create(), NULL);
	}

public:
	template<typename... Ts>
	MovementPattern(Ts... args) noexcept {
		arr = { args... };
	}

	cocos2d::Sequence* get(float angle, float speed = 1.0f) {
		std::string key = std::to_string(angle) + ":" + std::to_string(speed);
		if (memory.find(key) != end(memory))
			return memory[key]->clone();
		buffer = arr;
		for (std::tuple<float, cocos2d::Vec2> &mov : buffer) {
			std::get<1>(mov).rotate(cocos2d::Vec2(0, 0), angle * (M_PI / 180));
			std::get<0>(mov) = std::get<0>(mov) / speed;
		}
		memory[key] = getInside(detail::gen_seq<sz>());
		memory[key]->retain();
		return memory[key]->clone();
	}

	~MovementPattern() {
		for (std::pair<const std::string, cocos2d::Sequence*>& v : memory) {
			v.second->release();
		}
	}
};