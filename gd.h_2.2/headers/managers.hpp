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
		//2.202
		static GameManager* sharedState() {
			return reinterpret_cast<GameManager*(__stdcall*)()>(base + 0x120860)();
		}
		bool isColorUnlocked(int id, UnlockType type) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, int, UnlockType)>(base + 0x1217B0)(this, id, type);
		}
		bool isIconUnlocked(int id, IconType type) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, int, IconType)>(base + 0x1212B0)(this, id, type);
		}
		bool getGameVariable(char const* gvtag) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, char const*)>(base + 0x127A50)(this, gvtag);
		}
		int getIntGameVariable(char const* gvtag) {
			return reinterpret_cast<int(__thiscall*)(GameManager*, char const*)>(base + 0x127FA0)(this, gvtag);
		}
		bool getUGV(char const* gvtag) {
			return reinterpret_cast<bool(__thiscall*)(GameManager*, char const*)>(base + 0x127D40)(this, gvtag);
		}
		void setGameVariable(char const* gvtag, bool b) {
			return reinterpret_cast<void(__thiscall*)(GameManager*, char const*, bool)>(base + 0x127800)(this, gvtag, b);
		}
		void setIntGameVariable(char const* gvtag, int val) {
			return reinterpret_cast<void(__thiscall*)(GameManager*, char const*, bool)>(base + 0x127EA0)(this, gvtag, val);
		}
		void setUGV(char const* gvtag, int val) {
			return reinterpret_cast<void(__thiscall*)(GameManager*, char const*, bool)>(base + 0x127BF0)(this, gvtag, val);
		}
		std::string getPracticeMusicFile() {
			return reinterpret_cast<std::string(__thiscall*)(GameManager*)>(base + 0x120AD0)(this);
		}
		void reportPercentageForLevel(int a1, int a2, bool a3) {
			reinterpret_cast<void(__thiscall*)(GameManager*, int, int, bool)>(base + 0x120f30)(this, a1, a2, a3);
		}
		void fadeInMusic(std::string sName) {
			reinterpret_cast<void(__thiscall*)(GameManager*, std::string)>(base + 0x120D80)(this, sName);
		}
		//menuLoop
		void fadeInMusic() {
			reinterpret_cast<void(__thiscall*)(GameManager*)>(base + 0x120D10)(this);
		}
		//members
		/*
		GameManager:
			PlayLayer* | 0x198 -> playLayer1
			LevelEditorLayer* | 0x19C -> levelEditorLayer
			PlayLayer* | 0x1A0 -> playLayer2
			PlayLayer* | 0x1A8 -> menuLayer
			bool | 0x1AC -> inMenuLayer
		*/
		void getPlayLayer1() { MEMBERBYOFFSET(cocos2d::CCLayer*, this, 0x198); }
		void getLevelEditorLayer() { MEMBERBYOFFSET(cocos2d::CCLayer*, this, 0x19C); }
		void getPlayLayer2() { MEMBERBYOFFSET(cocos2d::CCLayer*, this, 0x1A0); }
		void getMenuLayer() { MEMBERBYOFFSET(cocos2d::CCLayer*, this, 0x1A8); }
		void isInMenuLayer() { MEMBERBYOFFSET(bool, this, 0x1AC); }
	};

	class GDH_DLL GameLevelManager : public cocos2d::CCNode {
	public:

		static GameLevelManager* sharedState() {//upd
			//return reinterpret_cast<GameLevelManager * (__stdcall*)()>(gd::base + 0xF2D90)();
		}

		GJGameLevel* getMainLevel(int id, bool unk) {//upd
			//return reinterpret_cast<GJGameLevel * (__thiscall*)(GameLevelManager*, int, bool)>(base + 0xF40E0)(this, id, unk);
		}

		void firstSetup(bool newFilter) {//upd
			//reinterpret_cast<void(__thiscall*)(void*, bool)>(base + 0x397d10)(this, newFilter);
		}

		GJUserScore* getGJUserInfo(int a1) {//upd, idk what class it returns tbh
			//return reinterpret_cast<GJUserScore * (__thiscall*)(void*, bool)>(base + 0x105270)(this, a1);
		}

		bool isDLActive(char const* a1) {
			//return reinterpret_cast<bool(__fastcall*)(GameLevelManager*, char const*)>(base + 0xf7910)(this, a1);
		}

		void uploadLevel(GJGameLevel* pGJGameLevel) {
			//reinterpret_cast<void(__fastcall*)(GameLevelManager*, GJGameLevel*)>(base + 0xFA560)(this, pGJGameLevel);
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