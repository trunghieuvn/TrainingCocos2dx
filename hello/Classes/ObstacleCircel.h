#ifndef __ObstacleCircel_H__
#define __ObstacleCircel_H__

#include "cocos2d.h"

class ObstacleCircel : public cocos2d::Node
{
public:
    static ObstacleCircel* create();

    virtual bool init();

private:
	cocos2d::Sprite *ball;
	
	void update(float delta);
};

#endif // __Player_H__
