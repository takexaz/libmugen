#pragma once
#include <_MUGEN_TYPES.hpp>

#include <kbi.hpp>
using namespace mugen20414::kbi;

namespace mugen20414::command {
	struct CommandData {
		KeyState* command;
		uint32_t paramCount;
		uint32_t time;
		uint32_t bufferTime;
		uint32_t nameIdx;
		uint32_t nameIdxNo;
	};
	struct CommandElem {
		CommandData* commands;
		char** names; // ‡‚É‚ÍÁ‚¦‚é
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