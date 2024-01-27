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

        cocos2d::CCDictionary* m_pLastBuildSave;   // 0xec
		SeedValueRSV m_nLevelID;      // 0xf8
        std::string m_sLevelName;       // 0xfc
        std::string m_sLevelDesc;       // 0x114
        std::string m_sLevelString;     // 0x12c
        std::string m_sCreatorName;     // 0x144
        std::string m_sRecordString;    // 0x15c
        std::string m_sUploadDate; // 0x174
        std::string m_sUpdateDate; // 0x18c

		std::string m_unkString1;
		std::string m_unkString2;

		cocos2d::CCPoint m_unkPoint;
		gd::SeedValueRSV m_userID;
		gd::SeedValueRSV m_accountID;
		GJDifficulty m_difficulty;
		int m_audioTrack;
		int m_songID;
		int m_levelRev;
		bool m_unlisted;
		bool m_friendsOnly;
		gd::SeedValueRSV m_objectCount;
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
		bool m_selected;
		bool m_localOrSaved;
		bool m_disableShake;
		gd::SeedValueRS m_isVerified;
		bool m_isVerifiedRaw;
		bool m_isUploaded;
		bool m_hasBeenModified;
		int m_levelVersion;
		int m_gameVersion;

		gd::SeedValueRSV m_attempts;
		gd::SeedValueRSV m_jumps;
		gd::SeedValueRSV m_clicks;
		gd::SeedValueRSV m_attemptTime;
		int m_chk;
		bool m_isChkValid;
		bool m_isCompletionLegitimate;
		gd::SeedValueVSR m_normalPercent;
		gd::SeedValueRSV m_orbCompletion;
		gd::SeedValueRSV m_newNormalPercent2;
		int m_practicePercent;
		int m_likes;
		int m_dislikes;
		int m_levelLength;
		int m_featured;
		int m_isEpic;
		bool m_levelFavorited;
		int m_levelFolder;
		gd::SeedValueRSV m_dailyID;
		gd::SeedValueRSV m_demon;
		int m_demonDifficulty;
		gd::SeedValueRSV m_stars;
		bool m_autoLevel;
		int m_coins;
		gd::SeedValueRSV m_coinsVerified;
		gd::SeedValueRS m_password;
		gd::SeedValueRSV m_originalLevel;
		bool m_twoPlayerMode;
		int m_failedPasswordAttempts;
		gd::SeedValueRSV m_firstCoinVerified;
		gd::SeedValueRSV m_secondCoinVerified;
		gd::SeedValueRSV m_thirdCoinVerified;
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
		bool m_unlimitedObjectsEnabled;
		std::string m_personalBests;
		int m_timestamp;
		int m_unkInt;
		std::string m_songIDs;
		std::string m_sfxIDs;
		int m_54;
		int m_bestTime;
		int m_bestPoints;
		int m_k111;
		std::string m_unkString3;
		std::string m_unkString4;
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