#pragma once
#include <_MUGEN_TYPES.hpp>

#undef main
namespace mugen20414::main {
	enum class GameMode {
		kGModeArcade = 0,
		kGModeVersus = 1,
		kGModeTeamArcade = 2,
		kGModeTeamVersus = 3,
		kGModeTeamCoop = 4,
		kGModeSurvival = 5,
		kGModeSurvivalCoop = 6,
		kGModeTraining = 7,
		kGModeWatch = 8,
	};
	enum class ScreenMode {
		kSModeMenuVersus = 0,
		kSModeMatch = 4,
		kSModeArcadeWin = 5,
		kSModeSurvivalLose = 6,
		kSModeCharSelect = 7,
	};
}