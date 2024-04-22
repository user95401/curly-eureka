﻿#include "ModUtils.hpp"
#include <fstream>
#include <array>
#include <filesystem>

using namespace cocos2d;
using namespace cocos2d::extension;

int MOD_SEED;

extern std::map<uint32_t, std::string> s_buildMap;
std::map<uint32_t, std::string> s_buildMap =
{
    { 1419173053, "1.900" },
    { 1419880840, "1.910" },
    { 1421745341, "1.920" },
    { 1440638199, "2.000" },
    { 1440643927, "2.001" },
    { 1443053232, "2.010" },
    { 1443077847, "2.011" },
    { 1443077847, "2.020" },
    { 1484612867, "2.100" },
    { 1484626658, "2.101" },
    { 1484737207, "2.102" },
    { 1510526914, "2.110" },
    { 1510538091, "2.111" },
    { 1510619253, "2.112" },
    { 1511220108, "2.113" },
    { 1702921605, "2.200" },
    { 1704582672, "2.201" },
    { 1704601266, "2.202" },
    { 1704948277, "2.203" },
    { 1705041028, "2.204" },
};

/*
    Recommended use it to create sprite :>
    It will try create sprite with CCSprite::create() or CCSprite::createWithSpriteFrameName()
    and if both methods falils, will be created placeholder
*/
cocos2d::CCSprite* ModUtils::createSprite(const char* name) {

    auto sprite = cocos2d::CCSprite::createWithSpriteFrameName(name);
    if (!sprite) sprite = cocos2d::CCSprite::create(name);
    if (sprite) return sprite;

    log(std::format(__FUNCTION__": cant create {}", name));

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

/*
    Write current process memory with bytes vector
    example:
    //Fixes trail cutting on high refresh rates
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(gd::base + 0x71D48, { 0xEB });
*/
bool ModUtils::WriteProcMem(const std::uintptr_t address, std::vector<uint8_t> const& bytes, std::string title) {
    //nothing to rewrite
    if (ReadProcMem(address, bytes.size()) == bytes) return false;
    //stringstream
    std::stringstream log;
    //some values
    std::string sbaserva = ModUtils::toHex((int)address - (int)GetModuleHandleA(0));
    if ((int)address < (int)GetModuleHandleA(0)) sbaserva = "NA - CANT BE IN MODULE";
    std::string starg = ModUtils::toHex((int)address);
    //log func and addr
    log << __func__ << (title != "" ? std::format(" \"{}\"", title) : "") << " at " << starg;
    //rva also
    log << " (base rva: " << sbaserva << ")";
    //with what
    log << " with \"";
    for (uint8_t value : bytes) {
        log << ((value != bytes[0]) ? " " : "") << std::hex << (int)value;
    }
    log << "\"";
    //was what
    log << ", org was \"" << ReadProcMemAsStr(address, bytes.size() < 16 ? 16 : bytes.size()) << "\"";
    //a
    bool rtn = WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(address), bytes.data(), bytes.size(), nullptr);
    if (rtn) ModUtils::log(log.str());
    else ModUtils::log(std::format("WriteProcMem{} failed (at {}, base rva: {})", (title != "" ? std::format(" \"{}\"", title) : ""), starg, sbaserva));
    log.clear();
    return rtn;
}
bool ModUtils::WriteProcMem(const std::uintptr_t address, std::vector<uint8_t> const& bytes) {
    return WriteProcMem(address, bytes, "");
}

std::vector<uint8_t> ModUtils::ReadProcMem(DWORD address, int length) {
    std::vector<uint8_t> buffer(length);
    ReadProcessMemory(GetCurrentProcess(), (void*)address, buffer.data(), length, NULL);
    return buffer;
}

std::string ModUtils::ReadProcMemAsStr(DWORD address, int length) {
    std::stringstream asd;
    std::vector<uint8_t> asdser = ReadProcMem(address, length);
    bool FirstWasAdded = false;//brainfuckway
    for (uint8_t value : asdser) {
        asd << (FirstWasAdded ? " " : "") << std::hex << (int)value;
        FirstWasAdded = true;
    }
    return asd.str();
}

//std::vector<uint8_t> { intToBytes(777)[0], intToBytes(777)[1], intToBytes(777)[2],intToBytes(777)[3] }
std::vector<unsigned char> ModUtils::intToBytes(int value) {
    std::vector<unsigned char> result;
    result.push_back(value & 0x000000ff);
    result.push_back((value & 0x0000ff00) >> 8);
    result.push_back((value & 0x00ff0000) >> 16);
    result.push_back((value & 0xff000000) >> 24);
    return result;
}

