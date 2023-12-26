#ifndef __FLALERTLAYER_HPP__
#define __FLALERTLAYER_HPP__

#include <gd.h>

namespace gd {

	class FLAlertLayerProtocol;
	class ButtonSprite;
	class ScrollingLayer;

	#pragma runtime_checks("s", off)
	class GDH_DLL FLAlertLayer : public cocos2d::CCLayerColor {
	public:
		virtual ~FLAlertLayer() {
			// recreate destructor
			cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
		}
	public:
		//order not tested
		/*cocos2d::CCMenu* m_buttonMenu;
		FLAlertLayerProtocol* m_alertProtocol;
		cocos2d::CCNode* m_scene;
		bool m_reverseKeyBack;
		cocos2d::ccColor3B m_color;
		cocos2d::CCLayer* m_mainLayer;
		int m_ZOrder;
		bool m_noElasticity;
		cocos2d::ccColor3B m_color2;
		ButtonSprite* m_button1;
		ButtonSprite* m_button2;
		ScrollingLayer* m_scrollingLayer;
		int m_controlConnected;
		bool m_containsBorder;
		bool m_noAction;
		int m_joystickConnected;
		bool m_forcePrioRegistered;*/

		//CCNode vtable
		/*virtual void onEnter() {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x23750
				)(this);
		}*/
		virtual void registerWithTouchDispatcher() {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x31df0
				)(this);
		}

		//CCTouchDelegate vtable
		virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) { 
			return reinterpret_cast<bool(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31ac0
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31c10
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31b50
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		virtual void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31bc0
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}

		//CCKeyboardDelegate vtable
		virtual void keyDown(cocos2d::enumKeyCodes key) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::enumKeyCodes)>(
				base + 0x31930
				)(this, key);
		}

		//CCKeypadDelegate vtable
		virtual void keyBackClicked() {
			return reinterpret_cast<void(__thiscall*)(char*)>(
				base + 0x319a0
				)(reinterpret_cast<char*>(this) + 0xF4);
		}

		//vtable
		virtual void show() {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x31c60
				)(this);
		}
		FLAlertLayer() {
			reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x30b80
				)(this);
		}

		void onBtn1(cocos2d::CCObject* btn) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
				base + 0x31a40
				)(this, btn);
		}
		void onBtn2(cocos2d::CCObject* btn) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
				base + 0x31a80
				)(this, btn);
		}
		/*TextArea supports colors of text for the caption. wrap desired text in "<cx></c>"
			* where x is the color desired. colors are:
			* r - red
			* l - lime
			* g - green
			* y - yellow
			* o - orange
			* and more that i'm too lazy to find.
			* MAKE SURE YOU FOLLOW THIS FORMAT. ROB'S PARSING CAN AND WILL MESS UP OTHERWISE.
			*/
		static FLAlertLayer* create(FLAlertLayerProtocol* pFLAlertLayerProtocol, const char* Title,
			const char* Btn1Text, const char* Btn2Text, std::string TextAreaContent) {
			auto pRet = reinterpret_cast<FLAlertLayer* (__fastcall*)(FLAlertLayerProtocol*, const char*,
				const char*, const char*, std::string)>(
					base + 0x30c40
					)(pFLAlertLayerProtocol, Title, Btn1Text, Btn2Text, TextAreaContent);
			//clean stack.
			__asm add esp, 0x20
			return pRet;
		}
		static FLAlertLayer* create(FLAlertLayerProtocol* pFLAlertLayerProtocol, const char* Title,
			const char* Btn1Text, const char* Btn2Text, float width, std::string TextAreaContent) {
			auto pRet = reinterpret_cast<FLAlertLayer* (__fastcall*)(FLAlertLayerProtocol*, const char*,
				const char*, const char*, float, std::string)>(
					base + 0x30cf0
					)(pFLAlertLayerProtocol, Title, Btn1Text, Btn2Text, width, TextAreaContent);
			__asm add esp, 0x24
			return pRet;
		}
		//custom function
		cocos2d::CCLayer* getLayer() { 
			return reinterpret_cast<CCLayer*>(this->getChildren()->objectAtIndex(0)); 
		}
		//custom function
		cocos2d::CCMenu* getButtonMenu() {
			return reinterpret_cast<cocos2d::CCMenu*>(this->getLayer()->getChildren()->objectAtIndex(3));
		}
	};
	#pragma runtime_checks("s", restore)
}


#endif