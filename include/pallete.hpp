#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <ebcommon.hpp>

namespace mugen20414::pallete {
	using namespace mugen20414::array;
	using namespace mugen20414::ebcommon::io;

	struct Color3
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
	};
	struct Pal3 {
		Color3 color[256];
	};
	struct Color4
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		undefined1 _unknown; /* Alpha? Padding? */
	};
	struct Pal4 {
		Color4 color[256];
	};

	struct FPal {
		uint16_t color[256];
	};

	enum class EBPalFlag {
		kIsDrawing   = 1 << 0,
		kDataChanged = 1 << 1,
		kUnknown2    = 1 << 2,
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
	struct EBPal
	{
		uint32_t numColor;
		BOOL isCopiedPal;
		Pal4* pal4Data;
		EBPalSetting subPal;
		EBPalSetting mainPal;
		EBPalFlag flags; // [21]|0x54
		int32_t numDrawing;
		FPal nowPal;
	};
	struct EBPalArray {
		Array<EBPal>* ebPals;
	};

	struct EBMasterPal {
		EBPalSetting subPal;
		EBPalSetting mainPal;
		BOOL isDrawing;
		int32_t numDrawing;
		BOOL initialized;
	};

	struct PalGroup
	{
		int32_t _unknown[5];
	};


	static const auto EBPalInit            = reinterpret_cast<BOOL(*)(EBPal * ebPal, uint32_t numColor, Pal4 * palletes, BOOL copyPalletes)>(0x448180);
	static const auto EBPalDeInit          = reinterpret_cast<void (*)(EBPal * ebPal)>(0x448280);
	static const auto EBPalReset           = reinterpret_cast<void (*)(EBPal * ebPal)>(0x4482b0);
	static const auto EBPalCopy            = reinterpret_cast<BOOL(*)(EBPal * dest, EBPal * src, BOOL copyPalletes)>(0x4482f0);
	static const auto EBPalGenerateFPal    = reinterpret_cast<void (*)(EBPal * ebPal)>(0x448360);
	static const auto EBPalUpdate          = reinterpret_cast<void (*)(EBPal * ebPal)>(0x4483c0);
	static const auto EBPalSetDataptr      = reinterpret_cast<BOOL(*)(EBPal * ebPal, uint32_t numColor, Pal4 * palletes)>(0x4484f0);
	static const auto EBPalGetDataptr      = reinterpret_cast<Pal4 * (*)(EBPal * ebPal)>(0x448530);
	static const auto EBPalGetNumcols      = reinterpret_cast<uint32_t(*)(EBPal * ebPal)>(0x448540);
	static const auto EBPalMarkDataChanged = reinterpret_cast<void (*)(EBPal * ebPal)>(0x448550);
	static const auto EBPalSettingsReset   = reinterpret_cast<void (*)(EBPalSetting * ebPalSet)>(0x448560);
	static const auto EBPalSettingsCopy    = reinterpret_cast<void(*)(EBPalSetting * dest, EBPalSetting * src)>(0x448590);
	static const auto EBPalSettingsMix     = reinterpret_cast<void(*)(EBPalSetting * dest, EBPalSetting * src1, EBPalSetting * src2)>(0x4485b0);
	static const auto EBPalSettingsAreSame = reinterpret_cast<BOOL(*)(EBPalSetting * ebPalSet1, EBPalSetting * ebPalSet2)>(0x448630);
	static const auto EBPalAdd             = reinterpret_cast<void(*)(EBPal * ebPal, uint32_t red, uint32_t green, uint32_t blue)>(0x448650);
	static const auto EBPalMul             = reinterpret_cast<void(*)(EBPal * ebPal, uint32_t red, uint32_t green, uint32_t blue)>(0x4486a0);
	static const auto EBPalInvertAll       = reinterpret_cast<void(*)(EBPal * ebPal, BOOL invert)>(0x448700);
	static const auto EBPalColorBal        = reinterpret_cast<void(*)(EBPal * ebPal, uint32_t colorBalance)>(0x448730);

	static volatile const auto MasterPal = reinterpret_cast<EBMasterPal**>(0x4b5fb0);
	static volatile const auto palupdatecount = reinterpret_cast<uint32_t*>(0x4b5fb4);

	static const auto MasterPalInit           = reinterpret_cast<BOOL(*)(void)>(0x448760);
	static const auto MasterPalDeInit         = reinterpret_cast<void(*)(void)>(0x4487e0);
	static const auto MasterPalProcessChanges = reinterpret_cast<void(*)(void)>(0x448800);
	static const auto MasterPalFinishedDraw   = reinterpret_cast<void(*)(void)>(0x448830);
	static const auto MasterPalReset          = reinterpret_cast<void(*)(void)>(0x448860);
	static const auto MasterPalAdd            = reinterpret_cast<void(*)(uint32_t red, uint32_t green, uint32_t blue)>(0x4488a0);
	static const auto MasterPalMul            = reinterpret_cast<void(*)(uint32_t red, uint32_t green, uint32_t blue)>(0x4488f0);
	static const auto MasterPalInvertAll      = reinterpret_cast<void(*)(BOOL invert)>(0x448940);
	static const auto MasterPalColorBal       = reinterpret_cast<void(*)(uint32_t colorBalance)>(0x448970);
	static const auto MasterPalConvertCol16   = reinterpret_cast<void(*)(Pal4 * palData)>(0x4489a0);

	static const auto Pal3toPal4         = reinterpret_cast<void(*)(Pal4 * dest, Pal3 * src, size_t length, uint32_t alpha)> (0x448a00);
	static const auto Pal4Copy           = reinterpret_cast<void(*)(Pal4 * dest, Pal4 * src, uint32_t startIndex, size_t size)> (0x448a60);
	static const auto Pal4SetSingle      = reinterpret_cast<void(*)(Pal4 * pal4Data, uint32_t colNo, uint32_t red, uint32_t green, uint32_t blue)> (0x448aa0);
	static const auto Pal4Contrast       = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t contrast, uint32_t startIndex, size_t length)> (0x448ad0);
	static const auto Pal4ContrastRGB    = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t red, uint32_t green, uint32_t blue, uint32_t startIndex, size_t length)> (0x448ba0);
	static const auto Pal4Brightness     = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t brightness, uint32_t startIndex, size_t length)> (0x448c80);
	static const auto Pal4BrightnessRGB  = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t red, uint32_t green, uint32_t blue, uint32_t startIndex, size_t length)> (0x448d50);
	static const auto Pal4ColorBal       = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t colorBalance, uint32_t startIndex, size_t length)> (0x448e40);
	static const auto Pal4InvertAll      = reinterpret_cast<void(*)(Pal4 * src, Pal4 * dest, uint32_t startIndex, size_t length)> (0x448ff0);
	static const auto Pal4Read3File      = reinterpret_cast<BOOL(*)(Pal4 * pal4Data, const char* filename)> (0x449040);
	static const auto Pal4Read3FilePtr   = reinterpret_cast<BOOL(*)(Pal4 * Pal4Data, MFile * mfp)> (0x4490d0);
	static const auto Pal4ToFpal         = reinterpret_cast<void(*)(Pal4 * pal4Data, FPal * fpalData, uint32_t startIndex, size_t length)> (0x449160);
	static const auto Pal4SettingsToFpal = reinterpret_cast<void(*)(Pal4 * pal4Data, EBPalSetting * ebPalSet, FPal * fpalData, uint32_t startIndex, size_t length)> (0x4491c0);

	// todo
}