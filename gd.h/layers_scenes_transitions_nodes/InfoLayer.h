#ifndef __INFOLAYER_H__
#define __INFOLAYER_H__

#include <gd.h>

namespace gd {

    class GJGameLevel;
    class GJUserScore;

    //members stolen from wylies gd decomp
    // m_nTotalItems moved before m_nPageStartIdx because thats the actual order on windows at least
    class InfoLayer : public FLAlertLayer {
    public:
        PAD(472 - sizeof(gd::FLAlertLayer));
        gd::GJGameLevel* m_pLevel;
        gd::GJUserScore* m_pScore;
        std::string m_sCommentKey;
        gd::LoadingCircle* m_pLoadingCircle;
        cocos2d::CCLabelBMFont* m_pPageLabel;
        cocos2d::CCLabelBMFont* m_pCommentsGoldLabel;
        void* m_pCommentList; //gd::GJCommentListLayer
        gd::CCMenuItemSpriteExtra* m_pNextPageBtn;
        gd::CCMenuItemSpriteExtra* m_pPrevPageBtn;
        gd::CCMenuItemSpriteExtra* m_pLikeIcon;
        gd::CCMenuItemSpriteExtra* m_pTimeIcon;
        gd::CCMenuItemSpriteExtra* m_pReportBtn;
        gd::CCMenuItemSpriteExtra* m_pCommentsBtn;
        gd::CCMenuItemSpriteExtra* m_pRefreshCommentsBtn;
        int m_nTotalItems;
        int m_nPageStartIdx;
        int m_nPageEndIdx;
        int m_nPageNumber;
        bool m_bCanUpdateUserScore;
        bool m_bCommentHistory;

        static InfoLayer* create(gd::GJGameLevel* level, gd::GJUserScore* score) {
            return reinterpret_cast<InfoLayer*(__fastcall*)(gd::GJGameLevel*, gd::GJUserScore*)>(
                gd::base + 0x14F4F0
            )(level, score);
        }

        void loadPage(int page, bool reload) {
            reinterpret_cast<void(__thiscall*)(InfoLayer*, int, bool)>(base + 0x151E70)(this, page, reload);
        }
    };

}

#endif
