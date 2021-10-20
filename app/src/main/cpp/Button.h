//
// Created by akasu on 2021/10/13.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    class CButton
    {
    private:

        MyFloat m_Top;
        MyFloat m_Bottom;
        MyFloat m_Left;
        MyFloat m_Right;

        MyS32 m_PrevX;
        MyS32 m_PrevY;

        MyBool m_bHold;

    public:

        explicit CButton(MyFloat l, MyFloat t, MyFloat r, MyFloat b);

        virtual ~CButton();

        MyBool IsPress() noexcept;

        MyBool IsPull() noexcept;

        MyFloat GetPosX() const noexcept;

        MyFloat GetPosY() const noexcept;

        MyFloat GetWidth() const noexcept;

        MyFloat GetHeight() const noexcept;

        MyFloat GetTop() const noexcept;

        MyFloat GetBottom() const noexcept;

        MyFloat GetLeft() const noexcept;

        MyFloat GetRight() const noexcept;
    };

    using ButtonPtr = std::shared_ptr<CButton>;
}



#endif //BUTTON_H
