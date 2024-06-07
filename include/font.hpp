#pragma once
#include <_MUGEN_TYPES.hpp>
#include <sprite.hpp>

namespace mugen20414::font {
	using namespace mugen20414::sprite;

	enum class FontType {
		kFixed = 0,
		kVariable = 1,
	};

	struct FontParam
	{
		int32_t fontNo;
		int32_t fontBank;
		int32_t alignMt;
	};

	struct Font {
		int32_t offsetX;
		int32_t offsetY;
		int32_t sizeX;
		int32_t sizeY;
		FontType type;
		int32_t spacingX;
		int32_t spacingY;
		int32_t startX[255];
		int32_t widthOfChar[255];
		SpriteArrayEx* spriteArray;
	};
}