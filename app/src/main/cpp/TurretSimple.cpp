/******************************************************************************/
/*! @file       TurretSimple.cpp
    @brief      シンプルな弾発射処理クラス実装ファイル
*******************************************************************************/


#include "TurretSimple.h"
#include "GameDefine.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      list    登録リスト名
    @param[in]      offx    オフセット位置X
    @param[in]      offy    オフセット位置Y
    @param[in]      sx      弾スピードX
    @param[in]      sy      弾スピードY
    @param[in]      wait    発射間隔
    @param[in]      img     弾画像ID
*******************************************************************************/
CTurretSimple::CTurretSimple(RKMyString list, MyFloat offx,
                             MyFloat offy, MyFloat sx,
                             MyFloat sy, MyS32 wait, MyInt img)
    : m_listName(list)
    , m_OffsetX(offx)
    , m_OffsetY(offy)
    , m_SpeedX(sx)
    , m_SpeedY(sy)
    , m_Interval(wait)
    , m_Wait(0)
    , m_ImageWidth(0)
    , m_ImageHeight(0)
    , m_BulletImage(img)
{
    MyInt iw, ih;
    DxLib::GetGraphSize(m_BulletImage, &iw, &ih);
    m_ImageWidth = iw; m_ImageHeight = ih;
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CTurretSimple::~CTurretSimple()
{
}

/******************************************************************************/
/*! タレットの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CTurretSimple::Initialize()
{
    m_Wait = 0;
    return k_Success;
}

/******************************************************************************/
/*! タレットの更新
    @param[in]      px    対象の座標X
    @param[in]      py    対象の座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CTurretSimple::Update(MyFloat px, MyFloat py)
{
    // ウェイトの減少
    m_Wait--;
    // ウェイトがある場合待機
    if (m_Wait > 0)
    {
        return k_failure;
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