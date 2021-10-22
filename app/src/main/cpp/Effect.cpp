/******************************************************************************/
/*! @file       Effect.cpp
    @brief      エフェクトクラス実装ファイル
*******************************************************************************/

#include "Effect.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      px       再生する座標X
    @param[in]      py       再生する座標Y
    @param[in]      anims    再生するアニメーション
*******************************************************************************/
CEffect::CEffect(MyFloat px, MyFloat py, AnimationListPtr anims)
    : CGameObject()
    , m_Animator()
{
    // アニメーション実行クラス生成
    m_Animator = anims->CreateAnimator();
    m_Animator->Change(0, true);

    // 初期情報設定
    m_bShow = true;
    m_PosX = px;
    m_PosY = py;
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CEffect::~CEffect()
{
}

/******************************************************************************/
/*! 更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEffect::Update()
{
    // 非表示のため動作なし
    if (!m_bShow) { return k_Success; }
    // アニメーション更新
    m_Animator->Update();
    // アニメーションの終了で非表示
    if (m_Animator->IsAnimationEnd())
    {
        m_bShow = false;
    }
    return k_Success;
}

/******************************************************************************/
/*! 描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CEffect::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }
    DxLib::DrawRotaGraph(k_SceneOffsetX + m_PosX, k_SceneOffsetY + m_PosY,
            1.0f, 0.0f, m_Animator->GetCurrentImage(), true);
    return k_Success;
}
