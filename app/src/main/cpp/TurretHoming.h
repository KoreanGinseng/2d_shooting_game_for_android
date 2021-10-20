//
// Created by akasu on 2021/10/13.
//

#ifndef TURRETHOMING_H
#define TURRETHOMING_H

#include "TurretSimple.h"

namespace Shooting2D
{
    class CTurretHoming : public CTurretSimple
    {
    protected:

    public:
        using CTurretSimple::CTurretSimple;
        virtual ~CTurretHoming() override = default;
        virtual MyS32 Update(MyFloat px, MyFloat py) override;
    };
}


#endif //TURRETHOMING_H
