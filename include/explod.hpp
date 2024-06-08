#pragma once
#include <_MUGEN_TYPES.hpp>

#include <Font.hpp>
#include <Sprite.hpp>
#include <Anim.hpp>

namespace mugen20414::explod {
	using namespace mugen20414::font;
	using namespace mugen20414::sprite;
	using namespace mugen20414::anim;

	enum class SysExplodType {
		kAnim = 1,
		kSprite = 2,
		kFont = 3,
	};

	struct SysExplod {
		SysExplodType type;
		union {
			int32_t anim;
			SpriteParam sprite;
			FontParam font;
		} param;
		undefined4 unknown_1;
		int32_t displayTime;
		int32_t offsetX;
		int32_t offsetY;
		int32_t layerNo;
		undefined4 unknown_2;
		int32_t uniqueId;
		BOOL facing;
		BOOL vfacing;
		float scaleX;
		float scaleY;
		char text[48];
	};

	struct Explod
	{
		uint32_t exists;
		uint32_t visible;
		uint32_t invisible;
		int32_t ownerPlayerId;
		int32_t id;
		float axisX;
		float axisY;
		float velX;
		float velY;
		float accelX;
		float accelY;
		int32_t offsetX;
		int32_t offsetY;
		int32_t pauseMoveTime;
		int32_t superMoveTime;
		int32_t elapsedTime;
		int32_t removeTime;
		float scaleX;
		float scaleY;
		float* basePlayerRealPosX;
		float* basePlayerRealPosY;
		int32_t* stagePosX;
		int32_t* stagePosY;
		uint32_t posType; /* 0: P1, Front: 1, Back: 2, Left: 3, Right: 4, P2: 5 */
		int32_t bindTime;
		uint32_t layerNo;
		uint32_t inverse; /* &1: facing, &2: vfacing */
		undefined4 _unknown_1;
		BOOL enableEnvShake;
		uint32_t shadow;
		uint32_t removeOnGetHit;
		uint32_t ignoreHitPause;
		AnimUsed* anim;
		DrawType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		SpriteArrayEx* spriteArray;
		undefined4 _unknown_3;
		undefined4 _unknown_4[15];
		undefined4 _unknown_5;
		undefined4 _unknown_6;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
	};
	struct ExplodArray
	{
		Explod* datas;
		int32_t explodsMax;
		int32_t explodsCnt;
	};
}