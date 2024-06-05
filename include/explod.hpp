#pragma once
#include <_MUGEN_TYPES.hpp>

#include <Font.hpp>
#include <Sprite.hpp>

namespace mugen20414::explod {
	using namespace mugen20414::font;
	using namespace mugen20414::sprite;

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
}