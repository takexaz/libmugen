#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <sprite.hpp>
#include <collision.hpp>

namespace mugen20414::anim {
	using namespace mugen20414::array;
	using namespace mugen20414::pallete;
	using namespace mugen20414::sprite;
	using namespace mugen20414::collision;

	enum class DrawType {
		kError          = -2,
		kDefault        = -1,
		kNone           = 0,
		kAdd            = 1,
		kSub            = 2,
		kAdd1           = 3,
		kAddAlpha       = 3,
	};
	struct Trans {
		DrawType type;
		int32_t alphaAS;
		int32_t alphaD;
	};

	struct PRSprite {
		int32_t priority;
		Sprite* sprite;
		int32_t curSprIdx;
		EBPal* ebPal;
		int32_t posX;
		int32_t posY;
		int32_t _unknown_01;
		Trans trans;
		float scaleX;
		float scaleY;
		float angle;
		FlipFlag flip;
	};
	using PRSpriteArray = Array<PRSprite>;
	struct PRSpriteArrayEx {
		PRSpriteArray* prSprArray;
		int32_t* indexes;
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
		Trans trans;
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
	using AnimRCArray = Array<AnimRC>;
	struct AnimRCArrayEx
	{
		AnimRCArray* animRCArray;
		int32_t totalAnims;
	};

	struct Anim
	{
		AnimRC* useAnimRC;
		SpriteArrayEx* sprite;
		BOOL isOwnSprite;
		int32_t currentAnimIndex;
		AnimElem* currentAnimElem;
		int32_t currentAnimElemIndex;
		int32_t totalElapsedFrames;
		int32_t currentFrame;
		Trans trans;
		int32_t currentSpriteIndex;
		PRSpriteArrayEx* spritesLayer; /* Ontop == 0: g->prioritySpritesLayer1, Otherwise: NULL */
		int32_t sprPriority;
	};

	// 0x4c
	struct AnimPersistent {
		int32_t posX;
		int32_t posY;
		FlipFlag flip;
		float scaleX;
		float scaleY;
		Anim anim;
	};
	using AnimPersistentArray = Array<AnimPersistent>;
	// 0x04
	struct AnimPersistentArrayEx {
		AnimPersistentArray* animPerArray;
	};

