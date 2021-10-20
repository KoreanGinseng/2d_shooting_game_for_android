//
// Created by akasu on 2021/10/13.
//

#ifndef MOVESIMPLE_H
#define MOVESIMPLE_H

#include "Move.h"

namespace Shooting2D
{
    class CMoveSimple : public IMove
    {
    protected:

        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

    public:

        explicit CMoveSimple(MyFloat sx, MyFloat sy);

        virtual ~CMoveSimple() override;

        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;

        virtual const MyFloat GetSpeedX() const noexcept override;

        virtual const MyFloat GetSpeedY() const noexcept override;
    };
}

#endif //MOVESIMPLE_H
