//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETARRAY_H
#define TURRETARRAY_H

#include "TurretSimple.h"

namespace Shooting2D
{
    class CTurretArray : public ITurret
    {
    protected:
        /*! 砲台を配列で用意 */
        TurretArray m_TurretArray;

    public:
        CTurretArray();
        virtual ~CTurretArray() override;
        template < typename T, typename... Types >
        std::shared_ptr<T> AddTurret(Types&&... _Args)
        {
            auto result = std::make_shared<T>(_Args...);
            m_TurretArray.push_back(result);
            return result;
        }

        MyS32 Update(MyFloat px, MyFloat py) override;

        MyFloat GetOffsetX() const noexcept override;
        MyFloat GetOffsetY() const noexcept override;
        MyFloat GetSpeedX() const noexcept override;
        MyFloat GetSpeedY() const noexcept override;
        MyVoid SetOffset(MyFloat sx, MyFloat sy) override;
        MyVoid SetSpeed(MyFloat sx, MyFloat sy) override;
        MyBool IsFire() const noexcept override;
    };
}

#endif //TURRETARRAY_H
