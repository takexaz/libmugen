#pragma once
#include <_MUGEN_TYPES.hpp>

#include <date.hpp>
#include <command.hpp>
#include <state.hpp>
#include <sprite.hpp>
#include <anim.hpp>
#include <sound.hpp>
#include <projectile.hpp>
#include <kbi.hpp>
#include <controller.hpp>
#include <afterimage.hpp>
#include <pallete.hpp>
#include <ai.hpp>
#include <clipboard.hpp>

namespace mugen20414::player {
	using namespace mugen20414::date;
	using namespace mugen20414::command;
	using namespace mugen20414::state;
	using namespace mugen20414::sprite;
	using namespace mugen20414::anim;
	using namespace mugen20414::sound;
	using namespace mugen20414::projectile;
	using namespace mugen20414::kbi;
	using namespace mugen20414::afterimage;
	using namespace mugen20414::pallete;
	using namespace mugen20414::player::ai;
	using namespace mugen20414::clipboard;


	enum class ProjContactType {
		kNone = 0,
		kGuarded = 1,
		kHit = 2,
		kCancel = 3
	};
	enum class MoveContactType {
		kNone     = 0,
		kGuarded  = 1,
		kHit      = 2,
		kReversed = 4
	};
	enum class StateType {
		kUnchanged = -1,
		kStand      = 1,
		kCrouch     = 2,
		kAir        = 3,
		kLying_Down = 4,
	};
	enum class MoveType {
		kUnchanged = -1,
		kIdle       = 0,
		kAttack     = 1,
		kHit        = 2,
	};
	enum class Physics {
		kUnchanged = -1,
		kNone       = 0,
		kStand      = 1,
		kCrouch     = 2,
		kAir        = 3,
	};

	struct Player;

	struct Target
	{
		Player* player;
		int32_t airJuggle;
		int32_t getTargetAt;
		int32_t bindPosX;
		int32_t bindPosY;
		int32_t bindPosZ;
		int32_t bindTime;
		int32_t preBindTime;
	};
	using  TargetArray = Array<Target>;

