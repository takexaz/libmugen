#pragma once
#include <_MUGEN_TYPES.hpp>

#include <kbi.hpp>

namespace mugen20414::command {
	using namespace mugen20414::kbi;

	struct CommandData {
		KeyState* command;
		uint32_t paramCount;
		int32_t time;
		int32_t bufferTime;
		uint32_t nameIdx;
		uint32_t nameIdxNo;
	};
	struct CommandElem {
		CommandData* commands;
		char** names; // ééçáéûÇ…ÇÕè¡Ç¶ÇÈ
		uint32_t count;
		uint32_t uniqueCount;
	};
	struct CommandInfo {
		ConfigKeyCodes* configKeyCodes;
		CommandElem* command;
		uint8_t isCommandDetect[128];
		uint32_t commandDetectTime[128];
	};
}