//
// Created by akasu on 2021/10/02.
//

#include "Bullet.h"
#include <DxLib.h>

using namespace Shooting2D;

CBullet::CBullet()
    : CGameObject()
    , m_SpeedX(0.0f)
    , m_SpeedY(0.0f)
    , m_Image(0)
{
}

CBullet::~CBullet()
{
}

MyS32 CBullet::Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img)
{
    m_bShow  = true;
    m_PosX   = px;
    m_PosY   = py;
    m_SpeedX = sx;
    m_SpeedY = sy;
    m_Width  = iw;
    m_Height = ih;
    m_Image  = img;
    return k_Success;
}

MyS32 CBullet::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }
    // 速度で等速移動
    m_PosX += m_SpeedX;
    m_PosY += m_SpeedY;
    // 画面外で消去
    if (m_PosX < -m_Width || m_PosY < -m_Height ||
    m_PosX > k_SceneWidth || m_PosY > k_SceneHeight)
    {
        m_bShow = false;
    }
    return k_Success;
}

MyS32 CBullet::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }

    DxLib::DrawGraph(k_SceneOffsetX + m_PosX, k_SceneOffsetY + m_PosY, m_Image, true);

    return k_Success;
}
