#ifndef __AN_FRAMEWORKS_H_
#define __AN_FRAMEWORKS_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "extensions\cocos-ext.h"
#include "ui\CocosGUI.h"
using namespace cocos2d;

USING_NS_CC_EXT;
using namespace ui;

namespace AnCocos
{
	enum AdBannerPosition { eBottom, eTop, eBoth };
	enum UIButtonPosition { eBottomLeft, eBottomRight, eTopLeft, eTopRight };

	class UI
	{
	public:
		UI();
		~UI();

		static Vec2 GetScreenCenter();

		static void AddCentredBackground(const std::string &background, cocos2d::Layer* layer);
		
		void AddAudioToggle(const std::string &onButton, const std::string &onButtonPressed, const std::string &offButton, const std::string &offButtonPressed, cocos2d::Layer *layer, int position);

	private:
		ui::Button *audioToggleButton;
		ui::Button *soundEffectsToggleButton;
		ui::Button *musicToggleButton;

		class Audio
		{
		public:
			static std::string offButtonString;
			static std::string offButtonPressedString;
			static std::string onButtonString;
			static std::string onButtonPressedString;
		};

		void AudioTouchEvent(Ref *sender, Widget::TouchEventType type);
	};
}
#endif // !__AN_FRAMEWORKS_H_

