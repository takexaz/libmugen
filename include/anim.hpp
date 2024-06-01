#pragma once
#include <_MUGEN_TYPES.hpp>

#include <sprite.hpp>

namespace mugen20414::anim {
	using namespace mugen20414::sprite;

	enum class TransType {
		kDefault     = -1,
		kNone        = 0,
		kAddition    = 1,
		kSubtraction = 2,
		kAlpha       = 3,
	};

	struct ClsnData
	{
		undefined4 _unknown;
		int32_t x_back;
		int32_t y_bottom;
		int32_t x_front;
		int32_t x_upper;
	};
	struct ClsnInfo
	{
		uint32_t enable;
		int32_t clsn_cnt;
		ClsnData* data;
	};

	struct AnimElemData
	{
		int32_t startFrame;
		int32_t displayTime;
		int32_t groupNo;
		int32_t itemNo;
		int32_t axisX;
		int32_t axisY;
		uint32_t inverse; /* &1: H, &2: V */
		TransType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		ClsnInfo* clsn1;
		ClsnInfo* clsn2;
	};
	struct AnimElemList
	{
		uint32_t enable;
		int32_t id;
		int32_t _unknown;
		int32_t elemNo;
	};
	struct AnimElemInfo
	{
		uint32_t enable;
		int32_t size;
		int32_t currentElemCnt;
		int32_t maxElemCnt;
		int32_t nextId;
		AnimElemData* data;
		AnimElemList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};

	struct AnimData
	{
		AnimElemInfo* info;
		int32_t totalElems;
		int32_t totalFrames;
		int32_t loopStartFrame;
	};
	struct AnimList
	{
		uint32_t enable;
		int32_t id;
		int32_t _unknown_1;
		int32_t animNo;
	};
	struct AnimInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t maxAnimIndex;
		int32_t currentAnimCnt;
		int32_t nextId;
		AnimData* data;
		AnimList* list;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};
	struct AnimInfoEx
	{
		AnimInfo* info;
		int32_t totalAnims;
	};

	struct AnimUsed
	{
		AnimInfoEx* useAnimInfoEx;
		SpriteInfoEx* sff;
		undefined4 _unknown_1;
		int32_t currentAnimIndex;
		AnimElemData* currentAnimElem;
		int32_t currentAnimElemIndex;
		int32_t totalElapsedFrames;
		int32_t currentFrame;
		TransType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		int32_t currentSpriteIndex;
		SpriteInfoEx* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
		int32_t sprPriority;
	};
}