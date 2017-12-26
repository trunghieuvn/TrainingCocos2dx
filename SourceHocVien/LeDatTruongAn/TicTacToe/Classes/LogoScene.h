#ifndef __LOGO_SCENE_H__
#define __LOGO_SCENE_H__

#include "cocos2d.h"

class LogoScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(LogoScene);

private:
	void SwitchToMainMenu(float dt);
};

#endif // __LOGO_SCENE_H__
