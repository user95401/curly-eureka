#ifndef __PROFILEPAGE_H__
#define __PROFILEPAGE_H__

#include <gd.h>

namespace gd {

    class GJUserScore;

    class ProfilePage : public gd::FLAlertLayer, public FLAlertLayerProtocol, public LevelCommentDelegate, public CommentUploadDelegate, public UserInfoDelegate, public UploadActionDelegate, public UploadPopupDelegate, public LeaderboardManagerDelegate {
    public:
        //PAD(472 - sizeof(gd::FLAlertLayer));
        gd::GJUserScore* score; //488-492
        int something; //492-496
        PAD(552 - 496); //this is at 532 on android???
        cocos2d::CCArray* objectsInMenu;
        //564

        /*static ProfilePage* create(int accountID, bool a2) {
            return reinterpret_cast<ProfilePage*(__fastcall*)(int, bool)>(
                gd::base + 0x20EE50
            )(accountID, a2);
        }*/

        void getUserInfoChanged(gd::GJUserScore* score) {
            reinterpret_cast<void*(__fastcall*)(ProfilePage*, gd::GJUserScore*)>(
                gd::base + 0x213430
            )(this, score);
        }

        //onUpdate 0x20FA20
    };

}

#endif
