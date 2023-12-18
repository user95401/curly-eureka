#ifndef __PLAYLAYER_H__
#define __PLAYLAYER_H__

#include <gd.h>

namespace gd {

	class GJBaseGameLayer;
	class CCCircleWaveDelegate;
	class GameObject;
	// class EndPortalObject;
	using EndPortalObject = GameObject;
	// class AudioEffectsLayer;
	using AudioEffectsLayer = cocos2d::CCLayerColor;
	// class GJGroundLayer;
	class GDH_DLL GJGroundLayer : public cocos2d::CCLayer {
	public:
		cocos2d::CCSprite* m_pGround1Sprite;
		cocos2d::CCSprite* m_pGround2Sprite;
		float m_fGroundWidth;
		cocos2d::CCSprite* m_pLineSprite;
		bool m_bShowGround;
		bool m_bLineBlend;
		float m_fGroundHeight;
		int m_nLineID;
	};
	class GJGameLevel;
	class GDH_DLL UILayer : public cocos2d::CCLayerColor {
		public:
			PAD(8)
			cocos2d::CCMenu* m_pCheckPointMenu;		// 0x1a0

			void onCheck(CCObject* pSender) {
				reinterpret_cast<void(__thiscall*)(UILayer*, CCObject*)>(
					base + 0x25fb60
				)(this, pSender);
			}

			void onDeleteCheck(CCObject* pSender) {
				reinterpret_cast<void(__thiscall*)(UILayer*, CCObject*)>(
					base + 0x25fc90
				)(this, pSender);
			}

			void onPause(CCObject* pSender) {
				reinterpret_cast<void(__thiscall*)(UILayer*, CCObject*)>(
					base + 0x25fad0
				)(this, pSender);
			}
	};

	using StartPosObject = gd::GameObject;
	class CheckpointObject;

	class GDH_DLL PlayLayer : public GJBaseGameLayer, public CCCircleWaveDelegate {
		public:
			PAD(8);
			unsigned int unk2D8;
			bool unk2DC;
			bool m_bHasCheated; // 0x2DD by taking less than 30s to beat lvl
			int unk2E0; // random value between 0 and 100 + unk2E8
			int unk2E4; // random value between 0 and 100
			int unk2E8;
			bool unk2EC; // opposite of isFrozen
			bool unk2ED;
			PAD(10);
			cocos2d::CCDrawNode* unk2F8;
			float unk2FC; // seems to be camera y
			float unk300;
			float unk304;
			float unk308; // bottom ground y maybe
			float unk30C; // last y or smth idk
			bool unk310;
			bool unk311;
			bool unk312;
			PAD(25);
			StartPosObject* m_startPos; // 0x32C
			CheckpointObject* unk330;
			EndPortalObject* m_endPortal; // 0x334
			cocos2d::CCArray* m_checkpoints; // 0x338
			cocos2d::CCArray* unk33C;
			cocos2d::CCArray* unk340;
			cocos2d::CCArray* unk344;
			cocos2d::CCSprite* unk348;
			PAD(8);
			cocos2d::CCArray* unk354;
			cocos2d::CCArray* unk358;
			cocos2d::CCArray* unk35C;
			cocos2d::CCArray* unk360;
			bool m_isMute; // 0x364 has to do with fmod
			PAD(7);
			cocos2d::CCArray* m_screenRingObjects; // 0x36C ring objects that are on screen, yes this is weird
			cocos2d::CCParticleSystemQuad* unk370;
			cocos2d::CCDictionary* unk374;
			cocos2d::CCArray* m_circleWaves; // 0x378
			cocos2d::CCArray* unk37C;
			AudioEffectsLayer* m_audioEffectsLayer; // 0x380
			PAD(8);
			GJGroundLayer* m_bottomGround; // 0x38C
			GJGroundLayer* m_topGround; // 0x390
			PAD(8);
			bool m_isDead; // 0x39C
			bool m_startCameraAtCorner; // smth to do with the camera
			bool m_cameraXLocked; // set to true when cameraMoveY is called
			bool m_cameraYLocked; // set to true when cameraMoveX is called
			PAD(4);
			int m_ballFrameSeed;
			PAD(12);
			float m_levelLength; // 0x3B4
			float unk3B8;
			cocos2d::CCLabelBMFont* m_attemptLabel; // 0x3BC
			cocos2d::CCLabelBMFont* m_percentLabel; // 0x3C0
			bool m_isCameraShaking; // 0x3C4
			float m_currentShakeStrength; // 0x3C8
			float m_currentShakeInterval; // 0x3CC
			double m_lastShakeTime; // 0x3D0
			cocos2d::CCPoint unk3D8;
			PAD(16);
			int unk3F0; // always 40
			cocos2d::CCDictionary* m_particleSystemsPlist; // 0x3F4 i really need a better name	 
			cocos2d::CCDictionary* unk3F8;
			cocos2d::CCArray* m_particleSystems; // 0x3FC
			cocos2d::CCNode* unk400;
			cocos2d::CCSprite* m_sliderGrooveSprite; // 0x404
			cocos2d::CCSprite* m_sliderBarSprite; // 0x408
			float m_sliderWidth; // 0x40C sliderbar2 width (?) minus 4
			float unk410; // always 8
			PAD(4);
			int unk418; // always 4
			PAD(8);
			cocos2d::CCArray* m_gravityEffectSprites; // 0x424 contains GravityEffectSprite s	   
			bool unk428;
			bool m_shouldRecordActions; // 0x429 for the hidden rob bot
			bool unk42A;
			bool unk42B; // 0x42B
			bool unk42C;
			bool m_isPlayer2Frozen; // 0x42D wat
			std::string m_previousRecords; // 0x430
			PAD(8);
			double m_time; // 0x450
			PAD(9);
			bool unk461;
			cocos2d::CCDictionary* unk464;
			PAD(8);
			bool m_isPlaybackMode; // 0x470
			PAD(11);
			bool m_isFlipped; // 0x47C
			PAD(7);
			UILayer* m_uiLayer; // 0x484
			GJGameLevel* m_level; // 0x488
			float m_cameraX; // 0x48C
			float m_cameraY; // 0x490
			bool m_isTestMode; // 0x494
			bool m_isPracticeMode; // 0x495
			bool unk496;
			bool unk497;
			cocos2d::CCArray* unk498; // animations array maybe
			bool unk49C;
			PAD(11);
			int m_currentAttempt; // 0x4A8
			int m_jumpCount; // 0x4AC
			bool unk4B0;
			float m_totalTime; // 0x4B4
			int m_attemptJumpCount; // 0x4B8 resets when you die
			bool unk4BC;
			bool m_hasLevelCompleteMenu; // 0x4BD true when the level complete menu shows up, so slightly after completing the lvl
			bool m_hasCompletedLevel; // 0x4BE
			int m_lastDeathPercent; // 0x4C0
			bool unk4C4;
			PAD(11);
			bool unk4D0;
			cocos2d::CCArray* unk4D4;
			cocos2d::CCDictionary* unk4D8;
			PAD(4);
			double unk4E0;
			double unk4E8; // seems to be time modulo 2 for some reason
			PAD(24);
			double unk508; // time again?
			PAD(31);
			bool m_bIsPaused; // 0x52f
			GameObject* unk530;
			bool unk534;
			bool unk535; // gets set to false when you cheat
			bool m_disableGravityEffect; // 0x536 comes from gv_0072
			PAD(1);

