#include "ModUtilsExt.hpp"
#include "ModUtils.hpp"
#include <fstream>
#include <array>
#include <filesystem>
#include <gd.h>//geometry dash headers

//creating menu item with ButtonSprite
gd::CCMenuItemSpriteExtra* ModUtils::createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale) {
    auto buttonSprite = gd::ButtonSprite::create(text, width, true, "bigFont.fnt", "GJ_button_01.png", height, scale);
    auto buttonButton = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        parent,
        handler
    );
    buttonButton->setSizeMult(1.2f);

    return buttonButton;
}

/*
    calls copyToClipboard(text) and popups on parent the text on black bg that says "Copied to clipboard"
    for me dont working btw
*/
void ModUtils::copyToClipboard(const char* text, cocos2d::CCLayer* parent) {
    copyToClipboard(text);
    parent->addChild(gd::TextAlertPopup::create("Copied to clipboard", 0.5f, 0.6f), 100);
}