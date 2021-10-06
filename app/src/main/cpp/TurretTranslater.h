//
// Created by akasu on 2021/10/06.
//

#ifndef TURRETTRANSLATER_H
#define TURRETTRANSLATER_H

#include "TurretDecorator.h"
#include "GameDefine.h"

namespace Shooting2D
{
    class CTurretTranslater : public CTurretDecorator
    {
    protected:
        MyFloat m_MoveX;
        MyFloat m_MoveY;

    public:
        explicit CTurretTranslater(MyFloat mx, MyFloat my)
            : CTurretDecorator()
            , m_MoveX(mx)
            , m_MoveY(my)
        {
        }

        virtual ~CTurretTranslater() override
        {
        }

        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            MyS32 result = CTurretDecorator::Update(px, py);
            // 発射したら移動実行
            if (result == k_Success)
            {
                MyFloat ox = GetOffsetX();
                MyFloat oy = GetOffsetY();
                SetOffset(ox + m_MoveX, oy + m_MoveY);
            }
            return result;
        }
    };
}

#endif //TURRETTRANSLATER_H
