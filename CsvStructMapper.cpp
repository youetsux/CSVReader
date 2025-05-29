#include "CsvStructMapper.h"

void CsvStructMapper::Map(MoveParams& p, CsvReader& csv) {
    p.velocity = csv.PopParamFloat();
    p.acceleration = csv.PopParamFloat();
    p.acceleValue = csv.PopParamFloat();
    p.fullAccelerate = csv.PopParamFloat();
    p.forwardVector = XMVectorSet(csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat());
    p.moveDirection = XMVectorSet(csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat());
    p.newPosition = XMVectorSet(csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat());
}

void CsvStructMapper::Map(RotationParams& p, CsvReader& csv) {
    p.moveRotateX = csv.PopParamFloat();
    p.fastRotateX = csv.PopParamFloat();
}

void CsvStructMapper::Map(JumpParams& p, CsvReader& csv) {
    p.gravity = csv.PopParamFloat();
    p.isOnGround = csv.PopParamBool();
    p.jumpSpeed = csv.PopParamFloat();
    p.lowerLimit = csv.PopParamFloat();
    p.upperLimit = csv.PopParamFloat();
}

void CsvStructMapper::Map(KnockBackParams& p, CsvReader& csv) {
    p.colliderSize = csv.PopParamFloat();
    p.direction = { csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat() };
    p.velocity = { csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat() };
    p.power = csv.PopParamFloat();
    p.decelerationRate = csv.PopParamFloat();
    p.endThreshold = csv.PopParamFloat();
}

void CsvStructMapper::Map(InvincibilityParams& p, CsvReader& csv) {
    p.time = csv.PopParamInt();
    p.active = csv.PopParamBool();
    p.value = csv.PopParamInt();
}

void CsvStructMapper::Map(ShadowParams& p, CsvReader& csv) {
    p.handle = csv.PopParamInt();
    p.height = csv.PopParamFloat();
    p.correction = csv.PopParamFloat();
    p.transform.position = { csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat() };
    p.transform.rotation = { csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat() };
    p.transform.scale = { csv.PopParamFloat(), csv.PopParamFloat(), csv.PopParamFloat() };
    p.ground = reinterpret_cast<void*>(static_cast<uintptr_t>(csv.PopParamInt())); // ポインタ再構成（仮）
}