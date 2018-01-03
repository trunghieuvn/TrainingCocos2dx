#include "InGameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* InGameScene::createScene()
{
    return InGameScene::create();
}

// on "init" you need to initialize your instance
bool InGameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Background
	auto background = Sprite::create("background.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height/2));
	addChild(background);

	auto border = Sprite::create("red_border.png");


	// Add Event Touch 
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(InGameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(InGameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(InGameScene::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(InGameScene::onTouchCancelled, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	// Add Event Touch End
	
	Vec2 pointStart = Vec2(320, 250);
	auto begin = Sprite::create("begin.png");
	begin->setPosition(pointStart);
	addChild(begin);

	player = Player::create(pointStart);
	player->mState = PlayerState::Rotate;
	addChild(player);
    return true;
}


// called when the touch first begins
bool InGameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	player->mState = PlayerState::Orientation;
	return true; // true if the function wants to swallow the touch
}

// called when the user moves their finger
void InGameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{

}

// called when the user lifts their finger
void InGameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	player->mState = PlayerState::Stationary;

	Point touchPoint = touch->getLocation();
	CCLOG("Touch %f - %f", touchPoint.x, touchPoint.y);
	
	player->MoveTo(touchPoint);
}

// called when the device goes to another application such as a phone call
void InGameScene::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{

}
