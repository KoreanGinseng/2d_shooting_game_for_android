/******************************************************************************/
/*! @file       MoveCreatorType4.h
    @brief      移動生成クラス定義ファイル
*******************************************************************************/

#ifndef MOVECREATORTYPE4_H
#define MOVECREATORTYPE4_H

#include "MoveCreatorType1.h"
#include "MoveDeadOrAlive.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveCreatorType4
        @brief  移動生成クラス
    *******************************************************************************/
    class CMoveCreatorType4 : public CMoveCreatorType1
    {
    protected:

        /*! 降下ポジションY */
        MyFloat m_StopPosY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  px     降下ポジションY
        *******************************************************************************/
        explicit CMoveCreatorType4(MyFloat sx, MyFloat sy, MyFloat py)
            : CMoveCreatorType1(sx, sy)
            , m_StopPosY(py)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveCreatorType4() override = default;

        /******************************************************************************/
        /*! 移動の生成
            @return         生成された移動クラス
        *******************************************************************************/
        virtual MovePtr Create() override
        {
            return std::make_shared<CMoveDeadOrAlive>(m_SpeedX, m_SpeedY, m_StopPosY);
        }
    };
}

#endif //MOVECREATORTYPE4_H
