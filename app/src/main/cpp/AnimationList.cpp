/******************************************************************************/
/*! @file       AnimationList.cpp
    @brief      アニメーションリスストクラス実装クラス
*******************************************************************************/

#include "AnimationList.h"
#include "Animator.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CAnimationList::CAnimationList(MyS32 count)
    : enable_shared_from_this()
    , m_AnimationArray(count)
{
    for (MyS32 i = 0; i < count; i++)
    {
        m_AnimationArray[i] = std::make_shared<CAnimation>();
    }
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CAnimationList::~CAnimationList()
{
    MyS32 result = Release();
    if (result != k_Success)
    {
        MyLOGD("%ld : animationList release failure\n", result);
    }
}

/******************************************************************************/
/*! アニメーターの生成
    @return         生成されたアニメーターポインタ
*******************************************************************************/
AnimatorPtr CAnimationList::CreateAnimator()
{
    return std::make_shared<CAnimator>(shared_from_this());
}

/******************************************************************************/
/*! 解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CAnimationList::Release()
{
    m_AnimationArray.clear();
    return k_Success;
}