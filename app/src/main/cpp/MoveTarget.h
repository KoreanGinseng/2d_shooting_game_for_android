/******************************************************************************/
/*! @file       MoveTarget.h
    @brief      標的へ向かって移動するクラス定義ファイル
*******************************************************************************/

#ifndef MOVETARGET_H
#define MOVETARGET_H

#include "MoveSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveTarget
        @brief  標的へ向かって移動するクラス
    *******************************************************************************/
    class CMoveTarget : public CMoveSimple
    {
    private:

        /*! ターゲット座標 */
        MyFloat m_TargetX;
        MyFloat m_TargetY;
        /*! 速度 */
        MyFloat m_Speed;
        /*! 設定フラグ */
        MyBool m_bSetSpeed;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  speed     移動速度
            @param[in]  tx        対象座標X
            @param[in]  ty        対象座標Y
        *******************************************************************************/
        explicit CMoveTarget(MyFloat speed, MyFloat tx, MyFloat ty);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveTarget() override = default;

        /******************************************************************************/
        /*! 更新
            @param[in,out]  px    移動させる座標X
            @param[in,out]  py    移動させる座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };

}



#endif //TEST_MOVETARGET_H
