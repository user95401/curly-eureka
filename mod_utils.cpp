﻿#include "mod_utils.hpp"

int MOD_SEED;

/*
    Recommended use it to create sprite :>
    It will try create sprite with CCSprite::create() or CCSprite::createWithSpriteFrameName()
    and if both methods falils, will be created placeholder
*/
cocos2d::CCSprite* ModUtils::createSprite(const char* name) {

    auto sprite = cocos2d::CCSprite::createWithSpriteFrameName(name);
    if (!sprite) sprite = cocos2d::CCSprite::create(name);
    if (sprite) return sprite;

    cocos2d::CCSprite* placeholder = createPlaceholder();
    auto placeholderLabel = cocos2d::CCLabelBMFont::create(name, "chatFont.fnt", 3.0, cocos2d::CCTextAlignment::kCCTextAlignmentCenter);
    placeholderLabel->setPosition({ placeholder->getContentSize().width / 2, placeholder->getContentSize().height / 2 });
    placeholder->addChild(placeholderLabel);

    return placeholder;
}

//create sprite only from medium scale factor
cocos2d::CCSprite* ModUtils::createSprite(const char* name, bool ForceScaleFactor) {
    float OldScaleFactor = cocos2d::CC_CONTENT_SCALE_FACTOR();
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(ForceScaleFactor ? 2.0f : OldScaleFactor);
    auto sprite = createSprite(name);
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(OldScaleFactor);
    return sprite;
}

//sd - 1.0, hd - 2.0, uhd - 4.0
cocos2d::CCSprite* ModUtils::createSprite(const char* name, float ForceScaleFactor) {
    float OldScaleFactor = cocos2d::CC_CONTENT_SCALE_FACTOR();

    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(ForceScaleFactor);
    auto sprite = createSprite(name);
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(OldScaleFactor);
    
    return sprite;
}

