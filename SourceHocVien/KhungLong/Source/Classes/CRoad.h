#ifndef __CROAD_H_
#define __CROAD_H_

#include "cocos2d.h"

class Road : public cocos2d::Sprite
{
public:
	Road ();
	~Road ();

	static Road* create(const std::string &filename);

	virtual bool init(const std::string &filename);

	cocos2d::Sprite* spRoad_1;

	cocos2d::Sprite* spRoad_2;

	void updateRoad(float dt);

private:

};

#endif //__CRAOD_H_