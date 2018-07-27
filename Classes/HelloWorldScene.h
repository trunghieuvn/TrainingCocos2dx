#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;
#pragma once
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
  // void menuCloseCallback(cocos2d::Ref* pSender);
	void menuCloseCallback(float dt);
	void gameStar();
	bool OntouchBegan(Touch *touch, Event *event);
	void Ontop(float dt);
	void update(float dt);
	void gameOver(float dt);

	void createPipes(float dt);
	bool OntacBegan(PhysicsContact &contact);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	cocos2d::Sprite *birdSprite;
	cocos2d::RepeatForever *swingAction;
	PhysicsWorld *world;
	bool isFalling = true;
	int score = 0;
	Label *label;
	cocos2d::Sprite *land1, *land2;
	cocos2d::Sprite *pipeUp, *pipeDown;
	void SetPhysicsWorld(PhysicsWorld *world)
	{
		world = world;
	}

};

#endif // __HELLOWORLD_SCENE_H__
