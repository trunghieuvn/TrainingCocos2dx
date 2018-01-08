#ifndef __Background_H__
#define __Background_H__

#include "cocos2d.h"

class BackgroundScrolling : public cocos2d::Node
{
public:
	static BackgroundScrolling* create();

    virtual bool init();

	cocos2d::Sprite *background;
	
	bool isCollision;
private:
	
	void update(float delta);
};

#endif // __Background_H__
