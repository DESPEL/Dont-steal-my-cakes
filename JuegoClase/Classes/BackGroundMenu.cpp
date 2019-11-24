#include "BackGroundMenu.h"

USING_NS_CC;

BackGroundMenu::BackGroundMenu() :_speed(150) {
	_screen = Director::getInstance()->getOpenGLView()->getFrameSize();
	_bgPart1 = Sprite::create("menus/BackGround1.png");
	_bgPart1->setContentSize(_screen);
	_bgPart2 = Sprite::create("menus/BackGround2.png");
	_bgPart2->setContentSize(_screen);
	_bgPart3 = Sprite::create("menus/BackGround3.png");
	_bgPart3->setContentSize(_screen);
	_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
	_bgPart2->setPosition(_screen.width / 2 + _screen.width, _screen.height / 2);
	_bgPart3->setPosition(_screen.width / 2 + 2 * _screen.width, _screen.height / 2);
	addChild(_bgPart1);
	addChild(_bgPart2);
	addChild(_bgPart3);
}

void BackGroundMenu::update(float delta) {
	BackGroundMenu::_bgPart1->setPositionX(_bgPart1->getPositionX() - _speed * delta);
	BackGroundMenu::_bgPart2->setPositionX(_bgPart2->getPositionX() - _speed * delta);
	BackGroundMenu::_bgPart3->setPositionX(_bgPart3->getPositionX() - _speed * delta);
	if (_bgPart2->getPositionX() <= -(_screen.width / 2)) {
		_bgPart1->setPosition(_screen.width / 2, _screen.height / 2);
		_bgPart2->setPosition(_screen.width / 2 + _screen.width, _screen.height / 2);
		_bgPart3->setPosition(_screen.width / 2 + 2 * _screen.width, _screen.height / 2);
	}
}

BackGroundMenu::~BackGroundMenu() {
}