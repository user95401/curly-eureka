#ifndef __CreatorLayer_H__
#define __CreatorLayer_H__

#include <gd.h>

namespace gd {
	class CreatorLayer : public cocos2d::CCLayer {
	public:
		//g e o d e 💥
		static CreatorLayer* create() {
			return reinterpret_cast<CreatorLayer * (__fastcall*)()>(base + 0x4dda0)();
		}
		virtual bool init() {
			return reinterpret_cast<bool(__thiscall*)(void*)>(base + 0x4de40)(this);
		}
		virtual void sceneWillResume() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x4fb50)(this);
		}
		void onBack(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4fae0)(this, pSender);
		}
		void onChallenge(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f1b0)(this, pSender);
		}
		void onLeaderboards(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4ed20)(this, pSender);
		}
		void onMyLevels(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4eaa0)(this, pSender);
		}
		void onSavedLevels(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4ebe0)(this, pSender);
		}
		void onDailyLevel(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f170)(this, pSender);
		}
		void onWeeklyLevel(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f190)(this, pSender);
		}
		void onFeaturedLevels(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4edf0)(this, pSender);
		}
		void onFameLevels(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4ee70)(this, pSender);
		}
		void onMapPacks(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4efb0)(this, pSender);
		}
		void onOnlineLevels(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4ef60)(this, pSender);
		}
		void onGauntlets(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f0a0)(this, pSender);
		}
		void onSecretVault(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f1d0)(this, pSender);
		}
		void onTreasureRoom(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x4f540)(this, pSender);
		}
	};
}

#endif