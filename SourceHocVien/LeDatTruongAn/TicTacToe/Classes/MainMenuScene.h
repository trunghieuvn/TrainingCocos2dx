#pragma once

#include "cocos2d.h"
#include "extensions\cocos-ext.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

USING_NS_CC_EXT;
using namespace ui;

class MainMenuScene : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(MainMenuScene);

private:

	cocos2d::Sprite* title;

	cocos2d::ui::Button* playButton;

	cocos2d::Sprite* playButtonOuter;

	void touchEvent(Ref* sender, Widget::TouchEventType type);

};
