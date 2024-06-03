#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::array {
	struct ArrayList {
		BOOL enable;
		int32_t id;
		int32_t grp;
		int32_t item;
	};
	struct Array {
		undefined4 _unknown_1;
		size_t dataSize;
		int32_t numData;
		size_t maxNumData;
		uint32_t nextID;
		void* dataArray;
		struct ArrayList* dataArrayList;
		int32_t scanedIdx;
		int32_t scanedCnt;
		int32_t minIdx;
		int32_t maxIdx;
	};

	static const auto ArrayNew             = reinterpret_cast<Array * (*)(size_t numData, size_t dataSize, int _unknown_1)>(0x408800);
	static const auto ArrayCopy            = reinterpret_cast<Array * (*)(Array * src)>(0x4088c0);
	static const auto ArrayCopyOnto        = reinterpret_cast<Array * (*)(Array * dest, Array * src)>(0x4089b0);
	static const auto ArrayFree            = reinterpret_cast<void (*)(Array * arrayPtr)>(0x408a30);
	static const auto ArrayHasSpace        = reinterpret_cast<BOOL(*)(Array * arrayPtr)>(0x408a70);
	static const auto ArrayAdd             = reinterpret_cast<Array * (*)(Array * arrayPtr, void* data, int32_t group, int32_t item)>(0x408a90);
	static const auto ArrayAddUnique       = reinterpret_cast<void (*)(Array * arrayPtr, void* data, int32_t group, int32_t item)>(0x408bf0);
	static const auto ArrayAddResize       = reinterpret_cast<Array * (*)(Array * arrayPtr, void* data, int32_t group, int32_t item)>(0x408c50);
	static const auto ArrayAddUniqueResize = reinterpret_cast<Array * (*)(Array * arrayPtr, void* data, int32_t group, int32_t item)>(0x408c90);
	static const auto ArrayDelete          = reinterpret_cast<void (*)(Array * arrayPtr, int32_t index)>(0x408d10);
	static const auto ArrayClear           = reinterpret_cast<void (*)(Array * arrayPtr)>(0x408de0);
	static const auto ArrayResize          = reinterpret_cast<BOOL(*)(Array * arrayPtr, int newNumData)>(0x408e20);
	static const auto ArrayFindEmpty       = reinterpret_cast<int32_t(*)(Array * arrayPtr)>(0x408ec0);
	static const auto ArrayAccessSafe      = reinterpret_cast<int32_t(*)(Array * arrayPtr, int index)>(0x408f30);
	static const auto ArrayFind            = reinterpret_cast<int32_t(*)(Array * arrayPtr, int32_t group, int32_t item)>(0x408f50);
	static const auto ArrayAccessGrpItem   = reinterpret_cast<int32_t(*)(Array * arrayPtr, int32_t group, int32_t item)>(0x4090f0);
	static const auto ArrayIdxToGrp        = reinterpret_cast<int32_t(*)(Array * arrayPtr, int32_t index)>(0x409160);
	static const auto ArrayIdxToItem       = reinterpret_cast<int32_t(*)(Array * arrayPtr, int32_t index)>(0x4091f0);
	static const auto ArrayScanFirst       = reinterpret_cast<int32_t(*)(Array * arrayPtr)>(0x409240);
	static const auto ArrayScanNext        = reinterpret_cast<int32_t(*)(Array * arrayPtr)>(0x4092b0);
}