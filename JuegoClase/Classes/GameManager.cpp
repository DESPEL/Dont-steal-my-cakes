#include "GameManager.h"

USING_NS_CC;

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager() :_playerScore(0) {
	_bgVolume = UserDefault::getInstance()->getIntegerForKey(BGVOLUME, 30);
	_effectsVolume = UserDefault::getInstance()->getIntegerForKey(SFXVOLUME, 40);
	_difCategory = UserDefault::getInstance()->getIntegerForKey(DIFFICULTY, 50);
	_difMode = UserDefault::getInstance()->getIntegerForKey(DIFMODE, 2);
}

GameManager::~GameManager() {}

void GameManager::saveSetting() {
	UserDefault::getInstance()->setIntegerForKey(BGVOLUME, _bgVolume);
	UserDefault::getInstance()->setIntegerForKey(SFXVOLUME, _effectsVolume);
	UserDefault::getInstance()->setIntegerForKey(DIFFICULTY, _difCategory);

	int temp_dif_mode;
	if (this->getDifficulty() >= 0 && this->getDifficulty() <= 33) {
		temp_dif_mode = 1;
	}
	else if (this->getDifficulty() >= 34 && this->getDifficulty() <= 66) {
		temp_dif_mode = 2;
	}
	else {
		temp_dif_mode = 3;
	}
	
	this->setDifiMode(temp_dif_mode);

	UserDefault::getInstance()->setIntegerForKey(DIFMODE, _difMode);
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