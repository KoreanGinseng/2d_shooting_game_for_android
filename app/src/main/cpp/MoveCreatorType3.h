//
// Created by akasu on 2021/10/20.
//

#ifndef MOVECREATORTYPE3_H
#define MOVECREATORTYPE3_H

#include "MoveCreatorType1.h"
#include "MoveCenterReturn.h"

namespace Shooting2D
{

    class CMoveCreatorType3 : public CMoveCreatorType1
    {
    protected:

        MyFloat m_TurnSpeedX;

    public:
        explicit CMoveCreatorType3(MyFloat sx, MyFloat sy, MyFloat tsx)
            : CMoveCreatorType1(sx, sy)
            , m_TurnSpeedX(tsx)
        {
        }

        virtual ~CMoveCreatorType3() override = default;

        MovePtr Create() override
        {
            return std::make_shared<CMoveCenterReturn>(m_SpeedX, m_SpeedY, m_TurnSpeedX);
        }
    };
}

#endif //MOVECREATORTYPE3_H
