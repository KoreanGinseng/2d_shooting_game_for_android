/******************************************************************************/
/*! @file       MoveSideReflect.h
    @brief      移動クラス定義ファイル
*******************************************************************************/

#ifndef MOVESIDEREFLECT_H
#define MOVESIDEREFLECT_H

#include "MoveSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveSideReflect
        @brief  移動クラス
    *******************************************************************************/
    class CMoveSideReflect : public CMoveSimple
    {
    protected:

        /*! 反射座標 */
        MyFloat m_ReflectLeft;
        MyFloat m_ReflectRight;
        /*! 反射フラグ */
        MyBool  m_bReflect;
        /*! オフセット */
        MyFloat m_OffsetX;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  rl     反射座標L
            @param[in]  rr     反射座標R
        *******************************************************************************/
        explicit CMoveSideReflect(MyFloat sx, MyFloat sy, MyFloat rl, MyFloat rr);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveSideReflect() override;

        /******************************************************************************/
        /*! 更新
            @param[in,out]  px    移動させる座標X
            @param[in,out]  py    移動させる座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };
}



#endif //TEST_MOVESIDEREFLECT_H
