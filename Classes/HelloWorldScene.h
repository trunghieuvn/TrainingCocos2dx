#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;
USING_NS_CC;
class HelloWorld :public cocos2d::Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	void createPipe(float dt);
	CREATE_FUNC(HelloWorld);

private:
	Sprite *pipeUp, *pipeDown;
	PhysicsWorld *world;
	void SetPhysicsWorld(PhysicsWorld *world)
	{
		world = world;
	}
};
#endif // __HELLOWORLD_SCENE_H__
