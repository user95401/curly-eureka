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

//lol 
#define HOOK_GD(offset, name) create_hook_gd(offset, h_##name, reinterpret_cast<LPVOID*>(&o_##name))
#define CC_HOOK(symbol, hook, orig) MH_CreateHook((PVOID)((int)GetProcAddress(GetModuleHandle("libcocos2d.dll"), symbol)), hook, (PVOID*)&orig)

static bool create_hook(
	LPVOID target,
	LPVOID hook,
	LPVOID* original)
{
	auto hook_status = MH_CreateHook(target, hook, original);
	if (hook_status != MH_STATUS::MH_OK) return false;
	return MH_EnableHook(target) == MH_STATUS::MH_OK;
}

static bool create_hook_gd(
	const std::uintptr_t offset,
	LPVOID hook,
	LPVOID* original)
{
	const auto base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL));
	auto pTarget = reinterpret_cast<LPVOID>(base + offset);
	return create_hook(pTarget, hook, original);
}

static bool create_hook_method(
	const std::string module_name,
	const std::string signature,
	LPVOID hook,
	LPVOID* original)
{
	auto h_module = GetModuleHandleA(module_name.c_str());
	if (!h_module) return false;
	auto method_address = GetProcAddress(h_module, signature.c_str());
	if (!method_address) return false;
	return create_hook(method_address, hook, original);
}

