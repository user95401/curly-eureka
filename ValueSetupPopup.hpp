#pragma once
#include "mod_utils.hpp"
#include "hooks.hpp"
#include "SimpleIni.h"

class ValueSetupPopup : public gd::FLAlertLayer {
public:
    cocos2d::extension::CCScale9Sprite* squareBg;
    cocos2d::extension::CCScale9Sprite* inputbg;
    gd::CCTextInputNode* input;
    const char* m_key;
    const char* m_section;
    const char* m_file;
    const char* m_comment;
    bool m_vanillaFadeOut;
    bool m_isBoolean;

    static ValueSetupPopup* create(const char* key, const char* section, const char* file, const char* comment);
    bool init(const char* value, const char* section, const char* file, const char* comment);
    virtual void keyBackClicked();
    virtual void update(float dt);
    void onClose(cocos2d::CCObject* callback);
    void onToggle(cocos2d::CCObject* callback);

    //close imedetatly
    ValueSetupPopup* vanillaFadeOut();
    //no showup anim
    ValueSetupPopup* noElasticity();
    //transform to bool
    ValueSetupPopup* isBoolean();
};