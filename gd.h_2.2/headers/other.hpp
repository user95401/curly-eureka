#ifndef __OTHER_H__
#define __OTHER_H__
#include <gd.h>
namespace gd {
	enum GJLevelType {
		kGJLevelTypeLocal = 1,
		kGJLevelTypeEditor = 2,
		kGJLevelTypeSaved = 3
	};
	enum GJDifficulty {
		kGJDifficultyAuto = 0,
		kGJDifficultyEasy = 1,
		kGJDifficultyNormal = 2,
		kGJDifficultyHard = 3,
		kGJDifficultyHarder = 4,
		kGJDifficultyInsane = 5,
		kGJDifficultyDemon = 6,
		kGJDifficultyDemonEasy = 7,
		kGJDifficultyDemonMedium = 8,
		kGJDifficultyDemonInsane = 9,
		kGJDifficultyDemonExtreme = 10
	};
	class GDH_DLL GJGameLevel /* 0x3bc */ : public cocos2d::CCNode {
	public:
		cocos2d::CCDictionary* m_lastBuildSave;
		int m_nLevelID_rand; // 0xf0
		int m_nLevelID_seed; // 0xf4 
		int m_nLevelID;      // 0xf8
		std::string m_levelName;
		std::string m_levelDesc;
		std::string m_levelString;
		std::string m_creatorName;
		std::string m_recordString;
		std::string m_uploadDate;
		std::string m_updateDate;
		std::string m_unkString1;
		std::string m_unkString2;
		cocos2d::CCPoint m_unkPoint;
		int m_nUserID_rand;     // 0x1a4
		int m_nUserID_seed;     // 0x1a8
		int m_nUserID;          // 0x1ac
		int m_nAccountID_rand;  // 0x1b0
		int m_nAccountID_seed;  // 0x1b4
		int m_nAccountID;       // 0x1b8
		GJDifficulty m_difficulty;
		int m_audioTrack;
		int m_songID;
		int m_levelRev;
		bool m_unlisted;
		int m_nObjectCount_rand;// 0x1d0
		int m_nObjectCount_seed;// 0x1d4
		int m_nObjectCount;     // 0x1d8
		int m_levelIndex;
		int m_ratings;
		int m_ratingsSum;
		int m_downloads;
		bool m_isEditable;
		bool m_gauntletLevel;
		bool m_gauntletLevel2;
		int m_workingTime;
		int m_workingTime2;
		bool m_lowDetailMode;
		bool m_lowDetailModeToggled;
		int m_nIsVerified_rand; // 0x1fc
		int m_nIsVerified_seed; // 0x200
		bool m_bIsVerified;     // 0x204
		bool m_isVerifiedRaw;
		bool m_isUploaded;
		bool m_hasBeenModified;
		int m_levelVersion;
		int m_gameVersion;
		int m_nAttempts_rand;   // 0x210
		int m_nAttempts_seed;   // 0x214
		int m_nAttempts;        // 0x218
		int m_nJumps_rand;      // 0x21c
		int m_nJumps_seed;      // 0x220
		int m_nJumps;           // 0x224
		int m_nClicks_rand;     // 0x228
		int m_nClicks_seed;     // 0x22c
		int m_nClicks;          // 0x230
		int m_nAttemptTime_rand;// 0x234
		int m_nAttemptTime_seed;// 0x238
		int m_nAttemptTime;     // 0x23c
		int m_chk;
		bool m_isChkValid;
		bool m_isCompletionLegitimate;
		int m_nNormalPercent;   // 0x248, yes, it is out of order
		int m_nNormalPercent_seed;  // 0x24c
		int m_nNormalPercent_rand;  // 0x250
		int m_nOrbCompletion_rand;  // 0x254
		int m_nOrbCompletion_seed;  // 0x258
		int m_nOrbCompletion;       // 0x25c
		int m_nNewNormalPercent2_rand;  // 0x260
		int m_nNewNormalPercent2_seed;  // 0x264
		int m_nNewNormalPercent2;       // 0x268
		int m_practicePercent;
		int m_likes;
		int m_dislikes;
		int m_levelLength;
		int m_featured;
		int m_isEpic;
		bool m_levelFavorited;
		int m_levelFolder;
		int m_nDailyID_rand;    // 0x288
		int m_nDailyID_seed;    // 0x28c
		int m_nDailyID;         // 0x290
		int m_nDemon_rand;      // 0x294
		int m_nDemon_seed;      // 0x298
		int m_nDemon;           // 0x29c
		int m_demonDifficulty;
		int m_nStars_rand;      // 0x2a4
		int m_nStars_seed;      // 0x2a8
		int m_nStars;           // 0x2ac
		bool m_autoLevel;
		int m_coins;
		int m_nCoinsVerified_rand;  // 0x2b8
		int m_nCoinsVerified_seed;  // 0x2bc
		int m_nCoinsVerified;       // 0x2c0
		int m_nPassword_rand;       // 0x2c4
		int m_nPassword_seed;       // 0x2c8
		int m_nOriginalLevel_rand;  // 0x2cc
		int m_nOriginalLevel_seed;  // 0x2d0
		int m_nOriginalLevel;       // 0x2d4
		bool m_twoPlayerMode;
		int m_failedPasswordAttempts;
		int m_nFirstCoinVerified_rand;  // 0x2e0
		int m_nFirstCoinVerified_seed;  // 0x2e4
		int m_nFirstCoinVerified;       // 0x2e8
		int m_nSecondCoinVerified_rand; // 0x2ec
		int m_nSecondCoinVerified_seed; // 0x2f0
		int m_nSecondCoinVerified;      // 0x2f4
		int m_nThirdCoinVerified_rand;  // 0x2f8
		int m_nThirdCoinVerified_seed;  // 0x2fc
		int m_nThirdCoinVerified;   // 0x300
		int m_starsRequested;
		bool m_showedSongWarning;
		int m_starRatings;
		int m_starRatingsSum;
		int m_maxStarRatings;
		int m_minStarRatings;
		int m_demonVotes;
		int m_rateStars;
		int m_rateFeature;
		std::string m_rateUser;
		bool m_dontSave;
		bool m_levelNotDownloaded;
		int m_requiredCoins;
		bool m_isUnlocked;
		cocos2d::CCPoint m_lastCameraPos;
		float m_fastEditorZoom;
		int m_lastBuildTab;
		int m_lastBuildPage;
		int m_lastBuildGroupID;
		GJLevelType m_levelType;
		int m_M_ID;
		std::string m_tempName;
		std::string m_capacityString;
		bool m_highObjectsEnabled;
		std::string m_personalBests;
		PAD(0x78);
		//2.200, this function is inlined on pc builds
		static GJGameLevel* create() {
			CALLLOG;
			return reinterpret_cast<GJGameLevel * (__stdcall*)()>(
				base + 0x112540
				)();
		}
		//2.200
		static GJGameLevel* createWithCoder(DS_Dictionary* dict, bool a1) {
			CALLLOG;
			//inlined on windows
			auto level = GJGameLevel::create();
			level->dataLoaded(dict);
			return level;
		}
		//2.200
		void dataLoaded(DS_Dictionary* dict) {
			CALLLOG;
			return reinterpret_cast<void(__thiscall*)(
				GJGameLevel*, DS_Dictionary*
				)>(base + 0x113B90)(this, dict);
		}
		inline bool isPlatformer() {
			CALLLOG;
			return m_levelLength == 5;
		}
	};
	class AchievementBar : public cocos2d::CCNodeRGBA {
	protected:
		PAD(0x24);//what ever, dont fucking care asdsadv fduasid

