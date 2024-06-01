#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::ebcommon::io {
	struct MFile {
		BOOL field0_0x0;
		FILE* fp;
		undefined4 field2_0x8;
		void* field3_0xc;
		undefined4 field4_0x10;
		undefined4 field5_0x14;
		undefined4 field6_0x18;
		undefined4 field7_0x1c;
		BOOL field8_0x20;
	};
}

namespace mugen20414::ebcommon::string {

}

namespace mugen20414::ebcommon::math {

}

namespace mugen20414::ebcommon::debug {
	enum class ErrorCode {
		kLoadFonts = 1,
		kInitSound = 2,
		kInitGraphics = 3,
		kChangeVideoMode = 4,
	};
	static volatile const auto TempStore = reinterpret_cast<ErrorCode*>(0x4b54ec);
	static volatile const auto ErrorMessage = reinterpret_cast<char*>(0x4b6c60);
	static volatile const auto DebugTmpStr = reinterpret_cast<char*>(0x4b6d60);

	static const auto ErrorSet = reinterpret_cast<void (*)(ErrorCode errCode)>(0x4181f0);
	static const auto ErrorGet = reinterpret_cast<ErrorCode(*)(void)>(0x418200);
	static const auto ErrorGetStr = reinterpret_cast<char*(*)(void)>(0x418210);
	static const auto DebugErrorExit = reinterpret_cast<void (*)(const char* errMsg)>(0x4187d0); // noreturn
}

#undef ZeroMemory;
namespace mugen20414::ebcommon::memory {
	static volatile const auto ElecOutOfMem = reinterpret_cast<BOOL*>(0x4b5fb4);

	static const auto ecalloc = reinterpret_cast<void*(*)(size_t count, size_t size)>(0x4181c0);
	static const auto efree = reinterpret_cast<void (*)(void* ptr)>(0x418f40);
	static const auto ZeroMemory = reinterpret_cast<void (*)(void* ptr, size_t size)>(0x418f20);
	
}
