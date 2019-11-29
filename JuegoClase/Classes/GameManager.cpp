#include "GameManager.h"

USING_NS_CC;

GameManager* GameManager::_instance = nullptr;

GameManager::GameManager() :_playerScore(0) {
	_bgVolume = UserDefault::getInstance()->getIntegerForKey(BGVOLUME, 30);
	_effectsVolume = UserDefault::getInstance()->getIntegerForKey(SFXVOLUME, 40);
	_difCategory = UserDefault::getInstance()->getIntegerForKey(DIFFICULTY, 50);
	_difMode = UserDefault::getInstance()->getIntegerForKey(DIFMODE, 2);
	_lang = UserDefault::getInstance()->getStringForKey(LANGUAGE, "ES_MX");
	miniScoresAlmacenados = UserDefault::getInstance()->getIntegerForKey(MINISC, 0);

	//int actualSize = UserDefault::getInstance()->getIntegerForKey(MINISC, 0);

	//if (miniScoresAlmacenados >= 1) {
		fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE1, 0));
		//if (miniScoresAlmacenados >= 2) {
			fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE2, 0));
			//if (miniScoresAlmacenados >= 3) {
				fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE3, 0));
				//if (miniScoresAlmacenados >= 4) {
					fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE4, 0));
					//if (miniScoresAlmacenados >= 5) {
						fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE5, 0));
					//}
				//}
			//}
		//}
	//}

	//if (scoresAlmacenados >= 1) {
		fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE1, 0));
		//if (scoresAlmacenados >= 2) {
			fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE2, 0));
			//if (scoresAlmacenados >= 3) {
				fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE3, 0));
				//if (scoresAlmacenados >= 4) {
					fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE4, 0));
					//if (scoresAlmacenados >= 5) {
						fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE5, 0));
					//}
				//}
			//}
		//}
	//}


}

GameManager::~GameManager() {}

void GameManager::saveSetting() {
	UserDefault::getInstance()->setIntegerForKey(BGVOLUME, _bgVolume);
	UserDefault::getInstance()->setIntegerForKey(SFXVOLUME, _effectsVolume);
	UserDefault::getInstance()->setStringForKey(LANGUAGE, _lang);
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

void GameManager::updateMiniScores(int score) {
	int actualSize = UserDefault::getInstance()->getIntegerForKey(MINISC, 0);
	

	if (actualSize < 1) {
		UserDefault::getInstance()->setIntegerForKey(MINISCORE1, score);
	}

	//if (actualSize >= 1) {
		fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE1, 0));
		//if (actualSize >= 2) {
			fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE2, 0));
			//if (actualSize >= 3) {
				fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE3, 0));
				//if (actualSize >= 4) {
					fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE4, 0));
					//if (actualSize >= 5) {
						fiveMiniScores.push_back(UserDefault::getInstance()->getIntegerForKey(MINISCORE5, 0));
					//}
				//}
			//}
		//}
	//}

	int newIndex = 10;
	for (int i = 4; i >= 0; i--) {
		if (i - 1 >= 0) {
			if (score > fiveMiniScores.at(i) && score < fiveMiniScores.at(i - 1))
				newIndex = i;
		}

		else if (i == 0 && score > fiveMiniScores.at(0)) {
			newIndex = 0;
		}

		/*else if (miniScoresAlmacenados < 5) {
			miniScoresAlmacenados++;
			UserDefault::getInstance()->setIntegerForKey(MINISC, miniScoresAlmacenados);
		}*/
	}

	fiveMiniScores.insert(fiveMiniScores.begin() +newIndex, score);

	if (newIndex <= 4) {
		UserDefault::getInstance()->setIntegerForKey(MINISCORE1, fiveMiniScores.at(0));
		UserDefault::getInstance()->setIntegerForKey(MINISCORE2, fiveMiniScores.at(1));
		UserDefault::getInstance()->setIntegerForKey(MINISCORE3, fiveMiniScores.at(2));
		UserDefault::getInstance()->setIntegerForKey(MINISCORE4, fiveMiniScores.at(3));
		UserDefault::getInstance()->setIntegerForKey(MINISCORE5, fiveMiniScores.at(4));
	}

}


void GameManager::updateScores(int score) {
	
	int actualSize = UserDefault::getInstance()->getIntegerForKey(SCORESALMACENADOS, 0);


	if(actualSize < 1) {
		UserDefault::getInstance()->setIntegerForKey(SCORE1, score);
	}

	//if (actualSize >= 1) {
		fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE1, 0));
		//if (actualSize >= 2) {
			fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE2, 0));
			//if (actualSize >= 3) {
				fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE3, 0));
				//if (actualSize >= 4) {
					fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE4, 0));
					//if (actualSize >= 5) {
						fiveScores.push_back(UserDefault::getInstance()->getIntegerForKey(SCORE5, 0));
					//}
				//}
			//}
		//}
	//}

	int newIndex = 10;
	for (int i = 4; i >= 0 ; i--) {
		if (i - 1 >= 0) {
			if (score > fiveScores.at(i) && score < fiveScores.at(i - 1))
				newIndex = i;
		}

		else if (i == 0 && score > fiveScores.at(0)) {
			newIndex = 0;
		}

		/*if (scoresAlmacenados < 5) {
			scoresAlmacenados++;
			UserDefault::getInstance()->setIntegerForKey(SCORESALMACENADOS, scoresAlmacenados);
		}*/
	}

	fiveScores.insert(fiveScores.begin() + newIndex, score);

	if (newIndex <= 4) {
		UserDefault::getInstance()->setIntegerForKey(SCORE1, fiveScores.at(0));
		UserDefault::getInstance()->setIntegerForKey(SCORE2, fiveScores.at(1));
		UserDefault::getInstance()->setIntegerForKey(SCORE3, fiveScores.at(2));
		UserDefault::getInstance()->setIntegerForKey(SCORE4, fiveScores.at(3));
		UserDefault::getInstance()->setIntegerForKey(SCORE5, fiveScores.at(4));
	}

};