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
	static cocos2d::Scene* createScene(int Historia);
	static cocos2d::Scene* createScene();
	void uphist(int t);
	int hist;
	CREATE_FUNC(MenuIns);
	
};