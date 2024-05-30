#pragma once
#include <_MUGEN_TYPES.hpp>
#include <trigger.hpp>
using namespace mugen20414::state::trigger;
#include <sound.hpp>
using namespace mugen20414::sound;
#include <anim.hpp>
using namespace mugen20414::anim;

namespace mugen20414::state::controller {
	enum class SCtrlId {
		kNull               = 0,
		kChangeState        = 1,
		kSelfState          = 2,
		kTurn               = 3,
		kVarSet             = 4,
		kVarAdd             = 5,
		kVarRandom          = 6,
		kVarRangeSet        = 7,
		kLifeSet            = 10,
		kLifeAdd            = 11,
		kPowerSet           = 12,
		kPowerAdd           = 13,
		kCtrlSet            = 20,
		kPosSet             = 21,
		kPosAdd             = 22,
		kPosFreeze          = 23,
		kVelSet             = 24,
		kVelAdd             = 25,
		kVelMul             = 26,
		kGravity            = 27,
		kOffset             = 28,
		kHitBy              = 30,
		kNotHitBy           = 30,
		kChangeAnim         = 32,
		kChangeAnim2        = 33,
		kPlaySnd            = 34,
		kStopSnd            = 35,
		kSndPan             = 36,
		kHitDef             = 37,
		kReversalDef        = 38,
		kProjectile         = 39,
		kWidth              = 40,
		kScreenBound        = 50,
		kSprPriority        = 51,
		kAngleDraw          = 60,
		kAngleSet           = 61,
		kAngleAdd           = 62,
		kAngleMul           = 63,
		kTrans              = 65,
		kTargetBind         = 70,
		kBindToTarget       = 71,
		kTargetState        = 72,
		kTargetPowerAdd     = 73,
		kTargetLifeAdd      = 74,
		kTargetVelSet       = 75,
		kTargetVelAdd       = 76,
		kTargetFacing       = 77,
		kTargetDrop         = 78,
		kAttackDist         = 90,
		kPlayerPush         = 91,
		kHitFallSet         = 100,
		kHitVelSet          = 101,
		kHitFallDamage      = 102,
		kHitFallVel         = 103,
		kHitAdd             = 104,
		kAttackMulSet       = 105,
		kDefenceMulSet      = 106,
		kStateTypeSet       = 110,
		kHitOverride        = 120,
		kMoveHitReset       = 130,
		kAssertSpecial      = 150,
		kEnvShake           = 200,
		kFallEnvShake       = 201,
		kEnvColor           = 202,
		kGameMakeAnim       = 203,
		kAfterImage         = 210,
		kAfterImageTime     = 211,
		kPause              = 212,
		kSuperPause         = 214,
		kMakeDust           = 215,
		kAllPalFx           = 216,
		kBGPalFx            = 216,
		kPalFx              = 216,
		kExplod             = 220,
		kRemoveExplod       = 221,
		kExplodBindTime     = 222,
		kModifyExplod       = 223,
		kForceFeedback      = 0, // 230,
		kHelper             = 300,
		kDestroySelf        = 301,
		kParentVarSet       = 304,
		kParentVarAdd       = 305,
		kDisplayToClipboard = 310,
		kAppendToClipboard  = 311,
		kClearClipboard     = 312,
		kBindToParent       = 320,
		kBindToRoot         = 321,
		kTagIn              = 10051,
		kTagOut             = 10052
	};

	struct SCtrlList {
		uint32_t enable;
		int32_t id;
		SCtrlId scID;
		int32_t laterLabelNo;
	};
	struct SCtrlData {
		TrigInfo* triggers;
		uint32_t triggerCnt;
		int32_t persistent;
		int32_t ignorehitpause;
		SCtrlId scID;
		undefined4 _unknown_1;
		EvalValue params[6];
		void* paramsEx;
	};
	struct SCtrlInfo {
		undefined4 _unknown;
		int32_t size;
		int32_t currentSCCnt;
		int32_t maxSCCnt;
		int32_t nextId;
		SCtrlData* scData;
		SCtrlList* scList;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};

