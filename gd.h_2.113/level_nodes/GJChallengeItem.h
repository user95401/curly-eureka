#pragma once
#ifndef GJCHALLENGEITEM_H
#define GJCHALLENGEITEM_H

#include <gd.h>

namespace gd {

    enum GJChallengeType
    {
        kGJChallengeTypeUnknown = 0x0,
        kGJChallengeTypeOrb = 0x1,
        kGJChallengeTypeUserCoin = 0x2,
        kGJChallengeTypeStars = 0x3
    };

    //i stole gjchallengeitem from wylies gd decompiled
    class GJChallengeItem : public cocos2d::CCObject {
        public:
            GJChallengeType m_eChallengeType;
            int m_nCountSeed;
            int m_nCountRand;
            int m_nCount;
            int m_nRewardSeed;
            int m_nRewardRand;
            int m_nReward;
            int m_nGoalSeed;
            int m_nGoalRand;
            int m_nGoal;
            int m_nTimeLeft;
            bool m_bCanClaim;
            int m_nQuestPosition;
            std::string m_sQuestName;
    };

}

#endif
