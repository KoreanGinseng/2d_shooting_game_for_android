/******************************************************************************/
/*! @file       MoveDeadOrAlive.h
    @brief      死ぬまで生きてる移動クラス定義ファイル
*******************************************************************************/

#ifndef MOVEDEADORALIVE_H
#define MOVEDEADORALIVE_H

#include "MoveSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveDeadOrAlive
        @brief  移動クラス
    *******************************************************************************/
    class CMoveDeadOrAlive : public CMoveSimple
    {
    private:

        /*! 移動パターンカウンタ */
        MyS32 m_MoveCount;
        MyS32 m_FrameCount;

        /*! 降下ポジションY */
        MyFloat m_StopPosY;

        /*! 移動パターン */
        MovePtr m_Move[2];

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  px     降下ポジションY
        *******************************************************************************/
        explicit CMoveDeadOrAlive(MyFloat sx, MyFloat sy, MyFloat py);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveDeadOrAlive() override = default;

        /******************************************************************************/
        /*! 更新
            @param[in,out]  px    移動させる座標X
            @param[in,out]  py    移動させる座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };
}


#endif MOVEDEADORALIVE_H
