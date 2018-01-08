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

	return true;
}

void BackgroundScrolling::update(float dt)
{
}
