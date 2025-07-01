#pragma once
#include <_MUGEN_TYPES.hpp>
#include <array.hpp>

namespace mugen20414::state::trigger {
	struct Trigger;
}
namespace mugen20414::player {
	struct Player;
	struct PlayerCache;
}


namespace mugen20414::arith {
	using namespace mugen20414::array;
	using namespace mugen20414::state::trigger;
	using namespace mugen20414::player;


	enum class EvalType {
		kEvalInteger  = 0,
		kEvalFloat    = 1,
		kEvalOperator = 2,
		kEvalTrigger  = 3,
		kEvalInvalid  = 4
	};
	enum class ExprType : char {
		kExprError = 0,
		kExprNumber = 0,
		kExprInteger = 1,
		kExprFloat = 2,
	};
	enum class Comparator {
		kCompEqual            = 0,
		kCompNotEqual         = 1,
		kCompGreaterThan      = 2,
		kCompGreaterThanEqual = 3,
		kCompLessThan         = 4,
		kCompLessThanEqual    = 5,
		kCompRangeInIn        = 10,
		kCompRangeInOut       = 11,
		kCompRangeOutIn       = 12,
		kCompRangeOutOut      = 13
	};
	enum class Operator {
		kOperEqual            = 1,
		kOperNotEqual         = 2,
		kOperGreaterThan      = 3,
		kOperLessThan         = 4,
		kOperGreaterThanEqual = 5,
		kOperLessThanEqual    = 6,
		kOperRangeOutOut      = 7,
		kOperRangeInOut       = 8,
		kOperRangeOutIn       = 9,
		kOperRangeInIn        = 10,
		kOperConditionalAND   = 11,
		kOperConditionalOR    = 12,
		kOperConditionalNOT   = 13,
		kOperConditionalXOR   = 14,
		kOperExponentiation   = 15,
		kOperBitwiseAND       = 16,
		kOperBitwiseOR        = 17,
		kOperBitwiseXOR       = 18,
		kOperBitwiseNEG       = 19,
		kOperIVarAssign       = 20,
		kOperFVarAssign       = 21,
		kOperBitwiseNOT       = 22,
		kOperAddition         = 23,
		kOperSubtraction      = 24,
		kOperMultiplication   = 25,
		kOperDivision         = 26,
		kOperModulo           = 27,
		kOperParenthesisOpen  = 28,
		kOperParenthesisClose = 29
	};

	union Evaluate {
		int32_t i;
		float f;
		Operator oper;
		Trigger* trig;
	};
	union ExprValue {
		int32_t i;
		float f;
		EvalType t;
	};
	struct Expression {
		Evaluate* evals;
		EvalType* types; /* 0: immediate value */
		ExprValue value;  /* types == NULL => immediate value, otherwise length of types, exprs */
	};
	using ExpressionArray = Array<Expression>;



	static const auto StackErrorExit = reinterpret_cast<void (*)(void)>(0x405700); // noreturn
	static const auto InfToPostArray = reinterpret_cast<int32_t(*)(char* value, Evaluate * eval, ExprType * types, PlayerCache * cache, int32_t maxValue, char** parseEnd, ExprType type)>(0x405720);
	static const auto OperCode       = reinterpret_cast<Operator(*)(char* oper)>(0x406b90);
	static const auto InfixToPostfix = reinterpret_cast<BOOL(*)(char* value, Expression * exp, PlayerCache * cache, char** parseEnd, int32_t numValue)>(0x406d10);
	static const auto FreeExpression = reinterpret_cast<void (*)(Expression * exp)>(0x406e00);
	static const auto FreeExpNoTrig  = reinterpret_cast<void (*)(Expression * exp)>(0x406e60);
	static const auto FreeExpArray   = reinterpret_cast<void (*)(ExpressionArray * expArray)>(0x406e90);
	static const auto ConstExpI = reinterpret_cast<void (*)(Expression * exp, int value)>(0x406f20);
	static const auto ConstExpF = reinterpret_cast<void (*)(Expression * exp, float value)>(0x406fa0);
	static const auto expcpy     = reinterpret_cast<BOOL(*)(Expression * dest, Expression * src)>(0x407010);
	static const auto expcpytrig = reinterpret_cast<BOOL(*)(Expression * dest, Expression * src)>(0x407100);
	static const auto ExpMulF = reinterpret_cast<void (*)(Expression * multiplicand, float multiplier)>(0x407250);
	static const auto ExpDivI = reinterpret_cast<void (*)(Expression * dividend, int divisor)>(0x407310);
	static const auto ShowExp = reinterpret_cast<void (*)(char* buffer, Expression * exp, Player * player)>(0x4073e0);
	static const auto EvalExpressionI = reinterpret_cast<int (*)(Player * player, Expression * exp, BOOL showWarn)>(0x4075e0);
	static const auto EvalExpressionF = reinterpret_cast<float (*)(Player * player, Expression * exp)>(0x4076d0);
	static const auto EvalExpression  = reinterpret_cast<ExprType(*)(Player * player, Expression * exp, int* i, float* f)>(0x407780);
}