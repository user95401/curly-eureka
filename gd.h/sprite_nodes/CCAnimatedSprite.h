#ifndef __CCANIMATEDSPRITE_H__
#define __CCANIMATEDSPRITE_H__

#include <gd.h>

namespace gd {
	class GDH_DLL CCAnimatedSprite : public cocos2d::CCSprite {
	protected:
		std::string m_sUnknown1;
		std::string m_sUnknown2;
		PAD(20);
		std::string m_sUnknown3;
		PAD(4);

	public:
		static CCAnimatedSprite* create(const char* file) {
			return reinterpret_cast<CCAnimatedSprite* (__fastcall*)(const char*)>(
				base + 0x14540
				)(file);
		}

		//own vtable
		virtual void animationFinished(const char*) {}
		virtual void animationFinishedO(cocos2d::CCObject*) {}

		void runAnimation(std::string name) {
			reinterpret_cast<void(__thiscall*)(CCAnimatedSprite*, std::string)>(base + 0x14f60)(this, name);
		}
		void tweenToAnimation(int a1, const char* a2, cocos2d::CCDelayTime* a3) {
			reinterpret_cast<void(__thiscall*)(CCAnimatedSprite*, int, const char*, cocos2d::CCDelayTime*)>(base + 0x15080)(this, a1, a2, a3);
		}
	};

	class GDH_DLL AnimatedSpriteDelegate {
		virtual void animationFinished(const char*) {}
	};
}

#endif