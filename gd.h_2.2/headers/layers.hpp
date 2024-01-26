#ifndef __LAYERS_HPP__
#define __LAYERS_HPP__

#include <gd.h>

namespace gd {
	#pragma runtime_checks("s", off)
	class GDH_DLL FLAlertLayer : public cocos2d::CCLayer {
	public:
		//2.200, vtable
		void show() {
			CALLLOG;

			//53 56 57 8b f9 80 bf d0 1 0 0 0 f 85 c 1
			uintptr_t addr = patterns::find_pattern("53 56 57 8b f9 80 bf d0 1 0 0 0 f 85 c 1");
			addr = gd::base + 0x31cd0; //2.204
			ModUtils::log((ModUtils::ReadProcMemAsStr(addr, 16)).c_str());

			return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
				addr
				)(this);

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
		static FLAlertLayer* create(
			FLAlertLayerProtocol* pFLAlertLayerProtocol, 
			const char* Title, std::string TextAreaContent,
			const char* Btn1Text, 
			const char* Btn2Text
		) {
			CALLLOG;
			//55 8b ec 6a ff 68 38 2c d7 0 64 a1 0 0 0 0 50 83 ec 8 53 56 57 a1 0 20 - 2200
			//55 8b ec 6a ff 68 58 95 e5 0 64 a1 0 0 0 0 50 83 ec 8 53 56 57 a1 0 a0 - 2204
			//5e 5b 8b e5 5d c3 cc cc cc cc cc cc cc cc cc cc cc cc 55 8b ec 6a ff 68 58 95 e5 0 64 a1 0 0 0 0 50 83 - 2204 (rva - 18)
			//?  ?  ?  ?  ?  68 ?  ?  ?  0 64 a1 0 0 0 0 50 83 ec 8 53 56 57 a1 0    - to use
			uintptr_t addr = patterns::find_pattern("cc cc cc ^ ?  ?  ?  ?  ?  68 ?  ?  ?  0 64 a1 0 0 0 0 50 83 ec 8 53 56 57 a1 0");
			//addr = gd::base + 0x30cf0; //2.200
			addr = gd::base + 0x30c40; //2.204
			ModUtils::log((ModUtils::ReadProcMemAsStr(addr, 16)).c_str());

			FLAlertLayer* pRet = reinterpret_cast
				<
				FLAlertLayer* (__thiscall*)
				(FLAlertLayerProtocol*, char const*, std::string, char const*, char const*)
				>
				(addr)(pFLAlertLayerProtocol, Title, TextAreaContent, Btn1Text, Btn2Text);

			ModUtils::log("return");
			//clean stack.
			//__asm add esp, 0x24
			return pRet;
		}
	};
	#pragma runtime_checks("s", restore)

	//uh thats shit yet
	class GDH_DLL PlayLayer : public GJBaseGameLayer, public CCCircleWaveDelegate {
	public:
		//2.200
		static PlayLayer* create(GJGameLevel* pGJGameLevel, bool a3, bool a4) {//upd
			CALLLOG;
			return reinterpret_cast<PlayLayer*(__fastcall*)(GJGameLevel*, int, int)>(base + 0x2D68F0)(pGJGameLevel, a3, a4);
		}
		//2.200
		static cocos2d::CCScene* scene(GJGameLevel* lvl, bool a1, bool a2) {//upd
			CALLLOG;
			return reinterpret_cast<cocos2d::CCScene * (__fastcall*)(GJGameLevel*, bool, bool)>(
				base + 0x2D68A0
				)(lvl, a1, a2);
		}
		//2.200
		void addObject(GameObject* obj) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x2DBD30)(this, obj);
		}
		//2.200
		void togglePracticeMode(bool on) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2e4eb0)(this, on);
		}
		//2.200
		void showHint() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e12d0)(this);
		}
		//2.200
		void resetLevelFromStart() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4210)(this);
		}
		//2.200
		void playEndAnimationToPos(cocos2d::CCPoint aCCPoint) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, cocos2d::CCPoint)>(base + 0x2da140)(this, aCCPoint);
		}
		//2.200
		void removeAllObjects() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5750)(this);
		}
		//2.200
		void destroyPlayer(PlayerObject* plrobj, GameObject* obj) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, GameObject*)>(base + 0x2e0a90)(this, plrobj, obj);
		}
		//2.200
		virtual void flipGravity(bool bool1, bool bool2) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, bool)>(base + 0x2CDDB0)(this, bool1, bool2);
		}
		//2.200
		void fullReset() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E40C0)(this);
		}
		//2.200
		void levelComplete() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d7f30)(this);
		}
		//2.200
		void loadFromCheckpoint(CheckpointObject* checkpoint) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, CheckpointObject*)>(base + 0x2e28d0)(this, checkpoint);
		}
		//2.200
		void markCheckpoint() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e2880)(this);
		}
		//2.203
		void onQuit() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x12E110)(this);
		}
		//2.200
		void onExit() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e5910)(this);
		}
		//2.200
		void pauseGame(bool par) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2e4fc0)(this, par);
		}
		//2.200
		void startGame() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d7e80)(this);
		}
		//2.200
		void prepareMusic(bool a1) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x2E5480)(this, a1);
		}
		//2.200
		void incrementJumps() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2e4e50)(this);
		}
		//2.200
		void resetLevel() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E42B0)(this);
		}
		//2.200
		void updateAttempts() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4CC0)(this);
		}
		//2.200
		void resumeAndRestart() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5160)(this);
		}
		//2.200
		void delayedResetLevel() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E4200)(this);
		}
		//2.200
		void showCompleteText() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2d8770)(this);
		}
		//2.200
		void startGameDelayed() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2D7EC0)(this);
		}
		//2.200
		void showNewBest(bool bool1, int int1, int int2, bool bool2, bool bool3, bool bool4) {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, int, int, bool, bool, bool)>(base + 0x2D9100)(this, bool1, int1, int2, bool2, bool3, bool4);
		}
		//2.200
		void startMusic() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2E5570)(this);
		}
		//2.200
		void updateInfoLabel() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2dfe30)(this);
		}
		//2.200
		void toggleGhostEffect() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2D20D0)(this);
		}
		//2.200
		void updateProgressbar() {//upd
			CALLLOG;
			reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2df7a0)(this);
		}
	};
}


#endif