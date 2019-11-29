#pragma once

#include "MotherMenu.h"
#include "ui/CocosGUI.h"

class OptionsMenu : public MotherMenu {
private:
	std::ostringstream _ostr;
	cocos2d::ui::Slider* _effectsVolume;
	cocos2d::ui::Slider* _backGroundVolume;
	cocos2d::ui::Slider* dificulty;
	cocos2d::Label* _backGroundVolumeLabel;
	cocos2d::Label* _effectsVolumeLabel;
	cocos2d::Label* dificulty_Label;

	cocos2d::ui::Button* us;
	cocos2d::ui::Button* mex;

	void actionButtonBack();
	void actionBackGroundVolumeSlider();
	void actionEffectsVolumeSlider();

	void langmex();
	void langus();

public:
	virtual bool init();
	static cocos2d::Scene* createScene();
	CREATE_FUNC(OptionsMenu);
	
};

