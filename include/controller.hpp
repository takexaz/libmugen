#pragma once
#include <_MUGEN_TYPES.hpp>
#include <array.hpp>
#include <trigger.hpp>
#include <sound.hpp>
#include <anim.hpp>
#include <arith.hpp>
#include <pallete.hpp>
namespace mugen20414::state::controller {
	using namespace mugen20414::arith;
	using namespace mugen20414::array;
	using namespace mugen20414::state::trigger;
	using namespace mugen20414::sound;
	using namespace mugen20414::anim;
	using namespace mugen20414::pallete;


	enum class SCtrlId {
		kSCtrlNull               = 0,
		kSCtrlChangeState        = 1,
		kSCtrlSelfState          = 2,
		kSCtrlTurn               = 3,
		kSCtrlVarSet             = 4,
		kSCtrlVarAdd             = 5,
		kSCtrlVarRandom          = 6,
		kSCtrlVarRangeSet        = 7,
		kSCtrlLifeSet            = 10,
		kSCtrlLifeAdd            = 11,
		kSCtrlPowerSet           = 12,
		kSCtrlPowerAdd           = 13,
		kSCtrlCtrlSet            = 20,
		kSCtrlPosSet             = 21,
		kSCtrlPosAdd             = 22,
		kSCtrlPosFreeze          = 23,
		kSCtrlVelSet             = 24,
		kSCtrlVelAdd             = 25,
		kSCtrlVelMul             = 26,
		kSCtrlGravity            = 27,
		kSCtrlOffset             = 28,
		kSCtrlHitBy              = 30,
		kSCtrlNotHitBy           = 30,
		kSCtrlChangeAnim         = 32,
		kSCtrlChangeAnim2        = 33,
		kSCtrlPlaySnd            = 34,
		kSCtrlStopSnd            = 35,
		kSCtrlSndPan             = 36,
		kSCtrlHitDef             = 37,
		kSCtrlReversalDef        = 38,
		kSCtrlProjectile         = 39,
		kSCtrlWidth              = 40,
		kSCtrlScreenBound        = 50,
		kSCtrlSprPriority        = 51,
		kSCtrlAngleDraw          = 60,
		kSCtrlAngleSet           = 61,
		kSCtrlAngleAdd           = 62,
		kSCtrlAngleMul           = 63,
		kSCtrlTrans              = 65,
		kSCtrlTargetBind         = 70,
		kSCtrlBindToTarget       = 71,
		kSCtrlTargetState        = 72,
		kSCtrlTargetPowerAdd     = 73,
		kSCtrlTargetLifeAdd      = 74,
		kSCtrlTargetVelSet       = 75,
		kSCtrlTargetVelAdd       = 76,
		kSCtrlTargetFacing       = 77,
		kSCtrlTargetDrop         = 78,
		kSCtrlAttackDist         = 90,
		kSCtrlPlayerPush         = 91,
		kSCtrlHitFallSet         = 100,
		kSCtrlHitVelSet          = 101,
		kSCtrlHitFallDamage      = 102,
		kSCtrlHitFallVel         = 103,
		kSCtrlHitAdd             = 104,
		kSCtrlAttackMulSet       = 105,
		kSCtrlDefenceMulSet      = 106,
		kSCtrlStateTypeSet       = 110,
		kSCtrlHitOverride        = 120,
		kSCtrlMoveHitReset       = 130,
		kSCtrlAssertSpecial      = 150,
		kSCtrlEnvShake           = 200,
		kSCtrlFallEnvShake       = 201,
		kSCtrlEnvColor           = 202,
		kSCtrlGameMakeAnim       = 203,
		kSCtrlAfterImage         = 210,
		kSCtrlAfterImageTime     = 211,
		kSCtrlPause              = 212,
		kSCtrlSuperPause         = 214,
		kSCtrlMakeDust           = 215,
		kSCtrlAllPalFx           = 216,
		kSCtrlBGPalFx            = 216,
		kSCtrlPalFx              = 216,
		kSCtrlExplod             = 220,
		kSCtrlRemoveExplod       = 221,
		kSCtrlExplodBindTime     = 222,
		kSCtrlModifyExplod       = 223,
		kSCtrlForceFeedback      = 0, // 230,
		kSCtrlHelper             = 300,
		kSCtrlDestroySelf        = 301,
		kSCtrlParentVarSet       = 304,
		kSCtrlParentVarAdd       = 305,
		kSCtrlDisplayToClipboard = 310,
		kSCtrlAppendToClipboard  = 311,
		kSCtrlClearClipboard     = 312,
		kSCtrlBindToParent       = 320,
		kSCtrlBindToRoot         = 321,
		kSCtrlTagIn              = 10051,
		kSCtrlTagOut             = 10052
	};

	template <typename T>
	struct SCtrl {
		ExpressionArray* triggerArray;
		int32_t triggerCnt;
		int32_t persistent;
		int32_t ignorehitpause;
		SCtrlId scID;
		undefined4 _unknown_1;
		Expression params[6];
		T* paramsEx;
	};
	template <typename T>
	using SCtrlArray = Array<SCtrl<T>>;

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
		SoundParam hitSound;
		uint32_t hitSoundFlag; /* S: 0, F: 1 */
		SoundParam guardSound;
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
	struct AfterImageParams {
		int32_t time;
		int32_t length;
		int32_t timeGap;
		int32_t frameGap;
		int32_t palColor;
		BOOL palInvertAll;
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
		Trans trans;
	};

	enum class PauseType {
		kNone = -1,
		kPause = 0,
		kSuperPause = 1,
	};
	struct PauseParams
	{
		PalGroupFlags palGroupFlags;
		BOOL darken;
		int32_t time;
		BOOL pauseBG;
		int32_t endCmdBufTime;
	};
}