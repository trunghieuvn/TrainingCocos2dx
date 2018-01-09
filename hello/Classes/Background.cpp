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
	{
		auto border = Sprite::create(nameTextureBorder);
		float scale = backgroundSize.height / border->getContentSize().height;
		border->setScaleY(scale);
		border->setPosition(Vec2(border->getContentSize().width / 2, pos.y));
		addChild(border);
	}
	{
		auto border = Sprite::create(nameTextureBorder);
		float scale = backgroundSize.height / border->getContentSize().height;
		border->setScaleY(scale);
		border->setPosition(Vec2(visibleSize.width - border->getContentSize().width / 2, pos.y));
		addChild(border);
	}

	return true;
}
