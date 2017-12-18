#include "SplashScene.h"
#include "Definitions.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
	auto scene = Scene::create();

	auto layer = SplashScene::create();

	scene->addChild(layer);

	return scene;
}

bool SplashScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* mySprite = Sprite::create(SPLASH_SCENE_BACKGROUND_FILEPATH);
	mySprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(mySprite);
	
	// Lên lịch 1 lần 
	scheduleOnce(schedule_selector(SplashScene::SwitchToMainMenu), SPLASH_SCENE_SHOW_TIME);

    return true;
}

void SplashScene::SwitchToMainMenu(float dt)
{
	Scene* scene = MainMenuScene::createScene();
	TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
	Director::getInstance()->replaceScene(transition);
}