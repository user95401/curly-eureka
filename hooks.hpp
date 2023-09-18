#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cstdint>
#include <iostream>
#include <MinHook.h>

struct hook {
	static bool create(LPVOID target, LPVOID hook, LPVOID* original);
	static bool safe_initialize();
};

#define MH_SafeInitialize() hook::safe_initialize()

/*examples:
	HOOK(base + 0x1907B0, MenuLayer_init, false); //to safe hook with a delay
	HOOK(base + 0x18C8E0, LoadingLayer_loadAssets, true); //to unsafe hook immediately
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