std::string ModUtils::toHex(const size_tType& number) {
    std::stringstream stream;
    stream << std::hex << number;
    return stream.str();
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
        MessageBox(nullptr, 
            std::format("The directory \"{}\"' isn't founded", path).c_str(),
            std::format("{}({},{})", __FUNCTION__, path, or_else).c_str(),
            MB_ICONERROR | MB_OK
        );
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

std::string ModUtils::GetGameVersion() {
    HMODULE hMod = GetModuleHandle(NULL);
    PIMAGE_DOS_HEADER dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(hMod);
    if (dos_header->e_magic == IMAGE_DOS_SIGNATURE) {
        PIMAGE_NT_HEADERS nt_header = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uintptr_t>(hMod) + dos_header->e_lfanew);
        if (nt_header->Signature == IMAGE_NT_SIGNATURE) {
            auto it = s_buildMap.find(nt_header->FileHeader.TimeDateStamp);
            if (it != s_buildMap.end()) return it->second;
            return std::format("{}", nt_header->FileHeader.TimeDateStamp);
        }
    }
    return std::string();
}

#define _CRT_SECURE_NO_WARNINGS 1;
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
    return (node) ? node : cocos2d::CCNode::create();
}

//set object id label for every children
cocos2d::CCNode* ModUtils::markChildrensWithIndex(cocos2d::CCNode* node) {
    node->setTag(5920);
    for (int index = 0; index < node->getChildrenCount(); index++) {
        cocos2d::CCNode* childa = reinterpret_cast<cocos2d::CCNode*>(node->getChildren()->objectAtIndex(index));
        if (childa->getChildByTag(8592)) break;//already got markChildrensWithIndex
        if (!childa) break;//bad node idk
        //hl shed
        markChildrensWithIndex(childa);
        float r = 1.5f;
        cocos2d::ccColor3B color;
        switch (rand() % 8) {
        case 0:
            color = { 255,255,255 };
            break;
        case 1:
            color = { 255,255,0 };
            break;
        case 2:
            color = { 0,0,255 };
            break;
        case 3:
            color = { 0,255,0 };
            break;
        case 4:
            color = { 255,0,0 };
            break;
        case 5:
            color = { 255,0,255 };
            break;
        case 6:
            color = { 0,0,0 };
            break;
        case 7:
            color = { 255,127,0 };
            break;
        case 8:
            color = { 166,166,166 };
            break;
        default:
            color = { 255,255,255 };
            break;
        }
        //someMarkIdk
        cocos2d::CCSprite* someMarkIdk = ModUtils::createSprite("circle.png");
        childa->addChild(someMarkIdk, 100, 8592);
        someMarkIdk->setScale(0.3f);
        someMarkIdk->runAction(ModUtils::CreateRGB(r));
        //a bg
        cocos2d::CCSprite* baga = ModUtils::createSprite("square.png");
        childa->addChild(baga, 100, 8592);
        if (someMarkIdk->getContentSize().height > 20);
        baga->setScaleX(childa->getContentSize().width / baga->getContentSize().width);
        baga->setScaleY(childa->getContentSize().height / baga->getContentSize().height);
        baga->setPosition(childa->getContentSize() / 2);
        baga->setColor(color);
        baga->setOpacity(0);
        baga->runAction(cocos2d::CCRepeatForever::create(cocos2d::CCSequence::create(cocos2d::CCFadeTo::create(r, 12), cocos2d::CCFadeTo::create(r, 32), nullptr)));
        //index label
        cocos2d::CCLabelTTF* pCCLabelTTF = cocos2d::CCLabelTTF::create(std::format("{}", index).c_str(), "arial", 8.f);
        childa->addChild(pCCLabelTTF, 100, 8592);
        pCCLabelTTF->setAnchorPoint(cocos2d::CCPointZero);
        pCCLabelTTF->setColor(color);
    }
    return node;
}

std::filesystem::path ModUtils::GetModResourcesPath() {
    //modResourcesPath
    return std::filesystem::path(std::filesystem::current_path() / "Resources" / ModUtils::GetModName());
}

