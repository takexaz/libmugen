#pragma once
#include <_MUGEN_TYPES.hpp>
#include <txtparse.hpp>

namespace mugen20414::collision {
	using namespace mugen20414::txtparse;

	struct Clsn
	{
		BOOL enable;
		int32_t x1;
		int32_t y1;
		int32_t x2;
		int32_t y2;
	};
	struct ClsnArray
	{
		uint32_t enable;
		int32_t maxData;
		Clsn* data;
		int32_t numData;
		int32_t numInstance;
	};

	static const auto ClsnArrayNew              = reinterpret_cast<ClsnArray * (*)(size_t numClsn)>(0x4132b0);
	static const auto ClsnArrayFree             = reinterpret_cast<void (*)(ClsnArray * clsnArray)>(0x413320);
	static const auto ClsnArrayCopy             = reinterpret_cast<ClsnArray * (*)(ClsnArray * clsnArray)>(0x413360);
	static const auto ClsnArrayInstance         = reinterpret_cast<ClsnArray * (*)(ClsnArray * clsnArray)>(0x413400);
	static const auto ClsnArrayAdd              = reinterpret_cast<BOOL(*)(ClsnArray * clsnArray, Clsn * clsn)>(0x413410);
	static const auto ClsnArrayAddRect          = reinterpret_cast<BOOL(*)(ClsnArray * clsnArray, int32_t x1, int32_t y1, int32_t x2, int32_t y2)>(0x413450);
	static const auto ClsnParseLine             = reinterpret_cast<ClsnArray * (*)(char* str, TPFile * tpf)>(0x4134d0);
	static const auto ClsnMixDetectRectIndiv    = reinterpret_cast<BOOL(*)(ClsnArray * clsnA, ClsnArray * clsnB, int32_t posX, int32_t posY)>(0x413990);
	static const auto ClsnMixDetectRectHFlip1   = reinterpret_cast<BOOL(*)(ClsnArray * clsnA, ClsnArray * clsnB, int32_t posX, int32_t posY)>(0x413a00);
	static const auto ClsnMixDetectRectHFlipAll = reinterpret_cast<BOOL(*)(ClsnArray * clsnA, ClsnArray * clsnB, int32_t posX, int32_t posY)>(0x413a90);
	static const auto ClsnArrayDetectRect       = reinterpret_cast<BOOL(*)(ClsnArray * clsnA, ClsnArray * clsnB, int32_t posX, int32_t posY)>(0x413b20);
	static const auto ClsnArrayDetectRectFlip   = reinterpret_cast<BOOL(*)(ClsnArray * clsnA, ClsnArray * clsnB, int32_t posX, int32_t posY, BOOL isClsnAFlip, BOOL isClsnBFlip)>(0x413c00);
}