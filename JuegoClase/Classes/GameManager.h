#pragma once

#include "cocos2d.h"
#include "GameWrapper.h"

#define LEVEL "level"
#define BGVOLUME "bgvolume"
#define SFXVOLUME "effectvolume"
#define MAXSCORE "maxscore"
#define MINIGAMEMAXSCORE "mgms"


class GameWrapper;

class GameManager {
private:
	GameManager();
	static GameManager* _instance;
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

public:

	CC_SYNTHESIZE(float, _bgVolume, BgVolume);
	CC_SYNTHESIZE(float , _effectsVolume, EffectsVolume);
	CC_SYNTHESIZE(int, _playerScore, PlayerScore);
	void saveSetting();
	void saveMaxScore(int score);
	int getMaxScore();
	static GameManager* getInstance();
	void saveGame(int tag);
	int getNextLevel();


	void saveMiniGameScore(int score);
	int getMiniGameScore();

	void resetScore();

	inline static GameWrapper* wrapper = GameWrapper::getInstance();
	
	
	~GameManager();
	const static int NUM_LEVELS = 9;
};

