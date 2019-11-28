#pragma once

#include <string>

#include "cocos2d.h"

#include "Player.h"
#include "BasicEnemy.h"
#include "GameWrapper.h"

class BasicEnemy;
class Player;
class GameWrapper;

class BasicBullet : public cocos2d::Sprite
{
public:
	BasicEnemy* parent;
	cocos2d::Sequence* seq;

	bool init() noexcept;

	void run(float);

	void update(float delta) override;

	static BasicBullet* create(std::string filename);

	static BasicBullet* create(BasicBullet* bull);

	~BasicBullet();

	CREATE_FUNC(BasicBullet);
};

