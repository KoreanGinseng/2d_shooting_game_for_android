//
// Created by akasu on 2021/10/05.
//

#ifndef TURRET_H
#define TURRET_H

#include <algorithm>
#include "Bullet.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    class ITurret : public std::enable_shared_from_this<ITurret>
    {
    public:

        virtual ~ITurret() = default;

        virtual MyS32 Initialize() = 0;

        virtual MyS32 Update(MyFloat px, MyFloat py) = 0;

        template < typename T, typename... Types >
        std::shared_ptr<T> Decorate(Types&&... _Args)
        {
            auto result = std::make_shared<T>(_Args...);
            result->SetTurret(shared_from_this());
            return result;
        }

        virtual MyFloat GetOffsetX() const noexcept = 0;

        virtual MyFloat GetOffsetY() const noexcept = 0;

        virtual MyFloat GetSpeedX() const noexcept = 0;

        virtual MyFloat GetSpeedY() const noexcept = 0;

        virtual MyVoid SetOffset(MyFloat sx, MyFloat sy) = 0;

        virtual MyVoid SetSpeed(MyFloat sx, MyFloat sy) = 0;

        virtual MyBool IsFire() const noexcept = 0;
    };
    using TurretPtr   = std::shared_ptr<ITurret>;
    using TurretArray = std::vector<TurretPtr>;
}

#endif //TURRET_H
