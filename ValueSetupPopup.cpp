#include "ValueSetupPopup.hpp"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

ValueSetupPopup* ValueSetupPopup::create(const char* key, const char* section, const char* file, const char* comment) {
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
    input->setTouchEnabled(false);
    auto toggle = CCMenuItemToggler::create(
        CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png"),
        CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png"),
        this,
        (cocos2d::SEL_MenuHandler)&ValueSetupPopup::onToggle
    );
    toggle->setPosition({-38.f, -10.f});
    toggle->setScale(0.56f);
    toggle->toggle(bool(string(input->getString()) == "true"));
    m_pButtonMenu->addChild(toggle);

    inputbg->setContentSize({ 216.f, inputbg->getContentSize().height });

    return this;
}
void ValueSetupPopup::onClose(CCObject* callback) {
    if (string(input->getString()) == "" || m_pLayer->getScale() != 1.000f) return;
    CSimpleIni ini;//make CSimpleIni
    ini.LoadFile(m_file);//load to mem
    SI_Error valSetRet = 
        m_isBoolean ? 
        ini.SetBoolValue(m_section, m_key, bool(string(input->getString()) == "true"), ("; " + string(m_comment)).c_str())
        : 
        ini.SetValue(m_section, m_key, input->getString(), ("; " + string(m_comment)).c_str());//set valie of input
    SI_Error saveRet = ini.SaveFile(m_file);//save to file from mem
    if (saveRet == SI_OK) input->setString("Saved!");
    else input->setString("Failed to save!");
    m_pLayer->runAction(CCEaseBackIn::create(CCScaleTo::create(0.3, 0.f)));
    if (m_vanillaFadeOut) this->removeFromParentAndCleanup(true);
}
void ValueSetupPopup::onToggle(CCObject* callback) {
    if (string(input->getString()) != "true") input->setString("true");
    else input->setString("false");
}
void ValueSetupPopup::keyBackClicked() {
    onClose(NULL);
}
bool ValueSetupPopup::init(const char* key, const char* section, const char* file, const char* comment) {
    m_key = key;
    m_section = section;
    m_file = file;
    m_comment = comment;
    //ini
    CSimpleIni ini;
    ini.LoadFile(m_file);
    //layer
    if (CCLayerColor::initWithColor(ccc4(0, 0, 0, 150))) {
        registerWithTouchDispatcher();
        setTouchEnabled(true);
        setKeypadEnabled(true);
        schedule(schedule_selector(ValueSetupPopup::update), 0);

        m_pLayer = CCLayer::create();
        addChild(m_pLayer);
        m_pButtonMenu = CCMenu::create();
        m_pLayer->addChild(m_pButtonMenu);

        //square bg
        squareBg = CCScale9Sprite::create("square01_001.png");
        squareBg->setContentSize({ 360, 160 });
        m_pButtonMenu->addChild(squareBg, -2);

        //title
        CCLabelBMFont* title = CCLabelBMFont::create(("" + string(m_key) + " key setup").c_str(), "goldFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        title->setPositionY(58.f);
        title->setScale((squareBg->getContentSize().width - 160) / title->getContentSize().width);
        m_pButtonMenu->addChild(title);

        //keyInf
        CCLabelBMFont* keyInf = CCLabelBMFont::create(
            ("key: " + string(m_key) + ", section: " + m_section + 
                ", \nfile: " + m_file + "\n \n "
                ).c_str(), "chatFont.fnt", 900, CCTextAlignment::kCCTextAlignmentCenter);
        keyInf->setPositionY(45.f);
        keyInf->setAnchorPoint({0.5f, 1.f});
        keyInf->setScale((squareBg->getContentSize().width - 190) / keyInf->getContentSize().width);
        keyInf->setOpacity(90);
        m_pButtonMenu->addChild(keyInf);
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
        m_pButtonMenu->addChild(commentLbl);
        
        //input
        input = CCTextInputNode::create("You cant leave empty value!", this, "chatFont.fnt", 280.f, 20.f);
        input->setPositionY(-10.f);
        input->setLabelPlaceholderColor(ccRED);
        input->setString(ini.GetValue(m_section, m_key));
        m_pButtonMenu->addChild(input);

        //inputbg
        inputbg = CCScale9Sprite::create("square02_001.png");
        inputbg->setContentSize({ input->getContentSize().width * 2 + 20, input->getContentSize().height * 2 + 15 });
        inputbg->setScale(0.5f);
        inputbg->setOpacity(60);
        inputbg->setPosition(input->getPosition());
        m_pButtonMenu->addChild(inputbg, -1);

        //okBtn
        auto okBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("OK", 160.f, true, "goldFont.fnt", "GJ_button_01.png", 0, 1.0),
            this, menu_selector(ValueSetupPopup::onClose));
        m_pButtonMenu->addChild(okBtn);
        okBtn->CCMenuItemSpriteExtra::setScale(0.8f);
        okBtn->setPositionY(-50.0f);

        return true;
    }
    else return false;
}