#pragma once

#include "cocos2d.h"

class BackGroundMenu : public cocos2d::Node {
private:
	CC_SYNTHESIZE(float, _speed, Speed);
	cocos2d::Size _screen;
	cocos2d::Sprite* _bgPart1;
	cocos2d::Sprite* _bgPart2;
	cocos2d::Sprite* _bgPart3;
	BackGroundMenu();

public:
	void update(float);
	~BackGroundMenu();
	CREATE_FUNC(BackGroundMenu);

};

