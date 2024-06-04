#pragma once
#include <_MUGEN_TYPES.hpp>

#include <controller.hpp>

namespace mugen20414::player {
	enum class StateType;
	enum class MoveType;
	enum class Physics;
}

namespace mugen20414::state {
	using namespace mugen20414::state::controller;
	using namespace mugen20414::player;


	struct Statedef
	{
		SCtrlArray* states;
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

	struct StatedefArray {
		Array<Statedef>* statedefArray;
	};
}