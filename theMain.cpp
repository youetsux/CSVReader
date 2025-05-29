#include <iostream>
#include "CsvReader.h"
#include "CsvStructMapper.h"

    int main() {
        CsvReader csv;
        csv.Load("datas.csv");

        // MoveParams
        if (csv.GetParamLine("MoveParams")) {
            MoveParams move;
            CsvStructMapper::Map(move, csv);
            std::cout << "[MoveParams]\n";
            std::cout << "velocity: " << move.velocity << "\n";
            std::cout << "acceleration: " << move.acceleration << "\n";
            std::cout << "acceleValue: " << move.acceleValue << "\n";
            std::cout << "fullAccelerate: " << move.fullAccelerate << "\n";
            XMFLOAT4 fv;
            XMStoreFloat4(&fv, move.forwardVector);
            std::cout << "forwardVector: (" << fv.x << ", " << fv.y << ", " << fv.z << ", " << fv.w << ")\n";
        }

        // RotationParams
        if (csv.GetParamLine("RotationParams")) {
            RotationParams rot;
            CsvStructMapper::Map(rot, csv);
            std::cout << "\n[RotationParams]\n";
            std::cout << "moveRotateX: " << rot.moveRotateX << "\n";
            std::cout << "fastRotateX: " << rot.fastRotateX << "\n";
        }

        // JumpParams
        if (csv.GetParamLine("JumpParams")) {
            JumpParams jump;
            CsvStructMapper::Map(jump, csv);
            std::cout << "\n[JumpParams]\n";
            std::cout << "gravity: " << jump.gravity << "\n";
            std::cout << "isOnGround: " << jump.isOnGround << "\n";
            std::cout << "jumpSpeed: " << jump.jumpSpeed << "\n";
            std::cout << "lowerLimit: " << jump.lowerLimit << "\n";
            std::cout << "upperLimit: " << jump.upperLimit << "\n";
        }

        // KnockBackParams
        if (csv.GetParamLine("KnockBackParams")) {
            KnockBackParams knock;
            CsvStructMapper::Map(knock, csv);
            std::cout << "\n[KnockBackParams]\n";
            std::cout << "colliderSize: " << knock.colliderSize << "\n";
            std::cout << "direction: (" << knock.direction.x << ", " << knock.direction.y << ", " << knock.direction.z << ")\n";
            std::cout << "velocity: (" << knock.velocity.x << ", " << knock.velocity.y << ", " << knock.velocity.z << ")\n";
            std::cout << "power: " << knock.power << "\n";
            std::cout << "decelerationRate: " << knock.decelerationRate << "\n";
            std::cout << "endThreshold: " << knock.endThreshold << "\n";
        }

        // InvincibilityParams
        if (csv.GetParamLine("InvincibilityParams")) {
            InvincibilityParams inv;
            CsvStructMapper::Map(inv, csv);
            std::cout << "\n[InvincibilityParams]\n";
            std::cout << "time: " << inv.time << "\n";
            std::cout << "active: " << inv.active << "\n";
            std::cout << "value: " << inv.value << "\n";
        }

        // ShadowParams
        if (csv.GetParamLine("ShadowParams")) {
            ShadowParams shadow;
            CsvStructMapper::Map(shadow, csv);
            std::cout << "\n[ShadowParams]\n";
            std::cout << "handle: " << shadow.handle << "\n";
            std::cout << "height: " << shadow.height << "\n";
            std::cout << "correction: " << shadow.correction << "\n";
            std::cout << "transform.position: (" << shadow.transform.position.x << ", " << shadow.transform.position.y << ", " << shadow.transform.position.z << ")\n";
            std::cout << "transform.rotation: (" << shadow.transform.rotation.x << ", " << shadow.transform.rotation.y << ", " << shadow.transform.rotation.z << ")\n";
            std::cout << "transform.scale: (" << shadow.transform.scale.x << ", " << shadow.transform.scale.y << ", " << shadow.transform.scale.z << ")\n";
        }

        return 0;
    }
