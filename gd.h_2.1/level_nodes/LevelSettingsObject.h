#ifndef __LEVELSETTINGSOBJECT_H__
#define __LEVELSETTINGSOBJECT_H__

#include <gd.h>

namespace gd {
    class GJEffectManager;
    class GJGameLevel;

    enum Gamemode {
        kGamemodeCube = 0,
        kGamemodeShip = 1,
        kGamemodeBall = 2,
        kGamemodeUfo = 3,
        kGamemodeWave = 4,
        kGamemodeRobot = 5,
        kGamemodeSpider = 6,
    };

    enum Speed {
        kSpeedNormal = 0,
        kSpeedSlow = 1,
        kSpeedFast = 2,
        kSpeedFaster = 3,
        kSpeedFastest = 4,
    };

    class GDH_DLL LevelSettingsObject : public cocos2d::CCNode {
        public:
            GJEffectManager* m_effectManager;
            PAD(9);
            bool m_twoPlayerMode;
            PAD(26);
            GJGameLevel* m_level;
            std::string m_guidelineString;

            std::string getSaveString() {
                std::string res;

                reinterpret_cast<void(__thiscall*)(LevelSettingsObject*, std::string*)>(
                    base + 0x16ebf0
                )(this, &res);

                return res;
            }
    };
}

#endif
