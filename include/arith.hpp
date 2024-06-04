#pragma once
#include <_MUGEN_TYPES.hpp>

namespace mugen20414::state::trigger {
	struct EvalTrigger;
}

namespace mugen20414::arith {
	using namespace mugen20414::state::trigger;


	enum class EvalType {
		kInteger      = 0,
		kFloat    = 1,
		kOperator = 2,
		kTrigger  = 3,
		kInvalidId  = 4
	};
	enum class EvalComparator {
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
	enum class EvalOperator {
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

	union EvalExprValue {
		int32_t i;
		float f;
		EvalOperator op;
		EvalTrigger* trig;
	};
	union EvalNode {
		int32_t i;
		float f;
		EvalType t;
	};

	struct EvalValue {
		EvalExprValue* exprs;
		EvalType* types; /* 0: immediate value */
		EvalNode value;  /* types == NULL => immediate value, otherwise length of types, exprs */
	};
}