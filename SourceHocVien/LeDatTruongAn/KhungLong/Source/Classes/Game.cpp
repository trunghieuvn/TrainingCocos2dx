#include "Game.h"
#include "SimpleAudioEngine.h"
#include "GameCommon.h"
#include "Definitions.h"
#include "CustomSound.h"
#include "CRoad.h"

USING_NS_CC;

Scene* Game::createScene()
{
	auto scene = Scene::create();

	auto layer = Game::create();

	// Ta có thể app màu vào scene

	//scene->addChild(LayerColor::create(Color4B(247, 247, 247, 255)));

	scene->addChild(layer);

	return scene;
}

bool Game::init()
{
	if (!LayerColor::init()) // LayerColor::initWithColor(Color4B(247, 247, 247, 255)
	{
		return false;
	}

	// Show spGameStartTitle
	spGameStartTitle = Sprite::create("title.png");
	spGameStartTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	spGameStartTitle->setPosition(DW / 2, DH - TITLE_GAMESTART_Y);
	this->addChild(spGameStartTitle, SCORE_ZORDER);
	// End spGameStartTitle
	// Show spGameOverTitle
	spGameOverTitle = Sprite::create("gameover.png");
	spGameOverTitle->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	spGameOverTitle->setPosition(DW / 2, DH - TITLE_GAMEOVER_Y);
	spGameOverTitle->setScale(0);
	this->addChild(spGameOverTitle, SCORE_ZORDER);
	// End spGameOverTitle
	// Show labTap2Jump
	labTap2Jump = LabelTTF::create("TAP TO JUMP", "fonts / score.ttf", 50);
	labTap2Jump->setPosition(Vec2(DW / 2, GROUND_HEIGHT - 70));
	labTap2Jump->setFontFillColor(Color3B::GRAY);
	this->addChild(labTap2Jump, SCORE_ZORDER);
	// End labTap2Jump
	// Show spHand
	spHand = Sprite::create("hand_1.png");
	spHand->setPosition(Vec2(DW / 2, GROUND_HEIGHT - 140));
	Vector<SpriteFrame*> aniHandFrame;
	aniHandFrame.pushBack(SpriteFrame::create("hand_1.png", Rect(0, 0, 90, 134)));
	aniHandFrame.pushBack(SpriteFrame::create("hand_2.png", Rect(0, 0, 90, 134)));
	auto aniHand = Animation::createWithSpriteFrames(aniHandFrame, 0.3f, 1U);
	spHand->runAction(RepeatForever::create(Animate::create(aniHand)));
	this->addChild(spHand);
	// End spHand
	// Load preSound
	auto se = CocosDenshion::SimpleAudioEngine::getInstance();
	se->preloadEffect(SOUND_JUMP);
	se->preloadEffect(SOUND_NEW_HIGH);
	se->preloadEffect(SOUND_OVER);
	// Test Sound
	CustomSound::playEff(SOUND_JUMP);
	// End preSound

	return true;
}