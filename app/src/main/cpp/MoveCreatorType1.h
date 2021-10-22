/******************************************************************************/
/*! @file       MoveCreatorType1.h
    @brief      移動生成クラス定義ファイル
*******************************************************************************/

#ifndef MOVECREATORTYPE1_H
#define MOVECREATORTYPE1_H

#include "MoveCreator.h"
#include "MoveSimple.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CMoveCreatorType1
        @brief  移動生成クラス
    *******************************************************************************/
    class CMoveCreatorType1 : public IMoveCreator
    {
    protected:

        /*! 移動速度 */
        MyFloat m_SpeedX;
        MyFloat m_SpeedY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]  sx     移動速度X
            @param[in]  sy     移動速度Y
        *******************************************************************************/
        explicit CMoveCreatorType1(MyFloat sx, MyFloat sy)
            : m_SpeedX(sx)
            , m_SpeedY(sy)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CMoveCreatorType1() override = default;

        /******************************************************************************/
        /*! 移動の生成
            @return         生成された移動クラス
        *******************************************************************************/
        virtual MovePtr Create() override
        {
            return std::make_shared<CMoveSimple>(m_SpeedX, m_SpeedY);
        }
    };
}

#endif //MOVECREATORTYPE1_H
