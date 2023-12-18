#ifndef __GJOPTIONSLAYER_H__
#define __GJOPTIONSLAYER_H__

#include <gd.h>

namespace gd {
    class GDH_DLL GJOptionsLayer : public FLAlertLayer {
        public:
            void addToggle(const char* name, const char* key, const char* info) {
                reinterpret_cast<void*(__thiscall*)(GJOptionsLayer*, const char*, const char*, const char*)>(base + 0x138C30)(this, name, key, info);
            }
            bool init() {
                reinterpret_cast<bool*(__thiscall*)(GJOptionsLayer*)>(base + 0x1387F0)(this);
            }
    };
}

#endif