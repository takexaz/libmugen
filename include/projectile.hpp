#pragma once
#include <_MUGEN_TYPES.hpp>
#include <array.hpp>
#include <controller.hpp>
#include <anim.hpp>
#include <afterimage.hpp>
#include <sprite.hpp>

namespace mugen20414::projectile {
	using namespace mugen20414::array;
	using namespace mugen20414::state::controller;
	using namespace mugen20414::anim;
	using namespace mugen20414::afterimage;
	using namespace mugen20414::sprite;


	struct Projectile
	{
		int32_t projId;
		int32_t status;
		int32_t teamSide;
		int32_t projPriority;
		int32_t projHitAnim;
		int32_t projRemAnim;
		int32_t projCancelAnim;
		int32_t projHits;
		int32_t elapsedTime;
		int32_t time;
		int32_t projBindTime;
		undefined4 _unknown_1;
		int32_t projMissTime;
		int32_t facing;
		uint32_t projRemove;
		int32_t projRemoveTime;
		uint32_t projShadow;
		float posX;
		float posY;
		float posZ;
		float projScale;
		float projScaleX;
		float projScaleY;
		undefined4 _unknown_2;
		undefined4 _unknown_3;
		float velocityX;
		float velocityY;
		float remVelocityX;
		float remVelocityY;
		float velMulX;
		float velMulY;
		float accelX;
		float accelY;
		int32_t projEdgeBound;
		int32_t projStageBoundLeft;
		int32_t projHeightBoundUpper;
		int32_t projStageBoundRight;
		int32_t projHeightBoundBottom;
		HitdefParams projHitDefParams;
		AnimUsed* anim;
		undefined4 sff;
		undefined4 _unknown_4;
		undefined4 _unknown_5;
		undefined4 _unknown_6;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
		undefined4 _unknown_9;
		undefined4 _unknown_10;
		undefined4 _unknown_11;
		undefined4 _unknown_12;
		undefined4 _unknown_13;
		undefined4 _unknown_14;
		undefined4 _unknown_15;
		int32_t projSprPriority;
		undefined4 _unknown_16;
		undefined4 _unknown_17;
		undefined4 _unknown_18;
		undefined4 _unknown_19;
		int32_t superMoveTime;
		int32_t pauseMoveTime;
		AfterimageData* afterImage;
	};
	struct ProjectileArray
	{
		Array<Projectile>* projInfo;
		AnimArray* animInfo;
		Sprite* sffInfo;
	};
}