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
#include <anim.hpp>
#include <afterimage.hpp>
#include <explod.hpp>
#include <bg.hpp>
#include <controller.hpp>
#include <system.hpp>
#include <kbi.hpp>
#include <joystick.hpp>
#include <player.hpp>
#include <clipboard.hpp>

namespace mugen20414::game {
	using namespace mugen20414::date;
	using namespace mugen20414::sound;
	using namespace mugen20414::font;
	using namespace mugen20414::ebcommon::io;
	using namespace mugen20414::bgm;
	using namespace mugen20414::charsel;
	using namespace mugen20414::main;
	using namespace mugen20414::sprite;
	using namespace mugen20414::anim;
	using namespace mugen20414::afterimage;
	using namespace mugen20414::explod;
	using namespace mugen20414::bg;
	using namespace mugen20414::state::controller;
	using namespace mugen20414::system;
	using namespace mugen20414::kbi;
	using namespace mugen20414::joystick;
	using namespace mugen20414::player;
	using namespace mugen20414::clipboard;


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
			ExplodStub winText;
			int32_t pose_time;
			int32_t fadeIn_time;
			int32_t fadeOut_time;
		} motifWinScreen;
		struct MotifSurvivalResultsScreen {
			uint32_t enabled;
			ExplodStub winsText;
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

		Font* systemFont_01;
		Font* systemFont_02;

		AnimRCArrayEx* persistentAnimArray;
		SpriteArrayEx* prioritySpritesLayer1;

		PalGroupArray* palGroupArray;
		AfterimageArray* afterimageArray;

		int32_t stageInfoZOffset;
		int32_t currentZOffset;
		int32_t stageInfoZOffSetLink;

		BOOL vRet;

		BOOL envColorUnder;
		uint32_t envColorValue;
		int32_t envColorTime;

		struct Fight {
			struct Files {
				SpriteArrayEx* fightFxSff;
				AnimRCArrayEx* fightFxAir;
				SpriteArrayEx* fightSff;
				AnimRCArrayEx* fightAir;
				Font* font[10];
				SoundArrayEx* snd;
				SoundArrayEx* commonSnd;
			} files;

			struct FightData {
				int32_t posX;
				int32_t posY;
				int32_t rangeX;
				int32_t rangeY;
				undefined4 unknown_1;
				ExplodStub bg0;
				ExplodStub bg1;
				ExplodStub bg2;
				ExplodStub mid;
				ExplodStub front;
			} lifebar[2];
			FightData simulLifebar[4];
			FightData turnsLifebar[4];

			FightData powerbar[2];
			ExplodStub p1CounterText;
			ExplodStub p2CounterText;
			int32_t powerbarLevelSndGroupNo[10];
			int32_t powerbarLevelSndItemNo[10];
			
			struct FaceData {
				ExplodStub p1Bg;
				ExplodStub p1Face;
				ExplodStub p2Bg;
				ExplodStub p2Face;
				ExplodStub p3Bg;
				ExplodStub p3Face;
				ExplodStub p4Bg;
				ExplodStub p4Face;
				int32_t p1PosX;
				int32_t p2PosX;
				int32_t p3PosX;
				int32_t p4PosX;
				int32_t p1PosY;
				int32_t p2PosY;
				int32_t p3PosY;
				int32_t p4PosY;
				int32_t p1FaceFacing;
				int32_t p2FaceFacing;
				int32_t p3FaceFacing;
				int32_t p4FaceFacing;
			} face;
			FaceData simulFace;
			struct TurnsFaceData {
				FaceData face;
				struct TeamMate {
					ExplodStub teamMateBg;
					ExplodStub teamMateFace;
					ExplodStub teamMateKo;
					int32_t teamMatePosX;
					int32_t teamMatePosY;
					undefined4 unknown_1;
					int32_t teamMateSpacingX;
					int32_t teamMateSpacingY;
				} p1;
				TeamMate p2;
			} turnsFace;

			struct NameData {
				ExplodStub p1Bg;
				ExplodStub p2Bg;
				ExplodStub p3Bg;
				ExplodStub p4Bg;
				ExplodStub p1Name;
				ExplodStub p2Name;
				ExplodStub p3Name;
				ExplodStub p4Name;
				int32_t p1PosX;
				int32_t p2PosX;
				int32_t p3PosX;
				int32_t p4PosX;
				int32_t p1PosY;
				int32_t p2PosY;
				int32_t p3PosY;
				int32_t p4PosY;
			} name;
			NameData simulName;
			NameData turnsName;

			struct TimeData
			{
				ExplodStub bg;
				ExplodStub counterText;
				int32_t posX;
				int32_t posY;
				int32_t framesPerCount;
			} time;
			struct ComboData
			{
				int32_t posX;
				int32_t posY;
				int32_t startX;
				int32_t displayTime;
				int32_t counterFontFontNo;
				int32_t counterFontFontBank;
				uint32_t counterShake;
				int32_t textFontFontNo;
				int32_t textFontFontBank;
				int32_t textOffsetX;
				int32_t textOffsetY;
				char textText[32];
			} combo;
			struct RoundData
			{
				int32_t matchWins;
				int32_t matchMaxDrawGames;
				int32_t startWaitTime;
				int32_t introTime;
				int32_t posX;
				int32_t posY;
				ExplodStub roundDefaultText;
				ExplodStub roundNText[10];
				int32_t roundTime;
				int32_t roundSndTime;
				int32_t roundNSndGroupNo[10];
				int32_t roundNSndItemNo[10];
				ExplodStub fightAnim;
				int32_t fightTime;
				int32_t fightSndTime;
				SoundParam fightSnd;
				ExplodStub koAnim;
				ExplodStub dkoText;
				ExplodStub toText;
				undefined4 unknown_1;
				int32_t koSndTime;
				SoundParam koSnd;
				SoundParam dkoSnd;
				SoundParam toSnd;
				ExplodStub winText;
				ExplodStub win2Text;
				ExplodStub drawText;
				SoundParam winSnd;
				SoundParam win2Snd;
				SoundParam drawSnd;
				int32_t winTime;
				int32_t ctrlTime;
				int32_t slowTime;
				int32_t overWaitTime;
				int32_t overHitTime;
				int32_t overWinTime;
				int32_t overTime;
			} round;
			struct WinIconData
			{
				ExplodStub p1Counter;
				ExplodStub p2Counter;
				ExplodStub p1N;
				ExplodStub p1S;
				ExplodStub p1H;
				ExplodStub p1C;
				ExplodStub p1T;
				ExplodStub p1Throw;
				ExplodStub p1Suicide;
				ExplodStub p1TeamMate;
				ExplodStub p1Perfect;
				ExplodStub p2N;
				ExplodStub p2S;
				ExplodStub p2H;
				ExplodStub p2C;
				ExplodStub p2T;
				ExplodStub p2Throw;
				ExplodStub p2Suicide;
				ExplodStub p2TeamMate;
				ExplodStub p2Perfect;
				int32_t p1PosX;
				int32_t p2PosX;
				int32_t p1PosY;
				int32_t p2PosY;
				int32_t p1IconOffsetX;
				int32_t p2IconOffsetX;
				int32_t p1IconOffsetY;
				int32_t p2IconOffsetY;
				int32_t useIconUpTo;
			} winIcon;
		} motifFilesFight;
		SpriteArrayEx* p1TurnsPortraits[4]; // Turnsのときのちっさいポトレ
		SpriteArrayEx* p2TurnsPortraits[4];
		BOOL isDisplayGameBars; // 0xa2e0

		ExplodArray* explodArray;
		ExplodArray* ExplodStubArray;

		struct Motif {
			char filename[512];
			char directory[512];
			struct Files {
				SpriteArrayEx* sprArray;
				char spr[512];
				SoundArrayEx* sndArray;
				char snd[512];
				AnimRCArrayEx* airArray;
				Font* font[10];
			} files;
			BGArrayEx* versusBGArray;
			BGArrayEx* titleBGArray;
			BGArrayEx* selectBGArray;
			BGArrayEx* optionBGArray;
			struct Music {
				char titleBGM[512];
				BOOL titleBGMLoop;
				char vsBGM[512];
				BOOL vsBGMLoop;
				char selectBGM[512];
				BOOL selectBGMLoop;
			} music;
		} motif;

		BGArrayEx* stageBG;

		PalFxParams bgPalFX;
		PalFxParams allPalFX;

		struct ConfigSoundVolume {
			BOOL sound;
			int32_t wavVolume;
			int32_t masterWavVolume;
			int32_t cdaVolume;
			int32_t midiVolume;
			int32_t mp3Volume;
			int32_t modVolume;
		} configSoundVolume;

		BGM optionBGM;

		int32_t gameTime;
		int32_t skipFrame;
		int32_t skipCnt;
		BOOL skip;
		BOOL field_0xb40c; // Pause中のサウンド関係
		BOOL isPause;

		int32_t randSeed;

		BOOL isLifeSaving;
		BOOL isScreenFading;
		int32_t screenFading;
		int32_t screenFadingGoal;

		float fStageAxisX;
		float fStageAxisY;
		int32_t iStageAxisX;
		int32_t iStageAxisY;
		float fStageAxisX2; /* Always same as the fStageAxisX? */
		float fStageAxisY2; /* Always same as the fStageAxisY? */
		int32_t shake_axisX;
		int32_t shake_axisY;
		EnvShakeParams envShake;

		struct ConfigRules {
			GameType gameType;
			float defaultAttackLifeToPowerMul;
			float defaultGetHitLifeToPowerMul;
			float superTargetDefenceMul;
		} configRules;
		ConfigKeyCodes configP1Keys;
		ConfigKeyCodes configP2Keys;
		ConfigKeyCodes p1KeyInput;
		ConfigKeyCodes p2KeyInput;
		ConfigKeyCodes configP1Joystick;
		ConfigKeyCodes configP2Joystick;
		ConfigKeyCodes configP1WinJoystick;
		ConfigKeyCodes configP2WinJoystick;

		struct ConfigInput {
			BOOL p1UseKeyboard;
			BOOL p2UseKeyboard;
			BOOL p1JoystickEnable;
			BOOL p2JoystickEnable;
			JoystickType p1JoystickType;
			JoystickType p2JoystickType;
			BOOL forceFeedback;
			int32_t psxDelay;
		} configInput;

		IntCircBuf intCircBuf;

		int32_t numSlots;
		int32_t numHelperSlots;
		int32_t numPlayerSlots;
		int32_t numEnablePlayers;

		PlayerCache* playerCache[64];
		Player* player[64];
		BOOL playerEnable[64];
		int32_t firstPlayerIndex;
		int32_t lastPlayerIndex;

		Player* playerArray[65];
		int32_t playerArrayLength;
		int32_t nextPlayerId;

		BOOL isRunnableSlot[64];
		BOOL isHelperSummoned;

		BOOL field_0xbb68; // 内部AI停止フラグ？
		BOOL field_0xbb6c; // 攻撃判定停止フラグ？

		int32_t nextAttackNo;
		BOOL takeScreenShot;

		struct GameSpecialFlag {
			uint8_t intro;
			uint8_t roundNotOver;
			uint8_t noKO;
			uint8_t noKOSnd;
			uint8_t noKOSlow;
			uint8_t noKOMusic;
			uint8_t globalNoShadow;
			uint8_t timerFreeze;
			uint8_t noBarDisplay;
			uint8_t noBG;
			uint8_t noFG;
			undefined1 _padding;
		} specialFlags;

		undefined4 field_0xbb84;
		undefined4 field_0xbb88;

		BOOL isPlayingDemo;
		struct MotifDemoMode {
			int32_t introWaitCycles;
			int32_t titleWaitTime;
			BOOL selectEnabled;
			BOOL selectVsScreenEnabled;
			int32_t fightEndTime;
			uint32_t fightPlayBGM;
			uint32_t fightBarsDisplay;
			BOOL debugInfo;
		} motifDemoMode;
		int32_t demoElapsedTime;
		int32_t currentWaitCycles;

		PauseType pauseType;
		PauseParams pauseParam;
		PauseParams superPauseParam;

		int32_t roundNo;
		int32_t p1Wins;
		int32_t p2Wins;

		BOOL isWinsAllotted;
		int32_t draws;

		int32_t leftKOSlowCnt;
		int32_t maxKOSlowTime;
		int32_t koSlowTime;

		int32_t introElapsedTime;    /* The elapsed time between rs1-rs2. */
		int32_t overWaitElapsedTime; /* The elapsed time between rs3-rs4. */
		int32_t overTime;

		int32_t roundState;
		uint32_t winTeam;
		enum class SettledType {
			kNone = 0,
			kKO = 1,
			kDoubleKO = 2,
			kTimeOver = 3,
		} settledType;

		int32_t currentStateElapsedTime;
		int32_t roundTimer;
		int32_t fightElapsedTime; /* The elapsed time between rs2-rs3. */

		BOOL introSkipFlag;
		BOOL roundOverFlag;

		enum class WinType {
			kNormal = 0,
			kSpecial = 1,
			kHyper = 2,
			kThrow = 3,
			kTimeOver = 4,
			kCheese = 5,
			kSuicide = 6,
			kTeamSuicide = 7,
			kPerfect = 8,
		} p1WinType[10];
		WinType p2WinType[10];
		WinType p1SubWinType[10]; // Perfect
		WinType p2SubWinType[10];

		undefined4 field_0xbcf0; // コンボ関係？
		undefined4 field_0xbcf4;

		int32_t matchNo;
		int32_t totalMatchNo;

		int32_t gameMatchWinner;
		BOOL matchCancelFlag;

		struct ComboCount
		{
			int32_t displayTime;
			int32_t internalComboCnt;
			undefined4 _unknown_1;
			int32_t comboCnt;
			int32_t posX;
			undefined4 _unknown_2;
		} p1ComboCount;
		ComboCount p2ComboCount;

		struct ConfigVideoWin {
			int32_t width;
			int32_t height;
			int32_t depth;     /* depth? always 32 */
			uint32_t dxMode;   /* "f*": DXSA, "h*": DXAC, "n*": GDIB, "o*": DXOV, "s*": DXSO, "w*": DXWN */
			uint32_t blitMode; /* "n*": 0, "p*": 1, "t*": 2 */
			BOOL stretch;
			int32_t doubleRes;
			uint32_t vRetrace; /* 0 */
		} configVideoWin;
		struct ConfigSoundWin {
			int32_t wavDevice;  /* -1: AUTO, 0: NONE, "DXA "-"DXJ ": DX0-DX9, "AXA "-"AXJ ": DXA0-DXA9, "WOA ": WAVEOUTA, "WOB ": WAVEOUTB */
			int32_t midiDevice; /* -1: AUTO, 0: NONE, "W32M": MAPPER, "W32A"-"W32J": MID0-MID9, "DIGI": DIGMID */
			int32_t wavChannels;
			int32_t modVoices;
			undefined4 _unknown; /* reverseStereo? */
			BOOL playMP3;
			BOOL playMIDI;
			BOOL playMOD;
			BOOL playCDA;
			char cdaDevice[32];
			uint32_t stereoEffects;
			int32_t panningWidth;
			int32_t pauseBGMOnDefocus;
		} configSoundWin;
		struct ConfigConfig {
			int32_t gameSpeed;
			int32_t drawShadows;
			int32_t afterImageMax;
			int32_t layeredSpriteMax;
			int32_t explodMax;
			int32_t ExplodStubMax;
			int32_t helperMax;
			int32_t playerProjectileMax;
			int32_t playerPalMax;
			BOOL firstRun;
		} configConfig;
		struct ConfigMisc
		{
			int32_t playerCache;
			BOOL precache;
			BOOL bufferedRead;
			BOOL unloadSystem;
			BOOL pauseOnDefocus;
		} configMisc;
		struct ConfigArcade
		{
			BOOL aiRandomColor;
			BOOL aiCheat;
			int32_t arcadeAIrampStartMatch;
			int32_t arcadeAIrampStartDiff;
			int32_t arcadeAIrampEndMatch;
			int32_t arcadeAIrampEndDiff;
			int32_t teamAIrampStartMatch;
			int32_t teamAIrampStartDiff;
			int32_t teamAIrampEndMatch;
			int32_t teamAIrampEndDiff;
			int32_t survivalAIrampStartMatch;
			int32_t survivalAIrampStartDiff;
			int32_t survivalAIrampEndMatch;
			int32_t survivalAIrampEndDiff;
		} configArcade;

		BOOL isLogMatch;
		char matchLogPath[512];

		undefined4 commandLineFlag[17]; // コマンドライン関連？ 0x0042B5C1のEDIの0xFFFFFFFF部分

		struct ConfigOptions {
			int32_t difficulty;
			int32_t life;
			int32_t time;
			int32_t gameSpeed;
			int32_t wavVolume;
			int32_t midiVolume;
			undefined4 _unknown_1[16];
			int32_t team1vs2life;
			uint32_t teamLoseOnKO;
			undefined4 _unknown_2;
			undefined4 _unknown_3;
			char motif[512];
		} configOptions;

		struct TrainingMenu {
			int32_t selectedLine;
			int32_t selectedInValue;
			BOOL isTrainingMenu;

			enum class DummyControl {
				kCooperative = 0,
				kAI = 1,
				kManual = 2,
			} dummyControl;

			int32_t unknown_1; // page?
			enum class GuardMode {
				kNone = 0,
				kAuto = 1,
			} guardMode;
			enum class DummyMode {
				kStand = 0,
				kCrouch = 1,
				kJump = 2,
				kWJump = 3,
			} dummyMode;
			enum class Distance {
				kAny = 0,
				kClose = 1,
				kMedium = 2,
				kFar = 3,
			} distance;
			enum class ButtonJam {
				kNone = 0,
				kA = 1,
				kB = 2,
				kC = 3,
				kX = 4,
				kY = 5,
				kZ = 6,
				kStart = 7,
			} buttonJam;

			int32_t unknown_2; // page?
			int32_t aiLevel;

			int32_t unknown_3; // page?
		} trainingMenu;

		char defaultStagePath[512];

		float bgLoadTimeUs;
		float player1LoadTimeUs;
		float player2LoadTimeUs;
		undefined4 field_0xc508;
		undefined4 field_0xc50c;
		float totalLoadTimeUs;
		int32_t palGroupsInBackGround;

		int32_t debugShowSlot;
		BOOL field_0xc51c; // デバッグ関係のなにか

		uint32_t debug;
		uint32_t allowDebugMode;
		uint32_t allowDebugKeys;
		enum class ClsnDebugMode {
			kNone = 0,
			kBoxFrame = 1,
			kRectangle = 2,
		} clsnDebugMode;
		Clipboard* warningClipboard;
		char errorMessage[1024];

		BOOL speedup;
		int32_t field_0xc938; // speedupと関係？

		BOOL resetRound; // F4
		BOOL reloadMatch; // Shift+F4

		undefined4 field_0xc944; // speedupと関係？
	};


	static volatile const auto g = reinterpret_cast<GameVar**>(0x4b5b4c);
}