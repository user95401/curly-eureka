#ifndef __EDITOROPTIONSLAYER_H__
#define __EDITOROPTIONSLAYER_H__

#include <gd.h>

namespace gd {
    class GDH_DLL EditorOptionsLayer : public GJOptionsLayer {
        public:
            static EditorOptionsLayer* create() {
                return reinterpret_cast<EditorOptionsLayer*(__fastcall*)()>(
                    base + 0x139D90
                )();
            }
            bool init() {
                reinterpret_cast<bool*(__thiscall*)(EditorOptionsLayer*)>(base + 0x1387F0)(this);
            }
            void setupOptions(const char* name, const char* key, const char* info) {
                reinterpret_cast<void*(__thiscall*)(EditorOptionsLayer*, const char*, const char*, const char*)>(base + 0x139E60)(this, name, key, info);
            }
    };
}

#endif