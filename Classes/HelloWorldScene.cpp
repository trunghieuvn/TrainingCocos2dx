#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
using namespace cocos2d;
using namespace CocosDenshion;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    //return HelloWorld::create();
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = HelloWorld::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("game.plist");
	isFalling = true;
	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
	edgeBody->setCollisionBitmask(2);
	edgeBody->setContactTestBitmask(true);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(edgeBody);
	this->addChild(edgeNode);
	//gameStatus = GAME_READY;
	auto background = Sprite::createWithSpriteFrameName("bg.png");
	background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(background);
	auto gameLogo = Sprite::createWithSpriteFrameName("bird_logo.png");
	gameLogo->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + 100);
	gameLogo->setName("logo");
	this->addChild(gameLogo);
	auto birdAnimation = Animation::create();
	birdAnimation->setDelayPerUnit(0.2f);
	birdAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird1.png"));
	birdAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird2.png"));
	birdAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("bird3.png"));
	AnimationCache::getInstance()->addAnimation(birdAnimation, "birdAnimation");
	birdSprite = Sprite::create();
	birdSprite->setPosition(origin.x + visibleSize.width / 3, origin.y + visibleSize.height / 2);

	auto birdBody = PhysicsBody::createCircle(birdSprite->getContentSize().width / 2);
	birdBody->setDynamic(false);
	birdBody->setContactTestBitmask(1);
	birdBody->setContactTestBitmask(true);
	birdSprite->setPhysicsBody(birdBody);

	this->addChild(birdSprite);
	auto birdAnim = Animate::create(AnimationCache::getInstance()->animationByName("birdAnimation"));
	birdSprite->runAction(RepeatForever::create(birdAnim));// con chim bird di chuyen luc ban dau vao man play
	auto up = MoveBy::create(0.4f, Point(0, 8));
	auto upBack = up->reverse();
	swingAction = RepeatForever::create(Sequence::create(up, upBack, NULL));
	birdSprite->runAction(swingAction);
	land1 = Sprite::createWithSpriteFrameName("land.png");// nen dat
	land1->setPosition(Vec2(visibleSize.width / 2, land1->getContentSize().height / 2));
	//land1->setAnchorPoint(Point::ZERO);
	//land1->setPosition(Point::ZERO);
	this->addChild(land1, 10);  //ÖÃÓÚ×î¶¥²ã
	/*auto land2 = Sprite::createWithSpriteFrameName("land.png");
	land2->setAnchorPoint(Point::ZERO);
	land2->setPosition(Point::ZERO);
	this->addChild(land2, 10);
	*/
	Node *groundNode = Node::create();
	auto groundBody = PhysicsBody::createBox(Size(visibleSize.width, land1->getContentSize().height));
	groundBody->setDynamic(false);
	groundBody->setContactTestBitmask(2);
	groundBody->setContactTestBitmask(true);
	//groundNode->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	groundNode->setPhysicsBody(groundBody);
	groundNode->setPosition(origin.x + visibleSize.width / 2, land1->getContentSize().height / 2);
	this->addChild(groundNode);

	__String *tempScore = __String::createWithFormat("%i", score);
	label = Label::createWithTTF(tempScore->getCString(), "fonts/Marker Felt.ttf", 20);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));


	label->setColor(Color3B::BLUE);
	addChild(label);
	this->scheduleUpdate(); // update vi tri con chim bird
	this->schedule(schedule_selector(HelloWorld::createPipes), 0.0055*visibleSize.width);//update ong nuoc pipe
	//su kien man hinh
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::OntouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	// su kien va cham
	auto contacLister = EventListenerPhysicsContact::create();
	contacLister->onContactBegin = CC_CALLBACK_1(HelloWorld::OntacBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contacLister, this);

    return true;
}
void HelloWorld::gameStar()// toc do bird luc moi vao play
{
	this->getChildByName("logo")->setVisible(false);
	birdSprite->stopAction(swingAction);
	//birdSprite->getPhysicsBody()->setGravityEnable(true);
	birdSprite->getPhysicsBody()->setDynamic(true);

}
void HelloWorld::update(float dt)// update vi tri con chim
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	if (isFalling == true)
	{
		birdSprite->setPositionX(visibleSize.width / 3);
		birdSprite->setPositionY(birdSprite->getPositionY() - visibleSize.height*0.005);
	}
	else
	{
		birdSprite->setPositionX(visibleSize.width / 3);
		birdSprite->setPositionY(birdSprite->getPositionY() + visibleSize.height*0.005);
	}
	//----------- luc bird va cham nen dat------------------
	/*if (birdSprite->getPositionY() <= land1->getContentSize().height + 15)
	{
	birdSprite->stopAllActions();
	birdSprite->setRotation(70);
	birdSprite->getPhysicsBody()->setDynamic(false);
	SimpleAudioEngine::getInstance()->playEffect("die.mp3");
	this->unscheduleUpdate();
	gameOver(dt);
	}*/

}
//-------------va cham com chim va ong nuoc tinh diem ----------------
bool HelloWorld::OntacBegan(PhysicsContact &contact)
{
	PhysicsBody *a = contact.getShapeA()->getBody();
	PhysicsBody *b = contact.getShapeB()->getBody();
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 3 ||
		a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 1)
	{
		++score;
		__String *tempScore = __String::createWithFormat("%i", score);
		SimpleAudioEngine::getInstance()->playEffect("point.mp3");
		label->setString(tempScore->getCString());
	}
	else
	{
		if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 2 ||
			a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 1)
		{
			CCLOG("game-over");
			
		}
	}
	return true;
}
bool HelloWorld::OntouchBegan(Touch *touch, Event *event)
{
	isFalling = false;
	gameStar();
	SimpleAudioEngine::getInstance()->playEffect("wing.mp3");
	this->scheduleOnce(schedule_selector(HelloWorld::Ontop), 0.4);
	return true;
}
void HelloWorld::Ontop(float dt)
{
	isFalling = true;
}