	struct Constants {
		int32_t dataLife;
		int32_t dataPower;
		int32_t dataAttack;
		int32_t sizeAttackZWidthFront;
		int32_t sizeAttackZWidthBack;
		int32_t dataAirJuggle;
		int32_t sizeAttackDist;
		int32_t sizeProjAttackDist;
		int32_t dataDefence;
		float dataFallDefenceMul;
		int32_t dataLieDownTime;
		float sizeXScale;
		float sizeYScale;
		int32_t sizeGroundBack;
		int32_t sizeGroundFront;
		int32_t sizeAirBack;
		int32_t sizeAirFront;
		int32_t sizeZWidth;
		int32_t sizeHeight;
		uint32_t sizeProjDoScale;
		int32_t sizeHeadPosX;
		int32_t sizeHeadPosY;
		int32_t sizeMidPosX;
		int32_t sizeMidPosY;
		int32_t sizeShadowOffset;
		float velocityWalkFwdX;
		float velocityWalkBackX;
		float velocityWalkUpX;
		float velocityWalkDownX;
		float velocityRunFwdX;
		float velocityRunFwdY;
		float velocityRunBackX;
		float velocityRunBackY;
		float velocityRunDownX;
		float velocityRunDownY;
		float velocityRunUpX;
		float velocityRunUpY;
		float velocityJumpY;
		float velocityJumpNewX;
		float velocityJumpFwdX;
		float velocityJumpBackX;
		float velocityJumpUpX;
		float velocityJumpDownX;
		float velocityRunJumpY;
		float velocityRunJumpFwdX;
		float velocityRunJumpBackX;
		float velocityRunJumpUpX;
		float velocityRunJumpDownX;
		int32_t movementAirJumpNum;
		int32_t movementAirJumpHeight;
		float velocityAirJumpY;
		float velocityAirJumpNewX;
		float velocityAirJumpFwdX;
		float velocityAirJumpBackX;
		float velocityAirJumpUpX;
		float velocityAirJumpDownX;
		float movementYAccel;
		float movementStandFriction;
		float movementCrouchFriction;
		int32_t dataSparkNo;
		int32_t dataGuardSparkNo;
		uint32_t dataKOEcho;
		int32_t sizeDrawOffsetX;
		int32_t sizeDrawOffsetY;
		int32_t dataIntPersistIndex;
		int32_t dataFloatPersistIndex;
	};
	struct PlayerSpecialFlags
	{
		uint8_t noStandGuard;
		uint8_t noCrouchGuard;
		uint8_t noAirGuard;
		uint8_t noAutoTurn;
		uint8_t noShadow;
		uint8_t noJuggleCheck;
		uint8_t noWalk;
		uint8_t noUnguardable;
		uint8_t invisible;
		uint8_t _padding[3];
	};
	struct GetHitVars {
		int32_t XVelAdd;
		int32_t YVelAdd;
		Player* attackedBy;
		uint32_t type;
		uint32_t animType;
		uint32_t airType;
		uint32_t groundType;
		int32_t damage;
		int32_t hitCount;
		int32_t fallCount;
		int32_t hitShakeTime;
		int32_t hitTime;
		int32_t slideTime;
		int32_t ctrlTime;
		int32_t recoverTime;
		uint32_t attr;
		float XOff;
		float YOff;
		float ZOff;
		float XVel;
		float YVel;
		float YAccel;
		uint32_t chainId;
		uint32_t guarded;
		Player* boundedBy;
		uint32_t fall;
		int32_t fall_damage;
		float fall_XVel;
		float fall_YVel;
		uint32_t fall_recover;
		int32_t fall_time;
		int32_t fall_recoverTime;
		uint32_t fall_kill;
		EnvShakeParams fall_envShake;
	};
	struct HitOverride
	{
		uint32_t enable;
		uint32_t attr;
		int32_t state;
		int32_t time;
		uint32_t forceAir;
	};
	struct PlayerBind
	{
		int32_t time;
		float* targetScreenPosX;
		float* targetPosY;
		float* targetPosZ;
		int32_t* targetFacing;
		int32_t facing;
		float posX;
		float posY;
		float posZ;
		Player* player;
	};

	struct PlayerCache {
		char name[48];
		char displayName[48];
		char authorName[48];
		MDY versionDate;
		MDY mugenVersion;
		undefined _unknown_1[512];
		int32_t charsIndex;
		Constants consts;
		CommandElem commands;
		StatedefArrayEx* statedefArray;
		SpriteArrayEx* spriteArrayEx;
		AnimRC* animArrayEx;
		int32_t volume;
		SoundArrayEx* soundArrayEx;
		char aiPath[512];
		void* _unknown_3;
		void* _unknown_4;
		undefined4 _unknown_5[64];
	};

