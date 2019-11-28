#include "OptionsMenu.h"
#include "GameManager.h"
#include "MainMenu.h"

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

	int marginX = 50 * getScaleX();
	int marginY = _visibleSize.height - 100 * getScaleY();


	//Label para ajustar sonidos de fondo
	_backGroundVolumeLabel = Label::createWithTTF("0", "fonts/arial.ttf", 16);
	_backGroundVolumeLabel->setAnchorPoint(Point(0, 1));
	_backGroundVolumeLabel->setTextColor(Color4B::BLACK);
	_ostr << GameManager::getInstance()->getBgVolume();
	_backGroundVolumeLabel->setString("Background volume: " + _ostr.str());
	_ostr.str("");
	_backGroundVolumeLabel->setPosition(Point(marginX, marginY));
	addChild(_backGroundVolumeLabel);

	//slider para ajustar volumen de fondo
	_backGroundVolume = Slider::create();
	_backGroundVolume->loadBarTexture("menus/Botones/sliders/bar_thing.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->loadSlidBallTextures("menus/Botones/sliders/peg0.png", "menus/Botones/sliders/peg1.png", "menus/Botones/sliders/peg2.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->loadProgressBarTexture("menus/Botones/sliders/bar_fill.png", Widget::TextureResType::LOCAL);
	_backGroundVolume->setAnchorPoint(Point(0, 1));
	marginY -= 5 * getScaleY() + _backGroundVolumeLabel->getBoundingBox().size.height;
	_backGroundVolume->setPosition(Point(marginX, marginY));
	_backGroundVolume->setPercent(GameManager::getInstance()->getBgVolume());
	_backGroundVolume->addEventListener(CC_CALLBACK_0(OptionsMenu::actionBackGroundVolumeSlider, this));
	addChild(_backGroundVolume);

	//Label para ajustar volumen de efectos
	_effectsVolumeLabel = Label::createWithTTF("0", "fonts/arial.ttf", 16);
	_ostr << GameManager::getInstance()->getEffectsVolume();
	_effectsVolumeLabel->setString("Effects volume: " + _ostr.str());
	_ostr.str("");
	_effectsVolumeLabel->setTextColor(Color4B::BLACK);
	_effectsVolumeLabel->setAnchorPoint(Point(0, 1));
	marginY -= 50 * getScaleY() + _backGroundVolume->getBoundingBox().size.height;
	_effectsVolumeLabel->setPosition(Point(marginX, marginY));
	addChild(_effectsVolumeLabel);

	//Slider para ajustar volumen de efectos
	_effectsVolume = Slider::create();
	_effectsVolume->loadBarTexture("menus/Botones/sliders/bar_thing.png", Widget::TextureResType::LOCAL);
	_effectsVolume->loadSlidBallTextures("menus/Botones/sliders/peg0.png", "menus/Botones/sliders/peg1.png", "menus/Botones/sliders/peg2.png", Widget::TextureResType::LOCAL);
	_effectsVolume->loadProgressBarTexture("menus/Botones/sliders/bar_fill.png", Widget::TextureResType::LOCAL);
	_effectsVolume->setAnchorPoint(Point(0, 1));
	marginY -= 5 * getScaleY() + _effectsVolumeLabel->getBoundingBox().size.height;
	_effectsVolume->setPosition(Point(marginX, marginY));
	_effectsVolume->setPercent(GameManager::getInstance()->getEffectsVolume());
	_effectsVolume->addEventListener(CC_CALLBACK_0(OptionsMenu::actionEffectsVolumeSlider, this));
	addChild(_effectsVolume);




	//boton de ir hacia atras
	auto backBt = Button::create("menus/Botones/Back0.png", "menus/Botones/Back1.png", "menus/Botones/Back1.png", Widget::TextureResType::LOCAL);
	backBt->setAnchorPoint(Point(0, 0.5));
	backBt->addClickEventListener(CC_CALLBACK_0(OptionsMenu::actionButtonBack, this));
	backBt->setPosition(Point(42.5 * getScaleX(), 50 * getScaleY()));
	addChild(backBt);
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

