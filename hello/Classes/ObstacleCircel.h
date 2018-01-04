#ifndef __ObstacleCircel_H__
#define __ObstacleCircel_H__

#include "cocos2d.h"

class ObstacleCircel : public cocos2d::Node
{
public:
    static ObstacleCircel* create(cocos2d::Vec2 pos);

    virtual bool init(cocos2d::Vec2 pos);

	cocos2d::Sprite *circle_background;
	inline float getRadius() 
	{ 
		return circle_background->getContentSize().width > circle_background->getContentSize().height 
			? circle_background->getContentSize().width : circle_background->getContentSize().height;
	}
	bool isCollision;
private:
	
	void update(float delta);
	cocos2d::ProgressTimer *circle_foreground_on;
	int parent;
};

#endif // __Player_H__
