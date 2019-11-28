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

		//if (name == "test") {
		//	/*auto test = MovementPatterns::create("linear");
		//	auto test2 = AttackPatterns::create("test");
		//	auto circular = AttackPatterns::create("circular");
		//	auto staticm = MovementPatterns::create("static");

		//	Enemy* testenemy = Enemy::create("enemigo1.png", test.get(-90), test2.get(), cocos2d::Vec2(400, 300));

		//	Enemy* enemyt = EnemyPlus::create(
		//		"enemigo1.png",
		//		{
		//			test.get(-180, 1, false),
		//			staticm.get(-180, 0.5)
		//		},
		//		{
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.0f, circular.get()},
		//			{ 0.5f, circular.get()},
		//			{ 0.5f, circular.get()}
		//		}
		//		);

		//	cocos2d::log("test created");
		//	levels[name] = Level(
		//		std::make_tuple(1.0f, enemyt->get({300, 300})),
		//		std::make_tuple(1.0f, testenemy->get(testenemy->getPosition(), test.get(-45))),
		//		std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(300, 400))),
		//		std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(400, 400))),
		//		std::make_tuple(1.0f, Enemy::create(testenemy, cocos2d::Vec2(300, 400))),
		//		std::make_tuple(1.0f, testenemy)
		//	);
		//	return levels.at(name);*/
		//}

		if (name == "level-1") {
			auto up100 = MovementPatterns::create("up-100");
			auto stmov = MovementPatterns::create("static");
			// 0.5f

			auto circular = AttackPatterns::create("circular");
			auto triple = AttackPatterns::create("triple");
			auto linear = AttackPatterns::create("linear");
			auto spray = AttackPatterns::create("test");


			Enemy* down1 = EnemyPlus::create(
				"enemigo4.png",
				{
					// angulo, velocidad, borrado al final
					up100.get(-180, 1, false),
					stmov.get(0, 1/5.0f, false),
					up100.get()
				}, {
					{ 1.7f, circular.get()},
					{ 2.7f, circular.get()}
				});

			Enemy *down2 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-180, 2, false),
					stmov.get(0, 1 / 5.0f, false),
					up100.get()
				}, {
					{ 0.5f, circular.get()}
			});

			Enemy* down3l = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-180, 2, false),
					up100.get()
				}, {
					{ 0.5f, linear.get()},
					{ 0.5f, linear.get()},
					{ 0.5f, linear.get()},
					{ 0.5f, linear.get()},
					{ 0.5f, linear.get()}
				}
			);

			Enemy* lat1 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2)
				}, {
					{ 0.0f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()}
				}
			);

			Enemy* lat2 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2)
				}, {
					{ 0.0f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()},
					{ 0.2f, linear.get()}
				}
			);

			Enemy* lat3 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2, false),
					up100.get(-90, 2)
				}, {
					{ 0.0f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()}
				}
			);

			Enemy* lat4 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2, false),
					up100.get(90, 2)
				}, {
					{ 0.0f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()},
					{ 0.3f, linear.get()}
				}
				);

			Enemy* spray1 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-180, 1, false),
					up100.get() 
				},
				{
					{ 0.0f, spray.get()}
				}
			);

			Enemy* triple1 = EnemyPlus::create(
				"enemigo4.png",
				{
					up100.get(-180, 1, false),
					up100.get()
				},
				{
					{ 1.0f, triple.get()},
					{ 0.5f, triple.get()}
				}
			);

			levels[name] = Level(
				std::make_tuple(0.5f, down1->get({ 100, sz.height })),
				std::make_tuple(0.0f, down1->get({ sz.width - 100, sz.height })),
				std::make_tuple(2.2f, down2->get({ sz.width / 2, sz.height + 50 })),
				std::make_tuple(0.5f, down2->get({ sz.width / 2, sz.height + 50 }, up100.get(135))),
				std::make_tuple(0.0f, down2->get({ sz.width / 2, sz.height + 50 }, up100.get(-135))),
				std::make_tuple(7.0f, down3l->get({ 100, sz.height })),
				std::make_tuple(0.0f, down3l->get({ sz.width - 100, sz.height })),
				std::make_tuple(0.1f, down3l->get({ 200, sz.height })),
				std::make_tuple(0.0f, down3l->get({ sz.width - 200, sz.height })),
				std::make_tuple(1.5f, down1->get({ 200, sz.height + 50 })),
				std::make_tuple(0, down1->get({ sz.width - 200, sz.height + 50 })),
				std::make_tuple(2.0f, lat1->get({0, sz.height - 50 })), 
				std::make_tuple(3.0f, lat2->get({ sz.width , sz.height - 50 })),
				std::make_tuple(0.0f, lat1->get({ 25 , sz.height - 50 })),
				std::make_tuple(2.0f, lat2->get({ sz.width - 25 , sz.height - 50 })),
				std::make_tuple(0.0f, lat1->get({ 25 , sz.height - 50 })), 
				std::make_tuple(1.0f, lat2->get({ sz.width - 25 , sz.height - 50 })),
				std::make_tuple(0.0f, lat1->get({ 25 , sz.height - 50 })), // 19.8
				std::make_tuple(2.0f, down1->get({ 100, sz.height + 50 })),// 21.8
				std::make_tuple(0, down1->get({ sz.width - 100, sz.height + 50 })),
				std::make_tuple(0, down1->get({ sz.width  / 2, sz.height + 50 })),
				std::make_tuple(1.0f, down3l->get({ 100, sz.height })), // 22.8
				std::make_tuple(0.0f, down3l->get({ sz.width - 100, sz.height })),
				std::make_tuple(0.1f, down3l->get({ 200, sz.height })),
				std::make_tuple(0.0f, down3l->get({ sz.width - 200, sz.height })),
				std::make_tuple(4.0f, lat3->get({ 0, sz.height - 50 })), // 26.8
				std::make_tuple(1.8f, lat4->get({ sz.width, sz.height - 50 })), // 28.8
				std::make_tuple(2.4f, lat3->get({ 0, sz.height - 50 })), // 30.8
				std::make_tuple(2.8f, spray1->get({ sz.width / 2, sz.height + 25 })), // 33.5
				std::make_tuple(3.5f, triple1->get({ 100, sz.height })), // 37
				std::make_tuple(0.0f, triple1->get({ sz.width - 100, sz.height }))
			);

			return levels.at(name);
		}

		if (name == "boss") {
			auto circular = AttackPatterns::create("circular");
			auto stmov = MovementPatterns::create("static");

			Enemy* boss = EnemyPlus::createBoss(
				"boss1.png",
				{
					stmov.get(0,1,false)
				},
				{
					{3.0f, circular.get()}
				}
			);

			levels[name] = Level(
				std::make_tuple(0.5f, boss->get({ sz.width / 2, sz.height - 100 }))
			);

			return levels[name];
		}

		throw "level not found";
	}
};

std::map<std::string, Level> Levels::levels;