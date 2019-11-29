#pragma once

#include "cocos2d.h"

#include "Enemy.h"

class Level
{
	cocos2d::Vector<Enemy*> enemies;
	std::vector<float> times;
	cocos2d::Node* base;
public:
	float elapsed = 0;
	std::string song = "NoMoney.mp3";

	template<typename... Ts>
	Level(Ts... args) { // tuple <float, enemy>
		std::array<std::tuple<float, Enemy*>, sizeof...(Ts)> arr = { args... };
		for (std::tuple<float, Enemy*>& el : arr) {
			times.push_back(std::get<0>(el));
			enemies.pushBack(std::get<1>(el));
		}
	}

	Level(cocos2d::Node* b, cocos2d::Vector<Enemy*> enems, std::vector<float> ts, std::string sng) {
		for (Enemy* enemy : enems) {
			enemies.pushBack(Enemy::create(enemy));
		}
		times = ts;
		base = b;
		song = sng;
	}

	void setSong(std::string sng) {
		song = sng;
	}

	Level get(cocos2d::Node* base) {
		return Level(base, enemies, times, song);
	}

	void run() {
		if (base == nullptr)
			return;
		float time = 0;
		for (int i = 0; i < enemies.size(); i++) {
			time += times.at(i);
			enemies.at(i)->p = base;
			base->addChild(enemies.at(i));
			enemies.at(i)->setVisible(false);
			enemies.at(i)->scheduleOnce(schedule_selector(Enemy::run), time);
			//cocos2d::log("enemy added to the scene");
		}
	}

	void update(float delta) {
		elapsed += delta;
	}

	~Level() {
		cocos2d::log("level deleted");
	}

};

