#ifndef __LEVELBROWSERLAYER_H__
#define __LEVELBROWSERLAYER_H__

#include <gd.h>

namespace gd {

    class GJSearchObject;
    class TextArea;

    class LevelBrowserLayer : public cocos2d::CCLayer, public LevelManagerDelegate, public FLAlertLayerProtocol, public SetIDPopupDelegate, public SetTextPopupDelegate {
    public:
        int unk0;
        TextArea* noInternet;
        GJListLayer* listLayer;
        CCMenuItemSpriteExtra* nextBtn;
        CCMenuItemSpriteExtra* prevBtn;
        CCMenuItemSpriteExtra* lastBtn;
        CCMenuItemSpriteExtra* cancelSearchBtn;
        void* unk4;
        cocos2d::CCArray* array;
        GJSearchObject* searchObject;
        cocos2d::CCLabelBMFont* countText;
        cocos2d::CCLabelBMFont* pageText;
        CCMenuItemSpriteExtra* pageBtn;
        cocos2d::CCLabelBMFont* folderText;
        CCMenuItemSpriteExtra* folderBtn;
        int total;
        int from;
        int to;

        static cocos2d::CCScene* scene(gd::GJSearchObject* searchObject) {
            return reinterpret_cast<cocos2d::CCScene*(__fastcall*)(gd::GJSearchObject*)>(
                gd::base + 0x159F60
            )(searchObject);
        }

        void loadPage(gd::GJSearchObject* searchObj) {
            reinterpret_cast<void(__thiscall*)(LevelBrowserLayer*, gd::GJSearchObject*)>(base + 0x15B160)(this, searchObj);
        }
    };

    class LevelSearchLayer : public cocos2d::CCLayer {
    public:
        PAD(12);
        CCTextInputNode* input;
    };

    class MoreSearchLayer : public FLAlertLayer {
    public:
        static MoreSearchLayer* create() {
            return reinterpret_cast<MoreSearchLayer*(__fastcall*)()>(
                gd::base + 0x182520
            )();
        }
    };

}

#endif
