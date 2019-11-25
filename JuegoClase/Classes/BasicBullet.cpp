#include "BasicBullet.h"

void BasicBullet::run(float) {
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