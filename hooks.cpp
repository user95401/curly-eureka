#include "hooks.hpp"

bool hook::create(LPVOID target, LPVOID hook, LPVOID* original) {

	MH_STATUS hook_status = MH_CreateHook(target, hook, original);

	if (hook_status != MH_STATUS::MH_OK) {
		MessageBoxA(nullptr, "something went wrong when attempting to hook function...", "MinHook", MB_ICONERROR | MB_OK);
		return false;
	}

	return MH_EnableHook(target) == MH_STATUS::MH_OK;
}

bool hook::safe_initialize() {

	std::random_device os_seed;
	const unsigned int seed = os_seed();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribute(250, 1000);
	int sleepMs = distribute(generator);

	Sleep(sleepMs);

	return MH_Initialize() == MH_STATUS::MH_OK;
}

const char* Made_with_curly_eureka_by_user666 = "Made with curly-eureka by user666. :>";