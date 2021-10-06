/******************************************************************************/
/*! @file       GameDefine.h
    @brief      ゲームで使用する定数値の定義ファイル
*******************************************************************************/
#ifndef GAMEDEFINE_H
#define GAMEDEFINE_H

#include "Common.h"

namespace Shooting2D
{
    /*! 共通定義 */
    constexpr MyS32   k_SceneOffsetX    =    0; /*!< 画面の左端 */
    constexpr MyS32   k_SceneOffsetY    =    0; /*!< 画面の上端 */
    constexpr MyS32   k_SceneWidth      =  540; /*!< 画面の横幅 */
    constexpr MyS32   k_SceneHeight     =  960; /*!< 画面の立幅 */
    constexpr MyS32   k_ColorBitNum     =   16; /*!< 使用色ビット */

    /*! プレイヤー定義 */
    constexpr MyS32   k_PlayerBulletWait = 10;
    constexpr MyFloat k_PlayerBulletSpeed = 1.0f;

    /*! 背景定義 */
    constexpr MyFloat k_ScrollSpeed     = 5.0f; /*!< 背景スクロールスピード */

}

#endif //GAMEDEFINE_H
