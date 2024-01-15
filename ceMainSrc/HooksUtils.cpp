#include "HooksUtils.hpp"
#include "patterns.hpp"
#include "ModUtils.hpp"
#include <shellapi.h>

const char* ShowThatModUsesCE = "Made with curly-eureka by user666. :>";

//hook

MH_STATUS HooksUtils::CreateHook(LPVOID target, LPVOID hook, LPVOID* original) {
	//MH_CreateHook
	MH_STATUS hook_status = MH_CreateHook(target, hook, original);
	//logit
	if(!HooksUtils::DontSendLogs) ModUtils::log(std::to_string((DWORD)target) + std::string(" [hook]: ") + MH_StatusToString(hook_status), false);
	//msg box if somth wrong
	if (hook_status != MH_STATUS::MH_OK) {
		//msg "%username%" Some message to display
		auto msg = std::format(
			"something went wrong when attempting to hook function\n"
			"at {} ({} excl base module),\n"
			"in {} mod,\n"
			"status: {}.",
			(int)target, (int)target - (int)GetModuleHandleA(0),
			ModUtils::GetModName(),
			MH_StatusToString(hook_status)
		).c_str();
		MessageBoxA(nullptr, msg, (ModUtils::GetModName() + " - " + __FUNCTION__).c_str(), MB_ICONERROR | MB_OK | MB_TASKMODAL);
		return hook_status;
	}
	//return status
	return MH_EnableHook(target);
}
