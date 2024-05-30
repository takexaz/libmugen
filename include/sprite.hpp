#pragma once
#include <_MUGEN_TYPES.hpp>

#include <pallete.hpp>
using namespace mugen20414::pallete;

namespace mugen20414::sprite {
	struct SpriteData
	{
		int32_t width;
		int32_t height;
		int32_t axisX;
		int32_t axisY;
		int32_t colorDepth;
		int32_t colors;
		undefined4 _unknown_1;
		uint32_t isAllegroBitmap;
		int32_t size;
		void* image; /* If isAllegroBitmap == 1 then BITMAP*, otherwise decoded pcx data */
		undefined4 _unknown_2;
		void* _unknown_3;
		int32_t palleteIndex;
	};
	struct SpriteList
	{
		uint32_t enable;
		int32_t id;
		int32_t groupNo;
		int32_t itemNo;
	};
	struct SpriteInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t currentSprCnt;
		int32_t maxSprCnt;
		int32_t nextId;
		SpriteData* data;
		SpriteList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};
	struct SpriteInfoEx
	{
		SpriteInfo* sprInfo;
		void* _unknown_1;
		PalleteInfo* palInfo;
		SpriteInfoEx* _unknown_2;
		int32_t refCnt;
	};
}