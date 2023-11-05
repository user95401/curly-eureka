#include "hooks.hpp"
#include "mod_utils.hpp"

MH_STATUS hook::create(LPVOID target, LPVOID hook, LPVOID* original) {
	//MH_CreateHook
	MH_STATUS hook_status = MH_CreateHook(target, hook, original);
	//msg box if somth wrong
	if (hook_status != MH_STATUS::MH_OK) {
		MessageBoxA(nullptr,
			(
				std::string("something went wrong when attempting to hook function...\n") +
				MH_StatusToString(hook_status)
				).c_str(),
			(ModUtils::GetModName() + " - " + __FUNCTION__).c_str(), MB_ICONERROR | MB_OK);
		return hook_status;
	}
	//logit
	ModUtils::log(std::to_string((DWORD)target) + std::string(" [hook]: ") + MH_StatusToString(hook_status));
	//return status
	return MH_EnableHook(target);
}

MH_STATUS hook::safe_initialize() {

	std::random_device os_seed;
	const unsigned int seed = os_seed();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribute(250, 1000);
	int sleepMs = distribute(generator);

	Sleep(sleepMs);

	return MH_Initialize();
}

const char* Made_with_curly_eureka_by_user666 = "Made with curly-eureka by user666. :>";