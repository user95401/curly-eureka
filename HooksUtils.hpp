#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cstdint>
#include <MinHook.h>

struct HooksUtils {
    static inline bool DontSendLogs;
	static MH_STATUS CreateHook(LPVOID target, LPVOID hook, LPVOID* original);
};

/*
	HOOK(base + 0x1907B0, MenuLayer_init); //MenuLayer_init as org, MenuLayer_init_H as hook
*/
#define HOOK(target, name) HooksUtils::CreateHook(reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*for libcocos2d.dll funcs hooking
example:
CC_HOOK("?create@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_create, false);
*/
#define CC_HOOK(symbol, name) HooksUtils::CreateHook((PVOID)((int)GetProcAddress(GetModuleHandle("libcocos2d.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*for libExtensions.dll funcs hooking*/
#define CCEXT_HOOK(symbol, name) HooksUtils::CreateHook((PVOID)((int)GetProcAddress(GetModuleHandle("libExtensions.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name))
/*hook::dontSendLogs*/
#define DISABLE_HOOKS_LOGGING() HooksUtils::DontSendLogs = true

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET

#include <string>
#include <cstdlib>
#include <cstdint>
#include <unordered_map>
#include <type_traits> 
#include "ModUtils.hpp"
namespace MappedHooks {
    inline auto btw = "MappedHooks created by Cvolton";
    using std::uintptr_t;
    inline std::unordered_map<void*, void*> hooks;
    inline auto registerHook(uintptr_t address, void* hook) {
        void* trampoline;
        auto status = HooksUtils::CreateHook(reinterpret_cast<void**>(address), hook, &trampoline);
        if (status == MH_OK) MappedHooks::hooks[hook] = trampoline;
        else ModUtils::log(__FUNCTION__" was failed!");
        return status;
    }
    template <typename F>
    inline auto getOriginal(F self) {
        return reinterpret_cast<F>(MappedHooks::hooks[self]);
    }
}