#pragma once
#include <_MUGEN_TYPES.hpp>


namespace mugen20414::kbi {
	enum class KeyCode{
		kEsc        = 1,
		k1          = 2,
		k2          = 3,
		k3          = 4,
		k4          = 5,
		k5          = 6,
		k6          = 7,
		k7          = 8,
		k8          = 9,
		k9          = 10,
		k0          = 11,
		kMinus      = 12,
		kEquals     = 13,
		kBackSpace  = 14,
		kTab        = 15,
		kQ          = 16,
		kW          = 17,
		kE          = 18,
		kR          = 19,
		kT          = 20,
		kY          = 21,
		kU          = 22,
		kI          = 23,
		kO          = 24,
		kP          = 25,
		kOpenBrace  = 26,
		kCloseBrace = 27,
		kEnter      = 28,
		kLControl   = 29,
		kA          = 30,
		kS          = 31,
		kD          = 32,
		kF          = 33,
		kG          = 34,
		kH          = 35,
		kJ          = 36,
		kK          = 37,
		kL          = 38,
		kColon      = 39,
		kQuote      = 40,
		kTilde      = 41,
		kLShift     = 42,
		kBackSlash  = 43,
		kZ          = 44,
		kX          = 45,
		kC          = 46,
		kV          = 47,
		kB          = 48,
		kN          = 49,
		kM          = 50,
		kComma      = 51,
		kStop       = 52,
		kSlash      = 53,
		kRShift     = 54,
		kAsterisk   = 55,
		kAlt        = 56,
		kSpace      = 57,
		kCapsLock   = 58,
		kF1         = 59,
		kF2         = 60,
		kF3         = 61,
		kF4         = 62,
		kF5         = 63,
		kF6         = 64,
		kF7         = 65,
		kF8         = 66,
		kF9         = 67,
		kF10        = 68,
		kNumLock    = 69,
		kScrLock    = 70,
		k7_Pad      = 71,
		k8_Pad      = 72,
		k9_Pad      = 73,
		kMinus_Pad  = 74,
		k4_Pad      = 75,
		k5_Pad      = 76,
		k6_Pad      = 77,
		kPlus_Pad   = 78,
		k1_Pad      = 79,
		k2_Pad      = 80,
		k3_Pad      = 81,
		k0_Pad      = 82,
		kDel_Pad    = 83,
		kPrtScr     = 84,
		kBackSlash2 = 86,
		kF11        = 87,
		kF12        = 88,
		kLWin       = 91,
		kRWin       = 92,
		kMenu       = 93,
		kKana       = 112,
		kABNT_C1    = 115,
		kConvert    = 121,
		kNoConvert  = 123,
		kYen        = 125,
	};
	enum class KeyState {
		//kUNDEF = 1 << 0,
		//kUNDEF = 1 << 1,
		//kUNDEF = 1 << 2,
		//kUNDEF = 1 << 3,
		kA = 1 << 4,
		kB = 1 << 5,
		kC = 1 << 6,
		kX = 1 << 7,
		kY = 1 << 8,
		kZ = 1 << 9,
		kStart = 1 << 10,
		kUp = 1 << 12,
		kFoward = 1 << 13,
		kDown = 1 << 14,
		kBack = 1 << 15,
		kTilde = 1 << 16,
		kSlash = 1 << 17,
		kDoller = 1 << 18,
		kNone = 1 << 19, // Nothing? Neutral?
	};

	struct ConfigKeyCodes
	{
		undefined4 _unknown_1;
		KeyCode jump;
		KeyCode right;
		KeyCode crouch;
		KeyCode left;
		KeyCode a;
		KeyCode b;
		KeyCode c;
		KeyCode x;
		KeyCode y;
		KeyCode z;
		KeyCode start;
		undefined4 _unknown_2;
	};
	struct KBIState
	{
		KeyCode inputKeyCode[30];
		undefined4 _unknonw_1;
		uint32_t jumpPushed;
		uint32_t fowardPushed;
		uint32_t downPushed;
		uint32_t backPushed;
		uint32_t aPushed;
		uint32_t bPushed;
		uint32_t cPushed;
		uint32_t xPushed;
		uint32_t yPushed;
		uint32_t zPushed;
		uint32_t startPushed;
		undefined4 _unknown_2;
		int32_t min_index;
		int32_t max_index;
		uint32_t _unknown_3;
		uint32_t flip;
		KeyState commandDetectLog[128];
		uint32_t commandDetectTime[128];
		uint32_t commandDetectedElapsedTime[128];
		uint32_t keyPushLeaveCntCarry;
		uint32_t keyPushLeaveCnt_1;
		uint32_t keyPushLeaveCnt_2;
		undefined4 _unknown_4;
		undefined4 _unknown_5;
		undefined4 _unknown_6;
		undefined4 _unknown_7;
		uint32_t aTime;
		uint32_t bTime;
		uint32_t cTime;
		uint32_t xTime;
		uint32_t yTime;
		uint32_t zTime;
		uint32_t startTime;
		undefined4 _unknown_8;
		uint32_t jumpPushTime;
		uint32_t fowardPushTime;
		uint32_t downPushTime;
		uint32_t backPushTime;
		uint32_t isHitPause;
		KeyState pushedKeys;
		KeyState pushedArrowKeys;
		KeyState simulPushedKeys;
	};
}