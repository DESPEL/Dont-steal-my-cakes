#include "TranslationEngine.h"

TranslationEngine* TranslationEngine::globalEngine = nullptr;

TranslationEngine::TranslationEngine() {
	CreateDirectory(L"Langs", NULL);
}

TranslationEngine* TranslationEngine::getInstance() {
	if (globalEngine == nullptr) {
		globalEngine = new TranslationEngine();
		globalEngine->setLanguage(defaultLanguage);
	}
	return globalEngine;
}

void TranslationEngine::setLanguage(std::string lang) {
	langStrings.clear();
	std::fstream langreader;
	langreader.open(".\\Langs\\" + lang);
	if (!langreader.is_open())
		throw "El lenguaje seleccionado no existe";
	std::string key;
	std::string val;
	while (getline(langreader, key, '~') && getline(langreader, val))
		langStrings[key] = val;
	language = lang;
}
