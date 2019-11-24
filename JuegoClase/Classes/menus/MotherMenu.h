#pragma once

#include "cocos2d.h"
#include "BackGroundMenu.h"

class MotherMenu : public cocos2d::Layer {
protected:
	BackGroundMenu* _bg;
	cocos2d::Size _visibleSize;

public:
	MotherMenu();
	virtual ~MotherMenu();

	virtual void update(float);
	virtual bool init();

	static cocos2d::Scene* createScene();

	CREATE_FUNC(MotherMenu);
};