#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <sprite.hpp>
#include <clsn.hpp>

namespace mugen20414::anim {
	using namespace mugen20414::array;
	using namespace mugen20414::sprite;
	using namespace mugen20414::clsn;

	enum class DrawType {
		kError          = -2,
		kDefault        = -1,
		kNone           = 0,
		kAdd            = 1,
		kSub            = 2,
		kAdd1           = 3,
		kAddAlpha       = 3,
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
		DrawType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		ClsnArray* clsn1;
		ClsnArray* clsn2;
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

	using AnimArray = Array<Anim>*;

	struct AnimArrayEx
	{
		AnimArray* AnimArrayEx;
		int32_t totalAnims;
	};

	struct AnimUsed
	{
		AnimArrayEx* useAnimArrayEx;
		Sprite* sprite;
		undefined4 _unknown_1;
		int32_t currentAnimIndex;
		AnimElemArray* currentAnimElemArray;
		int32_t currentAnimElemIndex;
		int32_t totalElapsedFrames;
		int32_t currentFrame;
		DrawType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		int32_t currentSpriteIndex;
		Sprite* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
		int32_t sprPriority;
	};


	BOOL
}