/*
    Its creating sprite with construction of square02b_001.png sub sprites.
    Looks like emo textures (pink and black cell)
*/
cocos2d::CCSprite* ModUtils::createPlaceholder() {
        auto sprite = cocos2d::CCSprite::create();

        auto subSprite1 = cocos2d::CCSprite::create("square02b_001.png");
        auto subSprite2 = cocos2d::CCSprite::create("square02b_001.png");
        auto subSprite3 = cocos2d::CCSprite::create("square02b_001.png");
        auto subSprite4 = cocos2d::CCSprite::create("square02b_001.png");

        std::array<cocos2d::CCSprite*, 4> sprites = {subSprite1, subSprite2, subSprite3, subSprite4};

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
    position as offset from 0 to center point of screen size
*/
const cocos2d::CCPoint ModUtils::getCenterPoint() {
    return cocos2d::CCDirector::sharedDirector()->getWinSize() / 2;
}

//creating rgb animation that u can apply to node
cocos2d::CCAction* ModUtils::CreateRGB(float speed) {
    return CreateRGB(speed, false);
}

//creating rgb animation that u can apply to node
cocos2d::CCAction* ModUtils::CreateRGB(float speed, bool is_reverse) {
    return is_reverse ?
        cocos2d::CCRepeatForever::create(cocos2d::CCSequence::create(
            cocos2d::CCTintTo::create(speed, 0, 255, 255),
            cocos2d::CCTintTo::create(speed, 0, 0, 255),
            cocos2d::CCTintTo::create(speed, 255, 0, 255),
            cocos2d::CCTintTo::create(speed, 255, 0, 0),
            cocos2d::CCTintTo::create(speed, 255, 255, 0),
            cocos2d::CCTintTo::create(speed, 0, 255, 0),
            nullptr
        )) : cocos2d::CCRepeatForever::create(cocos2d::CCSequence::create(
            cocos2d::CCTintTo::create(speed, 255, 0, 0),
            cocos2d::CCTintTo::create(speed, 255, 255, 0),
            cocos2d::CCTintTo::create(speed, 0, 255, 0),
            cocos2d::CCTintTo::create(speed, 0, 255, 255),
            cocos2d::CCTintTo::create(speed, 0, 0, 255),
            cocos2d::CCTintTo::create(speed, 255, 0, 255),
            nullptr
        ));
}

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
    Write current process memory with bytes vector
    example:
    //Fixes trail cutting on high refresh rates
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(gd::base + 0x71D48, { 0xEB });
*/
bool ModUtils::write_bytes(const std::uintptr_t address, std::vector<uint8_t> const& bytes) {
    return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}

//return string as relative path of random file in target directory
std::string ModUtils::getRandomFileNameFromDir(std::string path, std::string or_else) {
    if(cocos2d::CCFileUtils::sharedFileUtils()->isFileExist(path)){
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

/*
    FOR GEODE LOADER
    return true if pCCNode already has child with MOD_SEED tag
*/
bool ModUtils::ttcallesc(cocos2d::CCNode* pCCNode) {
    setupModSeed();
    if (pCCNode->getChildByTag(ModUtils::getModSeed())) return true;
    else pCCNode->addChild(cocos2d::CCNode::create(), 9999, ModUtils::getModSeed());
    //log(__FUNCTION__);
    return false;
}

#include <random>

/*
    FOR GEODE LOADER
    generates a random number and defines it in MOD_SEED
*/
void ModUtils::setupModSeed() {
    if (MOD_SEED < 1) {
        std::random_device os_seed;
        const unsigned int seed = os_seed();
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> distribute(250, 1000);
        MOD_SEED = distribute(generator);
        ModUtils::log((__FUNCTION__": MOD_SEED=" + std::to_string(getModSeed()) + "\n"));
    }
}

/*
    FOR GEODE LOADER
    returns MOD_SEED
*/
int ModUtils::getModSeed() {
    return MOD_SEED;
}

//returns std::filesystem::path of self
std::filesystem::path ModUtils::GetModPath() {
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(GetModPath, &mbi, sizeof(mbi));
    HINSTANCE hModule = (HINSTANCE)(mbi.AllocationBase);
    size_t size = 1;
    char* buffer;
    for (; ; ) {
        buffer = new char[size + 1];
        DWORD r = GetModuleFileName(hModule, buffer, size);
        if (r < size && r != 0) break;
        if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
            delete buffer;
            size += 64;
        }
        else return std::filesystem::path("");
    }
    return std::filesystem::path(buffer);
}

//get name of mod via parsing GetModPath()
std::string ModUtils::GetModName() {
    std::vector<std::string> vect = explode(GetModPath().filename().string(), '.');
    if (vect[2] == "dll") {
        return vect[1];
    }
    else return vect[0];
}

//get developer of mod via parsing GetModPath()
std::string ModUtils::GetModDev() {
    std::vector<std::string> vect = explode(GetModPath().filename().string(), '.');
    if (vect[2] == "dll") {
        return vect[0];
    }
    else return "unknown";
}

//simple printf with time and mod name
void ModUtils::log(std::string msg, std::string prefix, bool milliseconds) {
    std::ostringstream logentry;
    if (logentry << "\033[38;5;8m") {//gray color part bruh
        //logTime
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        logentry << std::put_time(&tm, "%H:%M:%S");
        //ms
        if (milliseconds) logentry << "." << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() % 1000;
        //log prefix
        logentry << " " << prefix;
    } logentry << "\033[0m";
    //mod name prefix
    logentry << " [" << GetModName() << "]: ";
    //msg
    logentry << msg << std::endl;
    //just do it
    printf(logentry.str().c_str());
}

//simple printf with time and mod name
void ModUtils::log(std::string msg, std::string prefix) {
    ModUtils::log(msg, prefix, false);
}

//simple printf with time and mod name
void ModUtils::log(std::string msg, bool milliseconds) {
    ModUtils::log(msg, "CE", milliseconds);
}

//simple printf with time and mod name
void ModUtils::log(std::string msg) {
    ModUtils::log(msg, "CE", false);
}

/*
    create strings vector by splitting string with separator char
    example:
    ModUtils::log(ModUtils::explode("zero_str.str1.strTwo", '.')[2]); //print strTwo
*/
std::vector<std::string> ModUtils::explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;
    // For each character in the string
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        }
        else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

//set every char of string to lower
void ModUtils::strToLower(std::string& str) {
    for (auto& c : str) c = tolower(c);
}

//its copy text to clipboard...
void ModUtils::copyToClipboard(const char* text) {
    const size_t len = strlen(text) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), text, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

/*
    calls copyToClipboard(text) and popups on parent the text on black bg that says "Copied to clipboard"
    for me dont working btw
*/
void ModUtils::copyToClipboard(const char* text, cocos2d::CCLayer* parent) {
    copyToClipboard(text);
    parent->addChild(gd::TextAlertPopup::create("Copied to clipboard", 0.5f, 0.6f), 100);
}

//for exaple: "(*&*$() 101 cvcds /*-`1мивфд" => "(*%26*%24()+101+cvcds+%2F*-%601мивфд"
std::string ModUtils::url_encode(const std::string& value) {
    using namespace std;
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char)c);
        escaped << nouppercase;
    }

    return escaped.str();
}

//for exaple: "dW5ubw==" => "unno"
std::string ModUtils::base64_encode(const std::string& in) {
    std::string out;
    int val = 0, valb = -6;
    for (char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
    while (out.size() % 4) out.push_back('=');
    return out;
}

//for exaple: "unno" => "dW5ubw=="
std::string ModUtils::base64_decode(const std::string& in) {
    std::string out;
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    int val = 0, valb = -8;
    for (char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

//if node is bad it return new cocos2d::CCNode to escape crash
cocos2d::CCNode* ModUtils::TheNodeOrSomeNode(cocos2d::CCNode* node) {
    return (node && node->isRunning()) ? node : cocos2d::CCNode::create();
}