#pragma once
#include <_MUGEN_TYPES.hpp>

#include <controller.hpp>
using namespace mugen20414::state::controller;

namespace mugen20414::player {
	enum class StateType;
	enum class MoveType;
	enum class Physics;
}
using namespace mugen20414::player;

namespace mugen20414::state {
	struct StatedefList
	{
		uint32_t enable;
		int32_t id;
		int32_t stateNo;
		undefined4 _unknown;
	};
	struct StatedefData
	{
		SCtrlInfo* states;
		StateType type;
		MoveType moveType;
		Physics physics;
		EvalValue juggle;
		EvalValue faceP2;
		EvalValue hitDefPersist;
		EvalValue hitCountPersist;
		EvalValue moveHitPersist;
		int sprPriorityFlag;
		EvalValue sprPriority;
		EvalValue velSetX;
		EvalValue velSetY;
		EvalValue velSetZ;
		EvalValue ctrl;
		EvalValue anim;
		EvalValue powerAdd;
	};
	struct StatedefInfo
	{
		undefined4 _unknown;
		int32_t size;
		int32_t currentDefCnt;
		int32_t maxDefCnt;
		int32_t nextId;
		StatedefData* defData;
		StatedefList* defList;
		int32_t scaned_index;
		int32_t scaned_cnt;
		int32_t min_index;
		int32_t max_index;
	};


}