#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cstdint>
#include <MinHook.h>

struct hook {
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

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET