#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::clipboard {
	struct Clipboard
	{
		char** messages; /* Ring buffer */
		char* _unknown;
		int32_t charsPerLine;
		int32_t lines;
		int32_t firstMessageIndex;
		int32_t lastMessageIndex;
	};
}