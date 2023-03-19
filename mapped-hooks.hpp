#include <cstdint>
#include <unordered_map>
#include <MinHook.h>

namespace MHook {
    using std::uintptr_t;

    inline std::unordered_map<void*, void*> hooks;

    auto registerHook(uintptr_t address, void* hook) {
        void* trampoline;
        auto status = MH_CreateHook(reinterpret_cast<void**>(address), hook, &trampoline);
        if (status == MH_OK)
            hooks[hook] = trampoline;
        else if(MessageBoxA(nullptr, "An error has occured while hooking a function...\nMaybe you have original minhook.x32.dll\nDo you want to download right version?", "MinHook", MB_ICONERROR | MB_YESNO) == IDYES) system("explorer https://github.com/HJfod/minhook/releases/latest");
        return status;
    }

    template <typename F>
    inline auto getOriginal(F self) {
        return reinterpret_cast<F>(hooks[self]);
    }
}

