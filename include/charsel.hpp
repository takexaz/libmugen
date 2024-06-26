#pragma once
#include <_MUGEN_TYPES.hpp>

#include <player.hpp>
#include <sprite.hpp>
#include <explod.hpp>

namespace mugen20414::charsel {
	using namespace mugen20414::player;
	using namespace mugen20414::sprite;
	using namespace mugen20414::explod;

	enum class SelectMode {
		kVersus = 0,
		kSurvival = 1,
		kWatch = 2,
		kTraining = 3,
	};
	enum class TeamMode {
		kSingle = 0,
		kSimul = 1,
		kTurns = 2,
	};
	

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
		int32_t includeStage; // =0なら0，=1なら3が入った
		SpriteArrayEx* portrait;
		int32_t enableColor; // bitフラグ
		int32_t palDefaults[4];
		int32_t order;
		char introStoryboard[512];
		char endingStoryboard[512];
		int32_t unselectedColor; // bitフラグ
	};

	// todo
	// 0x78 + numCharRegistable*4
	struct ArcadeList {
		int32_t charInfoIndex[];
	};

	struct SelectScreenMatrix
	{
		int32_t index; /* -1: Blank, -2: RandomSelect */
		char name[48];
		char defFilename[512];
		char defDirname[512];
		SpriteArrayEx* portraitsSprites;
	};

	struct CharselConfig {
		char motifFileSelect[512]; //
		struct MotifSelectInfo {
			int32_t fadeinTime;
			int32_t fadeoutTime;
			int32_t posX;
			int32_t posY;
			int32_t rows;
			int32_t columns;
			struct Cell {
				int32_t spacing;
				int32_t sizeX;
				int32_t sizeY;
			} cell;
			BOOL showEmptyBoxes;
			BOOL moveOverEmptyBoxes;
			BOOL wrapping;
			struct Portrait {
				float scaleX;
				float scaleY;
				int32_t offsetX;
				int32_t offsetY;
			} portrait;
			int32_t p1CursorStartCellX;
			int32_t p1CursorStartCellY;
			int32_t p2CursorStartCellX;
			int32_t p2CursorStartCellY;

			int32_t	p1SelectPosXChar[4]; // パラメータではなくデータ
			int32_t	p2SelectPosXChar[4];
			int32_t	p1SelectPosYChar[4];
			int32_t	p2SelectPosYChar[4];

			BOOL p2CursorBlink;
			int32_t p1CursorMoveSndGroupNo;
			int32_t p2CursorMoveSndGroupNo;
			int32_t p1CursorMoveSndItemNo;
			int32_t p2CursorMoveSndItemNo;
			int32_t p1CursorDoneSndGroupNo;
			int32_t p2CursorDoneSndGroupNo;
			int32_t p1CursorDoneSndItemNo;
			int32_t p2CursorDoneSndItemNo;
			int32_t p1RandomMoveSndGroupNo;
			int32_t p2RandomMoveSndGroupNo;
			int32_t p1RandomMoveSndItemNo;
			int32_t p2RandomMoveSndItemNo;
			BOOL randomMoveSndCancel;
			SoundParam stageMoveSnd;
			SoundParam stageDoneSnd;
			SoundParam cancelSnd;
			int32_t titleOffsetX;
			int32_t titleOffsetY;
			FontParam titleFont;
			ExplodStub cellBg;
			ExplodStub cellRandom; // 0x10CC
			int32_t cellRandomSwitchTime;
			ExplodStub p1CursorActive;
			ExplodStub p2CursorActive;
			ExplodStub p1CursorDone;
			ExplodStub p2CursorDone;
			struct Stage {
				int32_t posX;
				int32_t posY;
				int32_t activeFontFontNo;
				int32_t active2FontFontNo;
				int32_t doneFontFontNo;
				int32_t activeFontFontBank;
				int32_t active2FontFontBank;
				int32_t doneFontFontBank;
				int32_t activeFontAlignMt;
			} stage;
			struct Face {
				int32_t offsetX;
				int32_t offsetY;
				int32_t jacing;
				float scaleX;
				float scaleY;
			} p1Face;
			struct Name {
				FontParam font;
				int32_t offsetX;
				int32_t offsetY;
			} p1Name;
			Face p2Face;
			Name p2Name;
			BOOL teamMenuMoveWrapping;
			struct TeamMenu {
				int32_t posX;
				int32_t posY;
				ExplodStub bg;
				ExplodStub selfTitle;
				ExplodStub enemyTitle;
				SoundParam moveSnd;
				SoundParam valueSnd;
				SoundParam doneSnd;
				int32_t itemOffsetX;
				int32_t itemOffsetY;
				int32_t itemFonrFontNo;
				int32_t itemActiveFontFontNo;
				int32_t itemActive2FontFontNo;
				int32_t itemFontColorsNo;
				int32_t itemActiveFontColorsNo;
				int32_t itemActive2FontColors;
				int32_t itemFontAlignment;
				int32_t itemSpacingX;
				int32_t itemSpacingY;
				ExplodStub itemCursor;
				ExplodStub valueIcon;
				int32_t valueSpacingX;
				int32_t valueSpacingY;
				ExplodStub valueEmptyIcon;
				TeamMode teamMode;
				int32_t turnsNumChar;
			} p1TeamMenu;
			TeamMenu p2TeamMenu; // 0x18B8
		} motifSelectInfo;
		SelectScreenMatrix* matrix; // g+0x192C|slct+0xbc0(rows*column)
	};

	struct ExtraStage {
		char path[512];
		char name[80];
		uint32_t includeStage; //　CharInfoのincludeStageが3なら含める
	};

	static volatile const auto cellRows = reinterpret_cast<int32_t**>(0x4b54c0);
	static volatile const auto cellCols = reinterpret_cast<int32_t*>(0x4b54c4);
	static volatile const auto cellHead = reinterpret_cast<SelectScreenMatrix**>(0x4b54c8);
	static volatile const auto slct = reinterpret_cast<CharselConfig**>(0x4b54cc);
}