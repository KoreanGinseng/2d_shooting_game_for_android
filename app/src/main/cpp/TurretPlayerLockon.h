//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETPLAYERLOCKON_H
#define TURRETPLAYERLOCKON_H

#include "TurretDecorator.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class CTurretPlayerLockon : public CTurretDecorator
    {
    protected:
        // 弾の移動速度
        MyFloat m_Speed;

    public:
        explicit CTurretPlayerLockon(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        virtual ~CTurretPlayerLockon() override
        {
        }

        MyS32 Update(MyFloat px, MyFloat py) override
        {
            // 発射するフレームのみ
            if (IsFire())
            {
                // ターゲットとするプレイヤーの取得
                auto& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
                // プレイヤー方向に飛ぶように速度を算出
                MyFloat sx = player.GetPosX() - (px + m_Turret->GetOffsetX());
                MyFloat sy = player.GetPosY() - (py + m_Turret->GetOffsetY());
                MyFloat d = sqrt(sx * sx + sy * sy);
                sx /= d;
                sy /= d;
                sx *= m_Speed;
                sy *= m_Speed;
                m_Turret->SetSpeed(sx, sy);
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETPLAYERLOCKON_H
