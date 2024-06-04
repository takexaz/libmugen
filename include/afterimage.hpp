#pragma once
#include <_MUGEN_TYPES.hpp>

#include <pallete.hpp>
#include <controller.hpp>
#include <anim.hpp>

namespace mugen20414::afterimage {
	using namespace mugen20414::pallete;
	using namespace mugen20414::state::controller;
	using namespace mugen20414::anim;

	struct AfterimageItem {
		int32_t currentSpriteIndex;
		float posX;
		float posY;
		float scaleX;
		float scaleY;
		int32_t flip;
		int32_t sprPriority;
		undefined4 _unknown_8; // HFlipToSgn‚Ì•Ô‚è’l
		EBPal ebPal;
	};
	struct AfterimageData
	{
		AfterimageItem* items;
		int32_t length_maximum;
		AnimUsed* anim;
		int32_t _unknown_2;
		int32_t _unknown_3;
		int32_t elapsedTime;
		uint32_t enable;
		AfterimageParams params;
	};

	static const auto AftImgNew    = reinterpret_cast<AfterimageData* (*)(uint32_t length)>(0x401000);
	static const auto AftImgInit   = reinterpret_cast<void (*)(AfterimageData* afterImage, uint32_t length)>(0x4010e0);
	static const auto AftImgFree   = reinterpret_cast<void (*)(AfterimageData* afterImage)>(0x401160);
	static const auto AftImgDeInit = reinterpret_cast<void (*)(AfterimageData * afterImage)>(0x4011c0);
	static const auto AftImgSetup  = reinterpret_cast<void (*)(AfterimageData* afterImage, AfterimageParams* params, AnimUsed* anim)>(0x401220);
	static const auto AftImgUpdate = reinterpret_cast<void (*)(AfterimageData* afterImage, float posX, float posY, float scaleX, float scaleY, float angle, uint32_t isFlip, uint32_t isNotHitpaused)>(0x401250);
	static const auto AftImgDraw   = reinterpret_cast<void (*)(AfterimageData* afterImage, float posX, float posY, int32_t priority)>(0x4013b0);
}