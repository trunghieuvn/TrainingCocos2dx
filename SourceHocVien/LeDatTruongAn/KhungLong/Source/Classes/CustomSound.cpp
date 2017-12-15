#include "CustomSound.h"

USING_NS_CC;

void CustomSound::playEff(const char* path)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path);
}

CustomSound::CustomSound()
{
}

CustomSound::~CustomSound()
{
}