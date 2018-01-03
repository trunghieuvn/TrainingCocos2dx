#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"

enum PlayerState
{
	Stationary,
	Rotate,
	Orientation
};

class Player : public cocos2d::Node
{
public:
    static Player* create(cocos2d::Vec2 pos);

    virtual bool init(cocos2d::Vec2 point);
	
	void MoveTo(cocos2d::Vec2 point);

	PlayerState mState;
private:
	cocos2d::Vec2 pointStart;

	cocos2d::Sprite *ball;
	
	cocos2d::Layer* layerArrow;
	int parent;
	int num;
	cocos2d::ProgressTimer* directionArrow;

	int rotate;
	int rotateDirection;
	void update(float delta);
};

#endif // __Player_H__
