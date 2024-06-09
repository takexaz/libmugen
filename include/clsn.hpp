#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::clsn {
	struct Clsn
	{
		undefined4 _unknown;
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
}