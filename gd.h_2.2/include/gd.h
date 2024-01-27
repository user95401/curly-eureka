#ifndef __GD_H__
#define __GD_H__

#include <cocos2d.h>
#include <cocos-ext.h>

#include "gdMacros.h"

//yea ce requries now
#include "ModUtils.hpp"
#include "HooksUtils.hpp"

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

	class AchievementBar;
	class FLAlertLayerProtocol;
	class ButtonSprite;
	class ScrollingLayer;
	using GJBaseGameLayer = cocos2d::CCLayer;
	class CheckpointObject;
	class PlayerObject;
	class GameObject;

	// https://github.com/geode-sdk/geode/blob/main/loader/include/Geode/utils/SeedValue.hpp

	struct BaseSeedValue
	{
		BaseSeedValue() = default;
		BaseSeedValue(BaseSeedValue const& other) = default;
		BaseSeedValue(BaseSeedValue&& other) = default;
		BaseSeedValue& operator=(BaseSeedValue const& other) = default;
		BaseSeedValue& operator=(BaseSeedValue&& other) = default;
	};

	struct SeedValueRSV : public BaseSeedValue
	{
		int m_value_rand;
		int m_value_seed;
		int m_value;

		int value() const { return m_value; }
	};

	struct SeedValueVSR : public BaseSeedValue
	{
		int m_value;
		int m_value_seed;
		int m_value_rand;

		int value() const { return m_value; }
	};

	struct SeedValueRS : public BaseSeedValue
	{
		int m_value_rand;
		int m_value_seed;

		int value() const { return m_value_rand - m_value_seed; }
	};

}

namespace FMOD {
	class System;
	class Sound;
	class Channel;
	class DSP;
}
enum FMOD_RESULT;

#include "../headers/_main.hpp"

#include "GameToolbox.h"

#endif
