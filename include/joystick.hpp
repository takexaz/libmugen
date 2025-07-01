#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::joystick {
	enum class JoystickType {
		kJoyDisable = 0,
		kJoyAutodetect = 1,
		kJoyFourButton = 4,
		kJoySixButton = 6,
		kJoyEightButton = 8,
		kJoySidewinder = 20,
		kJoySNES = 21,
		kJoyPSX = 22,
		kJoyN64 = 23,
	};

}