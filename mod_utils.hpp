#include <cocos2d.h>
#include <gd.h>
#include <fstream>
#include <array>

using namespace cocos2d;
using namespace gd;

namespace ModUtils {
    /*Recommended use it to create sprite)
    It will try create sprite with CCSprite::create() or CCSprite::createWithSpriteFrameName()
    and if both methods falils, will be created placeholder*/
    CCSprite* createSprite(const char* name);
    
    CCSprite* createPlaceholder();
    
    void copyToClipboard(const char* text);
    
    void copyToClipboard(const char* text, cocos2d::CCLayer* parent);
    
    gd::CCMenuItemSpriteExtra* createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale);
    
    void strToLower(std::string& str);

    /*example:
    //Fixes trail cutting on high refresh rates
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(gd::base + 0x71D48, { 0xEB });*/
    bool write_bytes(const std::uintptr_t, std::vector<uint8_t> const&);

    /*idk why but CCMenu creates with center position 😏*/
    CCPoint getCenterPoint();

    /*Gets name of a random file in folder
    example: getRandomFileNameFromDir("Resources/DeathEffects", "explode_11.ogg")*/
    std::string getRandomFileNameFromDir(std::string path, std::string or_else);

    bool isCube(gd::PlayerObject* player);
}