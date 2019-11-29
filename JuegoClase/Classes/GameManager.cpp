#include "GameManager.h"

USING_NS_CC;

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager() :_playerScore(0) {
	_bgVolume = UserDefault::getInstance()->getIntegerForKey(BGVOLUME, 30);
	_effectsVolume = UserDefault::getInstance()->getIntegerForKey(SFXVOLUME, 40);
}

GameManager::~GameManager() {}

void GameManager::saveSetting() {
	UserDefault::getInstance()->setIntegerForKey(BGVOLUME, _bgVolume);
	UserDefault::getInstance()->setIntegerForKey(SFXVOLUME, _effectsVolume);
}

GameManager* GameManager::getInstance() {
	if (!_instance) {
		_instance = new GameManager();
	}
	return _instance;
}

void GameManager::saveGame(int tag) {
	if (tag > getNextLevel()) {
		UserDefault::getInstance()->setIntegerForKey(LEVEL, tag);
	}
}

int GameManager::getNextLevel() {
	return UserDefault::getInstance()->getIntegerForKey(LEVEL, 0);
}

void GameManager::saveMaxScore(int score) {
	UserDefault::getInstance()->setIntegerForKey(MAXSCORE, score);
}

int GameManager::getMaxScore() {
	return UserDefault::getInstance()->getIntegerForKey(MAXSCORE, 0);
}

void GameManager::saveMiniGameScore(int score) {
	if (score > this->GameManager::getMiniGameScore())
		UserDefault::getInstance()->setIntegerForKey(MINIGAMEMAXSCORE, score);

};

int GameManager::getMiniGameScore() {
	return UserDefault::getInstance()->getIntegerForKey(MINIGAMEMAXSCORE, 0);
};

void GameManager::resetScore() {

	UserDefault::getInstance()->setIntegerForKey(MAXSCORE, 0);
	UserDefault::getInstance()->setIntegerForKey(MINIGAMEMAXSCORE, 0);

};