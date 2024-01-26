#include "ValueSetupPopup.hpp"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

ValueSetupPopup* ValueSetupPopup::create(string key, string section, string file, string comment) {
    ValueSetupPopup* ret = new ValueSetupPopup();
    if (ret && ret->init(key, section, file, comment)) ret->autorelease();
    else CC_SAFE_DELETE(ret);
    return ret;
}
void ValueSetupPopup::update(float dt) {
    if(m_pLayer->getScale() < 0.01) this->removeFromParentAndCleanup(true);
}
ValueSetupPopup* ValueSetupPopup::vanillaFadeOut() {
    this->m_vanillaFadeOut = true;
    return this;
}
ValueSetupPopup* ValueSetupPopup::noElasticity() {
    this->m_bNoElasticity = true;
    return this;
}
ValueSetupPopup* ValueSetupPopup::isBoolean() {
    this->m_isBoolean = true;

    //layer setup
    this->input->setTouchEnabled(false);
    auto toggle = CCMenuItemToggler::create(
        CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
        CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png"),
        this,
        (cocos2d::SEL_MenuHandler)&ValueSetupPopup::onToggle
    );
    toggle->setPosition({-38.f, -10.f});
    toggle->setScale(0.56f);
    toggle->toggle(bool(string(this->input->getString()) == "true"));
    this->m_pButtonMenu->addChild(toggle);

    this->inputbg->setContentSize({ 216.f, this->inputbg->getContentSize().height });

    return this;
}
void ValueSetupPopup::onClose(CCObject* callback) {
    if (string(this->input->getString()) == "" || this->m_pLayer->getScale() != 1.000f) return;
    CSimpleIni ini;//make CSimpleIni
    ini.LoadFile(this->m_file.c_str());//load to mem
    SI_Error valSetRet = 
        this->m_isBoolean ?
        ini.SetBoolValue(this->m_section.c_str(), this->m_key.c_str(), bool(string(this->input->getString()) == "true"), ("; " + string(this->m_comment)).c_str())
        : 
        ini.SetValue(this->m_section.c_str(), this->m_key.c_str(), this->input->getString(), ("; " + string(this->m_comment)).c_str());//set valie of input
    SI_Error saveRet = ini.SaveFile(m_file.c_str());//save to file from mem
    if (saveRet == SI_OK) input->setString("Saved!");
    else this->input->setString("Failed to save:" + saveRet);
    this->m_pLayer->runAction(CCEaseBackIn::create(CCScaleTo::create(0.3, 0.f)));
    if (this->m_vanillaFadeOut) this->removeFromParentAndCleanup(true);
}
void ValueSetupPopup::onToggle(CCObject* callback) {
    if (string(this->input->getString()) != "true") this->input->setString("true");
    else this->input->setString("false");
}
void ValueSetupPopup::keyBackClicked() {
    onClose(nullptr);
}
bool ValueSetupPopup::init(string key, string section, string file, string comment) {
    this->m_key = key;
    this->m_section = section;
    this->m_file = file;
    this->m_comment = comment;
    //ini
    CSimpleIni ini;
    ini.LoadFile(this->m_file.c_str());
    //layer
    if (CCLayerColor::initWithColor(ccc4(0, 0, 0, 150))) {
        registerWithTouchDispatcher();
        setTouchEnabled(true);
        setKeypadEnabled(true);
        schedule(schedule_selector(ValueSetupPopup::update), 0);

        this->m_pLayer = CCLayer::create();
        addChild(this->m_pLayer);
        this->m_pButtonMenu = CCMenu::create();
        this->m_pLayer->addChild(this->m_pButtonMenu);

        //square bg
        this->squareBg = CCScale9Sprite::create("square01_001.png");
        this->squareBg->setContentSize({ 360, 160 });
        this->m_pButtonMenu->addChild(this->squareBg, -2);

        //title
        CCLabelBMFont* title = CCLabelBMFont::create(("" + string(this->m_key) + " key setup").c_str(), "goldFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        title->setPositionY(58.f);
        title->setScale((this->squareBg->getContentSize().width - 160) / title->getContentSize().width);
        this->m_pButtonMenu->addChild(title);

        //keyInf
        CCLabelBMFont* keyInf = CCLabelBMFont::create(
            ("key: " + this->m_key + ", section: " + this->m_section +
                ", \nfile: " + this->m_file + "\n \n "
                ).c_str(), "chatFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        keyInf->setPositionY(45.f);
        keyInf->setAnchorPoint({0.5f, 1.f});
        keyInf->setScale((this->squareBg->getContentSize().width - 190) / keyInf->getContentSize().width);
        keyInf->setOpacity(90);
        this->m_pButtonMenu->addChild(keyInf);
        //commentLbl
        CCLabelBMFont* commentLbl = CCLabelBMFont::create(
               ("\n "
                "\n "
                + string(comment)
                ).c_str(), "chatFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        commentLbl->setPositionY(keyInf->getPositionY());
        commentLbl->setAnchorPoint(keyInf->getAnchorPoint());
        commentLbl->setScale(keyInf->getScale());
        commentLbl->setOpacity(160);
        this->m_pButtonMenu->addChild(commentLbl);
        
        //input
        this->input = CCTextInputNode::create("You cant leave empty value!", this, "chatFont.fnt", 280.f, 20.f);
        this->input->setPositionY(-10.f);
        this->input->setLabelPlaceholderColor(ccRED);
        this->input->setString(ini.GetValue(this->m_section.c_str(), this->m_key.c_str()));
        this->m_pButtonMenu->addChild(this->input);

        //inputbg
        this->inputbg = CCScale9Sprite::create("square02_001.png");
        this->inputbg->setContentSize({ this->input->getContentSize().width * 2 + 20, this->input->getContentSize().height * 2 + 15 });
        this->inputbg->setScale(0.5f);
        this->inputbg->setOpacity(60);
        this->inputbg->setPosition(this->input->getPosition());
        this->m_pButtonMenu->addChild(this->inputbg, -1);

        //okBtn
        auto okBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("OK", 160.f, true, "goldFont.fnt", "GJ_button_01.png", 0, 1.0),
            this, menu_selector(ValueSetupPopup::onClose));
        this->m_pButtonMenu->addChild(okBtn);
        okBtn->CCMenuItemSpriteExtra::setScale(0.8f);
        okBtn->setPositionY(-50.0f);

        return true;
    }
    else return false;
}