#pragma once
#ifndef GJREWARDITEM_H
#define GJREWARDITEM_H

#include <gd.h>

namespace gd {

    enum GJRewardType
    {
        kGJRewardTypeUnknown = 0x0,
        kGJRewardTypeSmall = 0x1,
        kGJRewardTypeLarge = 0x2,
    };

    //i stole gjrewarditem from wylies gd decompiled
    class GJRewardItem : public cocos2d::CCObject {
        public:
            int m_nChestID;
            int m_nTimeRemaining;
            GJRewardType m_eRewardType;
            cocos2d::CCArray *m_pRewardObjects;
            bool m_bUnk;
    };

    //i stole this from geode gmd
    //i would like to applaud myself for consistency between using enum and enum class
    enum class SpecialRewardItem {
        FireShard = 0x1,
        IceShard = 0x2,
        PoisonShard = 0x3,
        ShadowShard = 0x4,
        LavaShard = 0x5,
        BonusKey = 0x6,
        Orbs = 0x7,
        Diamonds = 0x8,
        CustomItem = 0x9,
    };

    class GJRewardObject : public cocos2d::CCObject {
    public:
        SpecialRewardItem m_specialRewardItem;
        UnlockType m_unlockType;
        int m_itemID;
        int m_total;
    };

}

#endif
