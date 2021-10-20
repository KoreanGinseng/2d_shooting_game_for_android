//
// Created by akasu on 2021/10/13.
//

#include <DxLib.h>
#include "Button.h"

using namespace Shooting2D;

CButton::CButton(MyFloat l, MyFloat t, MyFloat r, MyFloat b)
    : m_Top(t)
    , m_Bottom(b)
    , m_Left(l)
    , m_Right(r)
    , m_bHold(false)
    , m_PrevX(-1)
    , m_PrevY(-1)
{
}

CButton::~CButton()
{
}

MyBool CButton::IsPress() noexcept
{
    MyS32 touchNum = DxLib::GetTouchInputNum();
    if (touchNum <= 0) { return false; }
    MyInt posX = 0, posY = 0;
    MyS32 result = DxLib::GetTouchInput(touchNum - 1, &posX, &posY, nullptr, nullptr);
    if (result == -1) { return false; }
    m_PrevX = posX; m_PrevY = posY;
    return (m_Left <= posX && m_Top <= posY && m_Right >= posX && m_Bottom >= posY);
}

MyBool CButton::IsPull() noexcept
{
    if (IsPress())
    {
        m_bHold = true;
    }
    else if (m_bHold)
    {
        m_bHold = false;
        return (m_Left <= m_PrevX && m_Top <= m_PrevY && m_Right >= m_PrevX && m_Bottom >= m_PrevY);
    }
    return false;
}

MyFloat CButton::GetPosX() const noexcept
{
    return m_Left;
}

MyFloat CButton::GetPosY() const noexcept
{
    return m_Top;
}

MyFloat CButton::GetWidth() const noexcept
{
    return m_Right - m_Left;
}

MyFloat CButton::GetHeight() const noexcept
{
    return m_Bottom - m_Top;
}

MyFloat CButton::GetLeft() const noexcept
{
    return m_Left;
}

MyFloat CButton::GetTop() const noexcept
{
    return m_Top;
}

MyFloat CButton::GetRight() const noexcept
{
    return m_Right;
}

MyFloat CButton::GetBottom() const noexcept
{
    return m_Bottom;
}