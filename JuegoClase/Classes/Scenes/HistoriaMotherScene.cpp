#include "Scenes/HistoriaMotherScene.h"
//#include "SimpleAudioEngine.h"
//using namespace CocosDenshion;
#include "AudioEngine.h"

#include "DebugScene.h"



#include "TranslationEngine.h"
#include "ui/CocosGUI.h"
#include "GameWrapper.h"
#include "menus/MainMenu.h"
#include "MiniGameScene.h"

USING_NS_CC;

HistoriaMotherScene::HistoriaMotherScene(int tipoP1, bool two, int tipoP2, int est) {
	this->two = two;
	this->naveP1 = tipoP1;
	this->naveP2 = tipoP2;
	this->historia = est;
	HistoriaMotherScene::init();
}

Scene* HistoriaMotherScene::createScene(int tipoP1, bool two, int tipoP2, int est) {
	auto scene = Scene::create();
	auto layer = new HistoriaMotherScene(tipoP1, two, tipoP2, est); //DebugScene::create(jug);
	scene->addChild(layer);

	return scene;
}

bool HistoriaMotherScene::init() {

	if (!Layer::init())
		return false;

	auto _visibleSize = Director::getInstance()->getWinSize();

	//Crea el background
	_bg = Background::create();
	auto capa = Sprite::create("transparente.png");
	capa->setScale(5, 5);
	addChild(capa, 1);
	addChild(_bg, -1);
	_bg->scheduleUpdate();

	Actual = Label::createWithTTF("", "fonts/SPACEBAR.ttf", 17);
	
	Actual->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2));
	addChild(Actual, 5);
	this->retain();
	if (ingles==true) {
		std::string m1 = "You are an amazing baker \nand you love all the cakes\n you have made but\n one day someone \nsteals your favorite cake,\n you will not let it happen";
		std::string m2 = "So you take your spaceship \nand chase\n the thief, fighting \nagainst any enemy\n along the way\n. Eventually he will \nlose the competition,\nbut he will try to \nmake his recipe";
		std::string m3 = " You are looking to defeat\n the evildoer who stole your\n favorite cake.You fight against\n his subordinates but\n every time you\n defeat a boss, they tell you\n that the person you are\n looking for is in another\n galaxy, or in another dimension";
		Historia1.push_back(m1);
		Historia1.push_back(m2);
		Historia1.push_back(m3);
		Historia1.push_back(m3);
		m1 = "-Have you involved other \npeople with cakes and milk ? \n - Yes.I involved them.";
		m2 = "- How did you get \n the cakes ? \n - If you allow them to sell \nthem to you, you don't \nhave to pay attention\n to the cake.";
		m3 = "-Okay, and you give him \nthe milk.\n-Where did you get the milk ?\n-There are millions of\n tons of milk in\n the universe.";
		Historia2.push_back(m1);
		Historia2.push_back(m2);
		Historia2.push_back(m3);
		Historia2.push_back(m3);
		m1 = "You finally found the man\n who stole your cake\n, now it's time to get revenge.\n You take a cake and\n start preparing to \n with it, but your \n are about to wake you up and\n you know that you should\n arrive at the principal'\n office as soon as possible\n but you won't let the\n thief win.";
		m2 = "-You found me, uh baker!\n-Yes, I can find every person who \n has tried my cakes, you can't\n get away from me.\n-I will not pay for that cake!\n-Oh don't worry, all those \n cakes will come to your face\n-Ah, since I will ate them all!";
		m3 = "-I will give you a reward\n before you pay.\n - In the end, I know exactly \nhow you make your cakes!\n - Now, you won't try \nany cake again!\n-Come on, finish me";
		Historia3.push_back(m1);
		Historia3.push_back(m2);
		Historia3.push_back(m3);
		Historia3.push_back(m3);
	}
	else {
		std::string m1 = " Eres un panadero increible\n y te encantan todos los pasteles\n que has hecho, pero\n un dia alguien roba tu pastel\n favorito, no dejaras que suceda";
		std::string m2 = " Asi que tomas tu nave espacial \n y persigues al ladron,\n luchando contra cualquier\n enemigo en el camino.\n Eventualmente el perdera\n la competencia, pero el\n intentara realizar  su receta. ";
		std::string m3 = " Estas buscando derrotar \n al malhechor\n que robo tu pastel favorito\n.Luchas contra sus subordinados\n pero cada vez que derrotas \n a un jefe,\n Te dicen que la persona que estas\n buscando esta en otra galaxia,\n o en otra dimension ";
		Historia1.push_back(m1);
		Historia1.push_back(m2);
		Historia1.push_back(m3);
		Historia1.push_back(m3);
		m1 = " -Has involucrado a otras \npersonas con los pasteles \ny la leche?\nSi. Los involucre";
		m2 = "-Como conseguiste los pasteles ? \n - Si permites que te los vendan, \n no tienes que prestar\n atencion al pastel";
		m3 = "-Esta bien, y le das la leche.\n - De donde sacaste la leche ?\n -Hay millones de toneladas\n de leche en el universo."	;
		Historia2.push_back(m1);
		Historia2.push_back(m2);
		Historia2.push_back(m3);
		Historia2.push_back(m3);
		m1 = "Finalmente encontraste al\n hombre que robo tu pastel\n, ahora es tiempo de vengarse.\n Coges un pastel y empiezas\n a prepararte\n para luchar con el, pero\n tus amigos estan a punto \nde despertarte\n y sabes que debes llegar a la\n oficina del director \nlo antes posible\n pero no dejaras que \n el ladron gane.";
		m2 = "Me encontraste, eh panadero!\n-Si, puedo encontrar a\ncada persona que\n haya probado mis pasteles,\n no podras\n alejarte de mi.\n-No pagare por ese pastel!\n-Oh, no te preocupes, \n-todos esos pasteles seran\n para destruir tu nave\n-Ah, ya que yo que\n queria probar todo!\n";
		m3 = "-Te dare una recompensa\n antes de que pagues.\n-Al final, se exactamente como \nhaces tus pasteles!\n-Ahora, no volveras a probar\nningun pastel!\n-Vamos, Acabame!";
		Historia3.push_back(m1);
		Historia3.push_back(m2);
		Historia3.push_back(m3);
		Historia3.push_back(m3);
	}
	
	button = ui::Button::create("menus/Botones/Back0.png", "menus/Botones/Back1.png", "menus/Botones/Back0.png");
	button->setScale(2, 2);
	button->setRotation(180);
	button->setAnchorPoint(Point(0, 0));
	button->setPosition(Point(450, 50));
	button->addClickEventListener(CC_CALLBACK_0(HistoriaMotherScene::NextButtonAction, this));

	button2 = ui::Button::create("menus/Botones/Back0.png", "menus/Botones/Back1.png", "menus/Botones/Back0.png");
	button2->setScale(2, 2);
	
	button2->setAnchorPoint(Point(0, 0));
	button2->setPosition(Point(30, 15));
	button2->addClickEventListener(CC_CALLBACK_0(HistoriaMotherScene::PrevButtonAction, this));
	addChild(button2, 3);
	addChild(button, 3);
	

	



	scheduleUpdate();



	//Crea al jugador
	


}

void HistoriaMotherScene::update(float delta) {


	if (estado <= 0) {
		estado = 0;
		button2->setVisible(false);
	}
	else if (estado>=3) {
		if (historia == 1) {
			Director::getInstance()->replaceScene(DebugScene::createScene(1, false, 0, 1));
		}
		else if (historia == 2) {
			Director::getInstance()->replaceScene(DebugScene::createScene(1, false, 0, 2));
		}
		else if (historia == 3) {
			Director::getInstance()->replaceScene (DebugScene::createScene(1, false, 0, 3));
		}
	}
	else {
		button2->setVisible(true);

	}
	
	salirButtonAction();

	
}
void HistoriaMotherScene::PrevButtonAction()
{
	estado -= 1;

}

void HistoriaMotherScene::NextButtonAction()
{
	estado += 1;

}

void HistoriaMotherScene::saveButtonAction() {
	
}

void HistoriaMotherScene::salirButtonAction() {

	if (historia == 1) {
		Actual->setString(Historia1.at(estado));
	}
	else if (historia==2){
		Actual->setString(Historia2.at(estado));
	}
	else if (historia == 3) {
		Actual->setString(Historia3.at(estado));
	}
}

