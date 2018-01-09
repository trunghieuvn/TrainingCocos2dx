#include "BackgroundScrolling.h"

USING_NS_CC;

BackgroundScrolling* BackgroundScrolling::create()
{
	BackgroundScrolling *pRet = new BackgroundScrolling();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

bool BackgroundScrolling::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Vec2 pos1 = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	background1 = Background::create("background.png", "red_border.png", pos1);

	Vec2 pos2 = Vec2(background1->background->getPosition().x, background1->background->getPosition().y + background1->background->getContentSize().height);
	background2 = Background::create("background1.png", "red_border.png", pos2);

	Vec2 pos3 = Vec2(background1->background->getPosition().x, background2->background->getPosition().y + background2->background->getContentSize().height);
	background3 = Background::create("background2.png", "red_border.png", pos3);

	addChild(background1);
	addChild(background2);
	addChild(background3);
	
	return true;
}

void BackgroundScrolling::update(float dt)
{
}

void BackgroundScrolling::ChangeBackgroundScrolling(cocos2d::Node* target)
{
	
}

