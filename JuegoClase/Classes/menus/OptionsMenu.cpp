#include "OptionsMenu.h"
#include "GameManager.h"
#include "TranslationEngine.h"
#include "MainMenu.h"
#include "AudioEngine.h"

USING_NS_CC;
using namespace ui;

Scene* OptionsMenu::createScene() {
	auto scene = Scene::create();
	auto layer = OptionsMenu::create();
	scene->addChild(layer);
	return scene;
}

bool OptionsMenu::init() {
	if (!MotherMenu::init()) {
		return false;
	}

	//int marginX = 50 * getScaleX();
	//int marginY = _visibleSize.height - 100 * getScaleY();


	//Label para ajustar sonidos de fondo
	_backGroundVolumeLabel = Label::createWithTTF("0", "fonts/arial.ttf", 16);
	_backGroundVolumeLabel->setAnchorPoint(Point(0, 1));
	_backGroundVolumeLabel->setTextColor(Color4B::BLACK);
	_ostr << GameManager::getInstance()->getBgVolume();
	if (!(TranslationEngine::getInstance()->getLanguage() == "ES_MX")) {
		_backGroundVolumeLabel->setString("Background volume: " + _ostr.str());
	}
	else
	{
		_backGroundVolumeLabel->setString("Volumen de Fondo: " + _ostr.str());
	}
	_ostr.str("");
	_backGroundVolumeLabel->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2));
	addChild(_backGroundVolumeLabel);

	//slider para ajustar volumen de fondo
	_backGroundVolume = Slider::create();
	_backGroundVolume->loadBarTexture("menus/Botones/sliders/bar_thing.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->loadSlidBallTextures("menus/Botones/sliders/peg0.png", "menus/Botones/sliders/peg1.png", "menus/Botones/sliders/peg2.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->loadProgressBarTexture("menus/Botones/sliders/bar_fill.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->setAnchorPoint(Point(0, 1));
	//marginY -= 5 * getScaleY() + _backGroundVolumeLabel->getBoundingBox().size.height;
	_backGroundVolume->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2 - 20));
	_backGroundVolume->setPercent(GameManager::getInstance()->getBgVolume());
	_backGroundVolume->addEventListener(CC_CALLBACK_0(OptionsMenu::actionBackGroundVolumeSlider, this));
	addChild(_backGroundVolume);

	//Label para ajustar volumen de efectos
	_effectsVolumeLabel = Label::createWithTTF("0", "fonts/arial.ttf", 16);
	_ostr << GameManager::getInstance()->getEffectsVolume();
	if (!(TranslationEngine::getInstance()->getLanguage() == "ES_MX")) {
		_effectsVolumeLabel->setString("Effects volume: " + _ostr.str());
	}
	else {
		_effectsVolumeLabel->setString("Volumen de Efectos : " + _ostr.str());
	}
	_ostr.str("");
	_effectsVolumeLabel->setTextColor(Color4B::BLACK);
	_effectsVolumeLabel->setAnchorPoint(Point(0, 1));
	//marginY -= 50 * getScaleY() + _backGroundVolume->getBoundingBox().size.height;
	_effectsVolumeLabel->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2 - 50));
	addChild(_effectsVolumeLabel);

	//Slider para ajustar volumen de efectos
	_effectsVolume = Slider::create();
	_effectsVolume->loadBarTexture("menus/Botones/sliders/bar_thing.png", Widget::TextureResType::LOCAL);
	_effectsVolume->loadSlidBallTextures("menus/Botones/sliders/peg0.png", "menus/Botones/sliders/peg1.png", "menus/Botones/sliders/peg2.png", Widget::TextureResType::LOCAL);
	_effectsVolume->loadProgressBarTexture("menus/Botones/sliders/bar_fill.png", Widget::TextureResType::LOCAL);
	_effectsVolume->setAnchorPoint(Point(0, 1));
	//marginY -= 5 * getScaleY() + _effectsVolumeLabel->getBoundingBox().size.height;
	_effectsVolume->setPosition(Point(_visibleSize.width/2, _visibleSize.height/2 - 70));
	_effectsVolume->setPercent(GameManager::getInstance()->getEffectsVolume());
	_effectsVolume->addEventListener(CC_CALLBACK_0(OptionsMenu::actionEffectsVolumeSlider, this));
	addChild(_effectsVolume);


	
	//Label para dificultad
	dificulty_Label = Label::createWithTTF("dificultad", "fonts/arial.ttf", 16);
	dificulty_Label->setAnchorPoint(Point(0, 1));
	dificulty_Label->setTextColor(Color4B::BLACK);
	_ostr << GameManager::getInstance()->getDifficulty();
	if (!(TranslationEngine::getInstance()->getLanguage() == "ES_MX")) {
		dificulty_Label->setString("Difficulty: " + _ostr.str());
	}
	else {
		dificulty_Label->setString("La Dificultad es: " + _ostr.str());
	}
	_ostr.str("");
	dificulty_Label->setPosition(Point(_visibleSize.width / 2, _visibleSize.height / 2 + 50));
	addChild(dificulty_Label);
	   	  	
	//slider para ajustar dificultad
	dificulty = Slider::create();
	dificulty->loadBarTexture("menus/Botones/sliders/dificulty_barthing.png", Widget::TextureResType::LOCAL);
	dificulty->loadSlidBallTextures("menus/Botones/sliders/peg0.png", "menus/Botones/sliders/peg1.png", "menus/Botones/sliders/peg2.png", Widget::TextureResType::LOCAL);
	dificulty->loadProgressBarTexture("menus/Botones/sliders/dificultybarfill.png", Widget::TextureResType::LOCAL);
	dificulty->setAnchorPoint(Point(0, 1));
	//marginY -= 5 * getScaleY() + _backGroundVolumeLabel->getBoundingBox().size.height;
	dificulty->setPosition(Point(_visibleSize.width / 2, _visibleSize.height / 2 + 30));
	dificulty->setPercent(GameManager::getInstance()->getDifficulty());
	dificulty->addEventListener(CC_CALLBACK_0(OptionsMenu::dificultySlider, this));
	addChild(dificulty);

	// Lenguaje

	mex = Button::create("menus/mextrue.png", "menus/mexfalse.png", "menus/mexfalse.png", Widget::TextureResType::LOCAL);
	mex->setAnchorPoint(Point(0.5, 0.5));
	mex->setScale(0.24);
	mex->addClickEventListener(CC_CALLBACK_0(OptionsMenu::langmex, this));
	mex->setPosition(Vec2(_visibleSize.width / 4 + 25, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(mex);

	us = Button::create("menus/ustrue.png", "menus/usfalse.png", "menus/usFalse.png", Widget::TextureResType::LOCAL);
	us->setAnchorPoint(Point(0.5, 0.5));
	us->setScale(0.2);
	us->setBright(false);
	us->addClickEventListener(CC_CALLBACK_0(OptionsMenu::langus, this));
	us->setPosition(Vec2(3 * _visibleSize.width / 4 - 25, _visibleSize.height / 2 + 100 * getScaleY()));
	addChild(us);



	//boton de ir hacia atras
	auto backBt = Button::create("menus/Botones/Back0.png", "menus/Botones/Back1.png", "menus/Botones/Back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->addClickEventListener(CC_CALLBACK_0(OptionsMenu::actionButtonBack, this));
	backBt->setPosition(Point(42.5 * getScaleX(), 50 * getScaleY()));
	addChild(backBt);




	this->schedule(schedule_selector(OptionsMenu::update));


	return true;

}

void OptionsMenu::actionBackGroundVolumeSlider() {
	_ostr << _backGroundVolume->getPercent();
	_backGroundVolumeLabel->setString("Background volume: " + _ostr.str());
	_ostr.str("");
	GameManager::getInstance()->setBgVolume(_backGroundVolume->getPercent());
}

void OptionsMenu::actionEffectsVolumeSlider() {
	_ostr << _effectsVolume->getPercent();
	_effectsVolumeLabel->setString("Effects volume: " + _ostr.str());
	_ostr.str("");
	GameManager::getInstance()->setEffectsVolume(_effectsVolume->getPercent());

}

//guarda la configuracion y va al menu principal 
void OptionsMenu::actionButtonBack() {
	GameManager::getInstance()->saveSetting();
	Director::getInstance()->replaceScene(TransitionFlipX::create(1, MainMenu::createScene()));
}

void OptionsMenu::dificultySlider() {	
	auto modo = GameManager::getInstance()->getDifiMode();
	
	if (!(TranslationEngine::getInstance()->getLanguage() == "ES_MX")) {
		if (modo == 1)
			_ostr << "Easy";
		else if (modo == 2)
			_ostr << "Medium";
		else
			_ostr << "Hard";
		dificulty_Label->setString("Difficulty: " + _ostr.str());
	}
	else {
		if (modo == 1)
			_ostr << "Fácil";
		else if (modo == 2)
			_ostr << "Moderado";
		else
			_ostr << "Maestro";
		dificulty_Label->setString("Dificultad: " + _ostr.str());
	}

	_ostr.str("");
	GameManager::getInstance()->setDifficulty(dificulty->getPercent());

};

void OptionsMenu::langmex() {
	this->mex->setBright(true);
	this->us->setBright(false);

	TranslationEngine::getInstance()->setLanguage("ES_MX");
	GameManager::getInstance()->setLanguage("ES_MX");

};


void OptionsMenu::langus() {
	this->mex->setBright(false);
	this->us->setBright(true);

	TranslationEngine::getInstance()->setLanguage("EN_US");
	GameManager::getInstance()->setLanguage("EN_US");

};

void OptionsMenu::update(float delta) {

	GameManager::getInstance()->saveSetting();
	cocos2d::experimental::AudioEngine::setVolume(GameManager::getInstance()->getCurrentMusicTag(), GameManager::getInstance()->getBgVolume()/100);

};