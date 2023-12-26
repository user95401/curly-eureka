#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

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

		bool m_switchModes;
		bool m_toFullscreen;
		bool m_reloading;
		bool m_unknown0;
		PAD(4);
		cocos2d::CCDictionary* m_valueKeeper;
		cocos2d::CCDictionary* m_unlockValueKeeper;
		cocos2d::CCDictionary* m_customObjectDict;
		double m_adTimer;
		double m_adCache;
		PAD(8);
		double m_unknownDouble;
		PAD(8);
		bool m_loaded;
		std::string m_unknownString;
		PlayLayer* m_playLayer;
		LevelEditorLayer* m_levelEditorLayer;
		int m_unknown1;
		MenuLayer* m_menuLayer;
		bool m_inMenuLayer;
		void* m_unknownVariable;
		bool m_unknownBool3;
		bool m_unknownPlayLayerBool;
		bool m_unknownBool4;
		bool m_unknownBool5;
		std::string m_playerUDID;
		std::string m_playerName;
		bool m_commentsEnabled;
		int m_playerUserID;
		float m_backgroundMusicVolume;
		float m_effectsVolume;
		float m_timeOffset;
		bool m_ratedGame;
		bool m_likedFacebook;
		bool m_followedTwitter;
		bool m_subbedYoutube;
		double m_socialsDuration;
		bool m_showedAd;
		bool m_unknownBool;
		bool m_editorEnabled;
		int m_sceneEnum;
		int m_searchObjectType;
		bool m_unknownBool6;
		IconType m_playerFrame;
		int m_playerShip;
		int m_playerBall;
		int m_playerBird;
		int m_playerDart;
		int m_playerRobot;
		int m_playerSpider;
		int m_playerColor;
		int m_playerColor2;
		int m_playerStreak;
		int m_playerDeathEffect;
		int m_chk;
		int m_secretNumber;
		bool m_playerGlow;
		IconType m_playerIconType;
		bool m_everyPlaySetup;
		bool m_showSongMarkers;
		bool m_showBPMMarkers;
		bool m_recordGameplay;
		bool m_showProgressBar;
		bool m_performanceMode;
		bool m_clickedGarage;
		bool m_clickedEditor;
		bool m_clickedName;
		bool m_clickedPractice;
		bool m_showedEditorGuide;
		bool m_showedRateDiffDialog;
		bool m_showedRateStarDialog;
		bool m_showedLowDetailDialog;
		PAD(48);
		int m_bootups;
		bool m_hasRatedGame;
		bool m_unk0;
		bool m_unk1;
		bool m_unk2;
		bool m_gameCenterEnabled;
		bool m_smoothFix;
		bool m_ratePower;
		bool m_canGetLevelSaveData;
		int m_resolution;
		cocos2d::TextureQuality m_quality;

		int getPlayerFrame() { return m_playerFrame; }
		int getPlayerShip() { return m_playerShip; }
		int getPlayerBall() { return m_playerBall; }
		int getPlayerBird() { return m_playerBird; }
		int getPlayerDart() { return m_playerDart; }
		int getPlayerRobot() { return m_playerRobot; }
		int getPlayerSpider() { return m_playerSpider; }
		int getPlayerStreak() { return m_playerStreak; }
		int getPlayerDeathEffect() { return m_playerDeathEffect; }
		int getPlayerColor() { return m_playerColor; }
		int getPlayerColor2() { return m_playerColor2; }
		bool getPlayerGlow() { return m_playerGlow; }
		IconType getPlayerIconType() { return m_playerIconType; }
		void setPlayerFrame(IconType id) { m_playerFrame = id; }
		void setPlayerShip(int id) { m_playerShip = id; }
		void setPlayerBall(int id) { m_playerBall = id; }
		void setPlayerBird(int id) { m_playerBird = id; }
		void setPlayerDart(int id) { m_playerDart = id; }
		void setPlayerRobot(int id) { m_playerRobot = id; }
		void setPlayerSpider(int id) { m_playerSpider = id; }
		void setPlayerStreak(int id) { m_playerStreak = id; }
		void setPlayerDeathEffect(int id) { m_playerDeathEffect = id; }
		void setPlayerColor(int id) { m_playerColor = id; }
		void setPlayerColor2(int id) { m_playerColor2 = id; }
		void setPlayerGlow(bool v) { m_playerGlow = v; }
		void setPlayerIconType(IconType v) { m_playerIconType = v; }
		void setQuality(cocos2d::TextureQuality quality) { m_quality = quality; }

		PlayLayer* getPlayLayer() { return m_playLayer; }
		LevelEditorLayer* getEditorLayer() { return m_levelEditorLayer; }

		bool getGameVariableDefault(const char* key, bool defaultValue) {
			auto object = static_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
			if (object == nullptr) return defaultValue;
			return object->boolValue();
		}

		int getIntGameVariableDefault(const char* key, int defaultValue) {
			auto object = static_cast<cocos2d::CCString*>(m_valueKeeper->objectForKey(std::string("gv_") + key));
			if (object == nullptr) return defaultValue;
			return object->intValue();
		}
		static GameManager* sharedState() {
			return reinterpret_cast<GameManager * (__stdcall*)()>(base + 0x11f720)();
		}
	};
}

#endif