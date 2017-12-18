#ifndef __FRAMEWORKS_H__
#define __FRAMEWORKS_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

USING_NS_CC_EXT;
using namespace ui;

namespace CocosHelp
{
	enum UIButtonPosition { eBottomLeft, eBottomRight, eTopLeft, eTopRight };
	class UI
	{
	public:
		void AddAudioToggle(const std::string &onButton, const std::string &onButtonPressed, const std::string &offButton, const std::string &offButtonPressed, cocos2d::Layer *layer, int position);
		static Vec2 GetScreenCorner(int position, Node *itemToPosition);
	private:
		class Audio
		{
		public:
			static std::string offButtonString;
			static std::string offButtonPressedString;
			static std::string onButtonString;
			static std::string onButtonPressedString;
		};

		class SoundEffects
		{
		public:
			static std::string offButtonString;
			static std::string offButtonPressedString;
			static std::string onButtonString;
			static std::string onButtonPressedString;
		};

		class Music
		{
		public:
			static std::string offButtonString;
			static std::string offButtonPressedString;
			static std::string onButtonString;
			static std::string onButtonPressedString;
		};

		ui::Button *audioToggleButton;

		void AudioTouchEvent(Ref *sender, Widget::TouchEventType type);
	};
}

#endif //__FRAMEWORKS_H__