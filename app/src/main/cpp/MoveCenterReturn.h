//
// Created by akasu on 2021/10/20.
//

#ifndef MOVECENTERRETURN_H
#define MOVECENTERRETURN_H

#include "MoveSimple.h"

namespace Shooting2D
{
    class CMoveCenterReturn : public CMoveSimple
    {
    protected:

        MyBool m_bTurn;
        MyFloat m_TurnSpeedX;

    public:
        explicit CMoveCenterReturn(MyFloat sx, MyFloat sy, MyFloat tsx);

        virtual ~CMoveCenterReturn() = default;

        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };
}

#endif //MOVECENTERRETURN_H
