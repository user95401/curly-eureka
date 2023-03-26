#ifndef __KeysLayer_H__
#define __KeysLayer_H__

#include <gd.h>

namespace gd {
	class KeysLayer : public cocos2d::CCLayer, FLAlertLayerProtocol, DialogDelegate {
	public:
		//mat is 💥 again
		static KeysLayer * create() {
			return reinterpret_cast<KeysLayer * (__fastcall*)()>(base + 0x1544C0)();
		}
		virtual bool init() {
			return reinterpret_cast<bool(__thiscall*)(void*)>(base + 0x154560)(this);
		}
		void switchToOpenedState(CCMenuItemSpriteExtra* ok) {
			reinterpret_cast<void(__thiscall*)(void*, CCMenuItemSpriteExtra*)>(base + 0x157BF0)(this, ok);
		}
		void onSpecialItem(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x157CA0)(this, pSender);
		}
		void onSelectItem(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x157FD0)(this, pSender);
		}
		void updateUnlockedLabel() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x158260)(this);
		}
	};
}

#endif