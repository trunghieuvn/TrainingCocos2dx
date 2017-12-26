#include "MainMenuScene.h"
#include "Definitions.h"
#include "AnCocos.h"
#include "GameScene.h"

#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
using namespace ui;

USING_NS_CC;

Scene* MainMenuScene::createScene() {

	auto scene = Scene::create();

	auto layer = MainMenuScene::create();

	scene->addChild(layer);

	return scene;
}

bool MainMenuScene::init() {

	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto label = Label::createWithTTF("Main Menu", "fonts/Marker Felt.ttf", 24);

	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));

	this->addChild(label, 1);

	AnCocos::UI::AddCentredBackground(MAIN_MENU_BACKGROUND_FILEPATH, this);

	title = Sprite::create(MAIN_MENU_TITLE_FILEPATH);

	title->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.75 + origin.y));

	this->addChild(title);
	

	playButton = Button::create(MAIN_MENU_PLAY_BUTTON, MAIN_MENU_PLAY_BUTTON_PRESSED);

	playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.4 + origin.y));

	this->addChild(playButton);


	playButton->addTouchEventListener(CC_CALLBACK_2(MainMenuScene::touchEvent, this));

	playButton->setTag(TAG_MAIN_MENU_PLAY_BUTTON);

	playButtonOuter = Sprite::create(MAIN_MENU_PLAY_BUTTON_OUTER);

	playButtonOuter->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 0.4 + origin.y));

	this->addChild(playButtonOuter);

	AnCocos::UI ui;

	ui.AddAudioToggle(SOUND_ON_BUTTON, SOUND_ON_BUTTON_PRESSED, SOUND_OFF_BUTTON, SOUND_OFF_BUTTON_PRESSED, this, AnCocos::UIButtonPosition::eBottomRight);

	return true;
}

void MainMenuScene::touchEvent(Ref* sender, Widget::TouchEventType type) {
	 
	Node* node = (Node*)sender;

	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		if (TAG_MAIN_MENU_PLAY_BUTTON == node->getTag())
		{
			Scene* scene = GameScene::createScene();

			TransitionFade* transition = TransitionFade::create(SCENE_TRANSITION_TIME, scene);

			Director::getInstance()->replaceScene(transition);
		}
		break;
	case Widget::TouchEventType::CANCELED:
		break;
	default:
		break;
	}
}