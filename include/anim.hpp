#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <sprite.hpp>

namespace mugen20414::anim {
	using namespace mugen20414::array;
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

	struct AnimElem
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

	using  AnimElemArray = Array<AnimElem>;

	struct Anim
	{
		AnimElemArray* animElemArray;
		int32_t totalElems;
		int32_t totalFrames;
		int32_t loopStartFrame;
		undefined4 _unknown_1;
	};
	struct AnimArray
	{
		Array<Anim>* animArray;
		int32_t totalAnims;
	};

	struct AnimUsed
	{
		AnimArray* useAnimArray;
		Sprite* sprite;
		undefined4 _unknown_1;
		int32_t currentAnimIndex;
		AnimElemArray* currentAnimElemArray;
		int32_t currentAnimElemIndex;
		int32_t totalElapsedFrames;
		int32_t currentFrame;
		TransType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		int32_t currentSpriteIndex;
		Sprite* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
		int32_t sprPriority;
	};
}