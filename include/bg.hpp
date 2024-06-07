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
        undefined4 field17_0x68;
        undefined4 field18_0x6c;
        DrawType drawType;
        int32_t alpha[2];
        int32_t mask;
        int32_t layerNo;
        int32_t viewScale;
        undefined4 field24_0x88;
        undefined4 field25_0x8c;
        undefined4 field26_0x90;
        undefined4 field27_0x94;
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
        undefined4 field38_0xc0;
        undefined4 field39_0xc4;
        undefined4 field40_0xc8;
        undefined4 field41_0xcc;
        int32_t positionLink;
        struct BGSin {
            float x;
            float y;
        } sin[3];
        undefined4 field44_0xec;
        undefined4 field45_0xf0;
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
        undefined4 field7_0x1c;
        AnimArrayEx* animArray;
        BOOL isNewAnim;
        SpriteArrayEx* spriteArray;
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
}