#ifndef __PLAYEROBJECT_H__
#define __PLAYEROBJECT_H__

#include <gd.h>

namespace gd {

	class GameObject;
	class AnimatedSpriteDelegate;
	class GJRobotSprite;
	class GJSpiderSprite;
	class HardStreak;
	class GhostTrailEffect;

	class GDH_DLL PlayerObject : public GameObject, public AnimatedSpriteDelegate {
	public:
		PAD(20);
		bool unk480;
		cocos2d::CCNode* unk484;
		cocos2d::CCDictionary* unk488;
		cocos2d::CCDictionary* unk48C;
		PAD(32);
		bool unk4B0;
		cocos2d::CCSprite* unk4B4;
		PAD(28);
		bool unk4D4;
		cocos2d::CCArray* m_particleSystems; // 0x4D8
		bool unk4DC;
		bool m_isHidden; // 0x4DD
		int m_hasGhostTrail; // 0x4E0
		GhostTrailEffect* m_ghostTrail; // 0x4E4
		cocos2d::CCSprite* unk4E8;
		cocos2d::CCSprite* unk4EC;
		cocos2d::CCSprite* unk4F0;
		cocos2d::CCSprite* unk4F4;
		cocos2d::CCSprite* unk4F8;
		cocos2d::CCSprite* unk4FC;
		cocos2d::CCSprite* unk500;
		cocos2d::CCSprite* unk504;
		cocos2d::CCSprite* unk508;
		cocos2d::CCSprite* unk50C;
		cocos2d::CCMotionStreak* m_regularTrail; // 0x510
		HardStreak* m_waveTrail; // 0x514
		double m_xAccel; // 0x518
		double m_jumpAccel; // 0x520
		double m_gravity; // 0x528
		PAD(8);
		bool unk538;
		bool unk539;
		bool unk53A;
		bool unk53B;
		bool m_isInPlayLayer; // 0x53C
		bool unk53D;
		bool unk53E; // is holding on ship idk
		bool unk53F;
		PAD(16);
		double m_lastJumpTime; // 0x550
		double unk558;
		PAD(36);
		float unk584;
		PAD(20);
		GameObject* unk59C;
		PAD(8);
		GJRobotSprite* RobotSprite;//unk5A8
		GJSpiderSprite* SpiderSprite;//unk5AC
		bool unk5B0;
		cocos2d::CCParticleSystemQuad* m_playerGroundParticles;
		cocos2d::CCParticleSystemQuad* m_unk5B8;
		cocos2d::CCParticleSystemQuad* m_shipBoostParticles;
		cocos2d::CCParticleSystemQuad* m_vehicleGroundParticles;
		cocos2d::CCParticleSystemQuad* m_unk5C4;
		cocos2d::CCParticleSystemQuad* m_robotJumpParticles;
		cocos2d::CCParticleSystemQuad* m_unk5CC;
		PAD(4);
		cocos2d::CCParticleSystemQuad* unk5D4;
		cocos2d::CCParticleSystemQuad* unk5D8;
		PAD(32);
		bool unk5FC;
		bool unk5FD;
		bool m_bDropping; // 0x5FE Black Orb Clicked
		PAD(17);
		bool unk610;
		bool m_isHolding; // 0x611
		bool m_hasJustHeld; // 0x612
		bool m_isHolding2; // 0x613 why are there 2 mr robert
		bool m_hasJustHeld2; // 0x614
		int unk618;
		float unk61C;
		int unk620; // always 213
		bool m_canRobotJump; // 0x624
		double m_yAccel; // 0x628
		bool unk630;
		bool unk631;
		float unk634;
		bool m_isShip; // 0x638
		bool m_isBird; // 0x639 ufo
		bool m_isBall; // 0x63A
		bool m_isDart; // 0x63B wave
		bool m_isRobot; // 0x63C
		bool m_isSpider; // 0x63D
		bool m_isUpsideDown; // 0x63E
		PAD(1);
		bool m_isOnGround; // 0x640
		bool m_isDashing; // 0x641
		float m_vehicleSize; // 0x644
		float m_playerSpeed; // 0x648
		cocos2d::CCPoint unk64C; // last pos idk
		cocos2d::CCPoint m_lastPortalPos; // 0x654
		cocos2d::CCLayer* unk65C;
		bool m_isSliding; // 0x660
		bool m_isRising; // 0x661
		bool unk662;
		cocos2d::CCPoint m_lastGroundedPos; // 0x664
		cocos2d::CCArray* m_touchingRings; // 0x66C
		GameObject* m_lastActivatedPortal; // 0x670
		bool unk674;
		PAD(7);
		cocos2d::CCPoint m_position; // 0x67C
		bool unk684;
		bool unk685;
		double unk688;
		PAD(8);
		float m_groundHeight; // 0x698
		float unk69C; // seems to be y vel, cant directly change it though
		PAD(4);
		float unk6A4[200]; // last 200 Y positions, tf
		PAD(28);

