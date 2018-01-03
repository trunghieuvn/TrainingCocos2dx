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

	
	this->scheduleUpdate();
	return true;
}

void ObstacleCircel::update(float dt)
{
	
}
