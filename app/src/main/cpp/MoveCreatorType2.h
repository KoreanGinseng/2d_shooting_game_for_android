/******************************************************************************/
/*! @file       MoveCreatorType2.h
    @brief      移動生成クラス定義ファイル
*******************************************************************************/

#ifndef MOVECREATORTYPE2_H
#define MOVECREATORTYPE2_H

#include "MoveCreatorType1.h"
#include "MoveSideReflect.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveCreatorType2
        @brief  移動生成クラス
    *******************************************************************************/
    class CMoveCreatorType2 : public CMoveCreatorType1
    {
    protected:

        /*! 反射座標LR */
        MyFloat m_ReflectLeft;
        MyFloat m_ReflectRight;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
            @param[in]  rl     反射座標L
            @param[in]  rr     反射座標R
        *******************************************************************************/
        explicit CMoveCreatorType2(MyFloat sx, MyFloat sy, MyFloat rl, MyFloat rr)
            : CMoveCreatorType1(sx, sy)
            , m_ReflectLeft(rl)
            , m_ReflectRight(rr)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveCreatorType2() override = default;

        /******************************************************************************/
        /*! 移動の生成
            @return         生成された移動クラス
        *******************************************************************************/
        virtual MovePtr Create() override
        {
            return std::make_shared<CMoveSideReflect>(m_SpeedX, m_SpeedY, m_ReflectLeft, m_ReflectRight);
        }
    };
}

#endif //MOVECREATORTYPE2_H
