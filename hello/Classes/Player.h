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
	
	void Move(cocos2d::Vec2 point);

	PlayerState mState;

	int rotate;
	int parent;

	inline cocos2d::Sprite* getBall() { return ball; }
private:
	cocos2d::Vec2 pointStart;

	cocos2d::Sprite *ball;
	
	cocos2d::Layer* layerArrow;
	int num;
	cocos2d::ProgressTimer* directionArrow;

	int rotateDirection;
	void update(float delta);
};

#endif // __Player_H__
