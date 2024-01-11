#ifndef __LAYERS_HPP__
#define __LAYERS_HPP__

#include <gd.h>

namespace gd {

	class FLAlertLayerProtocol;
	class ButtonSprite;
	class ScrollingLayer;

	#pragma runtime_checks("s", off)
	class GDH_DLL FLAlertLayer : public cocos2d::CCLayerColor {
	public:
		//2.200
		virtual ~FLAlertLayer() {
			// recreate destructor
			cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->decrementForcePrio(2);
		}
		//2.200
		virtual void registerWithTouchDispatcher() {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x31df0
				)(this);
		}
		//2.200, CCTouchDelegate vtable
		virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) { 
			return reinterpret_cast<bool(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31ac0
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		//2.200
		virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31c10
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		//2.200
		virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31b50
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		//2.200
		virtual void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
			return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
				base + 0x31bc0
				)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
		}
		//2.200, CCKeyboardDelegate vtable
		virtual void keyDown(cocos2d::enumKeyCodes key) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::enumKeyCodes)>(
				base + 0x31930
				)(this, key);
		}
		//2.200, CCKeypadDelegate vtable
		virtual void keyBackClicked() {
			return reinterpret_cast<void(__thiscall*)(char*)>(
				base + 0x319a0
				)(reinterpret_cast<char*>(this) + 0xF4);
		}
		//2.200, vtable
		void show() {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x31c60
				)(this);
		}
		//2.200
		FLAlertLayer() {
			reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				base + 0x30b80
				)(this);
		}
		//2.200
		void onBtn1(cocos2d::CCObject* btn) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
				base + 0x31a40
				)(this, btn);
		}
		//2.200
		void onBtn2(cocos2d::CCObject* btn) {
			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
				base + 0x31a80
				)(this, btn);
		}
		/*2.200, TextArea supports colors of text for the caption. wrap desired text in "<cx></c>"
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
			//__asm add esp, 0x20
			return pRet;
		}
		//2.200
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

	using GJBaseGameLayer = cocos2d::CCLayer;
	class CheckpointObject;
	class PlayerObject;
	class GameObject;

	//uh thats shit yet
	class GDH_DLL PlayLayer : public GJBaseGameLayer, public CCCircleWaveDelegate {
	public:
		//2.200
		static PlayLayer* create(GJGameLevel* pGJGameLevel, bool a3, bool a4) {//upd
			return reinterpret_cast<PlayLayer*(__fastcall*)(GJGameLevel*, int, int)>(base + 0x2D68F0)(pGJGameLevel, a3, a4);
		}
		//2.200
		static cocos2d::CCScene* scene(GJGameLevel* lvl, bool a1, bool a2) {//upd
			return reinterpret_cast<cocos2d::CCScene * (__fastcall*)(GJGameLevel*, bool, bool)>(
				base + 0x2D68A0
				)(lvl, a1, a2);
		}
		//2.200
		void addObject(GameObject* obj) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x2DBD30)(this, obj);
		}
		//2.200
		void togglePracticeMode(bool on) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2e4eb0)(this, on);
		}
		//2.200
		void showHint() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e12d0)(this);
		}
		//2.200
		void resetLevelFromStart() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4210)(this);
		}
		//2.200
		void playEndAnimationToPos(cocos2d::CCPoint aCCPoint) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, cocos2d::CCPoint)>(base + 0x2da140)(this, aCCPoint);
		}
		//2.200
		void removeAllObjects() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5750)(this);
		}
		//2.200
		void destroyPlayer(PlayerObject* plrobj, GameObject* obj) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, GameObject*)>(base + 0x2e0a90)(this, plrobj, obj);
		}
		//2.200
		virtual void flipGravity(bool bool1, bool bool2) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, bool)>(base + 0x2CDDB0)(this, bool1, bool2);
		}
		//2.200
		void fullReset() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E40C0)(this);
		}
		//2.200
		void levelComplete() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d7f30)(this);
		}
		//2.200
		void loadFromCheckpoint(CheckpointObject* checkpoint) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, CheckpointObject*)>(base + 0x2e28d0)(this, checkpoint);
		}
		//2.200
		void markCheckpoint() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e2880)(this);
		}
		//2.200
		void onQuit() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e5650)(this);
		}
		//2.200
		void onExit() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e5910)(this);
		}
		//2.200
		void pauseGame(bool par) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2e4fc0)(this, par);
		}
		//2.200
		void startGame() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d7e80)(this);
		}
		//2.200
		void prepareMusic(bool a1) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2E5480)(this, a1);
		}
		//2.200
		void incrementJumps() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e4e50)(this);
		}
		//2.200
		void resetLevel() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E42B0)(this);
		}
		//2.200
		void updateAttempts() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4CC0)(this);
		}
		//2.200
		void resumeAndRestart() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5160)(this);
		}
		//2.200
		void delayedResetLevel() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4200)(this);
		}
		//2.200
		void showCompleteText() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d8770)(this);
		}
		//2.200
		void startGameDelayed() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2D7EC0)(this);
		}
		//2.200
		void showNewBest(bool bool1, int int1, int int2, bool bool2, bool bool3, bool bool4) {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, int, int, bool, bool, bool)>(base + 0x2D9100)(this, bool1, int1, int2, bool2, bool3, bool4);
		}
		//2.200
		void startMusic() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5570)(this);
		}
		//2.200
		void updateInfoLabel() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2dfe30)(this);
		}
		//2.200
		void toggleGhostEffect() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2D20D0)(this);
		}
		//2.200
		void updateProgressbar() {//upd
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2df7a0)(this);
		}
	};
}


#endif