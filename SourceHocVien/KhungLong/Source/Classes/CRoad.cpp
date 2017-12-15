#include "CRoad.h"
#include "Definitions.h"

USING_NS_CC;

Road* Road::create(const std::string &filename)
{
	Road *pRet = new Road();
	if (pRet && pRet->init(filename))
	{
		pRet->autorelease();
	}
	else
	{
		delete pRet;
		pRet = NULL;
	}
	return pRet;

}

bool Road::init(const std::string &filename)
{
	if (!Sprite::initWithFile(filename))
	{
		return false;
	}

	spRoad_1 = Sprite::create("road_1.png");
	spRoad_1->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	spRoad_1->setPosition(Vec2(0, GROUND_HEIGHT));
	spRoad_2 = Sprite::create("road_2.png");
	spRoad_2->setPosition(Vec2(spRoad_1->getPositionX() + spRoad_1->getContentSize().width - 5, GROUND_HEIGHT));
	spRoad_2->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	this->addChild(spRoad_1, ROAD_ZORDER);
	this->addChild(spRoad_2, ROAD_ZORDER);

	return true;
}


void Road::updateRoad(float dt)
{

}

Road::Road()
{
}

Road ::~Road()
{
}