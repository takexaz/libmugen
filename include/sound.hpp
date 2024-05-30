#pragma once
#include <_MUGEN_TYPES.hpp>

#include <Allegro.hpp>
using namespace Allegro;

namespace mugen20414::sound {
	struct SoundItem
	{
		int32_t groupNo;
		int32_t itemNo;
	};
	struct SoundList
	{
		uint32_t enable;
		int32_t id;
		SoundItem item;
	};
	struct SoundData
	{
		SAMPLE* sound;
	};
	struct SoundInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t currentSndCnt;
		int32_t maxSndCnt;
		int32_t nextId;
		SoundData* data;
		SoundList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};
}