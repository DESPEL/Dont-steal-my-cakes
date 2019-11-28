#include "LevelSelectMenu.h"
#include "GameManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene* LevelSelectMenu::createScene() {
	auto scene = Scene::create();
	auto layer = LevelSelectMenu::create();
	scene->addChild(layer);
	return scene;
}


bool LevelSelectMenu::init() {
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
	backBt->addClickEventListener(CC_CALLBACK_0(LevelSelectMenu::actionButtonBack, this));
	backBt->setPosition(Point(30 * getScaleX(), 30 * getScaleY()));
	addChild(backBt);

	return true;
}

void LevelSelectMenu::initButtons() {
	
	auto level1 = Button::create("menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", "menus/Botones/buttonlevel1.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(0.4);
	level1->addClickEventListener(CC_CALLBACK_0(MainMenu::actionButton1, this));
	level1->setPosition(Vec2(_visibleSize.width / 2, _visibleSize.height / 2 + 100* getScaleY()));
	addChild(level1);

	
	/*int tag = 1;
	int sizeY = 0;
	int sizeX = 0;
	int marginX = 42.5 * getScaleX();
	int marginY = _visibleSize.height - 100 * getScaleY();
	//queremos un aspecto de matriz, usamos para ello dos bucles
	for (int i = 0; i < NUM_LEVELS / 3; i++) {
		for (int j = 0; j < NUM_LEVELS / 3; j++) {
			auto bt = Button::create("level_unlock0", "level_unlock1", "level_lock", Widget::TextureResType::PLIST);
			//inicialmente los niveles estan bloqueados por lo que los botones estaran deshabilitados
			bt->setEnabled(false);
			bt->setBright(false);
			//ponemos funcionalidad y nombre a cada boton 
			bt->addClickEventListener(functions.at(tag - 1));
			bt->setTag(tag); _ostr << tag; tag++;
			bt->setTitleText(_ostr.str()); _ostr.str("");
			//indicamos como de grande sera la fuente
			bt->setTitleFontSize(18);
			bt->setAnchorPoint(Point(0, 0.5));
			bt->setPosition(Point(marginX, marginY));
			//calculamos la posicion para el siguiente boton
			sizeX = bt->getBoundingBox().size.width;
			sizeY = bt->getBoundingBox().size.height;
			marginX += 42.5 * getScaleX() + sizeX;
			buttons.pushBack(bt);
			addChild(bt);
		}
		marginX = 42.5 * getScaleX();
		marginY -= (42.5 * getScaleY() + sizeY);
	}*/
}

void LevelSelectMenu::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}