	static const auto AnimRCReadFile    = reinterpret_cast<AnimRCArrayEx * (*)(char* path)>(0x401770);
	static const auto AnimRCReadFileTP  = reinterpret_cast<AnimRCArrayEx * (*)(TPFile * tpf)>(0x401830);
	static const auto AnimElemParseLine = reinterpret_cast<BOOL(*)(char* elem, int* dest, char* group, int elemNo)>(0x4023b0);
	static const auto AnimRCFree        = reinterpret_cast<void (*)(AnimRCArrayEx * animRCArrayEx)>(0x4026d0);

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
	static const auto AnimDrawFlip           = reinterpret_cast<void (*)(Anim * anim, int32_t posX, int32_t posY, FlipFlag flip)>(0x403250);
	static const auto AnimDrawScale          = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float scaleX, float scaleY)>(0x403540);
	static const auto AnimDrawScaleFlip      = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float scaleX, float scaleY, FlipFlag flip)>(0x403570);
	static const auto AnimDrawRotateFlip     = reinterpret_cast<void (*)(Anim * anim, int32_t PosX, int32_t PosY, float angle, float scaleX, float scaleY, FlipFlag flip)>(0x4039c0);
	static const auto AnimCurIDGrp           = reinterpret_cast<int32_t(*)(Anim * anim)>(0x403d30);
	static const auto AnimCurIDno            = reinterpret_cast<int32_t(*)(Anim * anim)>(0x403d50);
	static const auto AnimCurElemStartTime   = reinterpret_cast<int32_t(*)(Anim * anim, int32_t elemNo)>(0x403d70);
	static const auto AnimCurElemIndex_TEMP  = reinterpret_cast<AnimElemArray * (*)(Anim * anim, int32_t index)>(0x403f20); // Unknown func name
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

	static const auto PRSprArrayNew   = reinterpret_cast<PRSpriteArrayEx * (*)(size_t num)>(0x4047c0);
	static const auto PRSprArrayFree  = reinterpret_cast<void (*)(PRSpriteArrayEx * prSpr)>(0x404870);
	static const auto PRSprArrayClear = reinterpret_cast<void (*)(PRSpriteArrayEx * prSpr)>(0x4048a0);
	static const auto PRSprAdd        = reinterpret_cast<BOOL(*)(PRSpriteArrayEx * prSprArray, PRSprite * prSpr)>(0x4048b0);
	static const auto PRSprDraw       = reinterpret_cast<void (*)(PRSprite * prSpr)>(0x404940);
	static const auto PRSprArrayDraw  = reinterpret_cast<void (*)(PRSpriteArrayEx * prSpr)>(0x404b60);
	static const auto PRSprArrayScale = reinterpret_cast<void (*)(PRSpriteArrayEx * prSprArray, float scale)>(0x404be0);

	static const auto AnimPerUpdate            = reinterpret_cast<BOOL(*)(AnimPersistent * animPer)>(0x404cc0);
	static const auto AnimPerDraw              = reinterpret_cast<void (*)(AnimPersistent * animPer, int offsetX, int offsetY)>(0x404cf0);
	static const auto AnimPerDrawScale         = reinterpret_cast<void (*)(AnimPersistent * animPer, int32_t offsetX, int32_t offsetY, float scale)>(0x404d20);
	static const auto AnimPerArrayNew          = reinterpret_cast<AnimPersistentArrayEx * (*)(size_t num)>(0x404d80);
	static const auto AnimPerArrayFree         = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx)>(0x404dd0);
	static const auto AnimPerArrayAdd          = reinterpret_cast<int32_t(*)(AnimPersistentArrayEx * animPerArrayEx, Anim * anim, Sprite * sprite, int32_t groupNo, int32_t itemNo, int32_t posX, int32_t posY, FlipFlag flip, DrawType transType)>(0x404df0);
	static const auto AnimPerArraySetNo        = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t index, undefined4 no)>(0x404f80);
	static const auto AnimPerArrayDelete       = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t index)>(0x404fa0);
	static const auto AnimPerArrayClear        = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx)>(0x404fc0);
	static const auto AnimPerArrayUpdate       = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx)>(0x404fd0);
	static const auto AnimPerArrayUpdateGrp    = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t groupNo)>(0x405020);
	static const auto AnimPerArrayDraw         = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t offsetX, int32_t offsetY)>(0x405090);
	static const auto AnimPerArrayDrawGrp      = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t groupNo, int32_t offsetX, int32_t offsetY)>(0x4050e0);
	static const auto AnimPerArrayDrawScaleGrp = reinterpret_cast<void (*)(AnimPersistentArrayEx * animPerArrayEx, int32_t groupNo, int32_t offsetX, int32_t offsetY, float scale)>(0x405150);

	static const auto FlipFlagMix = reinterpret_cast<FlipFlag(*)(FlipFlag flip1, FlipFlag flip2)>(0x405200);

	static const auto AnimDrawSprFlip = reinterpret_cast<void (*)(Sprite * sprite, int32_t index, int32_t posX, int32_t posY, FlipFlag flip, Trans trans)>(0x405210);
	static const auto AnimScaleSpr_S  = reinterpret_cast<void (*)(Sprite * sprite, int32_t index, int32_t posX, int32_t posY, float scaleX, float scaleY, Trans trans)>(0x4054e0);
	static const auto AnimRotateSpr   = reinterpret_cast<void (*)(Sprite * sprite, int32_t index, int posX, int posY, float angle, float scaleX, float scaleY, float param_8, float param_9, Trans trans)>(0x4055d0);
}