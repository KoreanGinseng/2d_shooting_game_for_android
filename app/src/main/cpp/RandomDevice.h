/******************************************************************************/
/*! @file       RandomDevice.h
    @brief      乱数デバイスクラスの定義ファイル
*******************************************************************************/

#ifndef RANDOMDEVICE_H
#define RANDOMDEVICE_H

#include "Random.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! @class CRandomDevice
        @brief  乱数デバイスクラス
    *******************************************************************************/
    class CRandomDevice : public IRandom
    {
    private:

        /*! 乱数デバイス */
        std::random_device m_Device;
        std::mt19937       m_MersenneTwister;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CRandomDevice()
             : m_Device()
             , m_MersenneTwister(m_Device())
        {
        }

        /******************************************************************************/
        /*! 乱数の生成
            @param[in]      low    最低値
            @param[in]      high    最高値
            @return         low ~ highまでのランダムな値
        *******************************************************************************/
        virtual MyS32 Random(MyS32 low, MyS32 high) override
        {
            assert(low < high);
            thread_local std::uniform_int_distribution<int> d(low, high);
            return d(m_MersenneTwister);
        }

        /******************************************************************************/
        /*! シードのリセット
        *******************************************************************************/
        virtual MyVoid ResetSeed() override
        {
            m_MersenneTwister.seed(m_Device());
        }
    };
}

#endif //RANDOMDEVICE_H
