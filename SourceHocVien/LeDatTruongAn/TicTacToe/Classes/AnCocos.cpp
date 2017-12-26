#include "AnCocos.h"

using namespace AnCocos;
std::string UI::Audio::offButtonString = "";
std::string UI::Audio::offButtonPressedString = "";
std::string UI::Audio::onButtonString = "";
std::string UI::Audio::onButtonPressedString = "";

UI::UI(){}

UI::~UI() {}

Vec2 UI::GetScreenCenter()
{
	return Vec2(Director::getInstance()->getVisibleSize().width / 2 + Director::getInstance()->getVisibleOrigin().x, Director::getInstance()->getVisibleSize().height / 2 + Director::getInstance()->getVisibleOrigin().y);
}

void UI::AddCentredBackground(const std::string &background, cocos2d::Layer* layer) {

	Sprite* sprite = Sprite::create(background);

	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2 + Director::getInstance()->getVisibleOrigin().x, Director::getInstance()->getVisibleSize().height / 2 + Director::getInstance()->getVisibleOrigin().y));

	layer->addChild(sprite);
}

void UI::AddAudioToggle(const std::string &onButton, const std::string &onButtonPressed, const std::string &offButton, const std::string &offButtonPressed, cocos2d::Layer *layer, int position)
{
	audioToggleButton = ui::Button::create(onButton, onButtonPressed);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	switch (position)
	{
	case AnCocos::UIButtonPosition::eBottomLeft:
		audioToggleButton->cocos2d::Node::setPosition(audioToggleButton->getContentSize().width / 2 + origin.x, audioToggleButton->getContentSize().height / 2 + origin.y);

		break;

	case AnCocos::UIButtonPosition::eBottomRight:
		audioToggleButton->cocos2d::Node::setPosition(visibleSize.width - audioToggleButton->getContentSize().width / 2 + origin.x, audioToggleButton->getContentSize().height / 2 + origin.y);

		break;

	case AnCocos::UIButtonPosition::eTopLeft:
		audioToggleButton->cocos2d::Node::setPosition(audioToggleButton->getContentSize().width / 2 + origin.x, visibleSize.height - audioToggleButton->getContentSize().height / 2 + origin.y);

		break;

	case AnCocos::UIButtonPosition::eTopRight:
		audioToggleButton->cocos2d::Node::setPosition(visibleSize.width - audioToggleButton->getContentSize().width / 2 + origin.x, visibleSize.height - audioToggleButton->getContentSize().height / 2 + origin.y);

		break;
	}

	audioToggleButton->addTouchEventListener(CC_CALLBACK_2(UI::AudioTouchEvent, this));

	layer->addChild(audioToggleButton, 10000);

	UI::Audio::offButtonString = offButton;
	UI::Audio::offButtonPressedString = offButtonPressed;
	UI::Audio::onButtonString = onButton;
	UI::Audio::onButtonPressedString = onButtonPressed;
}

void UI::AudioTouchEvent(Ref *sender, Widget::TouchEventType type)
{
	ui::Button *node = (ui::Button *)sender;

	std::string tempString;

	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		// code to handle when the button is first clicked

		break;

	case Widget::TouchEventType::MOVED:
		// code to handle when the user is moving their finger/cursor whilst clicking the button
		break;

	case Widget::TouchEventType::ENDED:
		tempString = UI::Audio::offButtonString;

		UI::Audio::offButtonString = UI::Audio::onButtonString;
		UI::Audio::onButtonString = tempString;

		tempString = UI::Audio::offButtonPressedString;

		UI::Audio::offButtonPressedString = UI::Audio::onButtonPressedString;
		UI::Audio::onButtonPressedString = tempString;

		node->loadTextures(UI::Audio::onButtonString, UI::Audio::onButtonPressedString);

		float volume;

		if (CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume() > 0.0f)
		{
			volume = 0.0f;
		}
		else
		{
			volume = 1.0f;
		}

		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);

		if (CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() > 0.0f)
		{
			volume = 0.0f;
		}
		else
		{
			volume = 1.0f;
		}

		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);

		break;

	case Widget::TouchEventType::CANCELED:
		// code to handle when the button click has been cancelled,  this is usually handled the same way as ENDED in most applications (e.g. another application takes control of the device)


		break;

	default:
		break;
	}
}