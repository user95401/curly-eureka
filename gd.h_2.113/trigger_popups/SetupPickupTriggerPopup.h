#ifndef __SETUPPICKUPTRIGGERPOPUP_H__
#define __SETUPPICKUPTRIGGERPOPUP_H__

#include <gd.h>

namespace gd {
    class GDH_DLL SetupPickupTriggerPopup : public FLAlertLayer, public TextInputDelegate {
        public:
            PAD(0xc)
            CCTextInputNode* m_pCountInput; // 0x1dc
            // too lazy to RE more, it should be
            // really easy to find the rest tho
            //static SetupPickupTriggerPopup* create(EffectGameObject*, cocos2d::CCArray*) = mac 0x35e70, win 0x23d4a0;
            static SetupPickupTriggerPopup* create(EffectGameObject* trigger, cocos2d::CCArray* triggers) {
                return reinterpret_cast<SetupPickupTriggerPopup * (__fastcall*)(EffectGameObject*, cocos2d::CCArray*)>(
                    base + 0x23d4a0
                    )(trigger, triggers);
            }
    };
}

#endif
