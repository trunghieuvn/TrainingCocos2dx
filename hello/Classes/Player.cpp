#include "Player.h"

USING_NS_CC;

Player* Player::create()
{
	Player *pRet = new Player();
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
bool Player::init() 
{
	Vec2 pointStart = Vec2(320, 250);

	ball = Sprite::create("main.png");
	ball->setPosition(pointStart);
	addChild(ball);
	
	layerArrow = Layer::create();
	addChild(layerArrow);

	auto sprite = Sprite::create("arrow_2.png");
	sprite->setPosition(Vec2(pointStart.x, pointStart.y
		+ sprite->getContentSize().height / 2 
		+ ball->getContentSize().height));
	layerArrow->addChild(sprite);

	directionArrow = ProgressTimer::create(Sprite::create("arrow_1.png"));
	directionArrow->setType(ProgressTimer::Type::BAR);
	directionArrow->setMidpoint(Vec2(0, 0));
	directionArrow->setBarChangeRate(Vec2(0, 1));

	directionArrow->setPercentage(0);

	directionArrow->setPosition(Vec2(pointStart.x, pointStart.y 
		+ sprite->getContentSize().height / 2 
		+ ball->getContentSize().height ));
	layerArrow->addChild(directionArrow);

	layerArrow->setAnchorPoint(Vec2(0.5, 0));

	parent = 0;
	num = 1;
	rotate = 0;
	rotateDirection = 1;
	layerArrow->setRotationX(rotate);
	this->scheduleUpdate();
	return true;
}
void Player::MoveTo(cocos2d::Vec2 point)
{
	auto move = MoveTo::create(0.15f, point);
	auto move_ease_in = EaseOut::create(move->clone(), 2.0f);
	this->ball->runAction(move_ease_in);
}

void Player::update(float dt)
{
	parent += num;
	if (parent == 100)
	{
		num = -1;
	}
	if (parent == 0)
	{
		num = 1;
	}
	directionArrow->setPercentage(parent);

	if (rotate <= -20)
	{
		rotateDirection = 1;
	}
	if (rotate >= 20)
	{
		rotateDirection = -1;
	}
    
	rotate = layerArrow->getRotationX();
	rotate += rotateDirection * 1;
	CCLOG("angle: %f", rotate);
	layerArrow->setRotationX(rotate);
}
