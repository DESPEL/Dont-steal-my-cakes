#pragma once

#include "MainMenu.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"


class SelectPlayersMenu : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void actionButton1();
	void initButtons();

	cocos2d::ui::Button* P1;
	cocos2d::ui::Button* P2;
	cocos2d::ui::Button* nave1;
	cocos2d::ui::Button* nave2;
	cocos2d::ui::Button* nave3;
	cocos2d::ui::Button* nave4;

	// Nave Segundo Jugador
	
	cocos2d::ui::Button* P2nave1;
	cocos2d::ui::Button* P2nave2;
	cocos2d::ui::Button* P2nave3;
	cocos2d::ui::Button* P2nave4;

	void selecP1();
	void selecP2();
	void selecN1();
	void selecN2();
	void selecN3();
	void selecN4();

	void P2selecN1();
	void P2selecN2();
	void P2selecN3();
	void P2selecN4();


public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(SelectPlayersMenu);
};

