#pragma once
#include <_MUGEN_TYPES.hpp>

#include <date.hpp>
#include <sound.hpp>
#include <font.hpp>
#include <ebcommon.hpp>
#include <bgm.hpp>

namespace mugen20414::game {
	using namespace mugen20414::date;
	using namespace mugen20414::sound;
	using namespace mugen20414::font;
	using namespace mugen20414::ebcommon::io;
	using namespace mugen20414::bgm;

	// 0xc948(51528)
	struct GameVar {
		char currentDir[512];
		char currentDirPath[512];
		undefined4 _unknown_1;
		BOOL isExistTMPFile;
		MDY versionDate;
		char extraStageDefPath[512];
		char pathInCharParam[512];

		struct TitleInfo {
			int32_t fadeinTime;
			int32_t fadeoutTime;
			SoundItem cursorMoveSnd;
			SoundItem cursorDoneSnd;
			SoundItem cancelSnd;
			struct Menu {
				int32_t menuPosX;
				int32_t menuPosY;
				struct Item {
					FontItem font;
					FontItem activeFont;
					int32_t spacingWidth;
					int32_t spacingHeight;
				} item;
				struct ItemName
				{
					char arcade[32];
					char versus[32];
					char teamArcade[32];
					char teamVersus[32];
					char teamCoop[32];
					char survival[32];
					char survivalCoop[32];
					char training[32];
					char watch[32];
					char options[32];
					char exit[32];
				} itemName;
				int32_t windowMarginsYTop;
				int32_t windowMarginsYBottom;
				int32_t windowVisibleItems;
				struct BoxCursor {
					BOOL visible;
					int32_t coordsX1;
					int32_t coordsY1;
					int32_t coordsX2;
					int32_t coordsY2;
				} boxCursor;
			} menu;
		} titleInfo;

		undefined4 field_0x09dc;
		undefined4 field_0x09e0;

		struct OptionInfo {
			SoundItem cursorMoveSnd;
			SoundItem cursorDoneSnd;
			SoundItem cancelSnd;
		} optionInfo;

		struct Stage {
			BOOL resetBG;
			struct Camera {
				int32_t startX;
				int32_t startY;
				int32_t boundLeft;
				int32_t boundRight;
				int32_t boundHigh;
				int32_t boundLow;
				float verticalFollow;
				int32_t tension;
				int32_t floorTension;
			} camera;
			struct PlayerInfo {
				int32_t p1StartX;
				int32_t p2StartX;
				int32_t p3StartX;
				int32_t p4StartX;
				int32_t p1StartY;
				int32_t p2StartY;
				int32_t p3StartY;
				int32_t p4StartY;
				int32_t p1StartZ;
				int32_t p2StartZ;
				int32_t p3StartZ;
				int32_t p4StartZ;
				int32_t p1Facing;
				int32_t p2Facing;
				int32_t p3Facing;
				int32_t p4Facing;
				int32_t leftBound;
				int32_t rightBound;
				int32_t topBound;
				int32_t botBound;
			} playerInfo;
			BOOL autoTurn;
			struct Scaling {
				int32_t topZ;
				int32_t botZ;
				float topScale;
				float botScale;
			} scaling;
			struct Bound {
				int32_t screenLeft;
				int32_t screenRight;
			} bound;
			struct Shadow {
				int32_t intensity;
				uint32_t color;
				float yScale;
				int32_t fadeRangeHigh;
				int32_t fadeRangeMiddle;
			} shadow;
			struct Reflection {
				int32_t intensity;
			} reflection;
			BGM music;
		} stage;

		undefined4 field_0x0ccc;
	};
}