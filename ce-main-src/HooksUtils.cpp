#include "HooksUtils.hpp"
#include "patterns.hpp"
#include "ModUtils.hpp"
#include <shellapi.h>

const char* ShowThatModUsesCE = "Made with curly-eureka by user666. :>";

//hook

MH_STATUS HooksUtils::CreateHook(LPVOID target, LPVOID hook, LPVOID* original) {
	//MH_CreateHook
	MH_STATUS hook_status = MH_CreateHook(target, hook, original);
	//for logging
	std::string sbaserva = ModUtils::toHex((int)target - (int)GetModuleHandleA(0));
	if (target < GetModuleHandleA(0)) sbaserva = "NA - CANT BE IN MODULE";
	std::string starg = ModUtils::toHex((int)target);
	std::string smhstatus = MH_StatusToString(hook_status);
	//logit
	if (!HooksUtils::DontSendLogs) {
		ModUtils::log(std::format(
			"creating hook at {} (base rva: {}) => {}",
			starg, sbaserva, smhstatus
		), false);
	}
	//msg box if somth wrong
	if (hook_status != MH_STATUS::MH_OK) {
		std::string Caption = (ModUtils::GetModName() + " - " + __FUNCTION__).c_str();
		std::string Msg = std::format(
			"Something went wrong when attempting to hook function\n"
			"at {} (base rva: {}),\n"
			"in {} mod by {}.\n"
			"MH Status: {}.",
			starg, sbaserva,
			ModUtils::GetModName(), ModUtils::GetModDev(),
			smhstatus
		);
		ModUtils::ShowSafeMessageBox(Caption, Msg, MB_ICONERROR | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
		return hook_status;
	}
	//return status
	return MH_EnableHook(target);
}
