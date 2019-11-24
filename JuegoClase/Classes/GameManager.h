#pragma once

#include "cocos2d.h"
#define LEVEL "level"
#define BGVOLUME "bgvolume"
#define SFXVOLUME "effectvolume"
#define MAXSCORE "maxscore"

#include "Player.h"


class GameManager {
private:
	GameManager();
	static GameManager* _instance;
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

public:

	CC_SYNTHESIZE(int, _bgVolume, BgVolume);
	CC_SYNTHESIZE(int, _effectsVolume, EffectsVolume);
	CC_SYNTHESIZE(int, _playerScore, PlayerScore);
	void saveSetting();
	void saveMaxScore(int score);
	int getMaxScore();
	static GameManager* getInstance();
	void saveGame(int tag);
	int getNextLevel();

	~GameManager();
	const static int NUM_LEVELS = 1;

};

