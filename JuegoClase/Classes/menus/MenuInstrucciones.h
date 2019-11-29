
#pragma once

#include "MainMenu.h"
#include "ui/CocosGUI.h"

class MenuIns : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void actionButtonNext();
	void initButtons();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(MenuIns);
};