	public:
		static AchievementBar* create(const char* title,
			const char* desc, const char* icon, bool quest) {
			auto pRet = reinterpret_cast<AchievementBar * (__fastcall*)(const char*,
				const char*, const char*, bool)>(
					base + 0x3B120
					)(title, desc, icon, quest);
			__asm add esp, 0x8
			return pRet;
		}
	};
	class AchievementNotifier : public cocos2d::CCNode {
	protected:
		cocos2d::CCScene* m_pCurrentScene;
		cocos2d::CCArray* m_pQueue;
		AchievementBar* m_pCurrentAchievement;

	public:
		static AchievementNotifier* sharedState() {
			//55 8B EC 6A FF 68 1C 49 88 00 64 A1 00 00 00 00 50 51 56 A1 - 21
			uintptr_t addr = patterns::find_pattern("^ ?????? 1C 49 88 00 64 A1");
			//addr = gd::base + 0xFC90; //2.1 GeometryDash.exe+FC90
			ModUtils::OpenConsole();
			ModUtils::log((ModUtils::ReadProcMemAsStr(addr, 26)).c_str());
			return reinterpret_cast<AchievementNotifier * (__stdcall*)()>(
				addr
				)();
		}
		void showNextAchievement() {
			return reinterpret_cast<void(__thiscall*)(AchievementNotifier*)>(
				base + 0xFD60
				)(this);
		}
		//this is inlined on win32 so let's reconstruct it
		void notifyAchievement(const char* title, const char* desc, const char* icon, bool quest) {
			m_pQueue->addObject(AchievementBar::create(title, desc, icon, quest));
			if (!m_pCurrentAchievement) {
				this->showNextAchievement();
			}
		}
	};
}
#endif