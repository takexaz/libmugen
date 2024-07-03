#pragma once
#include <_MUGEN_TYPES.hpp>

#include <array.hpp>
#include <anim.hpp>
#include <sprite.hpp>

namespace mugen20414::bg {
    using namespace mugen20414::array;
    using namespace mugen20414::anim;
    using namespace mugen20414::sprite;
    

    enum class BGCtrlType {
        kNull = 0,
        kVisible = 1,
        kEnable = 2,
        kPosSet = 3,
        kVelSet = 4,
        kPosAdd = 5,
        kVelAdd = 6,
        kUnknown1 = 7,
        kAnim = 8,
        kUnknown2 = 9,
        kUnknown3 = 10,
        kSinX = 11,
        kSinY = 12,
        kUnknown4 = 13,
        kUnknown5 = 14,
        kUnknown6 = 15,
        kUnknown7 = 16,
        kUnknown8 = 17,
        kUnknown9 = 18,
        kUnknown10 = 19,
        kDummy = 20,
    };
    struct BGCtrl {
        int32_t ctrlId[10];
        undefined4 unknown_1;
        undefined4 unknown_2;
        BGCtrlType type;
        int32_t time[3];
        union IntParam {
            BOOL valueBool; // Visible,Enable
            int32_t valueInt; // Anim
        } intParam;
        union FloatParam {
            struct XY {
                float x;
                float y;
            } xy; // PosSet,VelSet,PosAdd,PosSet
            struct Value {
                float value[3];
            } value; // SinX,SinY
        } floatParam;
        undefined4 unknown_3;
    };

    enum class BGType {
        kNormal = 0,
        kParallax = 1,
        kH = 2,
        kAnim = 3,
        kUnknown1 = 4,
        kUnknown2 = 5,
        kUnknown3 = 6,
        kUnknown4 = 7,
        kUnknown5 = 8,
        kUnknown6 = 9,
        kDummy = 10
    };
    // 0x100
    struct BG {
        BGType type;
        int32_t startX;
        int32_t startY;
        int32_t displayPosX;
        int32_t displayPosY;
        float posX;
        float posY;
        float negDeltaX;
        float negDeltaY;
        float velocityX;
        float velocityY;
        int32_t tile[2];
        int32_t tileSpacing[2];
        int32_t spriteWidth;
        int32_t spriteHeight;
        undefined4 field12_0x44;
        undefined4 field13_0x48;
        undefined4 field14_0x4c;
        int32_t window[4];
        float windowDelta[2];
        int32_t winDeltaPosX; // round(pos X * windowDelta[0])
        int32_t winDeltaPosY; // round(pos Y * windowDelta[1])
        Trans trans;
        int32_t mask;
        int32_t layerNo;
        int32_t viewScale;
        BOOL hasBottomWidth;
        int32_t yScaleStart; // yScaleStart * 10.0
        int32_t scaledPosY; // posY*yScaleDelta+yScaleStart
        float yScaleDelta; // yScaleDelta * 10.0
        undefined4 field28_0x98;
        undefined4 field29_0x9c;
        undefined4 field30_0xa0;
        undefined4 field31_0xa4;
        undefined4 field32_0xa8;
        undefined4 field33_0xac;
        undefined4 field34_0xb0;
        int32_t id;
        undefined4 field36_0xb8;
        undefined4 field37_0xbc;
        int32_t field38_0xc0; // x?
        int32_t field39_0xc4; // y?
        undefined4 field40_0xc8;
        undefined4 field41_0xcc;
        int32_t positionLink;
        struct BGSin {
            float x;
            float y;
        } sin[3];
        undefined4 field44_0xec;
        int32_t animNo;
        int32_t spriteArrayNum;
        undefined4 field47_0xf8;
        undefined4 field48_0xfc;
    };
    using BGArray = Array<BG>;
	// 0x54
    struct BGArrayEx {
        float posX;
        float posY;
        undefined4 field2_0x8;
        undefined4 field3_0xc;
        undefined4 field4_0x10;
        undefined4 field5_0x14;
        undefined4 field6_0x18;
        int32_t field7_0x1c;
        AnimRCArrayEx* animRCArrayEx;
        BOOL isNewAnim;
        SpriteArrayEx* spriteArrayEx;
        BOOL isNewSprite;
        BGArray* bgArray;
        BGCtrl* bgCtrls;
        int32_t numBgCtrl;
        int32_t bgClearColorRed;
        int32_t bgClearColorGreen;
        int32_t bgClearColorBlue;
        undefined4 field18_0x48;
        undefined4 field19_0x4c;
        undefined4 field20_0x50;
    };

