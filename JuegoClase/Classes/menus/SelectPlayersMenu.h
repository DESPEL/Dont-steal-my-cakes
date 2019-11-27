#pragma once

#include "MainMenu.h"

class SelectPlayersMenu : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void initButtons();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(SelectPlayersMenu);
};