	struct EnvShakeParams
	{
		int32_t elapsedTime;
		int32_t time;
		int32_t dir;
		float freq;
		float ampl;
		float phase;
	};
	struct PalFxParams
	{
		int32_t elapsedTime;
		int32_t time;
		int32_t color;
		int32_t addR;
		int32_t addG;
		int32_t addB;
		int32_t mulR;
		int32_t mulG;
		int32_t mulB;
		int32_t sinAddR;
		int32_t sinAddG;
		int32_t sinAddB;
		uint32_t invertAll;
		uint32_t sinAddF;
		uint32_t resetFlag;
	};
	struct HitdefParams
	{
		uint32_t isAttacking;
		uint32_t isHitDef;
		uint32_t affectTeam;
		uint32_t attr;
		int32_t attackNo;
		int32_t hitId;
		int32_t chainId;
		int32_t noChainId;
		int32_t noChainId2;
		uint32_t kill;
		uint32_t guard_kill;
		uint32_t fall_kill;
		uint32_t hitOnce;
		int32_t jugglePoints;
		int32_t damage;
		int32_t guard_damage;
		int32_t getPower;
		int32_t guard_getPower;
		int32_t givePower;
		int32_t guard_givePower;
		int32_t p2HitPauseTime;
		int32_t p1HitPauseTime;
		int32_t numHits;
		SoundItem hitSound;
		uint32_t hitSoundFlag; /* S: 0, F: 1 */
		SoundItem guardSound;
		uint32_t guardSoundFlag; /* S: 0, F: 1 */
		uint32_t guardFlag;
		uint32_t hitFlag;
		int32_t hitPriority;
		uint32_t hitPriorityType;
		int32_t attackWidthZ1;
		int32_t attackWidthZ2;
		int32_t p1StateNo;
		int32_t p2StateNo;
		uint32_t p2GetP1StateNo;
		int32_t p2BindTime;
		int32_t p1SprPriority;
		int32_t p2SprPriority;
		uint32_t animType;
		uint32_t forceStand;
		uint32_t reversalAttr;
		int32_t fall_damage;
		uint32_t fall_animType;
		float fall_XVelocity;
		float fall_YVelocity;
		uint32_t fall_recover;
		int32_t fall_recover_time;
		EnvShakeParams fall_envShake;
		int32_t sparkNo;
		uint32_t sSparkFlag; /* S: 1, F: 0 */
		int32_t guard_sparkNo;
		uint32_t guard_sSparkFlag; /* S: 1, F: 0 */
		int32_t sparkX;
		int32_t sparkY;
		int32_t p1Facing;
		int32_t p1GetP2Facing;
		int32_t minDistX;
		int32_t minDistY;
		int32_t minDistZ;
		int32_t maxDistX;
		int32_t maxDistY;
		int32_t maxDistZ;
		int32_t p2Facing;
		uint32_t ground_type;
		int32_t ground_hitTime;
		int32_t ground_slideTime;
		float ground_velocityX;
		float ground_velocityY;
		float ground_cornerPush_velOff;
		uint32_t air_type;
		uint32_t air_animType;
		int32_t air_hitTime;
		uint32_t air_fall;
		float air_velocityX;
		float air_velocityY;
		float air_cornerPush_velOff;
		uint32_t down_bounce;
		int32_t down_hitTime;
		float down_velocityX;
		float down_velocityY;
		float down_cornerPush_velOff;
		float guard_velocity;
		int32_t guard_hitTime;
		int32_t guard_slideTime;
		int32_t guard_ctrlTime;
		int32_t guard_dist;
		int32_t guard_p2PauseTime;
		int32_t guard_p1PauseTime;
		float guard_cornerPush_velOff;
		float airGuard_velocityX;
		float airGuard_velocityY;
		int32_t airGuard_ctrlTime;
		float airGuard_cornerPush_velOff;
		float YAccel;
		PalFxParams palFX;
		EnvShakeParams envShake;
	};
	struct AfterimageParams {
		int32_t time;
		int32_t length;
		int32_t timeGap;
		int32_t frameGap;
		int32_t palColor;
		uint32_t palInvertAll;
		int32_t palBrightR;
		int32_t palBrightG;
		int32_t palBrightB;
		int32_t palContrastR;
		int32_t palContrastG;
		int32_t palContrastB;
		int32_t palPostBrightR;
		int32_t palPostBrightG;
		int32_t palPostBrightB;
		int32_t palAddR;
		int32_t palAddG;
		int32_t palAddB;
		int32_t palMulR;
		int32_t palMulG;
		int32_t palMulB;
		TransType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
	};
}