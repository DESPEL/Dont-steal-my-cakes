#pragma once

#include "cocos2d.h"

#include "Player.h"
#include "GameWrapper.h"

class Player;

class BasicBullet : public cocos2d::Sprite
{
public:
	cocos2d::Sequence* seq;
	void run(float);

	void update(float delta) override;

	CREATE_FUNC(BasicBullet);
};

