#ifndef __HARDSTREAK_H__
#define __HARDSTREAK_H__

#include <gd.h>

namespace gd {
    class GDH_DLL HardStreak : public cocos2d::CCDrawNode {
        public:
        cocos2d::CCArray* m_pointsArr; // 0x011C
        cocos2d::CCPoint m_currentPoint; // 0x0120 where the wave is at rn
        float m_waveSize; // 0x0128 bad name but its 1.0 for regular and 0.6 mini
        float m_pulseSize; // 0x012C
        bool m_isSolid; // 0x0130

            //reinterpret_cast<void(__thiscall*)(HardStreak*)>(base + 0x1e8f50)(this);

        virtual bool init() {
            reinterpret_cast<void(__thiscall*)(HardStreak*)>(base + 0x14e430)(this);
            //= mac 0x5c090, win 0x14e430;
        }
        void addPoint(cocos2d::CCPoint pos) {
            reinterpret_cast<void(__thiscall*)(HardStreak*, cocos2d::CCPoint)>(base + 0x14ebc0)(this, pos);
            //= mac 0x5c950, win 0x14ebc0;
        }
        void clearBehindXPos(float qqq) {
            reinterpret_cast<void(__thiscall*)(HardStreak*, float)>(base + 0x14ec00)(this, qqq);
            // = mac 0x5cb40, win 0x14ec00;
        }
        static HardStreak* create() {
            reinterpret_cast<HardStreak* (__thiscall*)()>(base + 0x14e390)();
            // = mac 0x5bfd0, win 0x14e390;
        }
        void firstSetup() {
            reinterpret_cast<void(__thiscall*)(HardStreak*)>(base + 0x14e490)(this);
            // = mac 0x5c160, win 0x14e490;
        }
        void stopStroke() {
            reinterpret_cast<void(__thiscall*)(HardStreak*)>(base + 0x14e460)(this);
            // = mac 0x5c8f0, win 0x14e460;
        }
        void updateStroke(float qqq) {
            reinterpret_cast<void(__thiscall*)(HardStreak*, float)>(base + 0x14e530)(this, qqq);
            // = mac 0x5c240, win 0x14e530;
        }
    }; // size = 0x134
}

#endif