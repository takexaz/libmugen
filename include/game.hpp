#pragma once
#include <_MUGEN_TYPES.hpp>

#include <date.hpp>
#include <sound.hpp>
#include <font.hpp>
#include <ebcommon.hpp>
#include <bgm.hpp>
#include <charsel.hpp>
#include <main.hpp>
#include <sprite.hpp>

namespace mugen20414::game {
	using namespace mugen20414::date;
	using namespace mugen20414::sound;
	using namespace mugen20414::font;
	using namespace mugen20414::ebcommon::io;
	using namespace mugen20414::bgm;
	using namespace mugen20414::charsel;
	using namespace mugen20414::main;
	using namespace mugen20414::sprite;

	// 0xc948(51528)
	struct GameVar {
		char currentDir[512];
		char currentDirPath[512];
		undefined4 _unknown_1;
		BOOL fileOverWritable;
		MDY versionDate;
		char extraStageDefPath[512];
		char pathInCharParam[512];

		struct MotifTitleInfo {
			int32_t fadeinTime;
			int32_t fadeoutTime;
			SoundParam cursorMoveSnd;
			SoundParam cursorDoneSnd;
			SoundParam cancelSnd;
			struct Menu {
				int32_t menuPosX;
				int32_t menuPosY;
				struct Item {
					FontParam font;
					FontParam activeFont;
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
		} motifTitleInfo;

		struct MotifOptionInfo {
			undefined4 field_0x09dc;
			undefined4 field_0x09e0;
			SoundParam cursorMoveSnd;
			SoundParam cursorDoneSnd;
			SoundParam cancelSnd;
		} motifOptionInfo;

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

		CharInfo* charInfo; // 0xcd0
		int32_t numChars;
		int32_t numCharCached;
		int32_t numCharRegistable;

		ArcadeList* arcadeList;

		undefined4 field_0x0ce4;
		undefined4 field_0x0ce8;
		undefined4 field_0x0cec;
		struct SelectOption {
			int32_t arcadeMaxMatches[10];
			int32_t teamMaxMatches[10];
		} selectOption;

		BOOL precache;
		HANDLE mutexHandle;
		BOOL isWorkingPrecacheThread;
		BOOL donePrecahce;
		BOOL field_0x0d50;
		BOOL field_0x0d54;
		int32_t cacheQueue[5];

		CharselConfig slct;

		char motifFilesLogoStoryBoard[512];
		char motifFilesIntroStoryBoard[512];

		undefined4 field_0x1d30;

		struct MotifEndCredits {
			uint32_t enabled;
			char storyBoard[512];
		} motifEndCredits;
		struct MotifDefaultEnding {
			uint32_t enabled;
			char storyBoard[512];
		} motifDefaultCredits;
		struct MotifWinScreen {
			uint32_t enabled;
			SysExplod winText;
			int32_t pose_time;
			int32_t fadeIn_time;
			int32_t fadeOut_time;
		} motifWinScreen;
		struct MotifSurvivalResultsScreen {
			uint32_t enabled;
			SysExplod winsText;
			int32_t show_time;
			int32_t fadeIn_time;
			int32_t fadeOut_time;
			int32_t roundsToWin;
		} motifSurvivalResultsScreen;
		struct MotifContinueScreen {
			uint32_t enabled;
			char storyBoard[512];
		} motifContinueScreen;
		struct MotifGameOverScreen {
			uint32_t enabled;
			char storyBoard[512];
		} motifGameOverScreen;
		struct MotifVSScreen {
			int32_t time;
			int32_t fadeInTime;
			int32_t fadeOutTime;
			int32_t p1PosX;
			int32_t p1PosY;
			FontParam p1NameFont;
			int32_t p1NamePosX;
			int32_t p1NamePosY;
			int32_t p1Facing;
			float p1ScaleX;
			float p1ScaleY;
			int32_t p2PosX;
			int32_t p2PosY;
			FontParam p2NameFont;
			int32_t p2NamePosX;
			int32_t p2NamePosY;
			int32_t p2Facing;
			float p2ScaleX;
			float p2ScaleY;
		} motifVSScreen;

		ExtraStage* selectExtraStage; // 0x269C
		int32_t numExtraStage;

		SelectMode selectMode; // 0x26A4

		int32_t field_0x26a8; // ContinueScreen, Demo関係？
		int32_t field_0x26ac;

		undefined4 field_0x26b0;
		undefined4 field_0x26b4;

		int32_t menuTeamSelectPlayer;
		int32_t menuSurvivalSelectPlayer;

		GameMode gameMode;
		BOOL isMenuSelectByP2;

		ScreenMode screenMode; // 0x26c4

		// todo
		struct Turns {
			int32_t numDefeated; // 何体撃破されたか
			int32_t numIcons;
			int32_t numTurns;
			struct CharSet {
				BOOL isSimul;
				undefined4 _unknown_1;
				int32_t simulEntries;       /* simul->2, otherwise->1 */
				struct CharData {
					uint32_t slotID;
					uint32_t charIndex;
					uint32_t palNo;
					BOOL aiFlag;
					BOOL isControlByP2;
				} firstPlayer;
				CharData secondPlayer;
				CharData thirdPlayer;
				CharData fourthPlayer;
			} charSet[4]; // Turnsのキャラ数分
			struct PersistIndex {
				int32_t var[60];
				float fvar[40];
			} persistIndex[4][4]; // Player数*キャラ数
			int32_t minLifeBack; // (100-(試合経過時間/TicksPerSecond)*0.01 = BaseLifeBack
			float timeBonusLifeBackBase; // BaseLifeBack*timeBonusLifeBackBase = TimeBonusLifeBack
			float raitoBasedLifeBackMul; // ((enemyLifeRaito*raitoBasedLifeBackMul)+(1.0-raitoBasedLifeBackMul)) = EnemyRaitBasedLifeBackMul
			// TimeBonusLifeBack*EnemyRaitBasedLifeBackMul = LifeBack
			BOOL undefined_4; 
			float maxLifeMul;
			int32_t teamMatchWins; // 勝利に必要な勝利数(Match.Winsとは別)
			int32_t teamMaxDrawGame;
			float enemyLifeRaito;
		} p1Turns;
		Turns p2Turns;

		Turns::CharSet p1CurrentTurn;
		Turns::CharSet p2CurrentTurn;

		// todo
		BOOL isEscToSelectScreen; // 一部のモードでセレクト画面に戻るかMenuに戻るかに関係
		BOOL escFlag; // 不明 Ecsフラグ？

		SpriteArrayEx* screenBuffer1;
		SpriteArrayEx* pauseBuffer;
		SpriteArrayEx* screenBuffer2;
		SpriteArrayEx* currentScreenBuffer;
	};


	static volatile const auto g = reinterpret_cast<GameVar**>(0x4b5b4c);
}