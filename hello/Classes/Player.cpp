#include "Player.h"

USING_NS_CC;

Player* Player::create(cocos2d::Vec2 pos)
{
	Player *pRet = new Player();
	if (pRet && pRet->init(pos))
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
bool Player::init(cocos2d::Vec2 pointStart)
{
	ball = Sprite::create("main.png");
	ball->setPosition(pointStart);
	addChild(ball);

	layerArrow = Layer::create();
	layerArrow->setPosition(pointStart);
	layerArrow->setAnchorPoint(Vec2(0.5, 0));

	addChild(layerArrow);

	auto sprite = Sprite::create("arrow_2.png");
	sprite->setPosition(Vec2(0,
		sprite->getContentSize().height / 2
		+ ball->getContentSize().height
	));
	layerArrow->addChild(sprite);

	directionArrow = ProgressTimer::create(Sprite::create("arrow_1.png"));
	directionArrow->setType(ProgressTimer::Type::BAR);
	directionArrow->setMidpoint(Vec2(0, 0));
	directionArrow->setBarChangeRate(Vec2(0, 1));

	directionArrow->setPercentage(0);

	directionArrow->setPosition(Vec2(0,
		sprite->getContentSize().height / 2
		+ ball->getContentSize().height
	));

	layerArrow->addChild(directionArrow);


	parent = 0;
	num = 1;
	rotate = 0;
	rotateDirection = 1;
	layerArrow->setRotationX(rotate);
	mState = PlayerState::Rotate;
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
	switch (mState)
	{
	case Stationary:
		break;
	case Rotate:
	{
		// Rotate
		if (rotate <= -40)
		{
			rotateDirection = 1;
		}
		if (rotate >= 40)
		{
			rotateDirection = -1;
		}

		rotate = layerArrow->getRotationX();
		rotate += rotateDirection * 1;
		CCLOG("angle: %f", rotate);
		layerArrow->setRotationX(rotate);
		break;
	}
	case Orientation:
	{
		// Arrow direction bar
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
		break;
	}
	default:
		break;
	}
}
