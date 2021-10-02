/******************************************************************************/
/*! @file       AnimationList.h
    @brief      アニメーションリストクラス定義ファイル
*******************************************************************************/

#ifndef ANIMATIONLIST_H
#define ANIMATIONLIST_H

#include "Animation.h"

namespace Shooting2D
{
    /*! アニメーター生成用前方定義 */
    class CAnimator;
    using AnimatorPtr = std::shared_ptr<CAnimator>;

    /******************************************************************************/
    /*! @class CAnimationList
        @brief  アニメーションリストクラス
    *******************************************************************************/
    class CAnimationList : public std::enable_shared_from_this<CAnimationList>
    {
    protected:

        /*! アニメーション */
        using AnimationArray = std::vector<AnimationPtr>;
        AnimationArray m_AnimationArray;

    public:

        /******************************************************************************/
        /*! コンストラクタ
         *  [in]
        *******************************************************************************/
        explicit CAnimationList(MyS32 count);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CAnimationList();

        AnimatorPtr CreateAnimator();

        MyS32 Release();

        AnimationPtr GetAnimation(MyS32 n) const noexcept;

        size_t GetAnimationCount() const noexcept;

    };

    /*! ポインタ置き換え */
    using AnimationListPtr = std::shared_ptr<CAnimationList>;
}

#endif //ANIMATIONLIST_H
