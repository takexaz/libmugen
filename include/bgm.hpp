#pragma once
#include <_MUGEN_TYPES.hpp>

#include <allegro.hpp>
#include <txtparse.hpp>
#include <ebcommon.hpp>

namespace mugen20414::bgm {
	using namespace allegro;
	using namespace mugen20414::txtparse;
	using namespace mugen20414::ebcommon::io;

	enum class BGMFileFormat
	{
		kNone = 0,
		kMid = 1,
		kModS3mXm = 2,
		kMp3 = 3,
		kCda = 4,
	};

	// todo
	struct BGM
	{
		BGMFileFormat format;
		MIDI* midiData;
		JGMOD* modData;
		uint32_t cdTrackNo;
		BOOL field4_0x10;
		BOOL field5_0x14;
		int32_t volume;
		BOOL field7_0x1c;
		undefined4 field8_0x20;
		BOOL field9_0x24;
		char path[512];
	};

	static const auto BGMParse             = reinterpret_cast<BOOL(*)(TPFile * tpf, char* buffer, char* valueName)>(0x40c1c0);
	static const auto BGMStart             = reinterpret_cast<void (*)(BGM * bgm)>(0x40c230);
	static const auto BGMPause             = reinterpret_cast<void (*)(BGM * bgm)>(0x40c320);
	static const auto BGMGetPause          = reinterpret_cast<BOOL(*)(BGM * bgm)>(0x40c3b0);
	static const auto BGMResume            = reinterpret_cast<void (*)(BGM * bgm)>(0x40c3d0);
	static const auto BGMGetVolume         = reinterpret_cast<int32_t(*)(BGM * bgm)>(0x40c470);
	static const auto BGMSetVolume         = reinterpret_cast<void (*)(BGM * bgm, int32_t volume)>(0x40c4c0);
	static const auto BGMPoll              = reinterpret_cast<int32_t(*)(BGM * bgm)>(0x40c520);
	static const auto BGMPollIgnoreDefocus = reinterpret_cast<int32_t(*)(BGM * bgm)>(0x40c6b0);
	static const auto BGMCheckExtension    = reinterpret_cast<Extension(*)(char* path)>(0x40c730);
	static const auto BGMLoad              = reinterpret_cast<BOOL(*)(BGM * bgm, char* path, BOOL param_3)>(0x40c760);
	static const auto BGMLoadAndStart      = reinterpret_cast<BOOL(*)(BGM * bgm, char* path, int param_3, int32_t volume)>(0x40ca10);
	static const auto BGMFree              = reinterpret_cast<void (*)(BGM * bgm)>(0x40cb50);
	static const auto BGMPlayForScene      = reinterpret_cast<void (*)(char* path, int param_2)>(0x40cbe0);
	static const auto BGMStopForScene      = reinterpret_cast<undefined(*)(void)>(0x40cd10);
}