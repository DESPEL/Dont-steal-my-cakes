#pragma once

#include "menus/MainMenu.h"

class TopMenu : public MainMenu {
private:
	std::ostringstream _ostr;
	void actionButtonBack();
	void initButtons();
	cocos2d::Label* Scores;

public:
	
	std::vector<std::string> Jugadores;
	std::vector<int> puntos;
	virtual bool init();
	void MostarPuntaje();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TopMenu);
};

