#ifndef __BackgroundScrolling_H__
#define __BackgroundScrolling_H__

#include "cocos2d.h"
#include "Background.h"

class BackgroundScrolling : public cocos2d::Node
{
public:
	static BackgroundScrolling* create();

    virtual bool init();

	bool isCollision;

	Background* background1;
	Background* background2;
	Background* background3;

	void ChangeBackgroundScrolling(cocos2d::Node* target);
private:
	
	void update(float delta);
};

#endif // __BackgroundScrolling_H__
