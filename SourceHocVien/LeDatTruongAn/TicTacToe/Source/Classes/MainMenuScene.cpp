#include "MainMenuScene.h"
#include "Frameworks.h"
#include "Definitions.h"
#include "GameScene.h"

Scene* MainMenuScene::createScene()
{
	auto scene = Scene::create();

	auto layer = MainMenuScene::create();

	scene->addChild(layer);

	return scene;
}

bool MainMenuScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
 

	Sprite* mySprite = Sprite::create(MAIN_MENU_SCENE_BACKGROUND_FILEPATH);
	mySprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(mySprite);

	Sprite* title = Sprite::create(MAIN_MENU_TITLE_FILEPATH);
	title->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));
	this->addChild(title);

	Button* playButton = Button::create(MAIN_MENU_PLAY_BUTTON, MAIN_MENU_PLAY_BUTTON_PRESSED);
	playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(playButton);

	playButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::touchEvent, this));
	playButton->setTag(TAG_PLAY_BUTTON);

	Sprite* playButtonOuter = Sprite::create(MAIN_MENU_PLAY_BUTTON_OUTER);
	playButtonOuter->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(playButtonOuter);

	CocosHelp::UI ui;

	ui.AddAudioToggle(SOUND_ON_BUTTON, SOUND_ON_BUTTON_PRESSED, SOUND_OFF_BUTTON, SOUND_OFF_BUTTON_PRESSED, this, CocosHelp::UIButtonPosition::eBottomRight);


	Button* achievementsButton = Button::create(ACHIEVEMENTS_BUTTON, ACHIEVEMENTS_BUTTON_PRESSED);
	achievementsButton->setPosition(CocosHelp::UI::GetScreenCorner(CocosHelp::eBottomLeft, achievementsButton));
	this->addChild(achievementsButton);
	achievementsButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::touchEvent, this));
	achievementsButton->setTag(TAG_ACHIEVEMENTS_BUTTON);

    return true;
}

void MainMenuScene::touchEvent(Ref* sender, Widget::TouchEventType type)
{
	Node* node = (Node*)sender;
	switch (type)
	{
	case cocos2d::ui::Widget::TouchEventType::BEGAN:
		break;
	case cocos2d::ui::Widget::TouchEventType::MOVED:
		break;
	case cocos2d::ui::Widget::TouchEventType::ENDED:
		if (TAG_PLAY_BUTTON == node->getTag())
		{
			Scene* scene = GameScene::createScene();
			TransitionFade * transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);
			Director::getInstance()->replaceScene(scene);
		}
		else if (TAG_ACHIEVEMENTS_BUTTON == node->getTag())
		{
			//
		}
		break;
	case cocos2d::ui::Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}
