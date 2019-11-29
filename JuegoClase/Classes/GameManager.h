#pragma once

#include "cocos2d.h"
#include "GameWrapper.h"
//#include "TranslationEngine.h"

#include <vector>

#define LEVEL "level"
#define BGVOLUME "bgvolume"
#define SFXVOLUME "effectvolume"
#define MAXSCORE "maxscore"
#define MINIGAMEMAXSCORE "mgms"
#define DIFFICULTY "diflevel"
#define DIFMODE "dificultycategory"
#define LANGUAGE "lang"
#define SCORESALMACENADOS "SCORES"
#define SCORE1 "S1"
#define SCORE2 "S2"
#define SCORE3 "S3"
#define SCORE4 "S4"
#define SCORE5 "S5"
#define MINISC "Si"
#define MINISCORE1 "MS1"
#define MINISCORE2 "MS2"
#define MINISCORE3 "MS3"
#define MINISCORE4 "MS4"
#define MINISCORE5 "MS5"
#define RAPIDIN "n1"
#define MCDONALDS "n2"

class GameWrapper;

class GameManager {
private:
	GameManager();
	static GameManager* _instance;
	GameManager(GameManager const&) = delete;
	void operator=(GameManager const&) = delete;

	int DifCategory;

public:

	std::vector<int> fiveScores;
	std::vector<int> fiveMiniScores;
	int scoresAlmacenados;
	int miniScoresAlmacenados;


	CC_SYNTHESIZE(float, _bgVolume, BgVolume);
	CC_SYNTHESIZE(float , _effectsVolume, EffectsVolume);
	CC_SYNTHESIZE(float, _difCategory, Difficulty);
	CC_SYNTHESIZE(int, _difMode, DifiMode);
	CC_SYNTHESIZE(int, _playerScore, PlayerScore);
	CC_SYNTHESIZE(int, _currentMusicTag, CurrentMusicTag);
	CC_SYNTHESIZE(std::string, _lang, Language);
	CC_SYNTHESIZE(bool, _nave1, UnlockRapidin);
	CC_SYNTHESIZE(bool, _nave4, UnlockMcDonalds);


	void saveSetting();
	void saveMaxScore(int score);
	int getMaxScore();
	static GameManager* getInstance();
	void saveGame(int tag);
	int getNextLevel();

	void updateScores(int score);
	void updateMiniScores(int score);


	void saveMiniGameScore(int score);
	int getMiniGameScore();


	void unlockRapidin();
	void unlockMcDonalds();

	void lockRapidin();
	void lockMcDonalds();

	void resetScore();

	inline static GameWrapper* wrapper = GameWrapper::getInstance();
	
	
	~GameManager();
	const static int NUM_LEVELS = 9;
};

