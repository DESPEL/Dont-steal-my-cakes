#pragma once

#include "cocos2d.h"
#include "GameWrapper.h"
//#include "TranslationEngine.h"

#define LEVEL "level"
#define BGVOLUME "bgvolume"
#define SFXVOLUME "effectvolume"
#define MAXSCORE "maxscore"
#define MINIGAMEMAXSCORE "mgms"
#define DIFFICULTY "diflevel"
#define DIFMODE "dificultycategory"
#define LANGUAGE "lang"


class GameWrapper;

class GameManager {
private:
	GameManager();
	static GameManager* _instance;
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

	int DifCategory;

public:




	CC_SYNTHESIZE(float, _bgVolume, BgVolume);
	CC_SYNTHESIZE(float , _effectsVolume, EffectsVolume);
	CC_SYNTHESIZE(float, _difCategory, Difficulty);
	CC_SYNTHESIZE(int, _difMode, DifiMode);
	CC_SYNTHESIZE(int, _playerScore, PlayerScore);
	CC_SYNTHESIZE(int, _currentMusicTag, CurrentMusicTag);
	CC_SYNTHESIZE(std::string, _lang, Language);


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

