#pragma once

#include "menus/MainMenu.h"

class TopMenu : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void initButtons();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TopMenu);
};

