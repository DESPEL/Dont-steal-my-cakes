#include "BasicBullet.h"

void BasicBullet::run(float) {
	if (parent->get_currentAnimation() == BasicEnemy::EXPLOSION) {
		runAction(cocos2d::RemoveSelf::create());
		return;
	}
	setVisible(true);
	runAction(seq);
	seq->release();
	schedule(schedule_selector(BasicBullet::update));
}

void BasicBullet::update(float delta) {
	if (GameWrapper::getInstance()->getPlayer()->getBoundingBox().intersectsRect(getBoundingBox())) {
		GameWrapper::getInstance()->getPlayer()->setCurrentAnimation(Player::EXPLOSION);
		this->runAction(cocos2d::RemoveSelf::create());
	}
}

BasicBullet* BasicBullet::createWithFile(std::string name) {
	BasicBullet* val = BasicBullet::create();
	val->initWithFile(name);
	return val;
}