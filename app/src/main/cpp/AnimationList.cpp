//
// Created by akasu on 2021/10/02.
//

#include "AnimationList.h"
#include "Animator.h"

using namespace Shooting2D;

CAnimationList::CAnimationList(MyS32 count)
    : enable_shared_from_this()
    , m_AnimationArray(count)
{
    for (MyS32 i = 0; i < count; i++)
    {
        m_AnimationArray[i] = std::make_shared<CAnimation>();
    }
}

CAnimationList::~CAnimationList()
{
    MyS32 result = Release();
    if (result != k_Success)
    {
        MyLOGD("%d : animationList release failure\n", result);
    }
}

AnimatorPtr CAnimationList::CreateAnimator()
{
    return std::make_shared<CAnimator>(shared_from_this());
}

MyS32 CAnimationList::Release()
{
    m_AnimationArray.clear();
    return k_Success;
}

AnimationPtr CAnimationList::GetAnimation(MyS32 n) const noexcept
{
    if (n >= m_AnimationArray.size()) { return nullptr; }
    return m_AnimationArray[n];
}

size_t CAnimationList::GetAnimationCount() const noexcept
{
    return m_AnimationArray.size();
}