		virtual void update(float ft) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1e8200)(this, ft);
		}
		virtual void setScaleX(float ft) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1fa7e0)(this, ft);
		}
		virtual void setScaleY(float ft) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1fa7e0)(this, ft);
		}
		virtual void setScale(float ft) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1fa820)(this, ft);
		}
		virtual void setPosition(cocos2d::CCPoint const& point) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, cocos2d::CCPoint const&)>(base + 0x1f7370)(this, point);
		}
		virtual void setVisible(bool visible) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1FA860)(this, visible);
		}
		virtual void setRotation(float ft) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1fa650)(this, ft);
		}
		virtual void setOpacity(unsigned char o) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, unsigned char)>(base + 0x1f7d40)(this, o);
		}
		virtual void setColor(cocos2d::_ccColor3B const& col3b){
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, cocos2d::_ccColor3B const&)>(base + 0x1f77f0)(this, col3b);
		}
		virtual void setFlipX(bool pr) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1fa690)(this, pr);
		}
		virtual void setFlipY(bool pr) {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1fa740)(this, pr);
		}
		virtual void resetObject() {
			return reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1eecd0)(this);
		}
		virtual cocos2d::CCPoint getRealPosition() {
			return reinterpret_cast<cocos2d::CCPoint(__thiscall*)(PlayerObject*)>(base + 0x1f7e20)(this);
		}
		void addAllParticles() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e7d60)(this);
		}
		void boostPlayer(float boost) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1f8f30)(this, boost);
		}
		void convertToClosestRotation(float rotidk) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1e9ac0)(this, rotidk);
		}
		void copyAttributes(PlayerObject* plObj) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, PlayerObject*)>(base + 0x1f93f0)(this, plObj);
		}
		void deactivateParticle() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e8f50)(this);
		}
		void playerDestroyed(bool param1) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1efaa0)(this, param1);
		}
		void pushButton(int button) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, int)>(base + 0x1F4E40)(this, button);
		}
		void releaseButton(int button) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, int)>(base + 0x1F4F70)(this, button);
		}
		bool playerIsFalling() {
			return reinterpret_cast<bool(__thiscall*)(PlayerObject*)>(base + 0x1f5d60)(this);
		}
		void runRotateAction() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9bf0)(this);
		}
		void playBurstEffect() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f6790)(this);
		}
		void spiderTestJump(bool param1) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1ed360)(this, param1);
		}
		void incrementJumps() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9a20)(this);
		}
		void flipGravity(bool param1, bool param2) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool, bool)>(base + 0x1f59d0)(this, param1, param2);
		}
		void runNormalRotation() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1e9c50)(this);
		}
		void runBallRotation(float ft) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, float)>(base + 0x1e9d10)(this,ft);
		}
		void playDynamicSpiderRun() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f9d80)(this);
		}
		void activateStreak() {
			reinterpret_cast<void(__thiscall*)(PlayerObject*)>(base + 0x1f9080)(this);
		}
		void stopRotation(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1e9aa0)(this, boolean);
		}
		void toggleBirdMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f6050)(this, boolean);
		}
		void toggleDartMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f62c0)(this, boolean);
		}
		void toggleFlyMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f5e40)(this, boolean);
		}
		/*void toggleGhostEffect(GhostType type) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, GhostType)>(base + 0x1f8930)(this, type);
		}*/
		void togglePlayerScale(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f9640)(this, boolean);
		}
		void toggleRobotMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f6a10)(this, boolean);
		}
		void toggleRollMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f68e0)(this, boolean);
		}
		void toggleSpiderMode(bool boolean) {
			reinterpret_cast<void(__thiscall*)(PlayerObject*, bool)>(base + 0x1f94d1)(this, boolean);
		}

		//custom func, returns bool(!m_isShip && !m_isBall && !m_isBird && !m_isDart && !m_isRobot && !m_isSpider)
		bool isCube() {
			return bool(!m_isShip && !m_isBall && !m_isBird && !m_isDart && !m_isRobot && !m_isSpider);
		}
	};
}

#endif