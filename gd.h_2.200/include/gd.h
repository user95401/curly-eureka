#ifndef __GD_H__
#define __GD_H__

#include <cocos2d.h>
#include <cocos-ext.h>

#include "gdMacros.h"

namespace gd {
	inline auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	inline auto libcocos2d = reinterpret_cast<uintptr_t>(GetModuleHandleA("libcocos2d.dll"));

	inline bool init() {
		static_assert(sizeof(std::string) == 24,
			"\n[GD.H] std::string is not 24 bytes\n" \
			"[GD.H] Any classes containing member strings or using strings in functions will break!\n" \
			"[GD.H] this is caused by building in Debug mode, to fix switch to Release\n");
		return base;
	}
}

namespace FMOD {
	class System;
	class Sound;
	class Channel;
	class DSP;
}
enum FMOD_RESULT;

#include "../headers/_main.hpp"
#include "../classes/_main.hpp"

#include "GameToolbox.h"

#endif
