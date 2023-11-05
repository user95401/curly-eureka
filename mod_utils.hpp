#include <cocos2d.h>
#include <gd.h>
#include <fstream>
#include <array>
#include "ValueSetupPopup.hpp"

namespace ModUtils {

    /*Recommended use it to create sprite)
    It will try create sprite with CCSprite::create() or CCSprite::createWithSpriteFrameName()
    and if both methods falils, will be created placeholder*/
    cocos2d::CCSprite* createSprite(const char* name);
    //create sprite only from medium scale factor
    cocos2d::CCSprite* createSprite(const char* name, bool IgnoreScaleFactor);
    //sd - 1.0, hd - 2.0, uhd - 4.0
    cocos2d::CCSprite* createSprite(const char* name, float ScaleFactor);
    
    cocos2d::CCSprite* createPlaceholder();

    /*idk why but CCMenu creates with center position 😏*/
    cocos2d::CCPoint getCenterPoint();

    cocos2d::CCAction* CreateRGB(float speed);
    cocos2d::CCAction* CreateRGB(float speed, bool is_reverse);
    
    gd::CCMenuItemSpriteExtra* createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale);

    /*example:
    //Fixes trail cutting on high refresh rates
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(gd::base + 0x71D48, { 0xEB });*/
    bool write_bytes(const std::uintptr_t, std::vector<uint8_t> const&);

    /*Gets name of a random file in folder
    example: getRandomFileNameFromDir("Resources/DeathEffects", "explode_11.ogg")*/
    std::string getRandomFileNameFromDir(std::string path, std::string or_else);

    /*return true; if layer init hook called 2 times*/
    bool ttlihe(cocos2d::CCNode* node);

    void setupModSeed();
    int getModSeed();

    std::filesystem::path GetModPath();

    std::string GetModName();

    std::string GetModDev();

    void log(std::string);

    std::vector<std::string> explode(const std::string& str, const char& ch);

    void copyToClipboard(const char* text);

    void copyToClipboard(const char* text, cocos2d::CCLayer* parent);

    void strToLower(std::string& str);

    std::string url_encode(const std::string& value);

    std::string base64_encode(const std::string& in);

    std::string base64_decode(const std::string& in);

}

/* 
stop the code via return true; if layer init hook called 2 times
useful for tradicional mod on Geode
*/
#define twoTimesLayerInitHookEscape(node) if(ModUtils::ttlihe(node)) return true;
/*
stop the code via return; if layer init hook called 2 times
useful for tradicional mod on Geode
*/
#define twoTimesLayerCustomSetupEscape(node) if(ModUtils::ttlihe(node)) return;

/*xd*/
#define geodeInstalled cocos2d::CCFileUtils::sharedFileUtils()->isFileExist("Geode.dll")
