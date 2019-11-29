#include "menus/LogorsMenu.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"
#include "DataEngine.h"

USING_NS_CC;
using namespace ui;

Scene* LogMenu::createScene() {
	auto scene = Scene::create();
	auto layer = LogMenu::create();
	scene->addChild(layer);
	return scene;
}


bool LogMenu::init() {
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
	backBt->addClickEventListener(CC_CALLBACK_0(LogMenu::actionButtonBack, this));
	backBt->setPosition(Point(30 * getScaleX(), 30 * getScaleY()));
	addChild(backBt);

	return true;
}

void LogMenu::initButtons() {

	auto High = Label::createWithTTF("Logros", "fonts/SPACEBAR.ttf", 36);

	auto stats = DataEngine::getInstance();

	int muertes =  stoi(stats->at("deaths"));
	int disparos = stoi(stats->at("shoots"));
	int puntosTotales = stoi(stats->at("puntos"));

	cocos2d::Vector<cocos2d::Label*> logros;

	logros.pushBack(Label::createWithTTF("Muere 10 veces", "fonts/arial.ttf", 18));
	logros.pushBack(Label::createWithTTF("Muere 100 veces", "fonts/arial.ttf", 18));
	logros.pushBack(Label::createWithTTF("Dispara 1,000 veces", "fonts/arial.ttf", 18));
	logros.pushBack(Label::createWithTTF("Dispara 10,000 veces", "fonts/arial.ttf", 18));
	logros.pushBack(Label::createWithTTF("Consigue un total de 5000 puntos", "fonts/arial.ttf", 18));
	
	auto red = cocos2d::Color3B(255, 0, 0);
	auto gold = cocos2d::Color3B(0,255,0);

	if (muertes < 10) {
		logros.at(0)->setColor(red);
	} else {
		logros.at(0)->setColor(gold);
	}
	if (muertes < 100) {
		logros.at(1)->setColor(red);
	}
	else {
		logros.at(1)->setColor(gold);
	}
	if (disparos < 1000) {
		logros.at(2)->setColor(red);
	}
	else {
		logros.at(2)->setColor(gold);
	}
	if (disparos < 10000) {
		logros.at(3)->setColor(red);
	}
	else {
		logros.at(3)->setColor(gold);
	}
	if (puntosTotales < 5000) {
		logros.at(4)->setColor(red);
	}
	else {
		logros.at(4)->setColor(gold);
	}
	int i = 6;
	for (cocos2d::Label* logro : logros) {
		logro->setPosition(_visibleSize.width / 2, i * _visibleSize.height / 9);
		addChild(logro, 5);
		i--;
	}

	High->setPosition(_visibleSize.width / 2, 7 * _visibleSize.height / 8);
	addChild(High, 5);



}

void LogMenu::actionButtonBack() {
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}