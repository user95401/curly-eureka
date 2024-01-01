#ifndef __MANAGERS_H__
#define __MANAGERS_H__

#include <gd.h>

namespace gd {

	enum IconType {
		kIconTypeCube = 0,
		kIconTypeShip = 1,
		kIconTypeBall = 2,
		kIconTypeUfo = 3,
		kIconTypeWave = 4,
		kIconTypeRobot = 5,
		kIconTypeSpider = 6,
		kIconTypeDeathEffect = 98,
		kIconTypeSpecial = 99,
	};

	enum UnlockType {
		kUnlockTypeUnknown = 0,
		kUnlockTypeCube = 1,
		kUnlockTypeColor1 = 2,
		kUnlockTypeColor2 = 3,
		kUnlockTypeShip = 4,
		kUnlockTypeBall = 5,
		kUnlockTypeUfo = 6,
		kUnlockTypeWave = 7,
		kUnlockTypeRobot = 8,
		kUnlockTypeSpider = 9,
		kUnlockTypeSpecial = 10,
		kUnlockTypeDeathEffect = 11,
		kUnlockTypeGlow = 12,
	};

	class PlayLayer;
	class LevelEditorLayer;
	class GJGameLevel;
	class MenuLayer;

	class GDH_DLL GManager : public cocos2d::CCNode {
	protected:
		std::string m_sFileName; // 0xec
		bool m_bSetup;			 // 0x104
		bool m_bSaved;			 // 0x105

	public:
		virtual void encodeDataTo(DS_Dictionary* data) {}
		virtual void dataLoaded(DS_Dictionary* data) {}
		virtual void firstLoad() {}
	};

	class GDH_DLL GameManager : public GManager {
	public:
		void reloadMenu() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c510)(this);
		}
		void doQuickSave() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12bf00)(this);
		}
		bool isIconUnlocked(int id, IconType type) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, int, IconType)>(base + 0x120170)(this, id, type);
		}
		static GameManager* sharedState() {
			return reinterpret_cast<GameManager*(__stdcall*)()>(base + 0x11f720)();
		}
		void reloadAllStep2() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c620)(this);
		}
		void reloadAllStep3() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c780)(this);
		}
		void reloadAllStep4() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c820)(this);
		}
		void reloadAllStep5() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c890)(this);
		}
		void fadeInMenuMusic() {//todo: fadeInMenuMusic looks strange
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x11FBD0)(this);
		}
		bool getGameVariable(char const* gvtag) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, char const*)>(base + 0x126920)(this, gvtag);
		}
		bool isColorUnlocked(int id, UnlockType type) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, int, UnlockType)>(base + 0x120670)(this, id, type);
		}
		void queueReloadMenu() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12c4c0)(this);
		}
		void setGameVariable(char const* gvtag, bool b) {
			return reinterpret_cast<void(__thiscall*)(GameManager*, char const*, bool)>(base + 0x1266D0)(this, gvtag, b);
		}
		void updateCustomFPS() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x12cd40)(this);
		}
		void resolutionForKey(int key) {
			reinterpret_cast<void(__thiscall*)(GameManager*, int)>(base + 0x12c8e0)(this, key);
		}
		void returnToLastScene(GJGameLevel* pGJGameLevel) {
			reinterpret_cast<void(__thiscall*)(GameManager*, GJGameLevel*)>(base + 0x12C1F0)(this, pGJGameLevel);
		}
		std::string getPracticeMusicFile() {
			return reinterpret_cast<std::string(__thiscall*)(GameManager*)>(base + 0x11f990)(this);
		}
		void reportPercentageForLevel(int a1, int a2, bool a3) {
			reinterpret_cast<void(__thiscall*)(GameManager*, int, int, bool)>(base + 0x120f30)(this, a1, a2, a3);
		}
	};

	class GDH_DLL GameLevelManager : public cocos2d::CCNode {
	public:

		static GameLevelManager* sharedState() {//upd
			return reinterpret_cast<GameLevelManager * (__stdcall*)()>(gd::base + 0xF2D90)();
		}

		GJGameLevel* getMainLevel(int id, bool unk) {//upd
			return reinterpret_cast<GJGameLevel * (__thiscall*)(GameLevelManager*, int, bool)>(base + 0xF40E0)(this, id, unk);
		}

		void firstSetup(bool newFilter) {//upd
			reinterpret_cast<void(__thiscall*)(void*, bool)>(base + 0x397d10)(this, newFilter);
		}

		GJUserScore* getGJUserInfo(int a1) {//upd, idk what class it returns tbh
			return reinterpret_cast<GJUserScore * (__thiscall*)(void*, bool)>(base + 0x105270)(this, a1);
		}

		bool isDLActive(char const* a1) {
			return reinterpret_cast<bool(__fastcall*)(GameLevelManager*, char const*)>(base + 0xf7910)(this, a1);
		}

		void uploadLevel(GJGameLevel* pGJGameLevel) {
			reinterpret_cast<void(__fastcall*)(GameLevelManager*, GJGameLevel*)>(base + 0xFA560)(this, pGJGameLevel);
		}

		//im lazy
	};

	class GDH_DLL GJAccountManager : public cocos2d::CCNode {
	public:
		PAD(0x4);
		std::string m_username;
		int m_accountID;
		PAD(0x8);
		std::string m_gjp2;
		/*	
			m_username 268,
			m_accountID 292,
			m_gjp2 304,
		*/
	public:
		static GJAccountManager* sharedState() {
			return reinterpret_cast<GJAccountManager * (__stdcall*)()>(
				base + 0x186ff0
				)();
		}
		auto getUsername() { return *reinterpret_cast<std::string*>(reinterpret_cast<uintptr_t>(this) + 268); }
		//gjp2
		auto getPassword() { return *reinterpret_cast<std::string*>(reinterpret_cast<uintptr_t>(this) + 292); }
		auto getAccountID() { return *reinterpret_cast<std::string*>(reinterpret_cast<uintptr_t>(this) + 304); }
	};
}

#endif