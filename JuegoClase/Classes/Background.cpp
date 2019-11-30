#include "background.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

#include "GameWrapper.h"

Background::Background() :_speed(120) {
	_screen = Director::getInstance()->getOpenGLView()->getFrameSize();
	int lvl = GameWrapper::getInstance()->actualLevel;
	
	switch (lvl) {
	case 1:
		_bgPart1 = Sprite::create("fondo5.png");
		_bgPart2 = Sprite::create("fondo5.png");
		break;
	case 2:
		_bgPart1 = Sprite::create("fondo7.png");
		_bgPart2 = Sprite::create("fondo7.png");
		break;
	case 3:
		_bgPart1 = Sprite::create("fondo6.png");
		_bgPart2 = Sprite::create("fondo6.png");
		break;
	case 4:
		_bgPart1 = Sprite::create("fondo4.png");
		_bgPart2 = Sprite::create("fondo4.png");
		break;
	default:
		_bgPart1 = Sprite::create("fondo5.png");
		_bgPart2 = Sprite::create("fondo5.png");
	}

	_bgPart1->setContentSize(_screen);
	_bgPart2->setContentSize(_screen);
	_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
	_bgPart2->setPosition(_screen.width / 2, _screen.height / 2 + _screen.height);
	addChild(_bgPart1);
	addChild(_bgPart2,-1);
}

void Background::update(float delta) {
	Background::_bgPart1->setPositionY(_bgPart1->getPositionY() - _speed * delta);
	Background::_bgPart2->setPositionY(_bgPart2->getPositionY() - _speed * delta);
	if (_bgPart1->getPositionY() <= -(_screen.height / 2)) {
		_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
		_bgPart2->setPosition(_screen.width / 2, _screen.height / 2 + _screen.height);
	}
}

Background::~Background() {
}