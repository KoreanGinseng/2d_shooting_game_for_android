//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETDECORATOR_H
#define TURRETDECORATOR_H

#include "Turret.h"

namespace Shooting2D
{
    class CTurretDecorator : public ITurret
    {
    protected:
        // 砲台を用意
        TurretPtr m_Turret;
    public:

        CTurretDecorator()
            : m_Turret()
        {
        }

        virtual ~CTurretDecorator() override
        {
        }

        template < typename T, typename... Types >
        std::shared_ptr<T> SetTurret(Types&&... _Args)
        {
            auto result = std::make_shared<T>(_Args...);
            SetTurret(result);
            return result;
        }

        virtual MyVoid SetTurret(TurretPtr obj)
        {
            m_Turret = obj;
        }

        virtual MyS32 Initialize() override
        {
            return m_Turret->Initialize();
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            return m_Turret->Update(px, py);
        }

        MyFloat GetOffsetX() const noexcept override
        {
            return m_Turret->GetOffsetX();
        }

        MyFloat GetOffsetY() const noexcept override
        {
            return m_Turret->GetOffsetY();
        }

        MyFloat GetSpeedX() const noexcept override
        {
            return m_Turret->GetSpeedX();
        }

        MyFloat GetSpeedY() const noexcept override
        {
            return m_Turret->GetSpeedY();
        }

        MyVoid SetOffset(MyFloat sx, MyFloat sy) override
        {
            m_Turret->SetOffset(sx, sy);
        }

        MyVoid SetSpeed(MyFloat sx, MyFloat sy) override
        {
            m_Turret->SetSpeed(sx, sy);
        }

        MyBool IsFire() const noexcept override
        {
            return m_Turret->IsFire();
        }
    };
}

#endif //TURRETDECORATOR_H