    static const auto BGArrayReadFile      = reinterpret_cast<BGArrayEx * (*)(char* path, char* dir)>(0x409330);
    static const auto BGArrayReadTP        = reinterpret_cast<BGArrayEx * (*)(char* path, char* groupName, SpriteArrayEx * sprArrayEx, AnimRCArrayEx * animRCArrayEx)>(0x409450);
    static const auto BGArrayReadCtrlTP    = reinterpret_cast<BGArrayEx * (*)(TPFile * tpf, char* dir, char* groupName, SpriteArrayEx * sprArrayEx, AnimRCArrayEx * animRCArrayEx)>(0x409580);
    static const auto BGArrayNew           = reinterpret_cast<BGArrayEx * (*)(size_t num, SpriteArrayEx * sprArrayEx)>(0x40a600);
    static const auto BGArrayFree          = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx)>(0x40a660);
    static const auto BGArrayAdd           = reinterpret_cast<int32_t(*)(BGArrayEx * bgArrayEx, int32_t itemNo, BGType bgType, int32_t startX, int32_t startY, float deltaX, float deltaY, Trans trans, int32_t mask, SpriteParam spriteParam)>(0x40a7f0);
    static const auto BGArrayAddAnim       = reinterpret_cast<int32_t(*)(BGArrayEx * bgArrayEx, int32_t itemNo, int32_t startX, int32_t startY, float deltaX, float deltaY, int32_t animNo)>(0x40a950);
    static const auto BGArraySetViewScale  = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, int32_t scale)>(0x40aa40);
    static const auto BGArrayMove          = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, float posX, float posY)>(0x40aa70);
    static const auto BGArrayMoveOffset    = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, float posX, float posY, int offsetX, int offsetY)>(0x40aa90);
    static const auto BGArrayDraw          = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx)>(0x40ac50);
    static const auto BGArrayDrawLayer     = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, int32_t layerNo)>(0x40aca0);
    static const auto BGArrayUpdate        = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx)>(0x40ad10);
    static const auto BGArrayReset         = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx)>(0x40b060);
    static const auto BGAccess             = reinterpret_cast<BG * (*)(BGArrayEx * bgArrayEx, int32_t itemNo)>(0x40b140);
    static const auto BGAccessID           = reinterpret_cast<BG * (*)(BGArrayEx * bgArrayEx, int32_t id)>(0x40b160);
    static const auto BGParalSetup         = reinterpret_cast<BOOL(*)(BGArrayEx * bgArrayEx, BG * bg, int32_t scaledTopWidth, int32_t scaledBottomWidth, int32_t yScaleStart, float yScaleDelta, int32_t xTile, BOOL hasBottomWidth)>(0x40b1a0);
    static const auto BGDraw               = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, BG * bg)>(0x40b3a0);
    static const auto BGParalDraw          = reinterpret_cast<void (*)(BGArray * bgArrayEx, BG * bg)>(0x40ba50);
    static const auto BGParalDrawScale     = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, BG * bg, int32_t scaled)>(0x40ba70);
    static const auto BGParalDraw8to16Flat = reinterpret_cast<void (*)(BGArrayEx * bgArrayEx, BG * bg, int32_t scaled)>(0x40be80);
}