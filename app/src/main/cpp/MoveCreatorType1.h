//
// Created by akasu on 2021/10/13.
//

#ifndef MOVECREATORTYPE1_H
#define MOVECREATORTYPE1_H

#include "MoveCreator.h"
#include "MoveSimple.h"

namespace Shooting2D
{
    class CMoveCreatorType1 : public IMoveCreator
    {
    protected:
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

    public:

        explicit CMoveCreatorType1(MyFloat sx, MyFloat sy)
            : m_SpeedX(sx)
            , m_SpeedY(sy)
        {
        }

        virtual ~CMoveCreatorType1() override = default;

        virtual MovePtr Create() override
        {
            return std::make_shared<CMoveSimple>(m_SpeedX, m_SpeedY);
        }
    };
}

#endif //MOVECREATORTYPE1_H