void HelloWorld::gameOver(float dt)
{
	birdSprite->stopAllActions();
	birdSprite->setRotation(70);
	birdSprite->getPhysicsBody()->setDynamic(false);
	SimpleAudioEngine::getInstance()->playEffect("die.mp3");
	this->unscheduleUpdate();// stop update vi tri con chim
	pipeUp->stopAllActions();
	pipeDown->stopAllActions();
}

void HelloWorld::createPipes(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	//---------ong nuoc tren ----------------
	pipeUp = Sprite::create("pipe_up.png");
	auto pipeUpPhysic = PhysicsBody::createBox(pipeUp->getContentSize());
	pipeUpPhysic->setCollisionBitmask(2);
	pipeUpPhysic->setContactTestBitmask(true);
	pipeUpPhysic->setDynamic(false);
	pipeUp->setPhysicsBody(pipeUpPhysic);
	//---------ong nuoc duoi ----------------
	pipeDown = Sprite::create("pipe_down.png");
	auto pipeDownPhysic = PhysicsBody::createBox(pipeDown->getContentSize());
	pipeDownPhysic->setCollisionBitmask(2);
	pipeDownPhysic->setContactTestBitmask(true);
	pipeDownPhysic->setDynamic(false);
	pipeDown->setPhysicsBody(pipeDownPhysic);

	auto random = CCRANDOM_0_1();

	if (random <0.4)
	{
		random = 0.4;
	}
	else if (random > 0.6)
	{
		random = 0.6;
	}

	auto topPipePosition = (random * visibleSize.height) + (pipeUp->getContentSize().height / 2);
	pipeUp->setPosition(Vec2(visibleSize.width + pipeUp->getContentSize().width, topPipePosition));
	pipeDown->setPosition(Vec2(pipeUp->getPositionX(), topPipePosition - 86 - pipeUp->getContentSize().height));
	this->addChild(pipeUp);
	this->addChild(pipeDown);

	auto pipeUpAction = MoveBy::create(0.01 * visibleSize.width, Vec2(-visibleSize.width * 1.5, 0));
	auto pipeDownAction = MoveBy::create(0.01 * visibleSize.width, Vec2(-visibleSize.width * 1.5, 0));
	pipeUp->runAction(pipeUpAction);
	pipeDown->runAction(pipeDownAction);

	auto pointNode = Node::create();// tao 1 node nam giua 2 ong nuoc pipe de tinh diem luc va cham voi con chim pipe
	pointNode->setPosition(Vec2(pipeUp->getPositionX(),
		pipeUp->getPositionY() - (pipeUp->getContentSize().height / 2) - 43));

	auto pointBody = PhysicsBody::createBox(Size(1, 86));
	pointBody->setCollisionBitmask(3);
	pointBody->setContactTestBitmask(true);
	pointBody->setDynamic(false);
	pointNode->setPhysicsBody(pointBody);
	auto pointNodeAction = MoveBy::create(0.01* visibleSize.width, Vec2(-visibleSize.width * 1.5, 0));
	pointNode->runAction(pointNodeAction);
	this->addChild(pointNode);
}


