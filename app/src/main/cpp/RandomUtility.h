/******************************************************************************/
/*! @file       RandomUtility.h
    @brief      乱数汎用クラス定義ファイル
*******************************************************************************/

#ifndef RANDOMUTILITY_H
#define RANDOMUTILITY_H

#include "Singleton.h"
#include "RandomDevice.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! @class CRandomUtility
        @brief  乱数汎用クラス
    *******************************************************************************/
    class CRandomUtility : public CSingleton<CRandomUtility>
    {
        friend class CSingleton<CRandomUtility>;
    private:
        /*! 乱数デバイス */
        RandomUniquePtr m_Random;

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CRandomUtility()
            : CSingleton()
            , m_Random(std::make_unique<CRandomDevice>())
        {
        }

    public:

        /******************************************************************************/
        /*! 乱数の生成
            @param[in]      high    最高値
            @return         0 ~ highまでのランダムな値
        *******************************************************************************/
        static MyS32 Random(MyS32 high)
        {
            return GetInstance().m_Random->Random(0, high);
        }

        /******************************************************************************/
        /*! 乱数の生成
            @param[in]      low    最低値
            @param[in]      high    最高値
            @return         low ~ highまでのランダムな値
        *******************************************************************************/
        static MyS32 Random(MyS32 low, MyS32 high)
        {
            return GetInstance().m_Random->Random(low, high);
        }

        /******************************************************************************/
        /*! 乱数の生成
            @return         0.0f ~ 1.0fまでのランダムな値
        *******************************************************************************/
        static MyFloat RandomFloat()
        {
            return GetInstance().m_Random->Random(0, 10001) * 0.0001f;
        }
    };
}

#endif //RANDOMUTILITY_H
