#include "Player.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "Scenes/DebugScene.h"

#include "menus/MainMenu.h"
#include "menus/DeathMenu.h"

using namespace CocosDenshion;

USING_NS_CC;


bool Player::init() {

	if (!Sprite::init())
		return false;

	_speed = 100;
	_currentAnimation = IDLE;

	createIdleAnimation();

	createExplosionAnimation();

	runAction(_idleAnimation);

	_control = KeyBoard::create();
	_control->keys.clear();
	addChild(_control);

	for (int i = 0; i < _numbullets; i++) {
		Balas.pushBack(Bullet::createPlayerBullet());
	}

	this->scheduleUpdate();


	return true;
}

void Player::createIdleAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("nave1.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 4; i++) {
		auto frame = SpriteFrame::create("animacion_nave.png", Rect(Vec2(size.width * i, 0), size));
		animFrames.pushBack(frame);
	}

	this->setSpriteFrame(animFrames.at(0));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.25f);

	auto animate = Animate::create(animation);

	_idleAnimation = RepeatForever::create(animate);

	_idleAnimation->setTag(Player::Animations::IDLE);

	_idleAnimation->retain();
}

void Player::createExplosionAnimation() {
	Vector<SpriteFrame*> animFrames;
	auto sprite1 = Sprite::create("explode1.png");
	auto size = sprite1->getContentSize();
	for (int i = 0; i < 4; i++) {
		auto frame = SpriteFrame::create("player_explosion.png", Rect(Vec2(size.width * i, 0), size));
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f);

	_explosionAnimation = Animate::create(animation);

	_explosionAnimation->setTag(Player::Animations::EXPLOSION);

	_explosionAnimation->retain();
}

void Player::shoot(Vec2 dir) {
	auto bullet = Balas.at(bulletsact);
	bullet->activa = true;
	bullet->direccion = dir;
	SimpleAudioEngine::getInstance()->playEffect("music/laser_shoot.wav");
	if(!vuelta)
		this->getParent()->addChild(bullet, -1);
	bullet->setAnchorPoint(Point(0.5, 0));
	if (!bullet->isVisible()) {
		bullet->setPosition(getPositionX(), getPositionY() + this->_contentSize.height/2);
		bullet->setVisible(true);
	}
	if (bulletsact == _numbullets - 1) {
		bulletsact = 0;
		vuelta = 1;
	}
	else
		bulletsact++;
}

void Player::setCurrentAnimation(Animations anim) {
	if (_currentAnimation == anim) return;
	_currentAnimation = anim;
	if (_currentAnimation == IDLE) {
		stopActionByTag(EXPLOSION);
		runAction(_idleAnimation);
	}
	if (_currentAnimation == EXPLOSION) {
		stopActionByTag(IDLE);
		runAction(_explosionAnimation);
	}
}

void Player::update(float delta) {

	if (_currentAnimation == EXPLOSION) {
		if (_explosionAnimation->isDone())
			setVisible(0);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		_control->keys.clear();
		
		Director::getInstance()->replaceScene(TransitionCrossFade::create(1, DeathMenu::createScene()));
		return;
	}

	auto director = Director::getInstance();
	auto visiblesize = director->getVisibleSize();
	float deltay = visiblesize.height / visiblesize.width;
	float deltax = visiblesize.width / visiblesize.height;

	for (auto K : KeyBoard::keys) {
		Vec2 loc = this->getPosition();
		switch (K.first) {
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:     
		case EventKeyboard::KeyCode::KEY_A:
			this->setPosition(loc.x - deltax * change, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
			this->setPosition(loc.x + deltax * change, loc.y);
			break;
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
			this->setPosition(loc.x, loc.y + deltay * change);
			break;
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		case EventKeyboard::KeyCode::KEY_S:
			this->setPosition(loc.x, loc.y - deltay * change);
			break;
		case EventKeyboard::KeyCode::KEY_SPACE:
			if (this->delay <= 0) {
				this->shoot(Vec2(0,2));
				this->shoot(Vec2(1, 1));
				this->shoot(Vec2(-1, 1));
				this->shoot(Vec2(0.5, 1.5));
				this->shoot(Vec2(-0.5, 1.5));
				this->shoot(Vec2(0.3, 1.8));
				this->shoot(Vec2(-0.3, 1.8));
				this->delay = this->delayvalue;
			}
			break;	
		case EventKeyboard::KeyCode::KEY_Q:
			if (this->delay <= 0) {
				this->shoot(Vec2(-1, 1));
				this->delay = this->delayvalue;
			}
			break;
		case EventKeyboard::KeyCode::KEY_E:
			if (this->delay <= 0) {
				this->shoot(Vec2(1, 1));
				this->delay = this->delayvalue;
			}
			break;
		}
	}

	if (this->getPosition().x > visiblesize.width + 15)
		this->setPosition(Vec2(-10, this->getPosition().y));

	if (this->getPosition().x < 0 - 15)
		this->setPosition(Vec2(visiblesize.width + 10, this->getPosition().y));

	if (this->getPosition().y + this->getContentSize().height / 2 >= visiblesize.height)
		this->setPosition(Vec2((this->getPosition().x), (this->getPosition().y - this->getContentSize().height / 2 + 10)));

	if (this->getPosition().y - this->getContentSize().height / 2 <= 0)
		this->setPosition(Vec2((this->getPosition().x), (this->getPosition().y + this->getContentSize().height / 2 - 10)));

	if(delay > 0)
		delay -= delta;
}