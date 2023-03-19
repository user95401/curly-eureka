#include <cocos2d.h>
#include <gd.h>
#include <fstream>
#include <array>

using namespace cocos2d;
using namespace gd;

namespace ModUtils {
    CCSprite* createWithSpriteFrameNameOrPlaceholder(const char* name);
    CCSprite* createSpriteOrPlaceholder(const char* name);
    CCSprite* createPlaceholder();
    void copyToClipboard(const char* text);
    void copyToClipboard(const char* text, cocos2d::CCLayer* parent);
    gd::CCMenuItemSpriteExtra* createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale);
    void strToLower(std::string& str);
}