#ifndef __LikeItemLayer_H__
#define __LikeItemLayer_H__

#include <gd.h>

namespace gd {

    class LikeItemLayer : public FLAlertLayer {
    public:
        LikeItemType m_type;
        int m_itemID;
        int m_special;
        LikeItemDelegate* m_delegate;

        static LikeItemLayer* create(LikeItemType type, int id, int special) {
            auto pRet = reinterpret_cast<LikeItemLayer*(__fastcall*)(LikeItemType, int, int)>(
                gd::base + 0x18B940
            )(type, id, special);
            __asm add esp, 0x4
            return pRet;
        }
    };

}

#endif
