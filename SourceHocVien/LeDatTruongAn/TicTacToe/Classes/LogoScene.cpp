#include "LogoScene.h"
#include "AnCocos.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* LogoScene::createScene() {

	auto scene = Scene::create();

	auto layer = LogoScene::create();

	scene->addChild(layer);

	return scene;
}

bool LogoScene::init() {

	if (!Layer::init())
	{
		return false;
	}

	AnCocos::UI::AddCentredBackground(LOGO_SCENE_BACKGROUND_FILEPATH, this);
	
	scheduleOnce(schedule_selector(LogoScene::SwitchToMainMenu), LOGO_SCENE_SHOW_TIME);

	return true;
}

void LogoScene::SwitchToMainMenu(float dt) {

	Scene* scene = MainMenuScene::createScene();

	TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);

	Director::getInstance()->replaceScene(transition);
}