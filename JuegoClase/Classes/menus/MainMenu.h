#pragma once

#include "MotherMenu.h"
#include <vector>

class MainMenu : public MotherMenu {
protected:
	void initFunctions(std::vector<std::function <void (cocos2d::Ref *)>> functions);

public:
	virtual bool init();
	static cocos2d::Scene* createScene();

	CREATE_FUNC(MainMenu);

	void selectMenuButton();
	void optionsButton();
	void selectPlayer();
	void actionButton1();
	void actionButton2();
	void actionButton3();
	void actionButton4();
	void actionButton5();
	void actionButton6();
	void actionButton7();
	void actionButton8();
	void actionButton9();

};

