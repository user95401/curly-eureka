#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cstdint>
#include <iostream>
#include <MinHook.h>

/*hook may looks like:

	inline bool(__thiscall* MenuLayer_init)(MenuLayer*);
	bool __fastcall MenuLayer_init_H(MenuLayer* self) {
		if (!MenuLayer_init(self)) return false;
		CCLabelTTF* msg = CCLabelTTF::create("hello", "Comic Sans MS", 30.0f);
		self->addChild(msg,10);
		return true;
	}

	or

	inline CCSprite* (__cdecl* CCSprite_create)(const char* name);
	CCSprite* CCSprite_create_H(const char* name) {
		if (std::string(name) == "GJ_colores_001.png" || std::string(name) == "GJ_paletaBtn_001.png")
			return ModUtils::createSprite("GJ_paintBtn_001.png");
		return CCSprite_create(name);
	}

*/

struct hook {
	static bool create(LPVOID target, LPVOID hook, LPVOID* original, bool immediately);
};

/*examples:
	HOOK(base + 0x1907B0, MenuLayer_init, false); //to safe hook with a delay
	HOOK(base + 0x18C8E0, LoadingLayer_loadAssets, true); //to unsafe hook immediately
*/
#define HOOK(target, name, immediately) hook::create(reinterpret_cast<LPVOID>(target), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name), immediately)
/*for libcocos2d.dll funcs hooking
example:
CC_HOOK("?create@CCSprite@cocos2d@@SAPAV12@PBD@Z", CCSprite_create, false);
*/
#define CC_HOOK(symbol, name, immediately) hook::create((PVOID)((int)GetProcAddress(GetModuleHandle("libcocos2d.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name), immediately)
/*for libExtensions.dll funcs hooking*/
#define CCEXT_HOOK(symbol, name, immediately) hook::create((PVOID)((int)GetProcAddress(GetModuleHandle("libExtensions.dll"), symbol)), reinterpret_cast<LPVOID*>(name##_H), reinterpret_cast<LPVOID*>(&name), immediately)

#define MEMBERBYOFFSET(type, class, offset) *reinterpret_cast<type*>(reinterpret_cast<uintptr_t>(class) + offset)
#define MBO MEMBERBYOFFSET