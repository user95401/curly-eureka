#ifndef __LEVELINFOLAYER_H__
#define __LEVELINFOLAYER_H__

#include <gd.h>

namespace gd {
    class GJGameLevel;
    class CCMenuItemSpriteExtra;
    class CCMenuItemToggler;
    class TextArea;

    class GDH_DLL EditLevelLayer :
        public cocos2d::CCLayer,
        public TextInputDelegate,
        public FLAlertLayerProtocol,
        public UploadActionDelegate,
        public UploadPopupDelegate,
        public SetIDPopupDelegate
    {
        public:
            cocos2d::CCMenu* m_pButtonMenu;
            GJGameLevel* m_pLevel;
            TextArea* m_pDescriptionInput;
            cocos2d::CCArray* m_pSomeArray;
            cocos2d::CCLabelBMFont* m_pSomeFont;

            static EditLevelLayer* create(gd::GJGameLevel* level) {
                return reinterpret_cast<EditLevelLayer*(__fastcall*)(gd::GJGameLevel*)>(
                    base + 0x6f530
                )(level);
            }

            static void scene(gd::GJGameLevel* level) {
                auto pScene = cocos2d::CCScene::create();

                pScene->addChild(gd::EditLevelLayer::create(level));

                cocos2d::CCDirector::sharedDirector()->replaceScene(
                    cocos2d::CCTransitionFade::create(.5f, pScene)
                );
            }
    };

    class GDH_DLL LevelInfoLayer : public cocos2d::CCLayer,
        LevelDownloadDelegate,
        LevelUpdateDelegate,
        RateLevelDelegate,
        LikeItemDelegate,
        FLAlertLayerProtocol,
        LevelDeleteDelegate,
        NumberInputDelegate,
        SetIDPopupDelegate
    {
        public:
            PAD(0x4)
            cocos2d::CCMenu* m_pPlayBtnMenu;
            GJGameLevel* m_pLevel;
            cocos2d::CCArray* m_pUnknown;
            CCMenuItemSpriteExtra* m_pLikeBtn;
            CCMenuItemSpriteExtra* m_pStarRateBtn;
            CCMenuItemSpriteExtra* m_pDemonRateBtn;
            PAD(0x4)
            CCMenuItemToggler* m_pToggler;
            cocos2d::CCLabelBMFont* m_pLabel0;
            cocos2d::CCLabelBMFont* m_pLabel1;
            cocos2d::CCLabelBMFont* m_pLabel2;
            cocos2d::CCLabelBMFont* m_pLabel3;
            cocos2d::CCLabelBMFont* m_pLabel4;
            cocos2d::CCLabelBMFont* m_pLabel5;
            CCMenuItemSpriteExtra* m_pCloneBtn;
            PAD(0x4)
        
        public:
            static LevelInfoLayer* create(gd::GJGameLevel* level) {
                return reinterpret_cast<LevelInfoLayer*(__fastcall*)(gd::GJGameLevel*)>(base + 0x175d50)(level);
            }
            virtual bool init(GJGameLevel* level) {
                return reinterpret_cast<bool(__thiscall*)(void*, GJGameLevel*)>(base + 0x175df0)(this, level);
            }
            void onGarage(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x177c10)(this, pSender);
            }
            void onViewProfile(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17ac90)(this, pSender);
            }
            void onLevelInfo(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17acf0)(this, pSender);
            }
            void onInfo(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x179B50)(this, pSender);
            }
            void onClone(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x179EE0)(this, pSender);
            }
            void onOwnerDelete(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17A460)(this, pSender);
            }
            void onLike(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17A8A0)(this, pSender);
            }
            void onPlay(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x179730)(this, pSender);
            }
            void onBack(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17C110)(this, pSender);
            }
            void onDelete(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17A2B0)(this, pSender);
            }
            void onRate(cocos2d::CCObject* pSender) {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*, cocos2d::CCObject*)>(base + 0x17a530)(this, pSender);
            }
            void setupProgressBars() {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*)>(base + 0x177fc0)(this);
            }
            void downloadLevel() {
                reinterpret_cast<void(__thiscall*)(LevelInfoLayer*)>(base + 0x177d90)(this);
            }
    };
}

#endif
