/******************************************************************************/
/*! @file       Animator.cpp
    @brief      アニメータークラス実装ファイル
*******************************************************************************/

#include "Animator.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
    @param[in]      list    管理するアニメーションリストポインタ
*******************************************************************************/
CAnimator::CAnimator(AnimationListPtr list)
    : m_AnimationList(list)
    , m_CurrentAnimationNo(0)
    , m_CurrentFrame(0)
    , m_Wait(0)
    , m_CurrentAnimation()
    , m_CurrentImage(0)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CAnimator::~CAnimator()
{
}

/******************************************************************************/
/*! アニメーションの変更
    @param[in]      no       変更する番号
    @param[in]      bSame    同一上書き再生フラグ
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CAnimator::Change(MyS32 no, MyBool bSame)
{
    // 同一アニメーションは無視
    if (m_CurrentAnimationNo == no && !bSame)
    {
        return k_Success;
    }

    // 実行中アニメーションフレームの初期化
    m_CurrentAnimationNo = no;
    m_CurrentFrame       =  0;
    m_Wait               =  0;
    // アニメーション中の画像を格納
    m_CurrentAnimation = m_AnimationList->GetAnimation(no);
    m_CurrentImage     = m_CurrentAnimation->GetFrame(0).image;
    return k_Success;
}

/******************************************************************************/
/*! アニメーションの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
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
    return k_Success;
}