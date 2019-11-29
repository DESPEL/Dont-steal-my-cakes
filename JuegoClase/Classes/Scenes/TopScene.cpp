#include "TopScene.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

USING_NS_CC;
using namespace ui;

Scene* TopMenu::createScene() {
	auto scene = Scene::create();
	auto layer = TopMenu::create();
	scene->addChild(layer);
	return scene;
}


bool TopMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}


	initButtons();

	
	auto backBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->setScale(2);
	backBt->addClickEventListener(CC_CALLBACK_0(TopMenu::actionButtonBack, this));
	backBt->setPosition(Point(30 * getScaleX(), 30 * getScaleY()));
	addChild(backBt);

	return true;
}

void TopMenu::initButtons() {

	auto High = Label::createWithTTF("TOP", "fonts/SPACEBAR.ttf", 36);
	
	High->setPosition(_visibleSize.width/2, 290);
	addChild(High, 5);

	Scores = Label::createWithTTF("LA\nLA\nLA\nLA\nLA", "fonts/arial.ttf", 30);
	MostarPuntaje();
	Scores->setPosition(_visibleSize.width / 2, _visibleSize.height / 2);
	addChild(Scores);
	
}

void TopMenu::actionButtonBack() {
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}
using namespace std;
void TopMenu::MostarPuntaje() {

	string LOL;
	string txt="";
	int num;

	ifstream estado("puntajes.txt");
	
	while (!estado.eof()) {
		getline(estado, LOL);
		Jugadores.push_back(LOL);
		std::istringstream iss(LOL);
		iss >> num;
		puntos.push_back(num);
	}
	sort(puntos.begin(), puntos.end(), std::greater<int>());
	estado.close();
	for (int i = 0; i < Jugadores.size(); i++) {
		if (i >= 5) {
			break;
		}
		txt += to_string(i+1)+") " + to_string(puntos[i]) + "\n";
		
	}
	Scores->setString(txt);
	
	
	Jugadores.clear();
}