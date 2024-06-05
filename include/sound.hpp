#pragma once
#include <_MUGEN_TYPES.hpp>

#include <allegro.hpp>
#include <array.hpp>

namespace mugen20414::sound {
	using namespace allegro;
	using namespace array;


	struct SoundItem
	{
		int32_t groupNo;
		int32_t itemNo;
	};
	struct Sound
	{
		SAMPLE* sound;
	};

	using SoundArray = Array<Sound>;

	struct SoundArrayEx {
		SoundArray* soundArrayEx;
	};
}