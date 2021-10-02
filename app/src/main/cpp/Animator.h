//
// Created by akasu on 2021/10/02.
//

#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "AnimationList.h"

namespace Shooting2D
{
    class CAnimator
    {
    protected:

        /*! アニメーションリスト */
        AnimationListPtr m_AnimationList;

        /*! アニメーション実行情報 */
        MyS32 m_CurrentAnimationNo;
        MyS32 m_CurrentFrame;
        MyS32 m_Wait;

        /*! 実行中のアニメーションポインタ */
        AnimationPtr m_CurrentAnimation;

        /*! 現在の画像 */
        MyInt m_CurrentImage;

    public:

        CAnimator(AnimationListPtr list);

        ~CAnimator();

        MyS32 Change(MyS32 no, MyBool bSame);

        MyS32 Update();

        MyInt GetCurrentImage() const noexcept;
    };

    using AnimatorPtr = std::shared_ptr<CAnimator>;
}

#endif //ANIMATOR_H
