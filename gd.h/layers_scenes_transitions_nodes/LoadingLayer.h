#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__
#include <gd.h>
#include <sprite_nodes/TextArea.h>
namespace gd {
	class GDH_DLL LoadingLayer : public cocos2d::CCLayer {
	public:
		PAD(4);
		int m_nLoadIndex;
		cocos2d::CCLabelBMFont* m_pCaption;
		TextArea* m_pLoadingText;
		cocos2d::CCSprite* m_pSliderBar;
		float m_fSliderGrooveXPos;
		PAD(4);
		bool m_bFromRefresh;
		static LoadingLayer* create(bool fromReload) {
			return reinterpret_cast<LoadingLayer* (__fastcall*)(bool)>(
				base + 0x18BFE0
				)(fromReload);
		}
		void setFromRefresh(bool value) {
			m_bFromRefresh = value;
		}
		bool init(bool fromReload) {
			return reinterpret_cast<bool(__fastcall*)(bool)>(base + 0x18c080)(fromReload);
		}
		static const char* getLoadingString() {
			return reinterpret_cast<const char*(__fastcall*)()>(base + 0x18cf40)();
		}
		void loadAssets() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x18C8E0)(this);
		}
		void loadingFinished() {
			reinterpret_cast<void(__thiscall*)(void*)>(base + 0x18C790)(this);
		}
	};
}
#endif