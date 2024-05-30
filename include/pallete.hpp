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
}