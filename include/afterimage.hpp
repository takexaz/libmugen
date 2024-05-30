#pragma once
#include <_MUGEN_TYPES.hpp>

#include <pallete.hpp>
using namespace mugen20414::pallete;

#include <anim.hpp>
using namespace mugen20414::anim;

namespace mugen20414::afterimage {
	struct AfterimagePalletes
	{
		int32_t _unknown_1;
		undefined4 _unknown_2;
		undefined4 _unknown_3;
		undefined4 _unknown_4;
		undefined4 _unknown_5;
		undefined4 _unknown_6;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
		PalleteData* palletes;
		undefined4 _unknown_9[406];
	};
	struct AfterimageList
	{
		uint32_t enable;
		int32_t id;
		int32_t _unknown;
		int32_t search_id;
	};
	struct AfterimageData
	{
		AfterimagePalletes* palletes;
		int32_t length_maximum;
		AnimUsed* anim;
		int32_t _unknown_2;
		int32_t _unknown_3;
		int32_t elapsedTime;
		uint32_t enable;
		int32_t time;
		int32_t length;
		int32_t timeGap;
		int32_t frameGap;
		int32_t palColor;
		uint32_t palInvertAll;
		int32_t palBrightR;
		int32_t palBrightG;
		int32_t palBrightB;
		int32_t palContrastR;
		int32_t palContrastG;
		int32_t palContrastB;
		int32_t palPostBrightR;
		int32_t palPostBrightG;
		int32_t palPostBrightB;
		int32_t palAddR;
		int32_t palAddG;
		int32_t palAddB;
		int32_t palMulR;
		int32_t palMulG;
		int32_t palMulB;
		TransType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
	};
	struct AfterimageInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t currentAfterImageCnt;
		int32_t maxAfterImageCnt;
		uint32_t nextId;
		AfterimageData* data;
		AfterimageList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};
}