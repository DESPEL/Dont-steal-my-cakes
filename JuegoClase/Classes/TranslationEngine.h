#pragma once

#include <Windows.h>
#include <fstream>
#include <map>
#include <string>
//#include "cocos2d.h"

class TranslationEngine
{
private: 
	TranslationEngine();

	static TranslationEngine* globalEngine;
	inline static std::string defaultLanguage = "ES_MX";
	std::string language;

	std::map<std::string, std::string> langStrings;
public:

	static TranslationEngine* getInstance();

	void setLanguage(std::string language);

	std::string getLanguage() {
		return language;
	}

	std::string get(std::string strname) {
		return langStrings[strname];
	}

	std::string operator[](std::string strname) {
		return langStrings[strname];
	}

};