#pragma once

#include "cocos2d.h"

#include "MovementPattern.h"
#include "AttackPattern.h"
#include "Level.h"

#include "MovementPatterns/MovementPatterns.h"
#include "AttackPatterns/AttackPatterns.h"

#define mktp std::make_tuple

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

		// Cancion: Mantis
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
					stmov.get(0, 1 / 5.0f, false),
					up100.get()
				}, {
					{ 1.7f, circular.get()},
					{ 2.7f, circular.get()}
				});

			Enemy* down2 = EnemyPlus::create(
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

			Enemy* boss = EnemyPlus::createBoss(
				"boss1.png",
				{ 
					up100.get(-180, 1, false),
					stmov.get(0,1,false)
				},
				{
					{3.0f, triple.get()},
					{3.0f, linear.get()}
				}
				);

			levels[name] = Level(
				mktp(0.5f, down1->get({ 100, sz.height })),
				mktp(0.0f, down1->get({ sz.width - 100, sz.height })),
				mktp(2.2f, down2->get({ sz.width / 2, sz.height + 50 })),
				mktp(0.5f, down2->get({ sz.width / 2, sz.height + 50 }, up100.get(135))),
				mktp(0.0f, down2->get({ sz.width / 2, sz.height + 50 }, up100.get(-135))),
				mktp(7.0f, down3l->get({ 100, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 100, sz.height })),
				mktp(0.1f, down3l->get({ 200, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 200, sz.height })),
				mktp(1.5f, down1->get({ 200, sz.height + 50 })),
				mktp(0, down1->get({ sz.width - 200, sz.height + 50 })),
				mktp(2.0f, lat1->get({ 0, sz.height - 50 })),
				mktp(3.0f, lat2->get({ sz.width , sz.height - 50 })),
				mktp(0.0f, lat1->get({ 25 , sz.height - 50 })),
				mktp(2.0f, lat2->get({ sz.width - 25 , sz.height - 50 })),
				mktp(0.0f, lat1->get({ 25 , sz.height - 50 })),
				mktp(1.0f, lat2->get({ sz.width - 25 , sz.height - 50 })),
				mktp(0.0f, lat1->get({ 25 , sz.height - 50 })), // 19.8
				mktp(2.0f, down1->get({ 100, sz.height + 50 })),// 21.8
				mktp(0, down1->get({ sz.width - 100, sz.height + 50 })),
				mktp(0, down1->get({ sz.width / 2, sz.height + 50 })),
				mktp(1.0f, down3l->get({ 100, sz.height })), // 22.8
				mktp(0.0f, down3l->get({ sz.width - 100, sz.height })),
				mktp(0.1f, down3l->get({ 200, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 200, sz.height })),
				mktp(4.0f, lat3->get({ 0, sz.height - 50 })), // 26.8
				mktp(1.8f, lat4->get({ sz.width, sz.height - 50 })), // 28.8
				mktp(2.4f, lat3->get({ 0, sz.height - 50 })), // 30.8
				mktp(2.8f, spray1->get({ sz.width / 2, sz.height + 25 })), // 33.5
				mktp(1.0f, spray1->get({ sz.width / 2 + 100, sz.height + 25 })),
				mktp(0.0f, spray1->get({ sz.width / 2 - 100, sz.height + 25 })),
				mktp(2.5f, triple1->get({ 100, sz.height })), // 37
				mktp(0.0f, triple1->get({ sz.width - 100, sz.height })),
				mktp(2.0f, down3l->get({ 100, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 100, sz.height })),
				mktp(0.1f, down3l->get({ 200, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 200, sz.height })), // 39
				mktp(1.0f, lat1->get({ 0, sz.height - 50 })),
				mktp(0.0f, lat2->get({ sz.width , sz.height - 50 })), // 40
				mktp(4.5f, lat4->get({ sz.width, sz.height - 50 })), // 44.5
				mktp(3.0f, lat3->get({ 0, sz.height - 50 })), // 47.5
				mktp(1.0f, down3l->get({ 100, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 100, sz.height })),
				mktp(0.0f, down3l->get({ 200, sz.height })),
				mktp(0.0f, down3l->get({ sz.width - 200, sz.height })), // 48.5
				mktp(2.5f, down1->get({ 100, sz.height })),
				mktp(0.0f, down1->get({ sz.width - 100, sz.height })), // 51
				mktp(3.5f, down3l->get({ 100, sz.height + 50 })), // 54.5
				mktp(0.0f, down3l->get({ sz.width - 100, sz.height + 50 })),
				mktp(1.0f, down3l->get({ 200, sz.height + 50 })), // 55.5
				mktp(0.0f, down3l->get({ sz.width - 200, sz.height + 50 })),
				mktp(2.5f, lat4->get({ sz.width, sz.height - 50 })), // 56.5
				mktp(3.0f, lat3->get({ 0, sz.height - 50 })), // 59.5
				mktp(3.0f, lat4->get({ sz.width, sz.height - 50 })), // 60.5
				mktp(2.5f, lat3->get({ 0, sz.height - 50 })), // 62
				mktp(2.0f, spray1->get({ sz.width / 2, sz.height + 25 })), // 64
				mktp(3.0f, spray1->get({ sz.width / 2 + 100, sz.height + 25 })), // 68
				mktp(0.0f, spray1->get({ sz.width / 2 - 100, sz.height + 25 })),
				mktp(0.5f, boss->get({ sz.width / 2, sz.height}))
			);
			levels.at(name).setSong("Mantis.mp3");

			return levels.at(name);
		}


		// Cancion : Tower of heaven
		if (name == "level-2") {
			auto up100 = MovementPatterns::create("up-100");
			auto stmov = MovementPatterns::create("static");
			// 0.5f

			auto circular = AttackPatterns::create("circular");
			auto triple = AttackPatterns::create("triple");
			auto linear = AttackPatterns::create("linear");
			auto spray = AttackPatterns::create("test");

			Enemy* slowdcir = EnemyPlus::create(
				"enemigo2.png",
				{
					up100.get(180, 1 / 2.0f, false),
					up100.get(0, 1 / 2.0f)
				},
				{
					{2.0f, circular.get()},
					{0.1f, circular.get()}
				}
				);

			Enemy* downslow = EnemyPlus::create(
				"enemigo2.png",
				{
					up100.get(180, 1 / 2.0f, false),
					stmov.get(0, 2.0f, false),
					up100.get(0, 1 / 1.5f)
				},
				{ // 0.5, 0.5, 0.5, 0.5, 0.5
					{0.5f, linear.get()},
					{0.5f, linear.get()},
					{0.5f, linear.get()},
					{0.5f, linear.get()},
					{0.5f, linear.get()}
				}
				);

			Enemy* downfast = EnemyPlus::create(
				"enemigo2.png",
				{
					up100.get(180, 1 / 2.0f, false),
					up100.get(0, 1 / 2.0f)
				},
				{ // 0.5, 0.5, 0.5, 0.5, 0.5
					{0.3f, linear.get()},
					{0.3f, linear.get()},
					{0.3f, linear.get()},
					{0.3f, linear.get()},
					{0.3f, linear.get()},
					{0.3f, linear.get()}
				}
				);

			Enemy* downfastcirc = EnemyPlus::create(
				"enemigo2.png",
				{
					up100.get(180, 1 / 2.0f, false),
					up100.get(0, 1 / 2.0f)
				},
				{ // 0.5, 0.5, 0.5, 0.5, 0.5
					{0.5f, circular.get()},
					{0.5f, circular.get()},
					{0.5f, circular.get()},
					{0.5f, circular.get()},
					{0.5f, circular.get()},
					{0.5f, circular.get()}
				}
				);

			Enemy* downfasttrip = EnemyPlus::create(
				"enemigo2.png",
				{
					up100.get(180, 1 / 2.0f, false),
					up100.get(0, 1 / 2.0f)
				},
				{ // 0.5, 0.5, 0.5, 0.5, 0.5
					{0.4f, triple.get()},
					{0.4f, triple.get()},
					{0.4f, triple.get()},
					{0.4f, triple.get()},
					{0.4f, triple.get()},
					{0.4f, triple.get()}
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

			Enemy* boss = EnemyPlus::createBoss(
				"boss1.png",
				{
					up100.get(-180, 1, false),
					stmov.get(0,1,false)
				},
				{
					{3.0f, circular.get()}
				}
				);

			levels[name] = Level( // Delta: 1s
				mktp(9.2f, slowdcir->get({ sz.width / 2, sz.height })), // s: 8.2, e: 10.2
				mktp(2.0f, downslow->get({ sz.width / 2 - 100, sz.height })), // s: 10.2 e: 12.7
				mktp(0.0f, downslow->get({ 100 / 2, sz.height })),
				mktp(0.0f, downslow->get({ sz.width - 100 / 2, sz.height })),
				mktp(0.0f, downslow->get({ sz.width / 2 + 100, sz.height })),
				mktp(2.5f, downfast->get({ 1 * sz.width / 4, sz.height })),// s: 12.7 e: 14.8
				mktp(0.0f, downfast->get({ 2 * sz.width / 4, sz.height })),
				mktp(0.0f, downfast->get({ 3 * sz.width / 4, sz.height })),
				mktp(2.1f, downfastcirc->get({ 1 * sz.width / 6, sz.height + 25 })), // s: 14.8 e: 17.8
				//mktp(0.0f, downfastcirc->get({ 3 * sz.width / 6, sz.height + 25 })),
				mktp(0.0f, downfastcirc->get({ 5 * sz.width / 6, sz.height + 25 })),
				mktp(3.0f, downslow->get({ 1 * sz.width / 4, sz.height })),// s: 17.8 e: 20.3
				mktp(0.0f, downslow->get({ 2 * sz.width / 4, sz.height })),
				mktp(0.0f, downslow->get({ 3 * sz.width / 4, sz.height })),
				mktp(4.5f, downfasttrip->get({ 1 * sz.width / 6, sz.height + 25 })), // s: 22.3 e: 24.7
				mktp(0.0f, downfasttrip->get({ 3 * sz.width / 6, sz.height + 25 })),
				mktp(0.0f, downfasttrip->get({ 5 * sz.width / 6, sz.height + 25 })),
				mktp(2.0f, downfasttrip->get({ sz.width / 2, sz.height + 25 })), // s: 26.7
				mktp(2.0f, downfast->get({ 1 * sz.width / 4, sz.height + 25 })), // s: 28.7
				mktp(2.0f, downfast->get({ 3 * sz.width / 4, sz.height + 25 })), // s: 30.7 e: 32.5
				mktp(3.0f, spray1->get({ 1 * sz.width / 6, sz.height })), // s: 33.7 f: 40.0
				mktp(0.0f, spray1->get({ 5 * sz.width / 6, sz.height })),
				mktp(3.0f, downfast->get({ 1 * sz.width / 6, sz.height + 25 })),
				mktp(0.0f, downfast->get({ 3 * sz.width / 6, sz.height + 25 })),
				mktp(0.0f, downfast->get({ 5 * sz.width / 6, sz.height + 25 })),
				mktp(3.3f, downfast->get({ 1 * sz.width / 4, sz.height })), // s: 40.0 e: 42.1
				mktp(0.0f, downfast->get({ 2 * sz.width / 4, sz.height })),
				mktp(0.0f, downfast->get({ 3 * sz.width / 4, sz.height })),
				mktp(4.6f, downfastcirc->get({ 3 * sz.width / 6, sz.height + 25 })), // s: 44.6 e: 46.8
				mktp(0.0f, downfast->get({ 1 * sz.width / 6, sz.height + 25 })),
				mktp(0.0f, downfast->get({ 5 * sz.width / 6, sz.height + 25 })),
				mktp(2.6f, downfastcirc->get({ 3 * sz.width / 6, sz.height })), // s: 47.2 e: 49.2
				mktp(3.0f, spray1->get({ 1 * sz.width / 6, sz.height })), // s: 51 e: 53
				mktp(0.0f, spray1->get({ 5 * sz.width / 6, sz.height })),
				mktp(2.0f, downfast->get({ 1 * sz.width / 4, sz.height })),
				mktp(0.1f, downfast->get({ 2 * sz.width / 4, sz.height })),
				mktp(0.2f, downfast->get({ 3 * sz.width / 4, sz.height })),
				mktp(0.1f, downfast->get({ 3 * sz.width / 8, sz.height })),
				mktp(0.3f, downfast->get({ 5 * sz.width / 8, sz.height })),
				mktp(0.0f, downfast->get({ 4 * sz.width / 8, sz.height })),
				mktp(0.1f, downfast->get({ 7 * sz.width / 8, sz.height })),
				mktp(0.3f, downfast->get({ 1 * sz.width / 8, sz.height })),
				mktp(0.1f, downfast->get({ 3 * sz.width / 8, sz.height })), // s: 52 e: final
				mktp(0.5f, boss->get({ sz.width / 2, sz.height }))
			);
			levels.at(name).setSong("TowerOfHeaven.mp3");
			return levels[name];
		}

		throw "level not found";
	}
};

std::map<std::string, Level> Levels::levels;