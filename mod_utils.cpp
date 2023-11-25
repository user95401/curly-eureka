#include "mod_utils.hpp"

int MOD_SEED;

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

cocos2d::CCSprite* ModUtils::createSprite(const char* name, bool ForceScaleFactor) {
    float OldScaleFactor = cocos2d::CC_CONTENT_SCALE_FACTOR();
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(ForceScaleFactor ? 2.0f : OldScaleFactor);
    auto sprite = createSprite(name);
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(OldScaleFactor);
    return sprite;
}

cocos2d::CCSprite* ModUtils::createSprite(const char* name, float ForceScaleFactor) {
    float OldScaleFactor = cocos2d::CC_CONTENT_SCALE_FACTOR();

    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(ForceScaleFactor);
    auto sprite = createSprite(name);
    cocos2d::CCDirector::sharedDirector()->setContentScaleFactor(OldScaleFactor);
    
    return sprite;
}

cocos2d::CCSprite* ModUtils::createPlaceholder(){
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

cocos2d::CCPoint ModUtils::getCenterPoint() {
    return cocos2d::CCPoint(cocos2d::CCMenu::create()->getPosition());
}

cocos2d::CCAction* ModUtils::CreateRGB(float speed) {
    return CreateRGB(speed, false);
}

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

gd::CCMenuItemSpriteExtra* ModUtils::createTextButton(cocos2d::CCLayer* parent, const char* text, cocos2d::SEL_MenuHandler handler, int width, float height, float scale){
    auto buttonSprite = gd::ButtonSprite::create(text, width, true, "bigFont.fnt", "GJ_button_01.png", height, scale);
    auto buttonButton = gd::CCMenuItemSpriteExtra::create(
        buttonSprite,
        parent,
        handler
    );
    buttonButton->setSizeMult(1.2f);

    return buttonButton;
}

bool ModUtils::write_bytes(const std::uintptr_t address, std::vector<uint8_t> const& bytes) {
    return WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
}

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

bool ModUtils::ttlihe(cocos2d::CCNode* node) {
    setupModSeed();
    if (node->getChildByTag(ModUtils::getModSeed())) return true;
    else node->addChild(cocos2d::CCNode::create(), 9999, ModUtils::getModSeed());
    return false;
}

#include <random>
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

int ModUtils::getModSeed() {
    return MOD_SEED;
}

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

void ModUtils::log(std::string msg) {
    std::ostringstream logentry;
    //logTime
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    logentry << std::put_time(&tm, "%H:%M:%S");
    //mod name prefix
    logentry << " [" << GetModName() << "]: ";
    //msg
    logentry << msg << std::endl;

    //just do it
    printf(logentry.str().c_str());
}

//explode("str1.str2.str3", '.')
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

void ModUtils::strToLower(std::string& str) {
    for (auto& c : str) c = tolower(c);
}

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

void ModUtils::copyToClipboard(const char* text, cocos2d::CCLayer* parent) {
    copyToClipboard(text);
    parent->addChild(gd::TextAlertPopup::create("Copied to clipboard", 0.5f, 0.6f), 100);
}

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

cocos2d::CCNode* ModUtils::TheNodeOrSomeNode(cocos2d::CCNode* node) {
    return (node && node->isRunning()) ? node : cocos2d::CCNode::create();
}