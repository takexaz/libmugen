#pragma once
#include <_MUGEN_TYPES.hpp>

#include <ebcommon.hpp>

namespace mugen20414::txtparse {
	using namespace mugen20414::ebcommon::io;

	struct TPFileWriter {
		int32_t* availableLineIndexes;
		char** lines;
		int32_t numLine;
		int32_t maxLine;
	};

	struct TPFile {
		int32_t* numClone;
		char* documents;
		int32_t docLength;
		int32_t docCurrentIndex;
		int32_t docCurrentOffset;
		int32_t currentLine;
		int32_t currentGroup;
		BOOL isGroupCurrentLine;
		char** lines;
		int32_t numLine;
		int32_t* groupIndexes;
		int32_t numGroup;
		TPFileWriter* writer;
	};

	static const auto TPFree             = reinterpret_cast<void (*)(TPFile * tpf)>(0x482c00);
	static const auto TPReadMFPtr        = reinterpret_cast<TPFile * (*)(MFile * mfp, BOOL isWrite)>(0x482cd0);
	static const auto TPReadMF           = reinterpret_cast<TPFile * (*)(MFile * mfp, BOOL isWrite)>(0x483150);
	static const auto TPReadFile         = reinterpret_cast<TPFile * (*)(const char* path)>(0x483190);
	static const auto TPClone            = reinterpret_cast<TPFile * (*)(TPFile * tpf)>(0x4831d0);
	static const auto TPReadFileForWrite = reinterpret_cast<TPFile * (*)(const char* path)>(0x483200);
	static const auto TPReadFilePtr      = reinterpret_cast<TPFile * (*)(FILE * fp, BOOL isWrite)>(0x483240);
	static const auto TPWriteFile        = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* path)>(0x4836c0);
	static const auto TPGroupSeek        = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* groupName)>(0x483730);
	static const auto TPGroupSeekIdx     = reinterpret_cast<int32_t(*)(TPFile * tpf, int32_t index)>(0x483840);
	static const auto TPGroupReset       = reinterpret_cast<void (*)(TPFile * tpf)>(0x4838a0);
	static const auto TPGroupScanFirst   = reinterpret_cast<void (*)(TPFile * tpf)>(0x4838f0);
	static const auto TPGroupScanNext    = reinterpret_cast<char* (*)(TPFile * tpf)>(0x483910);
	static const auto TPGroupMatchCount  = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* groupName)>(0x483980);
	static const auto TPGetLineNo        = reinterpret_cast<uint32_t(*)(TPFile * tpf, const char* pattern)>(0x4839e0);
	static const auto TPGetLineNo_Skip   = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* pattern, int32_t numSkip)>(0x483a90);
	static const auto TPGetValue         = reinterpret_cast<char* (*)(TPFile * tpf, const char* valueName)>(0x483b30);
	static const auto TPSeekValue        = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* valueName)>(0x483c20);
	static const auto TPSeekEog          = reinterpret_cast<void (*)(TPFile * tpf)>(0x483ca0);
	static const auto TPGetValueNewStr   = reinterpret_cast<char* (*)(TPFile * tpf, const char* valueName)>(0x483cf0);
	static const auto TPGetValueNext     = reinterpret_cast<char* (*)(TPFile * tpf, const char* valueName)>(0x483d50);
	static const auto TPGetValueFloat    = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* valueName, float* f)>(0x483e50);
	static const auto TPGetValueInt      = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* valueName, int32_t * i)>(0x483e80);
	static const auto TPScanf            = reinterpret_cast<void (*)(TPFile * tpf, const char* valueName, const char* format, ...)>(0x483eb0);
	static const auto TPAccessReset      = reinterpret_cast<void (*)(TPFile * tpf)>(0x483ee0);
	static const auto TPAccessFirstLine  = reinterpret_cast<char* (*)(TPFile * tpf)>(0x483f10);
	static const auto TPReaccessCurLine  = reinterpret_cast<int32_t(*)(TPFile * tpf)>(0x483f70);
	static const auto TPAccessNextLine   = reinterpret_cast<char* (*)(TPFile * tpf)>(0x483f90);
	static const auto TPAccessPrevLine   = reinterpret_cast<char* (*)(TPFile * tpf)>(0x483fd0);
	static const auto TPGetLine          = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* pattern)>(0x484000);
	static const auto TPGetGroupText     = reinterpret_cast<int32_t(*)(TPFile * tpf, char* buffer, size_t bufferSize)>(0x484070);
	static const auto TPWLineNo          = reinterpret_cast<int32_t(*)(TPFile * tpf, int32_t lineNo)>(0x4841e0);
	static const auto TPGroupRename      = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* groupName)>(0x484240);
	static const auto TPPrintf           = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* valueName, const char* format, ...)>(0x4843a0);
	static const auto TPPrintf_Skip      = reinterpret_cast<int32_t(*)(TPFile * tpf, const char* valueName, int32_t numSkip, const char* format, ...)>(0x484600);
	static const auto TPInsertLine       = reinterpret_cast<BOOL(*)(TPFile * tpf, const char* str)>(0x484860);
	static const auto TPDeleteLine       = reinterpret_cast<BOOL(*)(TPFile * tpf)>(0x4849c0);
	static const auto TPDeleteAllLines   = reinterpret_cast<void (*)(TPFile * tpf)>(0x484a90);

	static const auto strgetto = reinterpret_cast<void (*)(const char* dest, const char* src, int length, char sentinel)>(0x484b00);
	static const auto vsscanf  = reinterpret_cast<int32_t(*)(const char* buffer, const char* format, va_list arg_ptr)>(0x484b50);
}