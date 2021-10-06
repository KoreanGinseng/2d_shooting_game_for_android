//
// Created by akasu on 2021/10/05.
//

#include "TurretSimple.h"
#include "GameDefine.h"
#include <DxLib.h>

using namespace Shooting2D;

CTurretSimple::CTurretSimple(RKMyString list, MyFloat offx,
                             MyFloat offy, MyFloat sx,
                             MyFloat sy, MyS32 w, MyInt img)
    : m_listName(list)
    , m_OffsetX(offx)
    , m_OffsetY(offy)
    , m_SpeedX(sx)
    , m_SpeedY(sy)
    , m_Interval(w)
    , m_Wait(0)
    , m_ImageWidth(0)
    , m_ImageHeight(0)
    , m_BulletImage(img)
{
    MyInt iw, ih;
    DxLib::GetGraphSize(m_BulletImage, &iw, &ih);
    m_ImageWidth = iw; m_ImageHeight = ih;
}

CTurretSimple::~CTurretSimple()
{
}

MyS32 CTurretSimple::Update(MyFloat px, MyFloat py)
{
    // ウェイトの減少
    m_Wait--;
    // ウェイトがある場合待機
    if (m_Wait > 0)
    {
        return k_Success;
    }
    // 次の発射までのウェイトを設定
    m_Wait = m_Interval;
    // 弾を発射
    auto& list = CSingletonBlackboard<BulletList>::GetInstance().Get<BulletList>(m_listName);
    auto blt = std::make_shared<CBullet>();
    blt->Initialize(px + m_OffsetX, py + m_OffsetY, m_SpeedX, m_SpeedY, m_ImageWidth, m_ImageHeight, m_BulletImage);
    list.push_back(blt);
    return k_Success;
}

MyFloat CTurretSimple::GetOffsetX() const noexcept
{
    return m_OffsetX;
}

MyFloat CTurretSimple::GetOffsetY() const noexcept
{
    return m_OffsetY;
}

MyFloat CTurretSimple::GetSpeedX() const noexcept
{
    return m_SpeedX;
}

MyFloat CTurretSimple::GetSpeedY() const noexcept
{
    return m_SpeedY;
}

MyVoid CTurretSimple::SetOffset(MyFloat sx, MyFloat sy)
{
    m_OffsetX = sx;
    m_OffsetY = sy;
}

MyVoid CTurretSimple::SetSpeed(MyFloat sx, MyFloat sy)
{
    m_SpeedX = sx;
    m_SpeedY = sy;
}

MyBool CTurretSimple::IsFire() const noexcept
{
    return m_Wait <= 1;
}