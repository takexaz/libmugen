#pragma once
#include <_MUGEN_TYPES.hpp>

#undef main
namespace mugen20414::main {
	enum class GameMode {
		kArcade = 0,
		kVersus = 1,
		kTeamArcade = 2,
		kTeamVersus = 3,
		kTeamCoop = 4,
		kSurvival = 5,
		kSurvivalCoop = 6,
		kTraining = 7,
		kWatch = 8,
	};
	enum class ScreenMode {
		kMenuVersus = 0,
		kMatch = 4,
		kArcadeWin = 5,
		kSurvivalLose = 6,
		kCharSelect = 7,
	};
}