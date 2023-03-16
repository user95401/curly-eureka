#ifndef __GJUSERSCORE_H__
#define __GJUSERSCORE_H__

#include <gd.h>

namespace gd {
    class GJUserScore : public cocos2d::CCNode {
        public:
            std::string userName_;
            std::string userUDID_;
            int scoreType_; // legacy field, used in 1.9 to determine shown info
            int userID_;
            int accountID_;

            int stars_;
            int diamonds_;
            int demons_;
            int playerRank_;
            int creatorPoints_; // note - internally this is named levels
            int secretCoins_;
            int userCoins_;

            int iconID_; // for leaderboards, icon id to show
            int color1_;
            int color2_;
            int special_;
            IconType iconType_;

            int messageState_;
            int friendStatus_;
            int commentHistoryStatus_;

            std::string youtubeURL_;
            std::string twitterURL_;
            std::string twitchURL_;

            int playerCube_;
            int playerShip_;
            int playerBall_;
            int playerUfo_;
            int playerWave_;
            int playerRobot_;
            int playerSpider_;
            int playerStreak_;
            bool glowEnabled_ : 4;

            int playerExplosion_;

            int modBadge_;
            int globalRank_;

            int friendReqStatus_;
            int newMsgCount_;
            int friendReqCount_;
            bool isBlocked : 4;

            std::string lastScoreAge;

        public:
            static GJUserScore* create() {
                  return reinterpret_cast<GJUserScore*(__fastcall*)()>(
                      gd::base + 0xC1660
                  )();
            }


            static GJUserScore* create(cocos2d::CCDictionary* dict) {
                  return reinterpret_cast<GJUserScore*(__fastcall*)(cocos2d::CCDictionary*)>(
                      gd::base + 0xC0750
                  )(dict);
            }
            // static GJUserScore* create();
            // static GJUserScore* create(cocos2d::CCDictionary*);

            // bool isCurrentUser();
            // void mergeWithScore(GJUserScore*);

            inline IconType getIconType() const { return this->iconType_; };
            inline int getIconID() const { return this->iconID_; };
            inline int getUserID() const { return this->userID_; };
            inline int getAccountID() const { return this->accountID_; };
            inline int getMessageState() const { return this->messageState_; };
            inline int getFriendStatus() const { return this->friendStatus_; };
            inline int getCommentHistoryStatus() const { return this->commentHistoryStatus_; };

            inline int getPlayerCube() const { return this->playerCube_; };
            inline int getPlayerShip() const { return this->playerShip_; };
            inline int getPlayerBall() const { return this->playerBall_; };
            inline int getPlayerUfo() const { return this->playerUfo_; };
            inline int getPlayerWave() const { return this->playerWave_; };
            inline int getPlayerRobot() const { return this->playerRobot_; };
            inline int getPlayerSpider() const { return this->playerSpider_; };
            inline int getPlayerStreak() const { return this->playerStreak_; };
            inline bool getGlowEnabled() const { return this->glowEnabled_; };
            inline int getPlayerExplosion() const { return this->playerExplosion_; };
            inline int getPlayerRank() const { return this->playerRank_; };
            inline int getGlobalRank() const { return this->globalRank_; };

            inline int getPlayerColor1() const { return this->color1_; };
            inline int getPlayerColor2() const { return this->color2_; };

            inline std::string getPlayerName() const { return this->userName_; };

            inline void setPlayerCube(int cube) { this->playerCube_ = cube; };
            inline void setPlayerName(std::string name) { this->userName_ = name; };
            inline void setUserID(int userID) { this->userID_ = userID; };
    };
}

#endif
