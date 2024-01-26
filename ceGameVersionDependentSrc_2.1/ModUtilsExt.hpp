#include <gd.h>//geometry dash headers

namespace ModUtils {
    //creating menu item with ButtonSprite
    gd::CCMenuItemSpriteExtra* createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale);


    /*
        calls copyToClipboard(text) and popups on parent the text on black bg that says "Copied to clipboard"
        for me dont working btw
    */
    void copyToClipboard(const char* text, cocos2d::CCLayer* parent);
}