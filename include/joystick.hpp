#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::joystick {
	enum class JoystickType {
		kDisable = 0,
		kAutodetect = 1,
		kFourButton = 4,
		kSixButton = 6,
		kEightButton = 8,
		kSidewinder = 20,
		kSNES = 21,
		kPSX = 22,
		kN64 = 23,
	};

}