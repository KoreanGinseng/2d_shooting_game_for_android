//
// Created by akasu on 2021/10/13.
//

#ifndef MOVESIDEREFLECT_H
#define MOVESIDEREFLECT_H

#include "MoveSimple.h"

namespace Shooting2D
{
    class CMoveSideReflect : public CMoveSimple
    {
    protected:

        MyFloat m_ReflectLeft;
        MyFloat m_ReflectRight;
        MyBool  m_bReflect;
        MyFloat m_OffsetX;

    public:
        explicit CMoveSideReflect(MyFloat sx, MyFloat sy, MyFloat rl, MyFloat rr);

        virtual ~CMoveSideReflect() override;

        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };
}



#endif //TEST_MOVESIDEREFLECT_H
