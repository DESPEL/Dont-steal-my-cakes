#include "BasicBullet.h"

#define BULLET_MOVEMENT 90

bool BasicBullet::init() noexcept {
	return true;
}

void BasicBullet::run(float) {
	GameWrapper::getInstance()->val++;
	if (parent->exploded) {
		this->removeFromParentAndCleanup(true);
		return;
	}
	//cocos2d::log("running bullet");
	setPosition(parent->getPosition());
	setVisible(true);
	auto seqf = seq->clone();
	seqf->setTag(BULLET_MOVEMENT);
	runAction(seq->clone());
	schedule(schedule_selector(BasicBullet::update));
}

void BasicBullet::update(float delta) {
	if (GameWrapper::getInstance()->getPlayer()->getBoundingBox().intersectsRect(getBoundingBox())) {
		GameWrapper::getInstance()->getPlayer()->setCurrentAnimation(Player::EXPLOSION);
		this->stopActionByTag(BULLET_MOVEMENT);
		this->runAction(cocos2d::RemoveSelf::create());
		//this->removeFromParentAndCleanup(true);
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

BasicBullet::~BasicBullet() {
	GameWrapper::getInstance()->val--;
	//std::stringstream a;
	//a << "bullet deleted, remaining: " << GameWrapper::getInstance()->val;
	//cocos2d::log(a.str().c_str());
}