#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <pallete.hpp>

namespace mugen20414::sprite {
	using namespace mugen20414::array;
	using namespace mugen20414::pallete;


	struct Sprite
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

	using SpriteArray = Array<Sprite>;

	struct SpriteArrayEx
	{
		SpriteArray* spriteArray;
		void* _unknown_1;
		EBPalArray* palleteArray;
		void* _unknown_2;
		int32_t refCnt;
		int32_t _unknown_3;
		int32_t _unknown_4;
	};
}