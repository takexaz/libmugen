#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <sprite.hpp>
#include <clsn.hpp>

namespace mugen20414::anim {
	using namespace mugen20414::array;
	using namespace mugen20414::sprite;
	using namespace mugen20414::clsn;

	enum class DrawType {
		kError          = -2,
		kDefault        = -1,
		kNone           = 0,
		kAdd            = 1,
		kSub            = 2,
		kAdd1           = 3,
		kAddAlpha       = 3,
	};

	struct AnimElem
	{
		int32_t startFrame;
		int32_t displayTime;
		int32_t groupNo;
		int32_t itemNo;
		int32_t axisX;
		int32_t axisY;
		uint32_t inverse; /* &1: H, &2: V */
		DrawType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		ClsnArray* clsn1;
		ClsnArray* clsn2;
	};

	using  AnimElemArray = Array<AnimElem>;

	struct AnimRC
	{
		AnimElemArray* animElemArray;
		int32_t totalElems;
		int32_t totalFrames;
		int32_t loopStartFrame;
		undefined4 _unknown_1;
	};

	using AnimRCArray = Array<AnimRC>*;

	struct AnimRCArrayEx
	{
		AnimRCArray* animArrayEx;
		int32_t totalAnims;
	};

	struct Anim
	{
		AnimRCArrayEx* useAnimRCArrayEx;
		Sprite* sprite;
		BOOL isOwnSprite;
		int32_t currentAnimIndex;
		AnimElemArray* currentAnimElemArray;
		int32_t currentAnimElemIndex;
		int32_t totalElapsedFrames;
		int32_t currentFrame;
		DrawType trans;
		int32_t transAlphaAS;
		int32_t transAlphaD;
		int32_t currentSpriteIndex;
		Sprite* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
		int32_t sprPriority;
	};

	static const auto AnimRCReadFile         = reinterpret_cast<AnimRCArrayEx * (*)(char* path)>(0x401770);
	static const auto AnimRCReadFileTP       = reinterpret_cast<AnimRCArrayEx * (*)(TPFile * tpf)>(0x401830);
	static const auto AnimElemParseLine      = reinterpret_cast<BOOL(*)(char* elem, int* dest, char* group, int elemNo)>(0x4023b0);
	static const auto AnimRCFree             = reinterpret_cast<void (*)(AnimRCArrayEx * animRCArrayEx)>(0x4026d0);
	static const auto AnimNew                = reinterpret_cast<Anim * (*)(AnimRCArrayEx * animRCArrayEx, Sprite * sprite)>(0x4027a0);
	static const auto AnimSet                = reinterpret_cast<void (*)(Anim * anim, AnimRCArrayEx * animRCArrayEx, Sprite * sprite)>(0x4027e0);
	static const auto AnimCopy               = reinterpret_cast<void (*)(Anim * dest, Anim * src)>(0x402800);
	static const auto AnimFree               = reinterpret_cast<void (*)(Anim * anim)>(0x402820);
	static const auto AnimUpdate             = reinterpret_cast<Anim * (*)(Anim * anim)>(0x402850);
	static const auto AnimUpdateElemptr      = reinterpret_cast<void (*)(Anim * anim)>(0x402b90);
	static const auto AnimResetAction        = reinterpret_cast<void (*)(Anim * anim)>(0x402c80);
	static const auto AnimChangeAction       = reinterpret_cast<void (*)(Anim * anim, int32_t groupNo, int32_t itemNo)>(0x402d60);
	static const auto AnimChangeActionTime   = reinterpret_cast<BOOL(*)(Anim * anim, int32_t groupNo, int32_t itemNo, int32_t frame)>(0x402d80);
	static const auto AnimChangeActionElem   = reinterpret_cast<BOOL(*)(Anim * anim, int32_t groupNo, int32_t itemNo, int32_t elemNo)>(0x402fb0);
	static const auto AnimDraw               = reinterpret_cast<void (*)(Anim * anim, int32_t posX, int32_t posY)>(0x403230);
	static const auto AnimDrawFlip           = reinterpret_cast<void (*)(Anim * anim, int32_t posX, int32_t posY, BOOL isFlip)>(0x403250);
	static const auto AnimDrawScale          = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float scaleX, float scaleY)>(0x403540);
	static const auto AnimDrawScaleFlip      = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float scaleX, float scaleY, BOOL isFlip)>(0x403570);
	static const auto AnimDrawRotateFlip     = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float angle, float scaleX, float scaleY, BOOL isFlip)>(0x4039c0);
	static const auto AnimCurIDGrp           = reinterpret_cast<int32_t(*)(Anim * anim)>(0x403d30);
	static const auto AnimCurIDno            = reinterpret_cast<int32_t(*)(Anim * anim)>(0x403d50);
	static const auto AnimCurElemStartTime   = reinterpret_cast<int32_t(*)(Anim * anim, int32_t elemNo)>(0x403d70);
	static const auto AnimCurElemIndex_UNK   = reinterpret_cast<AnimElemArray * (*)(Anim * anim, int32_t index)>(0x403f20);
	static const auto AnimElemNo             = reinterpret_cast<int32_t(*)(Anim * anim, int32_t frame)>(0x403f70);
	static const auto AnimIdxToIDGrp         = reinterpret_cast<void (*)(Anim * anim, int32_t index)>(0x404180);
	static const auto AnimIdxToIDno          = reinterpret_cast<void (*)(Anim * anim, int32_t index)>(0x4041a0);
	static const auto AnimGrpNoToIdx         = reinterpret_cast<void (*)(Anim * anim, int32_t group, int32_t no)>(0x4041c0);
	static const auto AnimGetLooptime        = reinterpret_cast<int32_t(*)(Anim * anim)>(0x4041e0);
	static const auto AnimGetLooptimeID      = reinterpret_cast<int32_t(*)(Anim * anim, int32_t group, int32_t no)>(0x4042b0);
	static const auto AnimGetLoopstarttime   = reinterpret_cast<undefined4(*)(Anim * anim)>(0x4043f0);
	static const auto AnimGetLoopstarttimeID = reinterpret_cast<int32_t(*)(Anim * anim, int32_t group, int32_t no)>(0x4044c0);
	static const auto AnimGetTime            = reinterpret_cast<int32_t(*)(Anim * anim)>(0x404600);
	static const auto AnimGetCorrectedTime   = reinterpret_cast<int32_t(*)(Anim * anim)>(0x404610);
	static const auto AnimCurSpriteIdx       = reinterpret_cast<int32_t(*)(Anim * anim)>(0x4047b0);
}