#ifndef __GAME_H_
#define __GAME_H_

#include "cocos2d.h"

class Game : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(Game);

private:
#pragma region UIs

	cocos2d::Sprite* spGameStartTitle;

	cocos2d::Sprite* spGameOverTitle;

	cocos2d::LabelTTF* labTap2Jump;

	cocos2d::Sprite* spHand;

#pragma endregion

};

#endif // __GAME_H_
