#ifndef __CCSCROLLLAYEREXT_H__
#define __CCSCROLLLAYEREXT_H__

#include <gd.h>

namespace gd {

	class CCContentLayer;
	class CCScrollLayerExtDelegate;

	class CCScrollLayerExt : public cocos2d::CCLayer {
	public:
		cocos2d::CCTouch* m_pTouch;	// 0x11c
		cocos2d::CCPoint m_obTouchPosition;		 // 0x120
		cocos2d::CCPoint m_obTouchStartPosition; // 0x128
		PAD(8)
		bool m_bTouchDown;	// 0x138
		bool m_bNotAtEndOfScroll;	// 0x139
		PAD(2)
		cocos2d::CCLayerColor* m_pVerticalScrollbar;	// 0x13c
		cocos2d::CCLayerColor* m_pHorizontalScrollbar;	// 0x140
		CCScrollLayerExtDelegate* m_pDelete;	// 0x144
		CCContentLayer* m_pContentLayer;	// 0x148
		bool m_bCutContent; // 0x14c
		bool m_bVScrollbarVisible;	// 0x14d
		bool m_bHScrollbarVisible;	// 0x14e
		bool m_bDisableHorizontal; // 0x14f
		bool m_bDisableVertical; // 0x150
		bool m_bDisableMovement; // 0x151
		PAD(2)
		float m_fScrollLimitTop; // 0x154
		float m_fScrollLimitBottom; // 0x158
		float m_fPeekLimitTop; // 0x15c
		float m_fPeekLimitBottom; // 0x160

	protected:
		CCScrollLayerExt(cocos2d::CCRect rect) {
			reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, cocos2d::CCRect)>(
				base + 0x1B020
				)(this, rect);
		}

	public:
		//own vtable
		virtual void preVisitWithClippingRect(cocos2d::CCRect rect) {
			return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, cocos2d::CCRect)>(
				base + 0x1C000
				)(this, rect);
		}
		virtual void postVisit() {
			return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
				base + 0x1C090
				)(this);
		}
		void moveToTopWithOffset(float fOffset) {
			__asm { movss xmm1, fOffset }

			reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
				base + 0x1b420
			)(this);
		}
		void moveToTop() {
			reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
				base + 0x1b4a0
			)(this);
		}
	};

	class CCScrollLayerExtDelegate {
	public:
		//lol nice typo rob
		virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt*) {}
		virtual void scrollViewDidEndDecelerating(CCScrollLayerExt*) {}
		virtual void scrollViewTouchMoving(CCScrollLayerExt*) {}
		virtual void scrollViewDidEndMoving(CCScrollLayerExt*) {}
		virtual void scrollViewTouchBegin(CCScrollLayerExt*) {}
		virtual void scrollViewTouchEnd(CCScrollLayerExt*) {}
	};
}

#endif