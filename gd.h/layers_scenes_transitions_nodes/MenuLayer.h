#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include <gd.h>

namespace gd {
	class FLAlertLayerProtocol;

	class MenuLayer : public cocos2d::CCLayer, public FLAlertLayerProtocol, public GooglePlayDelegate {
	public:
		cocos2d::CCSprite* m_googlePlaySprite;
		cocos2d::CCSprite* m_viewProfileInfoText;
		cocos2d::CCLabelBMFont* m_playerNameLabel;
		CCMenuItemSpriteExtra* m_profileBtn;

		static MenuLayer* node() {
			return reinterpret_cast<MenuLayer*(__stdcall*)()>(base + 0x190550)();
		}
		static cocos2d::CCScene* scene(bool options) {
			return reinterpret_cast<cocos2d::CCScene*(__fastcall*)(bool)>(base + 0x190720)(options);
		}
		virtual bool init() {
			return reinterpret_cast<bool(__thiscall*)(void*)>(base + 0x1907b0)(this);
		}
		virtual void keyBackClicked() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x191f90)(this);
		}
		virtual void keyDown(cocos2d::enumKeyCodes key) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::enumKeyCodes)>(base + 0x1922c0)(this, key);
		}
		virtual void googlePlaySignedIn() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x191b20)(this);
		}
		virtual void FLAlert_Clicked(gd::FLAlertLayer* alert, bool btn2) {
			// thx pie
			reinterpret_cast<void(__thiscall*)(char*, void*, bool)>(base + 0x192150)(reinterpret_cast<char*>(this) + sizeof(cocos2d::CCLayer), alert, btn2);
		}
		//g e o d e 💥
		void onMoreGames(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x1919c0)(this, pSender);
		}
		void onGarage(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191dc0)(this, pSender);
		}
		void onQuit(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191fa0)(this, pSender);
		}
		void onMyProfile(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x1e0950)(this, pSender);
		}
		void onPlay(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191b50)(this, pSender);
		}
		void onCreator(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191cd0)(this, pSender);
		}
		void onRobTop(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191940)(this, pSender);
		}
		void onNewgrounds(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191e90)(this, pSender);
		}
		void onDaily(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x1916e0)(this, pSender);
		}
		void onOptions(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191c30)(this, pSender);
		}
		void onAchievements(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191af0)(this, pSender);
		}
		void onStats(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191ca0)(this, pSender);
		}
		void onFacebook(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191960)(this, pSender);
		}
		void onTwitter(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x191980)(this, pSender);
		}
		void onYouTube(cocos2d::CCObject* pSender) {
			reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCObject*)>(base + 0x1919A0)(this, pSender);
		}
	};

	class PlayerObject;

	class MenuGameLayer : public cocos2d::CCLayer {
	public:
		/*
			founded at iAndyHD3's and CattoDev's github repositories
		*/
		//PlayerObject* m_pPlayer;//0x12C
		//how works these fucks PAD()s

		static MenuGameLayer* create() {
			return reinterpret_cast<MenuGameLayer* (__fastcall*)()>(base + 0x18e6d0)();
		}
		void resetPlayer() {// = mac 0x28fdc0, win 0x18f4b0;
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x18f4b0)(this);
		}
		void destroyPlayer() {//= win 0x190100;
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x190100)(this);
		}
		virtual void update(float dt) {// = mac 0x28fa70, win 0x18f190;
			reinterpret_cast<void(__thiscall*)(void*, float)>(base + 0x18f190)(this, dt);
		}
		virtual bool init() {// = win 0x18e770;
			return reinterpret_cast<bool(__thiscall*)(void*)>(base + 0x18e770)(this);
		}
		void updateColors() {// = win 0x18edd0;
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x18edd0)(this);
		}
	};
}

#endif