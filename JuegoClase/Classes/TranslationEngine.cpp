#include "TranslationEngine.h"

TranslationEngine* TranslationEngine::globalEngine = nullptr;

TranslationEngine::TranslationEngine() {
	CreateDirectory(L"Langs", NULL);

}

TranslationEngine* TranslationEngine::getInstance() {
	if (globalEngine == nullptr) {
		globalEngine = new TranslationEngine();
		std::ifstream llang("Langs\\lastlang");
		std::string lastl;
		llang >> lastl;
		llang.close();
		if (lastl != "")
			globalEngine->setLanguage(lastl);
		else
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
	std::ofstream llang("Langs\\lastlang");
	llang << lang;
	llang.close();
}