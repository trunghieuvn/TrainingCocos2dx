#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
using namespace cocos2d;
using namespace CocosDenshion;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = HelloWorld::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(layer);
	return scene;
}
bool HelloWorld::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/*auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	edgeBody->setCollisionBitmask(1);
	edgeBody->setContactTestBitmask(true);*/

	this->schedule(schedule_selector(HelloWorld::createPipe), 0.005*visibleSize.width);
	return true;
}
void HelloWorld::createPipe(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	pipeUp = Sprite::create("pipe_up.png");// ong nuoc tren
	auto pipeUpphysic = PhysicsBody::createBox(pipeUp->getContentSize());
	pipeUpphysic->setCollisionBitmask(1);
	pipeUpphysic->setContactTestBitmask(true);
	pipeUpphysic->setDynamic(false);
	pipeUp->setPhysicsBody(pipeUpphysic);

	pipeDown = Sprite::create("pipe_down.png");// ong nuoc duoi
	auto pipeDownphysic = PhysicsBody::createBox(pipeDown->getContentSize());
	pipeDownphysic->setCollisionBitmask(1);
	pipeDownphysic->setContactTestBitmask(true);
	pipeDownphysic->setDynamic(false);
	pipeDown->setPhysicsBody(pipeDownphysic);

	auto random = CCRANDOM_0_1();
	if (random < 0.35)
	{
		random = 0.35;
	}
	else
	{
		if (random > 0.65)
		{
			random = 0.65;
		}
	}

	auto topPipePosition = (random * visibleSize.height) + (pipeUp->getContentSize().height / 2);
	pipeUp->setPosition(Vec2(visibleSize.width + pipeUp->getContentSize().width, topPipePosition));
	pipeDown->setPosition(Vec2(pipeUp->getPositionX(), topPipePosition - 86 - pipeUp->getContentSize().height));
	// 86 la khoang ho giua 2 ong nuoc de chim bay qua
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
