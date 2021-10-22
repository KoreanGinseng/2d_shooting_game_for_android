/******************************************************************************/
/*! @file       MoveCreatorType3.h
    @brief      移動生成クラス定義ファイル
*******************************************************************************/

#ifndef MOVECREATORTYPE3_H
#define MOVECREATORTYPE3_H

#include "MoveCreatorType1.h"
#include "MoveCenterReturn.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveCreatorType3
        @brief  移動生成クラス
    *******************************************************************************/
    class CMoveCreatorType3 : public CMoveCreatorType1
    {
    protected:

        /*! 折り返し速度X */
        MyFloat m_TurnSpeedX;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  tsx    折り返し移動速度X
        *******************************************************************************/
        explicit CMoveCreatorType3(MyFloat sx, MyFloat sy, MyFloat tsx)
            : CMoveCreatorType1(sx, sy)
            , m_TurnSpeedX(tsx)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveCreatorType3() override = default;

        /******************************************************************************/
        /*! 移動の生成
            @return         生成された移動クラス
        *******************************************************************************/
        MovePtr Create() override
        {
            return std::make_shared<CMoveCenterReturn>(m_SpeedX, m_SpeedY, m_TurnSpeedX);
        }
    };
}

#endif //MOVECREATORTYPE3_H
