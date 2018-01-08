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
	//auto background2 = Sprite::create("background.png");
	//background2->setPosition(Vec2(background1->getPosition().x,
	//	background1->getPosition().y + background1->getContentSize().height));
	//
	addChild(background);

	Size backgroundSize = background->getContentSize();
	{
		auto border = Sprite::create(nameTextureBorder);
		float scale = backgroundSize.height / border->getContentSize().height;
		border->setScaleY(scale);
		border->setPosition(Vec2(border->getContentSize().width / 2, backgroundSize.height / 2));
		addChild(border);
	}
	{
		auto border = Sprite::create(nameTextureBorder);
		float scale = backgroundSize.height / border->getContentSize().height;
		border->setScaleY(scale);
		border->setPosition(Vec2(visibleSize.width - border->getContentSize().width / 2, backgroundSize.height / 2));
		addChild(border);
	}

	return true;
}
