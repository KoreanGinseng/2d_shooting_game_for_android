/******************************************************************************/
/*! @file       Animation.h
    @brief      アニメーションクラス定義ファイル
*******************************************************************************/

#ifndef ANIMATION_H
#define ANIMATION_H

#include "Common.h"
#include <memory>
#include <vector>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CAnimation
        @brief  アニメーションクラス
    *******************************************************************************/
    class CAnimation
    {
    protected:
        /******************************************************************************/
        /*! @struct Frame
            @brief  アニメーションフレーム構造体
        *******************************************************************************/
        struct Frame
        {
        public:
            MyS32 offsetX; /*!< オフセット位置X */
            MyS32 offsetY; /*!< オフセット位置Y */
            MyS32 width;   /*!< 横幅 */
            MyS32 height;  /*!< 高さ */

            MyS32 frame;   /*!< フレーム番号 */
            MyInt image;   /*!< 画像ID */
        };

        /*! @brief 配列置き換え */
        using FrameArray = std::vector<Frame>;

        FrameArray m_FrameArray; /*!< アニメーション情報 */

    public:


        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        CAnimation();

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CAnimation();

        /******************************************************************************/
        /*! アニメーションフレームの追加
            @param[in]      ox     オフセット位置X
            @param[in]      oy     オフセット位置Y
            @param[in]      w      横幅
            @param[in]      h      高さ
            @param[in]      f      フレーム番号
            @param[in]      img    画像ID
            @return         this
        *******************************************************************************/
        CAnimation& AddFrame(MyS32 ox, MyS32 oy, MyS32 w, MyS32 h, MyS32 f, MyInt img);

        /******************************************************************************/
        /*! アニメーションの解放
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Release();

        /******************************************************************************/
        /*! フレーム情報の取得
            @param[in]      n    取得するフレーム番号
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        RKMy(Frame) GetFrame(MyS32 n) const noexcept
        {
            return m_FrameArray[n];
        }

        /******************************************************************************/
        /*! フレーム数取得
            @return         フレーム数
        *******************************************************************************/
        size_t GetFrameCount() const noexcept
        {
            return m_FrameArray.size();
        }
    };

    /*! @brief ポインタ置き換え */
    using AnimationPtr = std::shared_ptr<CAnimation>;
}

#endif //ANIMATION_H
