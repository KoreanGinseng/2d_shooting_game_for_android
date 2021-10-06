//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETCREATOR_H
#define TURRETCREATOR_H

#include "Turret.h"

namespace Shooting2D
{
    class ITurretCreator
    {
    public:
        virtual ~ITurretCreator() = default;

        virtual TurretPtr Create() = 0;
    };
    using TurretCreatorPtr = std::shared_ptr<ITurretCreator>;
}

#endif //TURRETCREATOR_H
