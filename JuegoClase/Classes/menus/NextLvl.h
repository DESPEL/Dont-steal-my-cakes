#pragma once

#include "MotherMenu.h"
#include "GameWrapper.h"
#include "Macros.h"
#include <vector>

class NextMenu : public MotherMenu {
private:
	void selectMenuButton();
	void optionsButton();
	void actionButton1();
	void actionButton2();
	void actionButton3();
	void actionButton4();
	void actionButton5();
	void actionButton6();
	void actionButton7();
	void actionButton8();
	void actionButton9();

protected:
	void initFunctions(std::vector<std::function <void(cocos2d::Ref*)>> functions);

public:
	virtual bool init();
	static cocos2d::Scene* createScene();

	CREATE_FUNC(NextMenu);

};
