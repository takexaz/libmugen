#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <controller.hpp>

namespace mugen20414::player {
	enum class StateType;
	enum class MoveType;
	enum class Physics;
}

namespace mugen20414::state {
	using namespace mugen20414::array;
	using namespace mugen20414::state::controller;
	using namespace mugen20414::player;


	struct Statedef
	{
		SCtrlArray<void>* states;
		StateType type;
		MoveType moveType;
		Physics physics;
		Expression juggle;
		Expression faceP2;
		Expression hitDefPersist;
		Expression hitCountPersist;
		Expression moveHitPersist;
		int sprPriorityFlag;
		Expression sprPriority;
		Expression velSetX;
		Expression velSetY;
		Expression velSetZ;
		Expression ctrl;
		Expression anim;
		Expression powerAdd;
	};

	using StatedefArray = Array<Statedef>;

	struct StatedefArrayEx {
		StatedefArray* statedefArray;
	};
}