			static PlayLayer* get() { return GameManager::sharedState()->getPlayLayer(); }

			static PlayLayer* create(GJGameLevel* lvl) {
				return reinterpret_cast<PlayLayer*(__fastcall*)(GJGameLevel*)>(
					base + 0x1fb6d0
				)(lvl);
			}

			static cocos2d::CCScene* scene(GJGameLevel* lvl) {
				return reinterpret_cast<cocos2d::CCScene*(__fastcall*)(GJGameLevel*)>(
					base + 0x1fb690
				)(lvl);
			}

			void togglePracticeMode(bool on) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(
					base + 0x20d0d0
				)(this, on);
			}

			void addObject(GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x2017e0)(this, obj);
			}
			void addToSpeedObjects(GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x208730)(this, obj);
			}
			void animateInDualGround(GameObject* obj, float fl, bool b) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*, float, bool)>(base + 0x208b10)(this, obj,fl,b);
			}
			void animateInGround(bool instant) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x209b20)(this, instant);
			}
			void animateOutGround(bool instant) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x209e60)(this, instant);
			}
			void applyEnterEffect(GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x206880)(this, obj);
			}
			void cameraMoveY(float fl1, float fl2, float fl3) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float, float, float)>(base + 0x207c80)(this, fl1, fl2, fl3);
			}
			void checkCollisions(PlayerObject* plobj, float fl) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, float)>(base + 0x203CD0)(this, plobj, fl);
			}
			void circleWaveWillBeRemoved(CCCircleWave* thing) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, CCCircleWave*)>(base + 0x20aa90)(this, thing);
			}
			void destroyPlayer(PlayerObject* plrobj, GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, GameObject*)>(base + 0x20a1a0)(this, plrobj, obj);
			}
			void flipFinished() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20ad10)(this);
			}
			virtual void flipGravity(PlayerObject* plrobj, bool bool1, bool bool2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, bool, bool)>(base + 0x207d30)(this, plrobj, bool1, bool2);
			}
			void fullReset() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20bdf0)(this);
			}
			void getLastCheckpoint() {
				return reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20b800)(this);
			}
			void getObjectsState() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20b8b0)(this);
			}
			void hasUniqueCoin(GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*)>(base + 0x202250)(this, obj);
			}
			void levelComplete() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x1fd3d0)(this);
			}
			void loadDefaultColors() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x206e10)(this);
			}
			void loadFromCheckpoint(CheckpointObject* checkpoint) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, CheckpointObject*)>(base + 0x20b4a0)(this, checkpoint);
			}
			void markCheckpoint() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20b450)(this);
			}
			void moveCameraToPos(cocos2d::CCPoint point) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, cocos2d::CCPoint)>(base + 0x207bf0)(this, point);
			}
			virtual void onEnterTransitionDidFinish() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20dbd0)(this);
			}
			void onQuit() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20D810)(this);
			}
			void onExit() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20d810)(this);
			}
			void optimizeColorGroups() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x202370)(this);
			}
			void optimizeSaveRequiredGroups() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2026f0)(this);
			}
			void pauseGame(bool par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x20d3c0)(this, par);
			}
			void playAnimationCommand(int int1, int int2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, int, int)>(base + 0x1ff2f0)(this, int1, int2);
			}
			void playExitDualEffect(PlayerObject* plrogj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*)>(base + 0x208e20)(this, plrogj);
			}
			void playFlashEffect(float fl1, int intpar, float fl2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float, int, float)>(base + 0x75e50)(this, fl1, intpar, fl2);
			}
			void playGravityEffect(bool par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x207e00)(this, par);
			}
			void playSpeedParticle(float par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float)>(base + 0x201130)(this, par);
			}
			void playerWillSwitchMode(PlayerObject* plrobj, GameObject* obj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, GameObject*)>(base + 0x16b290)(this, plrobj, obj);
			}
			void prepareSpawnObjects() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20c850)(this);
			}
			void removeAllObjects() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20da00)(this);
			}
			void removeLastCheckpoint() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20b830)(this);
			}
			void resetLevel() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20bf00)(this);
			}
			void resume() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20d5c0)(this);
			}
			void resumeAndRestart() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20d4c0)(this);
			}
			void saveRecordAction(bool par, PlayerObject* plrobj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, PlayerObject*)>(base + 0x20ad40)(this, par, plrobj);
			}
			void setupLevelStart(LevelSettingsObject* levelSettingsObj) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, LevelSettingsObject*)>(base + 0x1fb780)(this, levelSettingsObj);
			}
			void shakeCamera(float fl1, float fl2, float fl3) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float, float, float)>(base + 0x1ff210)(this, fl1, fl2, fl3);
			}
			void showCompleteEffect() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x1fe060)(this);
			}
			void showCompleteText() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x1fda90)(this);
			}
			void showEndLayer() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x1ffd00)(this);
			}
			void showNewBest(bool bool1, int int1, int int2, bool bool2, bool bool3, bool bool4) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, int, int, bool, bool, bool)>(base + 0x1fe3a0)(this,bool1,int1,int2,bool2,bool3,bool4);
			}
			void showTwoPlayerGuide() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2003b0)(this);
			}
			void sortGroups() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x202890)(this);
			}
			void spawnPlayer2() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x2089e0)(this);
			}
			void startMusic() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20C8F0)(this);
			}
			void stopCameraShake() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x1ff2d0)(this);
			}
			void storeCheckpoint(CheckpointObject* Checkpoint) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, CheckpointObject*)>(base + 0x20b420)(this, Checkpoint);
			}
			void timeForXPos(float par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float)>(base + 0x2087d0)(this, par);
			}
			void timeForXPos2(float par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float)>(base + 0x1fd3d0)(this, par);
			}
			void toggleDualMode(GameObject* obj, bool bool1, PlayerObject* plrobj, bool bool2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, GameObject*, bool, PlayerObject*, bool)>(base + 0x208880)(this, obj, bool1, plrobj, bool2);
			}
			void toggleFlipped(bool bool1, bool bool2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool, bool)>(base + 0x20ab20)(this, bool1, bool2);
			}
			void toggleGlitter(bool par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, bool)>(base + 0x20a0d0)(this, par);
			}
			void toggleProgressbar() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x208160)(this);
			}
			void updateAttempts() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20ced0)(this);
			}
			void updateCamera(float par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float)>(base + 0x2071d0)(this, par);
			}
			void updateDualGround(PlayerObject* plrobj, int par1, bool par2) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, PlayerObject*, int, bool)>(base + 0x209680)(this, plrobj, par1, par2);
			}
			void updateEffectPositions() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x20aab0)(this);
			}
			void updateLevelColors() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x203a90)(this);
			}
			void updateProgressbar() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x69b40)(this);
			}
			virtual void visit() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x200020)(this);
			}
			void visitWithColorFlash() {
				reinterpret_cast<void(__thiscall*)(PlayLayer*)>(base + 0x200190)(this);
			}
			void xPosForTime(float par) {
				reinterpret_cast<void(__thiscall*)(PlayLayer*, float)>(base + 0x208840)(this, par);
			}
	};
}

#endif
