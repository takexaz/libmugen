#pragma once
#include <_MUGEN_TYPES.hpp>
#include <sprite.hpp>

namespace mugen20414::vbuf {
	using namespace mugen20414::sprite;
	static volatile const auto V_Current = reinterpret_cast<SpriteArrayEx**>(0x4b6038);
	static volatile const auto V_CurrentIdx = reinterpret_cast<int32_t*>(0x4b603c);
}