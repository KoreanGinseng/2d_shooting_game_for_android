/******************************************************************************/
/*! @file       MoveCenterReturn.h
    @brief      移動クラス定義ファイル
*******************************************************************************/

#ifndef MOVECENTERRETURN_H
#define MOVECENTERRETURN_H

#include "MoveSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveCenterReturn
        @brief  移動クラス
    *******************************************************************************/
    class CMoveCenterReturn : public CMoveSimple
    {
    protected:

        /*! 折り返しフラグ */
        MyBool m_bTurn;

        /*! 折り返し速度X */
        MyFloat m_TurnSpeedX;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  tsx    折り返し移動速度X
        *******************************************************************************/
        explicit CMoveCenterReturn(MyFloat sx, MyFloat sy, MyFloat tsx);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveCenterReturn() = default;

        /******************************************************************************/
        /*! 更新
            @param[in,out]  px    移動させる座標X
            @param[in,out]  py    移動させる座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat& px, MyFloat& py) override;
    };
}

#endif //MOVECENTERRETURN_H
