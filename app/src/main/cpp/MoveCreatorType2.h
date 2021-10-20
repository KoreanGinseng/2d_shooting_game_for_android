//
// Created by akasu on 2021/10/13.
//

#ifndef MOVECREATORTYPE2_H
#define MOVECREATORTYPE2_H

#include "MoveCreatorType1.h"
#include "MoveSideReflect.h"

namespace Shooting2D
{
    class CMoveCreatorType2 : public CMoveCreatorType1
    {
    protected:

        MyFloat m_ReflectLeft;
        MyFloat m_ReflectRight;

    public:

        explicit CMoveCreatorType2(MyFloat sx, MyFloat sy, MyFloat rl, MyFloat rr)
            : CMoveCreatorType1(sx, sy)
            , m_ReflectLeft(rl)
            , m_ReflectRight(rr)
        {
        }

        virtual ~CMoveCreatorType2() override = default;

        virtual MovePtr Create() override
        {
            return std::make_shared<CMoveSideReflect>(m_SpeedX, m_SpeedY, m_ReflectLeft, m_ReflectRight);
        }
    };
}

#endif //MOVECREATORTYPE2_H
