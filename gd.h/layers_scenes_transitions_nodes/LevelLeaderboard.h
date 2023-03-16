#ifndef __LEVELLEADERBOARD_H__
#define __LEVELLEADERBOARD_H__

#include <gd.h>

namespace gd {

    class GJGameLevel;

    class LevelLeaderboard : public gd::FLAlertLayer {
    public:
        PAD(464 - sizeof(FLAlertLayer));
        GJGameLevel* level;
        int leaderboardType;

        void onUpdate(CCObject* sender) {
            reinterpret_cast<void(__thiscall*)(LevelLeaderboard*, CCObject*)>(base + 0x17D1B0)(this, sender);
        }

        static LevelLeaderboard* create(gd::GJGameLevel* level, int leaderboardType) { //lb type is actually enum member
            return reinterpret_cast<LevelLeaderboard*(__fastcall*)(gd::GJGameLevel*, int)>(
                gd::base + 0x17C440
            )(level, leaderboardType);
        }
    };

}

#endif
