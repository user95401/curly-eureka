#pragma once
#include "ModUtils.hpp"
#include "HooksUtils.hpp"
#include "SimpleIni.h"

class ValueSetupPopup : public gd::FLAlertLayer {
private:
    cocos2d::extension::CCScale9Sprite* squareBg;
    cocos2d::extension::CCScale9Sprite* inputbg;
    gd::CCTextInputNode* input;
    std::string m_key;
    std::string m_section;
    std::string m_file;
    std::string m_comment;
    bool m_vanillaFadeOut;
    bool m_isBoolean;
public:
    static ValueSetupPopup* create(std::string key, std::string section, std::string file, std::string comment);
    bool init(std::string key, std::string section, std::string file, std::string comment);
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