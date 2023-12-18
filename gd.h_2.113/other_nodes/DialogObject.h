#ifndef __DIALOGOBJECT_H__
#define __DIALOGOBJECT_H__

#include <gd.h>

namespace gd {
    
class GDH_DLL DialogObject : public cocos2d::CCObject
{
  public:
    std::string m_sText;
    std::string m_sTitle;
    int m_nDialogType;
    cocos2d::ccColor3B m_pColour;
    float m_fTextWidth;
    bool m_bCanSkip;

    static DialogObject* create(std::string title, std::string text, int portrait, float text_scale, bool is_unskippable, cocos2d::ccColor3B text_color) {
        return reinterpret_cast<DialogObject * (__fastcall*)(std::string, std::string, int, float, bool, cocos2d::_ccColor3B)>(base + 0x6D160)(title, text, portrait, text_scale, is_unskippable, text_color);
    }
 };
}

#endif
