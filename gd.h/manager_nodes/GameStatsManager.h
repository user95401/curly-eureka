#ifndef __GAMESTATSMANAGER_H__
#define __GAMESTATSMANAGER_H__

#include <gd.h>

namespace gd {

    class GJChallengeItem;

    class GameStatsManager : public cocos2d::CCNode {
    public:
        // i stole this from geode lol

        PAD(0x28);
        cocos2d::CCDictionary* m_dailyChests;
        cocos2d::CCDictionary* m_worldAdvertChests;
        cocos2d::CCDictionary* m_activeChallenges;
        cocos2d::CCDictionary* m_upcomingChallenges;
        PAD(0xc);
        cocos2d::CCDictionary* m_playerStats;
        PAD(0x10);
        cocos2d::CCDictionary* m_completedLevels;
        cocos2d::CCDictionary* m_verifiedUserCoins;
        cocos2d::CCDictionary* m_pendingUserCoins;
        cocos2d::CCDictionary* m_purchasedItems;
        cocos2d::CCDictionary* m_onlineCurrencyScores;
        cocos2d::CCDictionary* m_mainCurrencyScores;
        cocos2d::CCDictionary* m_gauntletCurrencyScores;
        cocos2d::CCDictionary* m_timelyCurrencyScores;
        cocos2d::CCDictionary* m_onlineStars;
        cocos2d::CCDictionary* m_timelyStars;
        cocos2d::CCDictionary* m_gauntletDiamondScores;
        cocos2d::CCDictionary* m_timelyDiamondScores;
        cocos2d::CCDictionary* m_unusedCurrencyAwardDict;
        cocos2d::CCDictionary* m_challengeDiamonds;
        cocos2d::CCDictionary* m_completedMappacks;
        cocos2d::CCDictionary* m_weeklyChest;
        cocos2d::CCDictionary* m_treasureRoomChests;
        int m_bonusKeySeed;
        int m_bonusKeyRand;
        int m_bonusKey;
        cocos2d::CCDictionary* m_miscChests;
        
        GJChallengeItem* getChallenge(int id) {
            return reinterpret_cast<GJChallengeItem*(__thiscall*)(GameStatsManager*, int)>(base + 0xA2FB0)(this, id);
        }

        static GameStatsManager* sharedState() {
            return reinterpret_cast<GameStatsManager*(__stdcall*)()>(
                base + 0xF1E50
            )();
        }

        int getAwardedCurrencyForLevel(GJGameLevel* level) {
            return reinterpret_cast<int(__thiscall*)(GameStatsManager*, GJGameLevel*)>(base + 0xF83E0)(this, level);
        }

        int getBaseCurrencyForLevel(GJGameLevel* level) {
            return reinterpret_cast<int(__thiscall*)(GameStatsManager*, GJGameLevel*)>(base + 0xF8530)(this, level);
        }
    };

}

#endif
