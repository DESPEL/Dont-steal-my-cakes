#include "Menuinstrucciones.h"
#include "GameManager.h"
#include "Scenes/DebugScene.h"
#include "AudioEngine.h"
#include "GameWrapper.h"
#include "Scenes/HistoriaMotherScene.h"

USING_NS_CC;
using namespace ui;



Scene* MenuIns::createScene() {
	auto scene = Scene::create();
	auto layer = MenuIns::create();
	scene->addChild(layer);
	return scene;
}
Scene* MenuIns::createScene(int Historia) {
	
	auto scene = Scene::create();
	auto layer = MenuIns::create();
	scene->addChild(layer);
		
	return scene;
}



void::MenuIns::uphist(int t) {
	hist = t;
}

bool MenuIns::init() {
	if (!MotherMenu::init()) {
		return false;
	}

	
	initButtons();

	
	auto backBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->setScale(2.5);
	backBt->setRotation(180);
	backBt->addClickEventListener(CC_CALLBACK_0(MenuIns::actionButtonNext, this));
	backBt->setPosition(Point(430, 40));
	addChild(backBt);

	auto cbackBt = Button::create("menus/Botones/back0.png", "menus/Botones/back1.png", "menus/Botones/back1.png", Widget::TextureResType::LOCAL);
	cbackBt->setAnchorPoint(Point(0, 0.5));
	cbackBt->setScale(2.5);

	cbackBt->addClickEventListener(CC_CALLBACK_0(MenuIns::actionButtonBack, this));
	cbackBt->setPosition(Point(40, 40));
	addChild(cbackBt);


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

	if ((TranslationEngine::getInstance()->getLanguage() == "ES_MX")) {
		auto label = Label::createWithTTF("Movimiento", "fonts/SpaceBoy.ttf", 18);
		label->setPosition(300, 120);
		label->setScaleX(1.3);
		label->setVisible(true);
		addChild(label, 3);

		auto label2 = Label::createWithTTF("Movimiento", "fonts/SpaceBoy.ttf", 18);
		label2->setPosition(300, 250);
		label2->setScaleX(1.3);
		label2->setVisible(true);
		addChild(label2, 3);

		auto label4 = Label::createWithTTF("Disparar", "fonts/SpaceBoy.ttf", 18);
		label4->setPosition(300, 195);
		label4->setScaleX(1.3);
		label4->setVisible(true);
		addChild(label4, 3);

		auto label5 = Label::createWithTTF("Disparar", "fonts/SpaceBoy.ttf", 18);
		label5->setPosition(300, 70);
		label5->setScaleX(1.3);
		label5->setVisible(true);
		addChild(label5, 3);

		auto label6 = Label::createWithTTF("J1", "fonts/SpaceBoy.ttf", 18);
		label6->setPosition(300, 290);
		label6->setScaleX(1.2);
		label6->setVisible(true);
		addChild(label6, 3);

		auto label7 = Label::createWithTTF("J2", "fonts/SpaceBoy.ttf", 18);
		label7->setPosition(300, 150);
		label7->setScaleX(1.2);
		label7->setVisible(true);
		addChild(label7, 3);
	}
	else {
		auto label = Label::createWithTTF("Move", "fonts/SpaceBoy.ttf", 18);
		label->setPosition(300, 120);
		label->setScaleX(1.3);
		label->setVisible(true);
		addChild(label, 3);

		auto label2 = Label::createWithTTF("Move", "fonts/SpaceBoy.ttf", 18);
		label2->setPosition(300, 250);
		label2->setScaleX(1.3);
		label2->setVisible(true);
		addChild(label2, 3);

		auto label4 = Label::createWithTTF("Shoot", "fonts/SpaceBoy.ttf", 18);
		label4->setPosition(300, 195);
		label4->setScaleX(1.3);
		label4->setVisible(true);
		addChild(label4, 3);

		auto label5 = Label::createWithTTF("Shoot", "fonts/SpaceBoy.ttf", 18);
		label5->setPosition(300, 70);
		label5->setScaleX(1.3);
		label5->setVisible(true);
		addChild(label5, 3);

		auto label6 = Label::createWithTTF("P1", "fonts/SpaceBoy.ttf", 18);
		label6->setPosition(300, 290);
		label6->setScaleX(1.2);
		label6->setVisible(true);
		addChild(label6, 3);

		auto label7 = Label::createWithTTF("P2", "fonts/SpaceBoy.ttf", 18);
		label7->setPosition(300, 150);
		label7->setScaleX(1.2);
		label7->setVisible(true);
		addChild(label7, 3);
	}
	
	
}

void MenuIns::actionButtonBack() {
	experimental::AudioEngine::stopAll();
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, MainMenu::createScene()));
}
void MenuIns::actionButtonNext() {
	auto wrapper = GameWrapper::getInstance();
	Director::getInstance()->pushScene(TransitionFadeBL::create(1, HistoriaMotherScene::createScene()));
}