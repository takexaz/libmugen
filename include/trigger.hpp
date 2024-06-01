#pragma once
#include <_MUGEN_TYPES.hpp>

#include <arith.hpp>

namespace mugen20414::state::trigger {
	using namespace mugen20414::arith;

	enum class TriggerId {
		kTime              = 0,
		kAnimTime          = 1,
		kAnimElem          = 2,
		kAnim              = 3,
		kPos               = 4,
		kScreenPos         = 5,
		kVel               = 6,
		kTimeMod           = 7,
		kP2Dist            = 8,
		kP2BodyDist        = 9,
		kP2Life            = 10,
		kFrondEdgeDist     = 11,
		kFrontEdgeBodyDist = 11,
		kBackEdgeBodyDist  = 12,
		kBackEdgeDist      = 12,
		kLife              = 15,
		kLifeMax           = 16,
		kPower             = 17,
		kPowerMax          = 18,
		kAlive             = 19,
		kCommand           = 20,
		kHitCount          = 30,
		kUniqHitCount      = 31,
		kMoveHit           = 32,
		kMoveGuarded       = 33,
		kMoveContact       = 34,
		kMoveReversed      = 35,
		kInGuardDist       = 36,
		kStateNo           = 40,
		kPrevStateNo       = 41,
		kP2StateNo         = 42,
		kStateType         = 43,
		kP2StateType       = 44,
		kMoveType          = 45,
		kP2MoveType        = 46,
		kCtrl              = 47,
		kHitDefAttr        = 48,
		kRandom            = 51,
		kNumProj           = 60,
		kProjHit           = 62,
		kProjGuarded       = 63,
		kProjContact       = 64,
		kName              = 90,
		kP1Name            = 90,
		kP2Name            = 91,
		kP3Name            = 92,
		kP4Name            = 93,
		kAuthorName        = 94,
		kNumPartner        = 95,
		kNumEnemy          = 96,
		kID                = 97,
		kFacing            = 99,
		kHitFall           = 100,
		kHitShakeOver      = 101,
		kHitOver           = 102,
		kHitVel            = 103,
		kHitPauseTime      = 104,
		kCanRecover        = 105,
		kPalNo             = 107,
		kWinPerfect        = 108,
		kWin               = 109,
		kLose              = 110,
		kDrawGame          = 111,
		kMatchOver         = 112,
		kGameTime          = 113,
		kRoundNo           = 114,
		kRoundState        = 115,
		kMatchNo           = 116,
		kRoundsExisted     = 117,
		kTeamSide          = 120,
		kTeamMode          = 121,
		kIsHomeTeam        = 122,
		kNumExplod         = 150,
		kNumTarget         = 160,
		kGetHitVar         = 180,
		kConst             = 181,
		kTicksPerSecond    = 190,
		kIsHelper          = 201,
		kNumHelper         = 202,
		kParentDist        = 203,
		kRootDist          = 204,
		kStandBy           = 205,
		kPi                = 300,
		kE                 = 301,
		kIfElse            = 305,
		kLog               = 310,
		kSin               = 320,
		kCos               = 321,
		kTan               = 322,
		kASin              = 323,
		kACos              = 324,
		kATan              = 325,
		kExp               = 326,
		kLn                = 327,
		kAbs               = 328,
		kFloor             = 329,
		kCeil              = 330,
		kAnimElemTime      = 331,
		kAnimExist         = 332,
		kSelfAnimExist     = 333,
		kPlayerIDExist     = 334,
		kIsHelper_ID       = 335,
		kNumHelper_ID      = 336,
		kProjHitTime       = 337,
		kProjGuardedTime   = 338,
		kProjContactTime   = 339,
		kNumProjID         = 340,
		kNumExplod_ID      = 341,
		kNumTarget_ID      = 342,
		kVar               = 343,
		kFVar              = 344,
		kSysVar            = 345,
		kSysFVar           = 346,
		kProjCancelTime    = 347,
		kAnimElemNo        = 348
	};
	enum class RedirectId {
		kNone      = 0,
		kParent    = 1,
		kRoot      = 2,
		kHelper    = 3,
		kTarget    = 4,
		kPartner   = 5,
		kEnemy     = 6,
		kEnemyNear = 7,
		kPlayerID  = 8
	};
	enum class GetHitVarId{
		kXVelAdd = 0,
		kYVelAdd,
		kType,
		kAnimType,
		kAirType,
		kGroundType,
		kDamage,
		kHitCount,
		kFallCount,
		kHitShakeTime,
		kHitTime,
		kSlideTime,
		kCtrlTime,
		kRecoverTime,
		kXOff,
		kYOff,
		kZOff,
		kXVel,
		kYVel,
		kYAccel,
		kChainID,
		kGuarded,
		kIsBound,
		kFall,
		kFallDamage,
		kFallXVel,
		kFallYVel,
		kFallRecover,
		kFallTime,
		kFallRecoverTime,
		kFallKill,
		kFallEnvShakeTime,
		kFallEnvShakeDir,
		kFallEnvShakeAmpl,
		kFallEnvShakeFreq,
		kFallEnvShakePhase,
	};
	enum class SpecialFlagId {
		kIntro          = 0,
		kRoundNotOver   = 1,
		kNoKO           = 2,
		kNoKOSnd        = 3,
		kNoKOSlow       = 4,
		kNoMusic        = 5,
		kGlobalNoShadow = 6,
		kTimerFreeze    = 7,
		kNoBarDisplay   = 8,
		kNoBG           = 9,
		kNoFG           = 10,
		kNoStandGuard   = 16,
		kNoCrouchGuard  = 17,
		kNoAirGuard     = 18,
		kNoAutoTurn     = 19,
		kNoShadow       = 20,
		kNoJuggleCheck  = 21,
		kNoWalk         = 22,
		kNoUnguardable  = 23,
		kInvisible      = 24
	};

	struct TrigData {
		TriggerId trigID;
		RedirectId redirectID;
		EvalValue redirectArg;
		EvalComparator compareStyle;
		uint32_t isFloat;
		EvalType trigArgs[6];
		char* trigStrArg;
	};
	struct TrigList {
		uint32_t enable;
		uint32_t id;
		int32_t triggerNo;
		int32_t triggerSubNo;
	};
	struct TrigInfo {
		undefined4 _unknown;
		int32_t size;
		int32_t currentTrigCnt;
		int32_t maxTrigCnt;
		int32_t nextId;
		EvalValue* trigData;
		TrigList* trigList;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};
}