#pragma once
#include <_MUGEN_TYPES.hpp>

#include <player.hpp>

namespace mugen20414::charsel {
	using namespace mugen20414::player;

	// 0xe30
	struct CharInfo {
		int32_t useCount;
		int32_t cachePriority;
		PlayerCache* cache;
		char _unknown_1[512];
		char defFilename[512];
		char defDir[512];
		char stagePath[512];
		char bgmPath[512];
		int32_t _unknown_2; // order関係？
		void* portrait; // bitフラグ
		int32_t enableColor; // bitフラグ
		int32_t palDefaults[4];
		int32_t order;
		char introStoryboard[512];
		char endingStoryboard[512];
		int32_t unselectedColor; // bitフラグ
	};
}