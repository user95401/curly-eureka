#include "ModUtilsExt.hpp"
#include <cocos2d.h>//cocos2d-x headers
#include <iostream>
#include <string>
#include <filesystem>

namespace ModUtils {

    /*Recommended use it to create sprite)
    It will try create sprite with CCSprite::create() or CCSprite::createWithSpriteFrameName()
    and if both methods falils, will be created placeholder*/
    cocos2d::CCSprite* createSprite(const char* name);
    //create sprite only from medium scale factor
    cocos2d::CCSprite* createSprite(const char* name, bool IgnoreScaleFactor);
    //sd - 1.0, hd - 2.0, uhd - 4.0
    cocos2d::CCSprite* createSprite(const char* name, float ScaleFactor);

    /*
        Its creating sprite with construction of square02b_001.png sub sprites.
        Looks like emo textures (pink and black cell)
    */
    cocos2d::CCSprite* createPlaceholder();

    /*
        position as offset from 0 to center point of screen size
    */
    const cocos2d::CCPoint getCenterPoint();

    //creating rgb animation that u can apply to node
    cocos2d::CCAction* CreateRGB(float speed);
    //creating rgb animation that u can apply to node
    cocos2d::CCAction* CreateRGB(float speed, bool is_reverse);

    /*
        Write current process memory with bytes vector
        example:
        //Fixes trail cutting on high refresh rates
        ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
        //Verify Hack
        ModUtils::write_bytes(gd::base + 0x71D48, { 0xEB });
    */
    bool WriteProcMem(const std::uintptr_t, std::vector<uint8_t> const&);
    bool WriteProcMem(const std::uintptr_t, std::vector<uint8_t> const&, std::string desc);

    std::vector<uint8_t> ReadProcMem(DWORD address, int length);

    std::string ReadProcMemAsStr(DWORD address, int length);

    //std::vector<uint8_t> { intToBytes(777)[0], intToBytes(777)[1], intToBytes(777)[2],intToBytes(777)[3] }
    std::vector<unsigned char> intToBytes(int value);

    typedef size_t size_tType;
    std::string toHex(const size_tType& number);

    //return string as relative path of random file in target directory
    std::string getRandomFileNameFromDir(std::string path, std::string or_else);

    /*
        FOR GEODE LOADER
        return true if pCCNode already has child with MOD_SEED tag
    */
    bool ttcallesc(cocos2d::CCNode* pCCNode);

    /*
        FOR GEODE LOADER
        generates a random number and defines it in MOD_SEED
    */
    void setupModSeed();

    /*
        FOR GEODE LOADER
        returns MOD_SEED
    */
    int getModSeed();

    //returns std::filesystem::path of self
    std::filesystem::path GetModPath();

    //get name of mod via parsing GetModPath()
    std::string GetModName();

    //get developer of mod via parsing GetModPath()
    std::string GetModDev();

    //get developer of mod via parsing GetModPath()
    std::string GetGameVersion();

    //simple printf with time and mod name
    void log(std::string msg, std::string prefix, bool milliseconds);
    //simple printf with time and mod name
    void log(std::string msg, std::string prefix);
    //simple printf with time and mod name
    void log(std::string msg, bool milliseconds);
    //simple printf with time and mod name
    void log(std::string msg);

    /*
        create strings vector by splitting string with separator char
        example:
        ModUtils::log(ModUtils::explode("zero_str.str1.strTwo", '.')[2]); //print strTwo
    */
    std::vector<std::string> explode(const std::string& str, const char& ch);

    //its copy text to clipboard...
    void copyToClipboard(const char* text);

    //set every char of string to lower
    void strToLower(std::string& str);

    //for exaple: "(*&*$() 101 cvcds /*-`1мивфд" => "(*%26*%24()+101+cvcds+%2F*-%601мивфд"
    std::string url_encode(const std::string& value);

    //for exaple: "dW5ubw==" => "unno"
    std::string base64_encode(const std::string& in);

    //for exaple: "unno" => "dW5ubw=="
    std::string base64_decode(const std::string& in);

    //if node is bad it return new cocos2d::CCNode to escape crash
    cocos2d::CCNode* TheNodeOrSomeNode(cocos2d::CCNode* node);

    //set object id label for every children
    cocos2d::CCNode* markChildrensWithIndex(cocos2d::CCNode* node);

    //return Resources/MOD_NAME
    std::filesystem::path GetModResourcesPath();

    //adds Resources/MOD_NAME at begin of search pathes vector
    std::string AddSearchPathForMod();

    //uses search paths
    bool FindOutIfFileExists(std::string sFileName);

    //URLDownloadToFile, retuns S_OK if ok
    STDAPI DownloadFile(std::string sUrl, std::string sFileName);

    void OpenConsole();

    //MessageBox in new thread and sleep for 100ms
    void ShowSafeMessageBox(std::string caption, std::string msg, UINT uType);
}

/*
stop the code via return true; if layer init hook called 2 times
useful for traditional mod on Geode
*/
#define twoTimesBoolCallEscapeByParrentNode(pCCNode) if(ModUtils::ttcallesc(pCCNode)) return true;

/*
stop the code via return; if hook called 2 times
useful for traditional mod on Geode
*/
#define twoTimesVoidCallEscapeByParrentNode(pCCNode) if(ModUtils::ttcallesc(pCCNode)) return;

/*xd*/
#define geodeInstalled cocos2d::CCFileUtils::sharedFileUtils()->isFileExist("Geode.dll")

/*will return new node if given node is wrong*/
#define TheObjOrSomeObj(class, obj) reinterpret_cast<class>(ModUtils::TheNodeOrSomeNode(reinterpret_cast<CCNode*>(obj)))
