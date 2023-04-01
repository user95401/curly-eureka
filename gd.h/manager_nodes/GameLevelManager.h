#ifndef __GAMELEVELMANAGER_H__
#define __GAMELEVELMANAGER_H__

#include <gd.h>

namespace gd {

class GJGameLevel;

    class GDH_DLL GameLevelManager : public cocos2d::CCNode {
    public:
        // thanks to wylie for most of these!

        cocos2d::CCDictionary* m_mainLevels; // the values are GJGameLevel
        cocos2d::CCDictionary* m_searchFilters; // the level search filters
        cocos2d::CCDictionary* m_onlineLevels;
        PAD(4);
        cocos2d::CCDictionary* m_followedCreators; // key is the account id
        cocos2d::CCDictionary* m_downloadedLevels;
        // dear robtop, have you heard of a set
        // all of these just have the value of CCString("1")
        cocos2d::CCDictionary* m_likedLevels; // https://github.com/Wyliemaster/gddocs/blob/client/docs/resources/client/gamesave/GLM.md#glm_12
        cocos2d::CCDictionary* m_ratedLevels;
        cocos2d::CCDictionary* m_reportedLevels;
        // the names of the folders
        cocos2d::CCDictionary* m_onlineFolders;
        cocos2d::CCDictionary* m_localLevelsFolders;
        cocos2d::CCDictionary* m_dailyLevels;
        int m_dailyTimeLeft; // i cant figure out the unit
        int m_dailyID;
        int m_dailyID_;
        PAD(4);
        int m_weeklyTimeLeft;
        int m_weeklyID;
        int m_weeklyID_; // ? (this was 2 lower than the other weekly id)
        cocos2d::CCDictionary* m_gauntletLevels;
        PAD(8);
        cocos2d::CCDictionary* unkDict14; // some cache thing it seems (values are strings)
        cocos2d::CCDictionary* m_knownUsers; // ? not sure 14C
        cocos2d::CCDictionary* m_accountIDtoUserIDDict; // 150
        cocos2d::CCDictionary* m_userIDtoAccountIDDict; // 154
        cocos2d::CCDictionary* unkDict18; // cached lvls?? (values are arrays)
        cocos2d::CCDictionary* unkDict19; // more cache stuff (values are strings)
        cocos2d::CCDictionary* unkDict20;
        cocos2d::CCDictionary* unkDict21;
        cocos2d::CCDictionary* unkDict22;
        cocos2d::CCDictionary* unkDict23;
        cocos2d::CCDictionary* unkDict24;
        cocos2d::CCDictionary* unkDict25;
        cocos2d::CCDictionary* unkDict26;
        cocos2d::CCDictionary* unkDict27;
        cocos2d::CCDictionary* unkDict28;
        std::string unkStr1;
        std::string unkStr2; // im not sure if this is actually is a std::string, although it looks like one
        PAD(92);
        std::string unkStr3;
        cocos2d::CCString* unkStr4;
        
        inline static GameLevelManager* sharedState() {
            return reinterpret_cast<GameLevelManager*(__stdcall*)()>( gd::base + 0x9f860 )();
        }

        inline static gd::GJGameLevel* createNewLevel() {
            return reinterpret_cast<gd::GJGameLevel*(__stdcall*)()>( gd::base + 0xa0db0 )();
        }

        GJGameLevel* getMainLevel(int id, bool unk) {
            return reinterpret_cast<GJGameLevel*(__thiscall*)(GameLevelManager*, int, bool)>( base + 0xa0940 )(this, id, unk);
        }

        void getCompletedLevels(bool newFilter) {
            reinterpret_cast<void(__thiscall*)(void*, bool)>(base + 0xa2d20)(this, newFilter);
        }

        void getGJUserInfo(int a1) {
            reinterpret_cast<void(__thiscall*)(void*, bool)>(base + 0xb00b0)(this, a1);
        }

        int requestUserAccess() {
            return reinterpret_cast<int(__fastcall*)(GameLevelManager*)>(base + 0xB8110)(this);
        }

        GameManager* onRequestUserAccessCompleted(int a1, const char** a2) {
            return reinterpret_cast<GameManager * (__fastcall*)(int, const char**)>(base + 0xa0940)(a1, a2);
        }

        cocos2d::CCArray* getSavedLevels(bool favorite, int levelFolder) {
            return reinterpret_cast<cocos2d::CCArray*(__fastcall*)(GameLevelManager*, bool,int)>(base + 0xa2960)(this, favorite, levelFolder);
        }

        cocos2d::CCArray* getSavedLevels(char const* e) {
            return reinterpret_cast<cocos2d::CCArray * (__fastcall*)(GameLevelManager*, char const*)>(base + 0xa3a90)(this, e);
        }

        void  updateUserScore() {
            return reinterpret_cast<void(__fastcall*)(GameLevelManager*)>(base + 0xada60)(this);
        }

        void downloadLevel(int id, bool downloadData) {
            return reinterpret_cast<void(__fastcall*)(GameLevelManager*, int, bool)>(base + 0xaa730)(this, id, downloadData);
        }// = win 0xaa730;

        bool hasDownloadedLevel(int id) {
            return reinterpret_cast<bool(__fastcall*)(GameLevelManager*, int)>(base + 0xab830)(this, id);
        }// = win 0xab830;

        GJGameLevel* getSavedLevel(int id) {
            return reinterpret_cast<GJGameLevel * (__fastcall*)(GameLevelManager*, int)>(base + 0xa2ee0)(this, id);
        } // = win 0xa2ee0;

        void saveLevel(GJGameLevel* level) {
            return reinterpret_cast<void(__fastcall*)(GameLevelManager*, GJGameLevel*)>(base + 0xa31c0)(this, level);
        }// = win 0xa31c0;
    };

}

#endif
