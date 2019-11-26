#include "GameWrapper.h"


GameWrapper* GameWrapper::instance = nullptr;



GameWrapper* GameWrapper::getInstance() {
	if (instance == nullptr)
		instance = new GameWrapper();
	return instance;
}

void GameWrapper::setPlayer(Player* pl) noexcept {
	_player = pl;
}

Player* GameWrapper::getPlayer() {
	return _player;
}

