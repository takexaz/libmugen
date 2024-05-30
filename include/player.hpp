#pragma once
#include <_MUGEN_TYPES.hpp>

#include <date.hpp>
using namespace mugen20414::date;
#include <command.hpp>
using namespace mugen20414::command;
#include <state.hpp>
using namespace mugen20414::state;
#include <sprite.hpp>
using namespace mugen20414::sprite;
#include <anim.hpp>
using namespace mugen20414::anim;
#include <sound.hpp>
using namespace mugen20414::sound;
#include <projectile.hpp>
using namespace mugen20414::projectile;
#include <kbi.hpp>
using namespace mugen20414::kbi;
#include <controller.hpp>
using namespace mugen20414::state::controller;
#include <afterimage.hpp>
using namespace mugen20414::afterimage;
#include <pallete.hpp>
using namespace mugen20414::pallete;
#include <ai.hpp>
using namespace mugen20414::player::ai;
#include <clipboard.hpp>
using namespace mugen20414::clipboard;

namespace mugen20414::player {

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

	struct TargetList
	{
		uint32_t enable;
		int32_t id;
		undefined4 _unknown_1;
		undefined4 _unknown_2;
	};
	struct TargetData
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
	struct TargetInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t currentTargetCnt;
		int32_t maxTargetCnt;
		int32_t nextId;
		TargetData* targetData;
		TargetList* targetList;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};

	struct Constants {
		int32_t data_life;
		int32_t data_power;
		int32_t data_attack;
		int32_t size_attack_z_width_front;
		int32_t size_attack_z_width_back;
		int32_t data_airJuggle;
		int32_t size_attack_dist;
		int32_t size_proj_attack_dist;
		int32_t data_defence;
		float data_fall_defence_mul;
		int32_t data_lieDown_time;
		float size_XScale;
		float size_YScale;
		int32_t size_ground_back;
		int32_t size_ground_front;
		int32_t size_air_back;
		int32_t size_air_front;
		int32_t size_z_width;
		int32_t size_height;
		uint32_t size_proj_doScale;
		int32_t size_head_pos_x;
		int32_t size_head_pos_y;
		int32_t size_mid_pos_x;
		int32_t size_mid_pos_y;
		int32_t size_shadowOffset;
		float velocity_walk_fwd_x;
		float velocity_walk_back_x;
		float velocity_walk_up_x;
		float velocity_walk_down_x;
		float velocity_run_fwd_x;
		float velocity_run_fwd_y;
		float velocity_run_back_x;
		float velocity_run_back_y;
		float velocity_run_down_x;
		float velocity_run_down_y;
		float velocity_run_up_x;
		float velocity_run_up_y;
		float velocity_jump_y;
		float velocity_jump_new_x;
		float velocity_jump_fwd_x;
		float velocity_jump_back_x;
		float velocity_jump_up_x;
		float velocity_jump_down_x;
		float velocity_runJump_y;
		float velocity_runJump_fwd_x;
		float velocity_runJump_back_x;
		float velocity_runJump_up_x;
		float velocity_runJump_down_x;
		int32_t movement_airJump_num;
		int32_t movement_airJump_height;
		float velocity_airJump_y;
		float velocity_airJump_new_x;
		float velocity_airJump_fwd_x;
		float velocity_airJump_back_x;
		float velocity_airJump_up_x;
		float velocity_airJump_down_x;
		float movement_YAccel;
		float movement_stand_friction;
		float movement_crouch_friction;
		int32_t data_sparkNo;
		int32_t data_guard_sparkNo;
		uint32_t data_KO_echo;
		int32_t size_draw_offset_x;
		int32_t size_draw_offset_y;
		int32_t data_intPersistIndex;
		int32_t data_floatPersistIndex;
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

	struct PlayerInfo {
		char name[48];
		char displayName[48];
		char authorName[48];
		MDY versionDate;
		MDY mugenVersion;
		undefined _unknown_1[512];
		int32_t charsIdx;
		Constants consts;
		CommandElem commands;
		StatedefInfo** stateList;
		SpriteInfoEx* sprite;
		AnimInfoEx* anim;
		int32_t volume;
		SoundInfo** sound;
		char ai_filepath[512];
		void* _unknown_3;
		void* _unknown_4;
		undefined4 _unknown_5[64];
	};
	struct Player {
		PlayerInfo* info;
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
		int32_t offsetZ;
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
		ProjectileInfoEx* projectiles;
		TargetInfo* targets;
		float cornerPushVel; // Hitdef
		float _unknown_2; //
		float _unknown_3; // cornerŠÖ˜A(4441f9)
		float _unknown_4; //
		float _unknown_5; //
		undefined4 _unknown_6;
		uint32_t keyCtrl;
		undefined4 _unknown_7;
		undefined4 _unknown_8;
		KBIState kbiState;
		CommandInfo commandInfo;
		StatedefInfo** usingStateList;
		StatedefInfo** enforcedStateList;
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
		undefined4 _unknown_13;
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
		TransType trans;
		int32_t alphaAS;
		int32_t alphaD;
		AfterimageData* afterImage;
		int32_t internalHitCount;
		int32_t hitCount;
		int32_t uniqHitCount;
		undefined4 _unknown_26;
		undefined4 _unknown_27;
		SpriteInfoEx* sprite;
		SpriteInfoEx* personalPalleteSff;
		SpriteInfoEx* commonPalleteSff;
		SpriteInfoEx* personalPalleteSff_;
		AnimUsed* anim;
		AnimInfoEx* enforcedAnim;
		int32_t palNo;
		undefined reserved1[0x1200]; /* Maybe unused */
		PalGroup palGroup;
		PalFxParams palFx;
		int32_t helperId;
		int32_t parentId;
		Player* parent;
		Player* root;
		PlayerAi ai;
		Player* p2Enemy;
		Player* enemynear;
		uint32_t roundsExisted;
		PlayerBind bindTo;
		uint32_t animInvalidFlag;
		Clipboard* clipboard;
		uint32_t standBy;
	};
}
