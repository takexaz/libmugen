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
		kInteger  = 0,
		kFloat    = 1,
		kOperator = 2,
		kTrigger  = 3,
		kInvalid  = 4
	};
	enum class ExprType : char {
		kError = 0,
		kNumber = 0,
		kInteger = 1,
		kFloat = 2,
	};
	enum class Comparator {
		kEqual            = 0,
		kNotEqual         = 1,
		kGreaterThan      = 2,
		kGreaterThanEqual = 3,
		kLessThan         = 4,
		kLessThanEqual    = 5,
		kRangeInIn        = 10,
		kRangeInOut       = 11,
		kRangeOutIn       = 12,
		kRangeOutOut      = 13
	};
	enum class Operator {
		kEqual            = 1,
		kNotEqual         = 2,
		kGreaterThan      = 3,
		kLessThan         = 4,
		kGreaterThanEqual = 5,
		kLessThanEqual    = 6,
		kRangeOutOut      = 7,
		kRangeInOut       = 8,
		kRangeOutIn       = 9,
		kRangeInIn        = 10,
		kConditionalAND   = 11,
		kConditionalOR    = 12,
		kConditionalNOT   = 13,
		kConditionalXOR   = 14,
		kExponentiation   = 15,
		kBitwiseAND       = 16,
		kBitwiseOR        = 17,
		kBitwiseXOR       = 18,
		kBitwiseNEG       = 19,
		kIVarAssign       = 20,
		kFVarAssign       = 21,
		kBitwiseNOT       = 22,
		kAddition         = 23,
		kSubtraction      = 24,
		kMultiplication   = 25,
		kDivision         = 26,
		kModulo           = 27,
		kParenthesisOpen  = 28,
		kParenthesisClose = 29
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