#include "ObstacleCircel.h"

USING_NS_CC;

ObstacleCircel* ObstacleCircel::create()
{
	ObstacleCircel *pRet = new ObstacleCircel();
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
bool ObstacleCircel::init()
{
	Vec2 pointStart = Vec2(320, 250);

	auto layer = Layer::create();

	circle_background = Sprite::create("circle_background.png");

	auto circle_foreground = Sprite::create("circle_foreground.png");
	auto circle_background_in = Sprite::create("circle_background_in.png");
	circle_foreground_on = ProgressTimer::create(Sprite::create("circle_foreground_on.png"));
	circle_foreground_on->setType(ProgressTimer::Type::RADIAL);
	circle_foreground_on->setPercentage(0);

	layer->addChild(circle_background);
	layer->addChild(circle_foreground);
	layer->addChild(circle_foreground_on);
	layer->addChild(circle_background_in);

	addChild(layer);

	this->scheduleUpdate();

	parent = 0;
	isCollision = false;
	return true;
}

void ObstacleCircel::update(float dt)
{
	if (!isCollision || parent++ >= 100)
	{
		return;
	}
	circle_foreground_on->setPercentage(parent);
}
