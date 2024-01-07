#pragma once
#ifndef GJCOMMENT_H
#define GJCOMMENT_H

#include <gd.h>

namespace gd {

    //i stole gjcomment from wylies gd decompiled
    class GJComment : public cocos2d::CCNode {
        public:
            std::string m_sComment;
            std::string m_sUsername;
            int m_nCommentID;
            int m_nAuthorPlayerID;
            int m_nLikes;
            int m_nLevelID;
            bool m_bIsSpam;
            int m_nAuthorAccountID;
            std::string m_sCommentAge;
            bool m_bCommentDeleted;
            int m_nPercentage;
            int m_nModBadge;
            cocos2d::ccColor3B m_cColor;
            bool m_bHasLevelID;
            gd::GJUserScore* m_pUserScore;
    };

}

#endif