	// 0x3464(13412)
	struct Player {
		PlayerCache* info;
		int32_t playerId;
		int32_t slotId;
		uint32_t teamSide;
		uint32_t turnCharsetIdx;
		uint32_t turnsNo;
		uint32_t isPartner;
		uint32_t isHelper;
		char debugName[48];
		Constants consts;
		uint32_t playerExist;
		uint32_t isFrozen;
		int32_t life;
		int32_t lifeMax;
		int32_t lifebarFront;
		int32_t lifebarBack;
		int32_t* pPower;
		int32_t* pPowerMax;
		int32_t power;
		int32_t powerMax;
		int32_t powerbar;
		int32_t powerbarCnt;
		float attackMul;
		float defenceMul;
		int32_t facing;
		int32_t turnFlag;
		uint32_t isVisible;
		float screenPosX;
		float posY;
		float posZ;
		float viewScreenPosX;
		float viewPosY;
		float viewPosZ;
		float velX;
		float velY;
		float velZ;
		int32_t offsetX;
		int32_t offsetY;
		int32_t offsetZ; // ではない可能性あり
		int32_t sprPriority;
		int32_t leftAirJumpNum;
		int32_t leftBounds;
		int32_t rightBounds;
		int32_t pauseMoveTime;
		int32_t superMoveTime;
		uint32_t screenBound;
		uint32_t moveCameraX;
		uint32_t moveCameraY;
		uint32_t playerPush;
		int32_t widthEdgeFront;
		int32_t widthEdgeBack;
		int32_t widthPlayerFront;
		int32_t widthPlayerBack;
		PlayerSpecialFlags specialFlags;
		int32_t projContactId;
		ProjContactType projContactType;
		int32_t projContactTime;
		ProjectileArrayEx* projectiles;
		TargetArray* targets;
		float cornerPushVel; // Hitdef
		float _unknown_2; //
		float _unknown_3; // corner関連(4441f9)
		float _unknown_4; //
		float _unknown_5; //
		undefined4 _unknown_6;
		uint32_t keyCtrl;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
		KBIState kbiState;
		CommandInfo commandInfo;
		StatedefArrayEx* usingStatedefs;
		StatedefArrayEx* enforcedStatedefs;
		uint32_t enforcedStateListBy;
		int32_t stateNo;
		int32_t prevStateNo;
		char persistents[512];
		int32_t time;
		StateType stateType;
		MoveType moveType;
		Physics physics;
		uint32_t ctrl;
		uint32_t isGuarding;
		int32_t idleTime;
		int32_t hitPauseTime;
		int32_t nextHitPauseTime;
		int32_t posFreeze;
		int32_t alive;
		int32_t timeSinceDeath;
		int32_t gameTime;
		MoveContactType moveContactType;
		int32_t moveContactTime;
		uint32_t attackHitTime; // 攻撃を当てた時間？ コンボ表示に使われている(0x443e04)
		uint32_t hasValidStateNo;
		int32_t var[60];
		float fvar[40];
		int32_t sysvar[5];
		float sysfvar[5];
		int32_t unhittable;
		uint32_t hitBy;
		uint32_t hitBy2;
		int32_t hitByTime;
		int32_t hitBy2Time;
		GetHitVars getHitVars;
		HitOverride hitOverrides[8];
		int32_t* _unknown_15;
		float _unknown_16;
		int32_t uninjuredCnt;
		int32_t* _unknown_18;
		HitdefParams hitDefParams;
		int32_t juggle;
		float scale;
		float scaleX;
		float scaleY;
		float realScreenPosX;
		float realScreenPosY;
		int32_t _unknown_19;
		int32_t _unknown_20;
		int32_t _unknown_21;
		int32_t _unknown_22; /* related to pos x? */
		int32_t _unknown_23; /* related to pos y? */
		int32_t _unknown_24; /* related to pos z? */
		int32_t offsetGapX;
		int32_t offsetGapY;
		float angle;
		uint32_t angleDrawFlag;
		undefined4 _unknown_25;
		Trans trans;
		AfterImage* afterImage;
		int32_t internalHitCount;
		int32_t hitCount;
		int32_t uniqHitCount;
		undefined4 _unknown_26;
		undefined4 _unknown_27;
		SpriteArrayEx* spriteArrayEx;
		SpriteArrayEx* personalPalleteSpriteArrayEx;
		SpriteArrayEx* commonPalleteSpriteArrayEx;
		SpriteArrayEx* personalPalleteSpritesArray_;
		Anim* anim;
		AnimRC* enforcedAnimArrayEx;
		int32_t palNo;
		undefined reserved1[0x1200]; // 未使用
		PalGroupFlags palGroupFlags;
		PalFxParams palFx;
		int32_t helperId;
		int32_t parentId;
		Player* parent;
		Player* root;
		uint32_t playerType;
		PlayerAI ai;
		Player* p2Enemy;
		Player* enemynear;
		uint32_t roundsExisted;
		PlayerBind bindTo;
		uint32_t animInvalidFlag;
		Clipboard* clipboard;
		uint32_t standBy;
	};
}
