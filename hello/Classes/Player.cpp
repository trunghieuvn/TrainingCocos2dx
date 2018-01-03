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
	layerArrow->setAnchorPoint(Vec2(0, 0));

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
	layerArrow->setRotation(rotate);
	mState = PlayerState::Rotate;

	this->scheduleUpdate();
	return true;
}

void Player::Move(cocos2d::Vec2 point)
{
	auto move_ease_in = EaseOut::create(MoveBy::create(0.15f, Vec2(point.x, point.y)), 2.0f);

	// auto end = CallFunc::create(this, CC_CALLFUNC_SELECTOR(Player::doneMove));
	auto doneMove = CallFunc::create([this, point]() 
	{
		mState = PlayerState::Rotate;
		parent = 0;
		directionArrow->setPercentage(parent);
	});

	auto action = Sequence::create(move_ease_in, doneMove, nullptr);
	this->runAction(action);
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
		if (rotate <= -45)
		{
			rotateDirection = 1;
		}
		if (rotate >= 45)
		{
			rotateDirection = -1;
		}

		rotate = layerArrow->getRotationX();
		rotate += rotateDirection * 1;
		layerArrow->setRotation(rotate);
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
