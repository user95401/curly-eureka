#ifndef __LEADERBOARDSLAYER_H__
#define __LEADERBOARDSLAYER_H__

#include <gd.h>

namespace gd {

    class LeaderboardsLayer : public cocos2d::CCLayer {
    public:

        static LeaderboardsLayer* create(int leaderboardState) { //lb state is actually enum member
            return reinterpret_cast<LeaderboardsLayer*(__fastcall*)(int)>(
                gd::base + 0x158710
            )(leaderboardState);
        }
    };

}

#endif
