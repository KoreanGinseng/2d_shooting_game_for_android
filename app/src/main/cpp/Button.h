/******************************************************************************/
/*! @file       Button.h
    @brief      ボタンクラス定義ファイル
*******************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#include <memory>
#include "Common.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CButton
        @brief  ボタンクラス
    *******************************************************************************/
    class CButton
    {
    private:

        MyFloat m_Top;     /*!< 上 */
        MyFloat m_Bottom;  /*!< 下 */
        MyFloat m_Left;    /*!< 左 */
        MyFloat m_Right;   /*!< 右 */

        MyS32 m_PrevX;     /*!< 最後にタッチした位置X */
        MyS32 m_PrevY;     /*!< 最後にタッチした位置Y */

        MyBool m_bHold;    /*!< 押しているフラグ */

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      l    左
            @param[in]      t    上
            @param[in]      r    右
            @param[in]      b    下
        *******************************************************************************/
        explicit CButton(MyFloat l, MyFloat t, MyFloat r, MyFloat b);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CButton();

        /******************************************************************************/
        /*! このフレーム押しているか
            @return         true 押してる, false 押してない
        *******************************************************************************/
        MyBool IsPress() noexcept;

        /******************************************************************************/
        /*! ボタンから離れたか
            @return         true 離れた, false 押してないor押してる
        *******************************************************************************/
        MyBool IsPull() noexcept;

        /******************************************************************************/
        /*! 座標X取得
            @return         座標X
        *******************************************************************************/
        MyFloat GetPosX() const noexcept
        {
            return m_Left;
        }

        /******************************************************************************/
        /*! 座標Y取得
            @return         座標Y
        *******************************************************************************/
        MyFloat GetPosY() const noexcept
        {
            return m_Top;
        }

        /******************************************************************************/
        /*! 幅取得
            @return         幅
        *******************************************************************************/
        MyFloat GetWidth() const noexcept
        {
            return m_Right - m_Left;
        }

        /******************************************************************************/
        /*! 高さ取得
            @return         高さ
        *******************************************************************************/
        MyFloat GetHeight() const noexcept
        {
            return m_Bottom - m_Top;
        }

        /******************************************************************************/
        /*! 上座標取得
            @return         上座標
        *******************************************************************************/
        MyFloat GetTop() const noexcept
        {
            return m_Top;
        }

        /******************************************************************************/
        /*! 下座標取得
            @return         下座標
        *******************************************************************************/
        MyFloat GetBottom() const noexcept
        {
            return m_Bottom;
        }

        /******************************************************************************/
        /*! 左座標取得
            @return         左座標
        *******************************************************************************/
        MyFloat GetLeft() const noexcept
        {
            return m_Left;
        }

        /******************************************************************************/
        /*! 右座標取得
            @return         右座標
        *******************************************************************************/
        MyFloat GetRight() const noexcept
        {
            return m_Right;
        }
    };

    /*! ポインタ置き換え */
    using ButtonPtr = std::shared_ptr<CButton>;
}



#endif //BUTTON_H
