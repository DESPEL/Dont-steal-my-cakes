#pragma once

#include "cocos2d.h"

#include "Player.h"
#include "BasicEnemy.h"
#include "GameWrapper.h"

class BasicEnemy;
class Player;

class BasicBullet : public cocos2d::Sprite
{
public:
	BasicEnemy* parent;
	cocos2d::Sequence* seq;
	void run(float);

	void update(float delta) override;

	static BasicBullet* createWithFile(std::string);

	CREATE_FUNC(BasicBullet);
};

