#ifndef __Player_SCENE_H__
#define __Player_SCENE_H__

#include "cocos2d.h"

class Player : public cocos2d::Node
{
public:
    static Player* create();

    virtual bool init();
	
	void MoveTo(cocos2d::Vec2 point);
private:
	cocos2d::Sprite *ball;
	
	cocos2d::Layer* layerArrow;
	int parent;
	int num;
	cocos2d::ProgressTimer* directionArrow;

	int rotate;
	int rotateDirection;
	void update(float delta);
};

#endif // __HELLOWORLD_SCENE_H__
