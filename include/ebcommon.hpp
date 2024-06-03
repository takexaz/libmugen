#pragma once
#include <_MUGEN_TYPES.hpp>

#include <zlib.hpp>


namespace mugen20414::ebcommon::debug {
	enum class ErrorCode {
		kLoadFonts = 1,
		kInitSound = 2,
		kInitGraphics = 3,
		kChangeVideoMode = 4,
	};
	static volatile const auto TempStore    = reinterpret_cast<ErrorCode*>(0x4b54ec);
	static volatile const auto ErrorMessage = reinterpret_cast<char*>(0x4b6c60);
	static volatile const auto DebugTmpStr  = reinterpret_cast<char*>(0x4b6d60);

	static const auto ErrorSet       = reinterpret_cast<void (*)(ErrorCode errCode)>(0x4181f0);
	static const auto ErrorGet       = reinterpret_cast<ErrorCode(*)(void)>(0x418200);
	static const auto ErrorGetStr    = reinterpret_cast<char* (*)(void)>(0x418210);
	static const auto DebugErrorExit = reinterpret_cast<void (*)(const char* errMsg)>(0x4187d0); // noreturn
}

#undef ZeroMemory
namespace mugen20414::ebcommon::memory {
	static volatile const auto ElecOutOfMem = reinterpret_cast<BOOL*>(0x4b5fb4);

	static const auto ecalloc    = reinterpret_cast<void* (*)(size_t count, size_t size)>(0x4181c0);
	static const auto efree      = reinterpret_cast<void (*)(void* ptr)>(0x418f40);
	static const auto ZeroMemory = reinterpret_cast<void (*)(void* ptr, size_t size)>(0x418f20);
}

namespace mugen20414::ebcommon::io {
	using namespace zlib::unzip;
	enum class Extension {
		kNone = 0,
		kPcx = 1,
		kSff = 2,
		kWav = 3,
		kSnd = 4,
		kMp3 = 5,
		kMid = 6,
		kModS3mXm = 7,
		kDa = 8,
		kZip = 9,
	};
	static const auto CheckExtension = reinterpret_cast<Extension(*)(const char* filename)>(0x418250);

	static const auto igetw         = reinterpret_cast<uint16_t(*)(FILE * fp)>(0x4183c0);
	static const auto igetl         = reinterpret_cast<uint32_t(*)(FILE * fp)>(0x418400);
	static const auto strimatch     = reinterpret_cast<BOOL(*)(const char* string1, const char* string2)>(0x418470);
	static const auto strimatchlen  = reinterpret_cast<BOOL(*)(const char* string1, const char* string2, int32_t length)>(0x4184c0);
	static const auto strmatchlen   = reinterpret_cast<BOOL(*)(const char* string1, const char* string2, int32_t length)>(0x418520);
	static const auto strtoupper    = reinterpret_cast<void (*)(char* dest, const char* src)>(0x418560);
	static const auto splitdirfile  = reinterpret_cast<void (*)(const char* path, char* dir, char* filename)>(0x418590);
	static const auto joindirfile   = reinterpret_cast<void (*)(const char* path, char* dir, char* filename)>(0x418620);
	static const auto isabsolutedir = reinterpret_cast<BOOL(*)(const char* path)>(0x4186e0);
	static const auto ffilelength   = reinterpret_cast<int32_t(*)(FILE * fp)>(0x418710);
	static const auto strcpyslash   = reinterpret_cast<void (*)(char* dest, const char* src)>(0x418750);
	static const auto getfileonly   = reinterpret_cast<char* (*)(const char* path)>(0x418f50);

	enum class MFOpenType {
		kOpenFile = 1,
		kOpenMemory = 2,
		kOpenZipFile = 3
	};
	struct MFile {
		MFOpenType mfOpenType;
		FILE* fp;
		unzFile zfp; // unz_s*
		void* memory;
		void* memEnd;
		void* memReadPos;
		BOOL hasMemory;
		BOOL isVAlloc;
		BOOL memEOF;
	};
	static const auto MFgetc      = reinterpret_cast<char (*)(MFile * mfp)>(0x418850);
	static const auto MFfgets     = reinterpret_cast<char* (*)(const char* str, int count, MFile * mfp)>(0x418890);
	static const auto MFfread     = reinterpret_cast<size_t(*)(void* buffer, size_t size, size_t count, MFile * mfp)>(0x418910);
	static const auto MFfeof      = reinterpret_cast<BOOL(*)(MFile * mfp)>(0x4189b0);
	static const auto MFfopenFile = reinterpret_cast<MFile * (*)(const char* filename, const char* mode)>(0x4189e0);
	static const auto MFfopenMem  = reinterpret_cast<void (*)(void* memory, size_t size)>(0x418a30);
	static const auto MFzopen     = reinterpret_cast<undefined4(*)(MFile * mfp, const char* filename)>(0x418a70);
	static const auto MFzclose    = reinterpret_cast<void (*)(MFile * mfp)>(0x418b70);
	static const auto MFfopenZip  = reinterpret_cast<MFile * (*)(const char* filename, const char* mode)>(0x418b90);
	static const auto MFfclose    = reinterpret_cast<uint32_t(*)(MFile * mfp)>(0x418bf0);
	static const auto MFfseek     = reinterpret_cast<int (*)(MFile * mfp, long offset, uint32_t origin)>(0x418cb0);
	static const auto MFftell     = reinterpret_cast<int (*)(MFile * mfp)>(0x418d20);
	static const auto MFigetw     = reinterpret_cast<uint16_t(*)(MFile * mfp)>(0x418d50);
	static const auto MFigetl     = reinterpret_cast<uint32_t(*)(MFile * mfp)>(0x418de0);
}

namespace mugen20414::ebcommon::math {
	static const auto IntSwap    = reinterpret_cast<void (*)(int32_t * x, int32_t * y)>(0x418790);
	static const auto IntMin     = reinterpret_cast<int32_t(*)(int32_t x, int32_t y)>(0x4187b0);
	static const auto IntMax     = reinterpret_cast<int32_t(*)(int32_t x, int32_t y)>(0x4187c0);
	static const auto roundfloat = reinterpret_cast<int32_t(*)(float f)>(0x418f00);
}