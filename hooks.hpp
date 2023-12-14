#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cstdint>
#include <MinHook.h>

struct hook {
    static inline bool dontSendLogs;
	static MH_STATUS create(LPVOID target, LPVOID hook, LPVOID* original);
	static MH_STATUS safe_initialize();
};

#define MH_SafeInitialize() hook::safe_initialize()

/*
	HOOK(base + 0x1907B0, MenuLayer_init); //MenuLayer_init as org, MenuLayer_init_H as hook
*/
#define HOOK(target, name) hook::create(reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*for libcocos2d.dll funcs hooking
example:
CC_HOOK("?create@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_create, false);
*/
#define CC_HOOK(symbol, name) hook::create((PVOID)((int)GetProcAddress(GetModuleHandle("libcocos2d.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*for libExtensions.dll funcs hooking*/
#define CCEXT_HOOK(symbol, name) hook::create((PVOID)((int)GetProcAddress(GetModuleHandle("libExtensions.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*hook::dontSendLogs*/
#define DISABLE_HOOKS_LOGGING() hook::dontSendLogs = true

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET

#include <string>
#include <cstdlib>
#include <cstdint>
#include <unordered_map>
#include <type_traits> 
#include "mod_utils.hpp"
namespace MappedHooks {
    using std::uintptr_t;
    inline std::unordered_map<void*, void*> hooks;
    inline auto registerHook(uintptr_t address, void* hook) {
        void* trampoline;
        auto status = hook::create(reinterpret_cast<void**>(address), hook, &trampoline);
        if (status == MH_OK) MappedHooks::hooks[hook] = trampoline;
        else ModUtils::log(__FUNCTION__" was failed!");
        return status;
    }
    template <typename F>
    inline auto getOriginal(F self) {
        return reinterpret_cast<F>(MappedHooks::hooks[self]);
    }
}