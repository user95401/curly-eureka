#ifndef __DIALOGLAYER_H__
#define __DIALOGLAYER_H__

#include <gd.h>

namespace gd {
    class GDH_DLL DialogLayer : public cocos2d::CCLayerColor {
        public:
            char pad1[0x8];
            cocos2d::CCLayer *m_pLayer;
            cocos2d::CCLabelBMFont *m_pTitle;
            TextArea *m_pDialog;
            cocos2d::CCSprite *m_pIcon;
            cocos2d::CCArray *m_pDialogObjects;
            char PAD2[0X4];
            cocos2d::CCSprite *m_pChatBtn;
            bool m_bUnk;
            char m_bCanSkip;
            char PAD3[0x2];
            DWORD m_pUnk;
            char PAD4[0x8];
            //Fuck off I want to sleep
            //static DialogLayer* createDialogLayer(DialogObject* DialogObj, cocos2d::CCArray Array, int color) {
            //    return reinterpret_cast<DialogLayer*(__fastcall*)(DialogObject*, cocos2d::CCArray, int)>(base + 0x6D470)(DialogObj, Array, color);
            //}
            //bool init(DialogLayer DialogLay, DialogObject DialogObj, cocos2d::CCArray Array, int ok) {
            //    return reinterpret_cast<bool(__thiscall*)(void*, DialogLayer, DialogObject, cocos2d::CCArray, int)>(base + 0x6D520)(this, DialogLay, DialogObj, Array, ok);
            //}
            //virtual void onEnter() {
            //    reinterpret_cast<void(__thiscall*)(void*)>(base + 0x23750)(this);
            //}// same as every other FLAlertLayer
            //cocos2d::CCAction* animateIn(int location) {
            //    return reinterpret_cast<CCAction*(__thiscall*)(void*, int)>(base + 0x6E130)(this, location);
            //}// = win 0x6E130;
    };
}

#endif
