#pragma once
#include <_MUGEN_TYPES.hpp>

#include <pallete.hpp>
#include <controller.hpp>
#include <anim.hpp>

namespace mugen20414::afterimage {
	using namespace mugen20414::pallete;
	using namespace mugen20414::anim;
	using namespace mugen20414::state::controller;

	struct AfterImageItem {
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
	struct AfterImage
	{
		AfterImageItem* items;
		int32_t maxLength;
		Anim* anim;
		int32_t _unknown_2;
		int32_t _unknown_3;
		int32_t elapsedTime;
		uint32_t enable;
		AfterImageParams params;
	};

	using AfterImageArray = mugen20414::array::Array<AfterImage>;

	static const auto AftImgNew    = reinterpret_cast<AfterImage * (*)(uint32_t length)>(0x401000);
	static const auto AftImgInit   = reinterpret_cast<void (*)(AfterImage * afterImage, uint32_t length)>(0x4010e0);
	static const auto AftImgFree   = reinterpret_cast<void (*)(AfterImage * afterImage)>(0x401160);
	static const auto AftImgDeInit = reinterpret_cast<void (*)(AfterImage * afterImage)>(0x4011c0);
	static const auto AftImgSetup  = reinterpret_cast<void (*)(AfterImage * afterImage, AfterImageParams* params, Anim* anim)>(0x401220);
	static const auto AftImgUpdate = reinterpret_cast<void (*)(AfterImage * afterImage, float posX, float posY, float scaleX, float scaleY, float angle, uint32_t isFlip, uint32_t isNotHitpaused)>(0x401250);
	static const auto AftImgDraw   = reinterpret_cast<void (*)(AfterImage * afterImage, float posX, float posY, int32_t priority)>(0x4013b0);
}