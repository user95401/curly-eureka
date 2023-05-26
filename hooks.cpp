#include "hooks.hpp"
bool hook::create(LPVOID target, LPVOID hook, LPVOID* original) {
	MH_STATUS hook_status = MH_CreateHook(target, hook, original);
	if (hook_status != MH_STATUS::MH_OK) {
		MessageBoxA(nullptr, "something went wrong when attempting to hook function...", "MinHook", MB_ICONERROR | MB_OK);
		return false;
	}
	return MH_EnableHook(target) == MH_STATUS::MH_OK;
}