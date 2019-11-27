#include "BasicBullet.h"

bool BasicBullet::init() noexcept {
	return true;
}

void BasicBullet::run(float) {
	if (parent->getCurrentAnimation() == BasicEnemy::EXPLOSION) {
		runAction(cocos2d::RemoveSelf::create());
		return;
	}
	setPosition(parent->getPosition());
	setVisible(true);
	runAction(seq->clone());
	schedule(schedule_selector(BasicBullet::update));
}

void BasicBullet::update(float delta) {
	if (GameWrapper::getInstance()->getPlayer()->getBoundingBox().intersectsRect(getBoundingBox())) {
		GameWrapper::getInstance()->getPlayer()->setCurrentAnimation(Player::EXPLOSION);
		this->runAction(cocos2d::RemoveSelf::create());
	}
}

BasicBullet* BasicBullet::create(BasicBullet* bull) {
	BasicBullet* ret = BasicBullet::create();
	ret->initWithTexture(bull->getTexture());
	ret->seq = bull->seq;
	return ret;
}

BasicBullet* BasicBullet::create(std::string name) {
	BasicBullet* val = BasicBullet::create();
	if (val == nullptr)
		return nullptr;
	val->initWithFile(name);
	return val;
}