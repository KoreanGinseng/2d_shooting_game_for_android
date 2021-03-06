/******************************************************************************/
/*! @file       GameObject.cpp
    @brief      ゲームオブジェクト基底クラス実装ファイル
*******************************************************************************/
#include "GameObject.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CGameObject::CGameObject()
    : m_bShow(false)
    , m_PosX(0.0f)
    , m_PosY(0.0f)
    , m_Width(0)
    , m_Height(0)
    , m_Radius(0.0f)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CGameObject::~CGameObject()
{
}

/******************************************************************************/
/*! ゲームオブジェクトの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameObject::Update()
{
    return k_Success;
}

/******************************************************************************/
/*! ゲームオブジェクトの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameObject::Draw()
{
    return k_Success;
}