//
// Created by akasu on 2021/10/02.
//

#include "Animator.h"

using namespace Shooting2D;

CAnimator::CAnimator(AnimationListPtr list)
    : m_AnimationList(list)
    , m_CurrentAnimationNo(0)
    , m_CurrentFrame(0)
    , m_Wait(0)
    , m_CurrentAnimation()
    , m_CurrentImage(0)
{
}

CAnimator::~CAnimator()
{
}

MyS32 CAnimator::Change(MyS32 no, MyBool bSame)
{
    // 同一アニメーションは無視
    if (m_CurrentAnimationNo == no && !bSame)
    {
        return k_Success;
    }

    // 実行中アニメーションフレームの初期化
    m_CurrentAnimationNo = no;
    m_CurrentFrame       = 0;
    m_Wait               = 0;
    // アニメーション中の画像を格納
    m_CurrentAnimation = m_AnimationList->GetAnimation(no);
    m_CurrentImage     = m_CurrentAnimation->GetFrame(0).image;
    return k_Success;
}

MyS32 CAnimator::Update()
{
    // アニメーションを進める
    m_Wait++;
    if (m_CurrentFrame < m_CurrentAnimation->GetFrameCount())
    {
        // フレーム情報を取り出し
        auto frame = m_CurrentAnimation->GetFrame(m_CurrentFrame);
        m_CurrentImage = frame.image;

        // 既定フレームの経過で次のフレームへ
        if (m_Wait >= frame.frame)
        {
            m_Wait = 0;
            m_CurrentFrame++;
        }
    }
}

MyInt CAnimator::GetCurrentImage() const noexcept
{
    return m_CurrentImage;
}