#pragma once
#include <cstdint>
#include <iostream>
#include <MinHook.h>
struct hook {
	static bool create(LPVOID target, LPVOID hook, LPVOID* original);
};

#define GD_HOOK(target, name) hook::create(reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID*>(name##_h), reinterpret_cast<LPVOID*>(&name##_org))
#define CC_HOOK(symbol, hook, orig) MH_CreateHook((PVOID)((int)GetProcAddress(GetModuleHandle("libcocos2d.dll"), symbol)), hook, (PVOID*)&orig)
#define CCEXT_HOOK(symbol, hook, orig) MH_CreateHook((PVOID)((int)GetProcAddress(GetModuleHandle("libExtensions.dll"), symbol)), hook, (PVOID*)&orig)