#include "HelloWorldScene.h"

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


	this->schedule(schedule_selector(HelloWorld::createPipe), 0.0055*visibleSize.width);
	return true;

}
void HelloWorld::createPipe(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	pipeUp = Sprite::create("pipe_up.png");
	auto pipeUpphysic = PhysicsBody::createBox(pipeUp->getContentSize());
	pipeUpphysic->setCollisionBitmask(1);
	pipeUpphysic->setContactTestBitmask(true);
	pipeUpphysic->setDynamic(false);
	pipeUp->setPhysicsBody(pipeUpphysic);

	pipeDown = Sprite::create("pipe_down.png");
	auto pipedownphysic = PhysicsBody::createBox(pipeDown->getContentSize());
	pipedownphysic->setCollisionBitmask(1);
	pipedownphysic->setContactTestBitmask(true);
	pipedownphysic->setDynamic(false);
	pipeDown->setPhysicsBody(pipedownphysic);

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
	auto topPipe = visibleSize.height*random + pipeUp->getContentSize().height / 2;
	pipeUp->setPosition(Vec2(visibleSize.width + pipeUp->getContentSize().width, topPipe));
	pipeDown->setPosition(Vec2(pipeUp->getPositionX(), topPipe - pipeUp->getContentSize().height - 86));
	this->addChild(pipeUp);
	this->addChild(pipeDown);
	auto pipeUpmove = MoveBy::create(0.01*visibleSize.width, Vec2(-visibleSize.width* 1.5, 0));
	auto pipeDownmove = MoveBy::create(0.01*visibleSize.width, Vec2(-visibleSize.width * 1.5, 0));
	pipeUp->runAction(pipeUpmove);
	pipeDown->runAction(pipeDownmove);

	// tao 1 node mam giua 2 ong nuoc de tinh diem khi va cham voi bird

	auto pointNode = Node::create();
	pointNode->setPosition(pipeUp->getPositionX(), pipeUp->getPositionY()
		- pipeUp->getContentSize().height / 2 - 43);
	auto pointPhysic = PhysicsBody::createBox(Size(1, 86));
	pointPhysic->setCollisionBitmask(2);
	pointPhysic->setContactTestBitmask(true);
	pointPhysic->setDynamic(false);
	pointNode->setPhysicsBody(pointPhysic);
	auto pointMove = MoveBy::create(0.01*visibleSize.width, Vec2(-visibleSize.width * 1.5, 0));
	pointNode->runAction(pointMove);
	this->addChild(pointNode);

}