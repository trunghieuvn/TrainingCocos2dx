#include "Background.h"

USING_NS_CC;

Background* Background::create(const char* nameTextureBackground, const char* nameTextureBorder, cocos2d::Vec2 pos)
{
	Background *pRet = new Background();
	if (pRet && pRet->init(nameTextureBackground, nameTextureBorder, pos))
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

bool Background::init(const char* nameTextureBackground, const char* nameTextureBorder, cocos2d::Vec2 pos)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	background = Sprite::create(nameTextureBackground);
	background->setPosition(pos);
	addChild(background);

	Size backgroundSize = background->getContentSize();
	
	borderLeft = Sprite::create(nameTextureBorder);
	float scale = backgroundSize.height / borderLeft->getContentSize().height;
	borderLeft->setScaleY(scale);
	borderLeft->setPosition(Vec2(borderLeft->getContentSize().width / 2, pos.y));
	addChild(borderLeft);

	borderRight = Sprite::create(nameTextureBorder);
	borderRight->setScaleY(scale);
	borderRight->setPosition(Vec2(visibleSize.width - borderRight->getContentSize().width / 2, pos.y));
	addChild(borderRight);

	return true;
}
