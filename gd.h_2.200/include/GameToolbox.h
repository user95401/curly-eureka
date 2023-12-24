#ifndef __GAMETOOLBOX_H__
#define __GAMETOOLBOX_H__

#include <gd.h>

class CCMenuItemToggler;

namespace gd {
    namespace GameToolbox {
        static CCMenuItemToggler* createToggleButton(
            cocos2d::SEL_MenuHandler onToggle,
            bool bToggled,
            cocos2d::CCMenu* pToggleMenu,
            cocos2d::CCNode* pTarget,
            cocos2d::CCNode* pLabelParent,
            float fCheckboxScale,
            float fLabelSize,
            float fMaxWidth,
            const char* sIdk,
            bool bIdk,
            int nTag,
            cocos2d::CCArray* pToggleArray,
            std::string sText,
            cocos2d::CCPoint obPosition,
            cocos2d::CCPoint obLabelOffset
        );
        static void transformColor(cocos2d::ccColor3B const& src, cocos2d::ccColor3B & dest, cocos2d::ccHSVValue hsv);
    }
}

#endif
