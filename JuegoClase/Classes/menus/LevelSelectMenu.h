#pragma once

#include "MainMenu.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

class LevelSelectMenu : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void actionButton1();
	void initButtons();
	cocos2d::ui::Button* l1;
	cocos2d::ui::Button* l2;
	cocos2d::ui::Button* l3;

	void selecl1();
	void selecl2();
	void selecl3();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(LevelSelectMenu);
};

