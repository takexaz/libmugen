#pragma once
#include <_MUGEN_TYPES.hpp>

#include <state.hpp>

namespace mugen20414::player {
	struct Player;
}

namespace mugen20414::player::ai {
	using namespace mugen20414::state;
	using namespace mugen20414::player;

	struct PlayerAIPlayersState
	{
		Player* player;
		undefined4 _unknown;
		int32_t stateNo;
		StatedefArray* statedefArray;
	};
	struct PlayerAIParams
	{
		undefined4 _unknown_1;
		undefined4 _unknown_2;
		uint32_t stateType;
		int32_t screenPosX;
		int32_t posY;
		int32_t facing;
		undefined4 _unknown_3;
		undefined4 _unknown_4;
		undefined4 _unknown_5;
		int32_t lastStateNo;
		uint32_t lastStateType;
		uint32_t lastMoveType;
		uint32_t lastCtrl;
		undefined4 _unknown_6[125];
		int32_t stateNo;
		uint32_t stateType_;
		undefined4 commnands[10];
		undefined4 _unknown_7[48];
		float _unknown_8;
		undefined4 _unknown_9[15];
		float _unknown_10;
		undefined4 _unknown_11[95];
	};
	struct PlayerAI
	{
		BOOL enable;
		uint32_t aiLevel;
		undefined4 _unknown_1[18];
		Statedef* currentStateDefData;
		undefined4 _unknown_2[362];
		PlayerAIPlayersState _unknown_3[10];
		int32_t _unknown_4;
		undefined4 _unknown_5[57];
		StatedefArray* _unknown_6;
		StatedefArray* _unknown_7;
		undefined4 _unknown_8[64];
		PlayerAIParams params;
		int32_t commands[10];
		int32_t gametime;
		int32_t commandHistory[10];
		int32_t lastFiredProjId;
		int32_t preStateNo;
		StateType preStateType;
		MoveType preMoveType;
		uint32_t preCtrl;
		undefined4 _unknown_9[11];
	};
}