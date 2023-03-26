#ifndef AppDelegate_H
#define AppDelegate_H

#include <gd.h>
//how this even works? im stupid 
namespace gd {
    class AppDelegate : public cocos2d::CCApplication {
        virtual bool applicationDidFinishLaunching() {
            return reinterpret_cast<bool(__thiscall*)(void*)>(base + 0x3cbb0)(this);
        }
        virtual void applicationDidEnterBackground() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3cf40)(this);
        }
        virtual void applicationWillEnterForeground() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3d130)(this);
        }
        virtual void applicationWillBecomeActive() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3ce90)(this);
        }
        virtual void applicationWillResignActive() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3cf20)(this);
        }
        virtual void trySaveGame() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3d5e0)(this);
        }
        virtual void willSwitchToScene(cocos2d::CCScene* tr) {
            reinterpret_cast<void(__thiscall*)(void*, cocos2d::CCScene*)>(base + 0x3d690)(this, tr);
        }
        static AppDelegate* get() {
            return static_cast<AppDelegate*>(cocos2d::CCApplication::sharedApplication());
        }
        bool musicTest() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3d580)(this);
        }
        void pauseGame() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3d3e0)(this);
        }
        void resumeSound() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3d4d0)(this);
        }
        void setupGLView() {
            reinterpret_cast<void(__thiscall*)(void*)>(base + 0x3c950)(this);
        }

        cocos2d::CCScene* m_runningScene;
    };
}

#endif
