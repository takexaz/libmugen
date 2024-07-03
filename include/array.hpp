#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::array {
	struct ArrayList {
		BOOL enable;
		int32_t id;
		int32_t grp;
		int32_t item;
	};

	template <typename T>
	struct Array {
		undefined4 _unknown_1;
		size_t dataSize;
		int32_t numData;
		size_t maxNumData;
		uint32_t nextID;
		T* datas;
		ArrayList* list;
		int32_t scanedIdx;
		int32_t scanedCnt;
		int32_t minIndex;
		int32_t maxIndex;
	};

	template <typename T>
	static const auto ArrayNew             = reinterpret_cast<Array<T> * (*)(size_t numData, size_t dataSize, int _unknown_1)>(0x408800);
	template <typename T>
	static const auto ArrayCopy            = reinterpret_cast<Array<T> * (*)(Array<T> * src)>(0x4088c0);
	template <typename T>
	static const auto ArrayCopyOnto        = reinterpret_cast<Array<T> * (*)(Array<T> * dest, Array<T> * src)>(0x4089b0);
	template <typename T>
	static const auto ArrayFree            = reinterpret_cast<void (*)(Array<T> * arrayPtr)>(0x408a30);
	template <typename T>
	static const auto ArrayHasSpace        = reinterpret_cast<BOOL(*)(Array<T> * arrayPtr)>(0x408a70);
	template <typename T>
	static const auto ArrayAdd             = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, T* data, int32_t group, int32_t item)>(0x408a90);
	template <typename T>
	static const auto ArrayAddUnique       = reinterpret_cast<void (*)(Array<T> * arrayPtr, T* data, int32_t group, int32_t item)>(0x408bf0);
	template <typename T>
	static const auto ArrayAddResize       = reinterpret_cast<Array<T> * (*)(Array<T> * arrayPtr, T* data, int32_t group, int32_t item)>(0x408c50);
	template <typename T>
	static const auto ArrayAddUniqueResize = reinterpret_cast<Array<T> * (*)(Array<T> * arrayPtr, T* data, int32_t group, int32_t item)>(0x408c90);
	template <typename T>
	static const auto ArrayDelete          = reinterpret_cast<void (*)(Array<T> * arrayPtr, int32_t index)>(0x408d10);
	template <typename T>
	static const auto ArrayClear           = reinterpret_cast<void (*)(Array<T> * arrayPtr)>(0x408de0);
	template <typename T>
	static const auto ArrayResize          = reinterpret_cast<BOOL(*)(Array<T> * arrayPtr, int newNumData)>(0x408e20);
	template <typename T>
	static const auto ArrayFindEmpty       = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr)>(0x408ec0);
	template <typename T>
	static const auto ArrayAccessSafe      = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, int index)>(0x408f30);
	template <typename T>
	static const auto ArrayFind            = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, int32_t group, int32_t item)>(0x408f50);
	template <typename T>
	static const auto ArrayAccessGrpItem   = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, int32_t group, int32_t item)>(0x4090f0);
	template <typename T>
	static const auto ArrayIdxToGrp        = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, int32_t index)>(0x409160);
	template <typename T>
	static const auto ArrayIdxToItem       = reinterpret_cast<int32_t(*)(Array<T> * arrayPtr, int32_t index)>(0x4091f0);
	template <typename T>
	static const auto ArrayScanFirst       = reinterpret_cast<T * (*)(Array<T> * arrayPtr)>(0x409240);
	template <typename T>
	static const auto ArrayScanNext        = reinterpret_cast<T * (*)(Array<T> * arrayPtr)>(0x4092b0);
}