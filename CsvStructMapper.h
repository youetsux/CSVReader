#pragma once
#include "CsvReader.h"
#include <DirectXMath.h>
using namespace DirectX;

struct MoveParams {
    float velocity;
    float acceleration;
    float acceleValue;
    float fullAccelerate;
    XMVECTOR forwardVector;
    XMVECTOR moveDirection;
    XMVECTOR newPosition;
};

struct RotationParams {
    float moveRotateX;
    float fastRotateX;
};

struct JumpParams {
    float gravity;
    bool isOnGround;
    float jumpSpeed;
    float lowerLimit;
    float upperLimit;
};

struct KnockBackParams {
    float colliderSize;
    XMFLOAT3 direction;
    XMFLOAT3 velocity;
    float power;
    float decelerationRate;
    float endThreshold;
};

struct InvincibilityParams {
    int time;
    bool active;
    int value;
};

struct ShadowParams {
    int handle;
    float height;
    float correction;
    struct Transform {
        XMFLOAT3 position;
        XMFLOAT3 rotation;
        XMFLOAT3 scale;
    } transform;
    void* ground;
};

class CsvStructMapper {
public:
    static void Map(MoveParams& p, CsvReader& csv);
    static void Map(RotationParams& p, CsvReader& csv);
    static void Map(JumpParams& p, CsvReader& csv);
    static void Map(KnockBackParams& p, CsvReader& csv);
    static void Map(InvincibilityParams& p, CsvReader& csv);
    static void Map(ShadowParams& p, CsvReader& csv);
};