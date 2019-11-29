#include "TopScene.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"

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

	//std::vector<std::function<void>*> functions;
	//cocos2d::Vector buttons;

	//initFunctions(functions);
	//insertamos los botones a la escena
	initButtons();

	//habilitamos todos los niveles que el jugador puede realizar actualmente
	/*for (int i = 0; i < GameManager::NUM_LEVELS; i++) {
		if (i > GameManager::getInstance()->getNextLevel()) break;
		//habilitamos el boton
		buttons.at(i)->setEnabled(true);
		//cambiamos la imagen a habilitado
		buttons.at(i)->setBright(true);
	}*/

	//boton de ir hacia atras
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


	
}

void TopMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}