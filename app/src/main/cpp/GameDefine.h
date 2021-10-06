/******************************************************************************/
/*! @file       GameDefine.h
    @brief      ゲームで使用する定数値の定義ファイル
*******************************************************************************/
#ifndef GAMEDEFINE_H
#define GAMEDEFINE_H

#include "Common.h"
#include <cmath>

namespace Shooting2D
{
    /*! 共通定義 */
    constexpr MyS32   k_SceneOffsetX    =    0; /*!< 画面の左端 */
    constexpr MyS32   k_SceneOffsetY    =    0; /*!< 画面の上端 */
    constexpr MyS32   k_SceneWidth      =  540; /*!< 画面の横幅 */
    constexpr MyS32   k_SceneHeight     =  960; /*!< 画面の立幅 */
    constexpr MyS32   k_ColorBitNum     =   16; /*!< 使用色ビット */

    /*! プレイヤー定義 */
    constexpr MyS32   k_PlayerBulletWait    = 10;
    constexpr MyFloat k_PlayerBulletSpeed   = 1.0f;
    constexpr MyS32   k_PlayerBulletOffsetY = 50;
    constexpr MyS32   k_PlayerDrawOffsetX   =  5;
    constexpr MyS32   k_PlayerDrawOffsetY   = 40;

    constexpr MyS32   k_BulletDrawOffsetX = 3;
    constexpr MyS32   k_BulletDrawOffsetY = 3;

    /*! 背景定義 */
    constexpr MyFloat k_ScrollSpeed     = 5.0f; /*!< 背景スクロールスピード */

}

/*! ラジアン角との相互変換 */
#define ToRadian(x) (x / 180.0f * DX_PI)
#define ToDegree(x) (x / DX_PI * 180.0f)

#endif //GAMEDEFINE_H