std::string ModUtils::AddSearchPathForMod() {
    //modResourcesPath
    std::filesystem::path modResourcesPath = ModUtils::GetModResourcesPath();
    //create dir
    std::filesystem::create_directories(modResourcesPath);
    //add search path
    cocos2d::CCFileUtils::sharedFileUtils()->addSearchPath(modResourcesPath.string().c_str());
    return modResourcesPath.string();
}

bool ModUtils::FindOutIfFileExists(std::string sFileName) {
    auto pCCFileUtils = cocos2d::CCFileUtils::sharedFileUtils();
    return pCCFileUtils->isFileExist(pCCFileUtils->fullPathForFilename(sFileName.c_str(), 0).c_str());
}

#pragma comment (lib, "urlmon.lib") //has a URLDownloadToFile, retuns S_OK if ok
STDAPI ModUtils::DownloadFile(std::string sUrl, std::string sFileName) {
    //modResourcesPath
    std::string modResourcesPath = AddSearchPathForMod();
    //download.
    return URLDownloadToFile(NULL,
        //link
        sUrl.c_str(),
        //output
        std::format("{}/{}", modResourcesPath, sFileName).c_str(),
        0, NULL);
}

void ModUtils::OpenConsole() {
    //https://github.com/geode-sdk/geode/blob/main/loader/src/platform/windows/LoaderImpl.cpp#L57C2-L57C2
    if (!AllocConsole()) return;
    SetConsoleCP(CP_UTF8);
    // redirect console output
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
    freopen_s(reinterpret_cast<FILE**>(stdin), "CONIN$", "r", stdin);
    // Set output mode to handle ansi color sequences
    auto handleStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode = 0;
    if (GetConsoleMode(handleStdout, &consoleMode)) {
        consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(handleStdout, consoleMode);
    }
}

static std::string NextCaption;
static std::string NextMsg;
static UINT NextType;
DWORD WINAPI MsgThread(void* hModule) {
    Sleep(100);
    MessageBoxA(nullptr, NextMsg.c_str(), NextCaption.c_str(), NextType);
    ExitThread(0);
    return 0;
}
void ModUtils::ShowSafeMessageBox(std::string Caption, std::string Msg, UINT uType) {
    NextCaption = Caption;
    NextMsg = Msg;
    if (uType == 0) NextType = (MB_ICONINFORMATION | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
    else NextType = uType;
    CreateThread(0, 0, MsgThread, nullptr, 0, 0);
}

std::string ModUtils::truncate(std::string str, size_t width, bool show_ellipsis) {
    if (str.length() > width)
        if (show_ellipsis) return str.substr(0, width) + "...";
        else return str.substr(0, width);
    return str;
}

int ModUtils::stoi(const std::string& str, int* p_value, std::size_t* pos, int base) {
    // wrapping std::stoi because it may throw an exception
    try {
        *p_value = std::stoi(str, pos, base);
        return 0;
    }
    catch (const std::invalid_argument& ia) {
        //std::cerr << "Invalid argument: " << ia.what() << std::endl;
        return -1;
    }
    catch (const std::out_of_range& oor) {
        //std::cerr << "Out of Range error: " << oor.what() << std::endl;
        return -2;
    }
    catch (const std::exception& e)
    {
        //std::cerr << "Undefined error: " << e.what() << std::endl;
        return -3;
    }
}

std::string ModUtils::getTexturePath(CCNode* node) {
    if (auto sprite_node = dynamic_cast<CCSprite*>(node); sprite_node) {
        auto* texture = sprite_node->getTexture();
        auto* texture_cache = CCTextureCache::sharedTextureCache();
        auto* cached_textures = public_cast(texture_cache, m_pTextures);
        CCDictElement* el;
        CCDICT_FOREACH(cached_textures, el) {
            if (el->getObject() == texture) {
                return (el->getStrKey());
                break;
            }
        }
    }
    return "nah";
}

std::string ModUtils::getFrameName(CCNode* node) {
    if (auto sprite_node = dynamic_cast<CCSprite*>(node); sprite_node) {
        auto* texture = sprite_node->getTexture();
        auto* frame_cache = CCSpriteFrameCache::sharedSpriteFrameCache();
        auto* cached_frames = public_cast(frame_cache, m_pSpriteFrames);
        const auto rect = sprite_node->getTextureRect();
        CCDictElement* el;
        CCDICT_FOREACH(cached_frames, el) {
            auto* frame = static_cast<CCSpriteFrame*>(el->getObject());
            if (frame->getTexture() == texture && frame->getRect().equals(rect)) {
                return (el->getStrKey());
            }
        }
    }
    return "nah";
}

