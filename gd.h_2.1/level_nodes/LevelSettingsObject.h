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
            // TODO: make enums for these
            int m_startMode;
            Speed m_startSpeed;
            bool m_startMini;
            bool m_startDual;
            bool m_twoPlayerMode;
            float m_songOffset;
            bool m_fadeIn;
            bool m_fadeOut;
            int m_backgroundIndex;
            int m_groundIndex;
            int m_fontIndex;
            bool m_startsWithStartPos;
            bool m_isFlipped;
            GJGameLevel* m_level;
            std::string m_guidelineString;
            int m_defaultSongID;
            int m_colorPage;
            int m_groundLineIndex;

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
