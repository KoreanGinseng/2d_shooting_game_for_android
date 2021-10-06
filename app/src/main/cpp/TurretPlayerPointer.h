//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETPLAYERPOINTER_H
#define TURRETPLAYERPOINTER_H

#include "TurretDecorator.h"
#include "GameDefine.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class CTurretPlayerPointer : public CTurretDecorator
    {
    protected:
        MyFloat m_PosX;
        MyFloat m_PosY;
    public:

        CTurretPlayerPointer()
            : CTurretDecorator()
            , m_PosX(0.0f)
            , m_PosY(0.0f)
        {
        }

        virtual ~CTurretPlayerPointer() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            if (IsFire())
            {
                // ターゲットとするプレイヤーの取得
                auto& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
                m_PosX = player.GetPosX();
                m_PosY = player.GetPosY();
            }
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETPLAYERPOINTER_H
