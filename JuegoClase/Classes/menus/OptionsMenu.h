#pragma once

#include "MotherMenu.h"
#include "ui/CocosGUI.h"

class OptionsMenu : public MotherMenu {
private:
	std::ostringstream _ostr;
	cocos2d::ui::Slider* _effectsVolume;
	cocos2d::ui::Slider* _backGroundVolume;
	cocos2d::Label* _backGroundVolumeLabel;
	cocos2d::Label* _effectsVolumeLabel;
	void actionButtonBack();
	void actionBackGroundVolumeSlider();
	void actionEffectsVolumeSlider();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(OptionsMenu);

};

