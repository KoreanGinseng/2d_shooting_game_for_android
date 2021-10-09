//
// Created by akasu on 2021/10/09.
//

#include "Effect.h"

using namespace Shooting2D;

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

CEffect::~CEffect()
{
}

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

MyS32 CEffect::Draw()
{
    // 非表示のため描画なし
    if (!m_bShow) { return k_Success; }
    DxLib::DrawRotaGraph(k_SceneOffsetX + m_PosX, k_SceneOffsetY + m_PosY,
            1.0f, 0.0f, m_Animator->GetCurrentImage(), true);
    return k_Success;
}
