#include "Menuinstrucciones.h"
#include "GameManager.h"
#include "Scenes/DebugScene.h"


USING_NS_CC;
using namespace ui;

Scene* MenuIns::createScene() {
	auto scene = Scene::create();
	auto layer = MenuIns::create();
	scene->addChild(layer);
	return scene;
}


bool MenuIns::init() {
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
	backBt->setScale(2.5);
	backBt->setRotation(180);
	backBt->addClickEventListener(CC_CALLBACK_0(MenuIns::actionButtonBack, this));
	backBt->setPosition(Point(430, 40));
	addChild(backBt);

	return true;
}

void MenuIns::initButtons() {

	auto level1 = Button::create("wasd.png", "wasd.png", "wasd.png", Widget::TextureResType::LOCAL);
	level1->setAnchorPoint(Point(0.5, 0.5));
	level1->setScale(.8);
	level1->setPosition(Vec2(100, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(level1);



	auto level2 = Button::create("espacio.png", "espacio.png", "espacio.png", Widget::TextureResType::LOCAL);
	level2->setAnchorPoint(Point(0.5, 0.5));
	level2->setScale(0.7);
	level2->setPosition(Vec2(100, 195));
	addChild(level2);

	auto level3 = Button::create("flechas.png", "flechas.png", "flechas.png", Widget::TextureResType::LOCAL);
	level3->setAnchorPoint(Point(0.5, 0.5));
	level3->setScale(0.4);
	level3->setPosition(Vec2(100, 130));
	addChild(level3);

	auto level4 = Button::create("f.png", "f.png", "f.png", Widget::TextureResType::LOCAL);
	level4->setAnchorPoint(Point(0.5, 0.5));
	level4->setScale(0.4);
	level4->setPosition(Vec2(100, 80));
	addChild(level4);


	auto label = Sprite::create("Movimiento.png");
	label->setPosition(300, 120);
	label->setScaleX(1.3);
	label->setVisible(true);
	addChild(label, 3);

	auto label2 = Sprite::create("Movimiento.png");
	label2->setPosition(300, 250);
	label2->setScaleX(1.3);
	label2->setVisible(true);
	addChild(label2, 3);

	auto label4 = Sprite::create("Disparar.png");
	label4->setPosition(300, 195);
	label4->setScaleX(1.3);
	label4->setVisible(true);
	addChild(label4, 3);

	auto label5 = Sprite::create("Disparar.png");
	label5->setPosition(300, 70);
	label5->setScaleX(1.3);
	label5->setVisible(true);
	addChild(label5, 3);

	auto label6 = Sprite::create("J1.png");
	label6->setPosition(300, 290);
	label6->setScaleX(1.2);
	label6->setVisible(true);
	addChild(label6, 3);

	auto label7 = Sprite::create("J2.png");
	label7->setPosition(300, 150);
	label7->setScaleX(1.2);
	label7->setVisible(true);
	addChild(label7, 3);

	auto texto = Sprite::create("transparente.png");
	texto->setPosition(0, 0);
	addChild(texto, 5);




	//level1->addClickEventListener(CC_CALLBACK_0(MainMenu::actionButton1, this));




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

void MenuIns::actionButtonBack() {
	Director::getInstance()->replaceScene(TransitionFadeBL::create(1, DebugScene::createScene()));
}