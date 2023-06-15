#include <cocos2d.h>
#include <gd.h>
#include <fstream>
#include "mod_utils.hpp"
#include <array>

using namespace cocos2d;
using namespace gd;

CCSprite* ModUtils::createSprite(const char* name){
    auto spriteWithSpriteFrameName = CCSprite::createWithSpriteFrameName(name);
    if (spriteWithSpriteFrameName) return spriteWithSpriteFrameName;
    auto sprite = CCSprite::create(name);
    if (sprite) return sprite;

    CCSprite* placeholder = createPlaceholder();

    auto placeholderLabel = CCLabelBMFont::create(name, "chatFont.fnt", 6, kCCTextAlignmentCenter);
    placeholderLabel->setPosition({ placeholder->getContentSize().width / 2, placeholder->getContentSize().height / 2 });
    placeholder->addChild(placeholderLabel);

    return placeholder;
}

CCSprite* ModUtils::createPlaceholder(){
        auto sprite = CCSprite::create();

        auto subSprite1 = CCSprite::create("square02b_001.png");
        auto subSprite2 = CCSprite::create("square02b_001.png");
        auto subSprite3 = CCSprite::create("square02b_001.png");
        auto subSprite4 = CCSprite::create("square02b_001.png");

        std::array<CCSprite*, 4> sprites = {subSprite1, subSprite2, subSprite3, subSprite4};

        subSprite1->setAnchorPoint({0,0});
        subSprite2->setAnchorPoint({1,0});
        subSprite3->setAnchorPoint({0,1});
        subSprite4->setAnchorPoint({1,1});

        subSprite2->setColor({251,64,249});
        subSprite1->setColor({0,0,0});
        subSprite3->setColor({251,64,249});
        subSprite4->setColor({0,0,0});

        for(auto subSprite : sprites){
                subSprite->setScale(.25f);
                subSprite->setPosition(subSprite->getContentSize() / 2);
                sprite->addChild(subSprite);

        }

        sprite->setContentSize(subSprite1->getContentSize());

        return sprite;
}
/*
        Windows only code :D
*/
void ModUtils::copyToClipboard(const char* text){
        const size_t len = strlen(text) + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), text, len);
        GlobalUnlock(hMem);
        OpenClipboard(0);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
}

void ModUtils::copyToClipboard(const char* text, CCLayer* parent){
        copyToClipboard(text);
        parent->addChild(TextAlertPopup::create("Copied to clipboard", 0.5f, 0.6f), 100);
}

CCMenuItemSpriteExtra* ModUtils::createTextButton(CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale){
    auto buttonSprite = gd::ButtonSprite::create(text, width, true, "bigFont.fnt", "GJ_button_01.png", height, scale);
    auto buttonButton = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        parent,
        handler
    );
    buttonButton->setSizeMult(1.2f);

    return buttonButton;
}

void ModUtils::strToLower(std::string& str) {
        for(auto& c : str) c = tolower(c);
}

bool ModUtils::write_bytes(const std::uintptr_t address, std::vector<uint8_t> const& bytes) {
    return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}

CCPoint ModUtils::getCenterPoint() {
    return CCMenu::create()->getPosition();
}

std::string ModUtils::getRandomFileNameFromDir(std::string path, std::string or_else) {
    if(CCFileUtils::sharedFileUtils()->isFileExist(path)){
        std::vector<std::string> files;
        for (auto& p : std::filesystem::directory_iterator(std::filesystem::current_path() / path)) {
            files.push_back(p.path().filename().string());
        }
        if (files.size() == 0) { return or_else; }
        return path + std::string("/") + files[rand() % files.size()].c_str();
    }
    else {
        //                          :skull:
        MessageBox(nullptr, std::string("The directory '" + path + "' isn't founded").c_str(), std::string("ModUtils::getRandomFileNameFromDir("+ path +", " + or_else + ")").c_str(), MB_ICONERROR | MB_OK);
    }
    return or_else;
}