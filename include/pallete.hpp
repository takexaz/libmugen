#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::pallete {
	struct PalleteParams
	{
		undefined4 _unknown[9];
	};
	struct PalleteDataRGB
	{
		uint32_t r;
		uint32_t g;
		uint32_t b;
		undefined4 _unknown; /* Alpha? Padding? */
	};
	struct PalleteData
	{
		undefined4 size;
		uint32_t enable;
		PalleteDataRGB* rgbData;
		PalleteParams _unknown_1;
		PalleteParams _unknown_2;
		undefined4 _unknown_3;
		undefined4 _unknown_4;
		PalleteDataRGB _unknown_5[];
	};
	struct PalleteList
	{
		uint32_t enable;
		int32_t id;
		int32_t _unknown_1;
		int32_t _unknown_2;
	};
	struct PalleteInfo
	{
		undefined4 _unknown_1;
		int32_t size;
		int32_t currentPalleteCnt;
		int32_t maxPalleteCnt;
		int32_t nextId;
		PalleteData* data;
		PalleteList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};

	struct PalGroup
	{
		int32_t _unknown[5];
	};

	enum class EBPalFlag {
		kUnknown1 = 1 << 0,
		kDataChanged = 1 << 1,
		kUnknown2 = 1 << 2,
	};

	struct EBPalSetting {
		int32_t colorBalance; // todo
		int32_t palAddR; // 0x10
		int32_t palAddG;
		int32_t palAddB;
		int32_t palMulR; // 0x1C
		int32_t palMulG;
		int32_t palMulB;
		undefined4 _unknown_1;
		int32_t invertAll;
	};

	// 1628
	struct EBPallete {
		uint32_t numColor;
		bool isCopiedPal;
		PalleteData* palletes;
		EBPalSetting setting;
		undefined4 _unknown_3;
		undefined4 _unknown_4;
		undefined4 _unknown_5;
		undefined4 _unknown_6;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
		undefined4 _unknown_9;
		undefined4 _unknown_10;
		undefined4 _unknown_11;
		EBPalFlag flags; // [21]|0x54
		undefined4 _unknown_13;
		undefined4 _unknown_14; // [23]|0x5C
		undefined _unknown_15[1532]; // todo
	};

	static const auto EBPalInit            = reinterpret_cast<bool(*)(EBPallete * ebPal, uint32_t numColor, PalleteData * palletes, bool copyPalletes)>(0x448180);
	static const auto EBPalDeInit          = reinterpret_cast<void (*)(EBPallete * ebPal)>(0x448280);
	static const auto EBPalReset           = reinterpret_cast<void (*)(EBPallete * ebPal)>(0x4482b0);
	static const auto EBPalCopy            = reinterpret_cast<bool(*)(EBPallete * dest, EBPallete * src, bool copyPalletes)>(0x4482f0);
	static const auto EBPalGenerateFPal    = reinterpret_cast<void (*)(EBPallete * ebPal)>(0x448360);
	static const auto EBPalUpdate          = reinterpret_cast<void (*)(EBPallete * ebPal)>(0x4483c0);
	static const auto EBPalSetDataptr      = reinterpret_cast<bool(*)(EBPallete * ebPal, uint32_t numColor, PalleteData * palletes)>(0x4484f0);
	static const auto EBPalGetDataptr      = reinterpret_cast<PalleteData * (*)(EBPallete * ebPal)>(0x448530);
	static const auto EBPalGetNumcols      = reinterpret_cast<uint32_t(*)(EBPallete * ebPal)>(0x448540);
	static const auto EBPalMarkDataChanged = reinterpret_cast<void (*)(EBPallete * ebPal)>(0x448550);
	static const auto EBPalSettingsReset   = reinterpret_cast<void (*)(EBPalSetting * ebPalSet)>(0x448560);
	static const auto EBPalSettingsCopy    = reinterpret_cast<void(*)(EBPalSetting * dest, EBPalSetting * src)>(0x448590);
	static const auto EBPalSettingsMix     = reinterpret_cast<void(*)(EBPalSetting * dest, EBPalSetting * src1, EBPalSetting * src2)>(0x4485b0);
	static const auto EBPalSettingsAreSame = reinterpret_cast<bool(*)(EBPalSetting * ebPalSet1, EBPalSetting * ebPalSet2)>(0x448630);
	static const auto EBPalAdd             = reinterpret_cast<void(*)(EBPallete * ebPal, uint32_t Red, uint32_t Green, uint32_t Blue)>(0x448650);
	static const auto EBPalMul             = reinterpret_cast<void(*)(EBPallete * ebPal, uint32_t Red, uint32_t Green, uint32_t Blue)>(0x4486a0);
	static const auto EBPalInvertAll       = reinterpret_cast<void(*)(EBPallete * ebPal, bool invert)>(0x448700);
	static const auto EBPalColorBal        = reinterpret_cast<void(*)(EBPallete * ebPal, uint32_t colorBalance)>(0x448730);
}