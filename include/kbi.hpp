#pragma once
#include <_MUGEN_TYPES.hpp>


namespace mugen20414::kbi {
	enum class KeyCode{
		kKCodeEsc        = 1,
		kKCode1          = 2,
		kKCode2          = 3,
		kKCode3          = 4,
		kKCode4          = 5,
		kKCode5          = 6,
		kKCode6          = 7,
		kKCode7          = 8,
		kKCode8          = 9,
		kKCode9          = 10,
		kKCode0          = 11,
		kKCodeMinus      = 12,
		kKCodeEquals     = 13,
		kKCodeBackSpace  = 14,
		kKCodeTab        = 15,
		kKCodeQ          = 16,
		kKCodeW          = 17,
		kKCodeE          = 18,
		kKCodeR          = 19,
		kKCodeT          = 20,
		kKCodeY          = 21,
		kKCodeU          = 22,
		kKCodeI          = 23,
		kKCodeO          = 24,
		kKCodeP          = 25,
		kKCodeOpenBrace  = 26,
		kKCodeCloseBrace = 27,
		kKCodeEnter      = 28,
		kKCodeLControl   = 29,
		kKCodeA          = 30,
		kKCodeS          = 31,
		kKCodeD          = 32,
		kKCodeF          = 33,
		kKCodeG          = 34,
		kKCodeH          = 35,
		kKCodeJ          = 36,
		kKCodeK          = 37,
		kKCodeL          = 38,
		kKCodeColon      = 39,
		kKCodeQuote      = 40,
		kKCodeTilde      = 41,
		kKCodeLShift     = 42,
		kKCodeBackSlash  = 43,
		kKCodeZ          = 44,
		kKCodeX          = 45,
		kKCodeC          = 46,
		kKCodeV          = 47,
		kKCodeB          = 48,
		kKCodeN          = 49,
		kKCodeM          = 50,
		kKCodeComma      = 51,
		kKCodeStop       = 52,
		kKCodeSlash      = 53,
		kKCodeRShift     = 54,
		kKCodeAsterisk   = 55,
		kKCodeAlt        = 56,
		kKCodeSpace      = 57,
		kKCodeCapsLock   = 58,
		kKCodeF1         = 59,
		kKCodeF2         = 60,
		kKCodeF3         = 61,
		kKCodeF4         = 62,
		kKCodeF5         = 63,
		kKCodeF6         = 64,
		kKCodeF7         = 65,
		kKCodeF8         = 66,
		kKCodeF9         = 67,
		kKCodeF10        = 68,
		kKCodeNumLock    = 69,
		kKCodeScrLock    = 70,
		kKCode7_Pad      = 71,
		kKCode8_Pad      = 72,
		kKCode9_Pad      = 73,
		kKCodeMinus_Pad  = 74,
		kKCode4_Pad      = 75,
		kKCode5_Pad      = 76,
		kKCode6_Pad      = 77,
		kKCodePlus_Pad   = 78,
		kKCode1_Pad      = 79,
		kKCode2_Pad      = 80,
		kKCode3_Pad      = 81,
		kKCode0_Pad      = 82,
		kKCodeDel_Pad    = 83,
		kKCodePrtScr     = 84,
		kKCodeBackSlash2 = 86,
		kKCodeF11        = 87,
		kKCodeF12        = 88,
		kKCodeLWin       = 91,
		kKCodeRWin       = 92,
		kKCodeMenu       = 93,
		kKCodeKana       = 112,
		kKCodeABNT_C1    = 115,
		kKCodeConvert    = 121,
		kKCodeNoConvert  = 123,
		kKCodeYen        = 125,
	};
	enum class KeyState {
		//kKStateUNDEF = 1 << 0,
		//kKStateUNDEF = 1 << 1,
		//kKStateUNDEF = 1 << 2,
		//kKStateUNDEF = 1 << 3,
		kKStateA = 1 << 4,
		kKStateB = 1 << 5,
		kKStateC = 1 << 6,
		kKStateX = 1 << 7,
		kKStateY = 1 << 8,
		kKStateZ = 1 << 9,
		kKStateStart = 1 << 10,
		kKStateUp = 1 << 12,
		kKStateFoward = 1 << 13,
		kKStateDown = 1 << 14,
		kKStateBack = 1 << 15,
		kKStateTilde = 1 << 16,
		kKStateSlash = 1 << 17,
		kKStateDoller = 1 << 18,
		kKStateNone = 1 << 19, // Nothing? Neutral?
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
		BOOL aPushed;
		BOOL bPushed;
		BOOL cPushed;
		BOOL xPushed;
		BOOL yPushed;
		BOOL zPushed;
		BOOL startPushed;
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
		int32_t aTime;
		int32_t bTime;
		int32_t cTime;
		int32_t xTime;
		int32_t yTime;
		int32_t zTime;
		int32_t startTime;
		undefined4 _unknown_8;
		int32_t jumpPushTime;
		int32_t fowardPushTime;
		int32_t downPushTime;
		int32_t backPushTime;
		uint32_t isHitPause;
		KeyState pushedKeys;
		KeyState pushedArrowKeys;
		KeyState simulPushedKeys;
	};

	struct IntCircBuf
	{
		int32_t* buf;
		int32_t requiredIdx;
		int32_t currentIdx;
		int32_t length;
	};
}