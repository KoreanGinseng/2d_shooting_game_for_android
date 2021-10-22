/******************************************************************************/
/*! @file       GameDefine.h
    @brief      ゲームで使用する定数値の定義ファイル
*******************************************************************************/
#ifndef GAMEDEFINE_H
#define GAMEDEFINE_H

#include "Common.h"
#include <cmath>
#include <algorithm>
#include <DxLib.h>
#include "ServiceLocator.h"
#include "SEController.h"
#include "SceneChanger.h"
#include "SceneChangeFade.h"

namespace Shooting2D
{
    /*! 共通定義 */
    constexpr MyS32   k_SceneOffsetX    =    0; /*!< 画面の左端 */
    constexpr MyS32   k_SceneOffsetY    =    0; /*!< 画面の上端 */
    constexpr MyS32   k_SceneWidth      =  540; /*!< 画面の横幅 */
    constexpr MyS32   k_SceneHeight     =  960; /*!< 画面の立幅 */
    constexpr MyS32   k_ColorBitNum     =   16; /*!< 使用色ビット */

    /*! タイトル画面 */
    constexpr MyS32   k_StartButtonW = 300;
    constexpr MyS32   k_StartButtonH = 150;
    constexpr MyS32   k_StartButtonX = k_SceneOffsetX + (k_SceneWidth - k_StartButtonW) * 0.5f;
    constexpr MyS32   k_StartButtonY = k_SceneOffsetY + k_SceneHeight * 0.5f;
    constexpr MyS32   k_LogoW = 450;
    constexpr MyS32   k_LogoH = 200;
    constexpr MyS32   k_LogoX = k_SceneOffsetX + (k_SceneWidth - k_LogoW) * 0.5f;
    constexpr MyS32   k_LogoY = k_StartButtonY - k_LogoH * 1.05f;

    /*! SE列挙 */
    enum class SEType
    {
        Shot,       /*!< 弾発射の音 */
        Explosion,  /*!< 爆発      */

        Count,      /*!< 列挙定数  */
    };
    /*! SE最大数MyS32アクセス用 */
    constexpr MyS32   k_SECount = ((MyS32)SEType::Count);
    using SEService = CServiceLocator<ISEController<SEType>>;

    /*! 画面遷移用 */
    using SceneChangerService = CServiceLocator<ISceneChanger>;

    /*! エミッターの登録名 */
    constexpr LPMyS8 k_EmitterBoardName[] =
    {
            "Hit",
            "Explosion",
    };

    /*! 画面上ボタン位置定義 */
    constexpr MyS32 k_BtnBullet_1_x1 = k_SceneWidth * 0.75f;
    constexpr MyS32 k_BtnBullet_1_y1 = 100;
    constexpr MyS32 k_BtnBullet_1_x2 = k_SceneWidth * 0.95f;
    constexpr MyS32 k_BtnBullet_1_y2 = k_BtnBullet_1_y1 + 50;

    constexpr MyS32 k_BtnBullet_2_x1 = k_BtnBullet_1_x1;
    constexpr MyS32 k_BtnBullet_2_y1 = 160;
    constexpr MyS32 k_BtnBullet_2_x2 = k_BtnBullet_1_x2;
    constexpr MyS32 k_BtnBullet_2_y2 = k_BtnBullet_2_y1 + 50;

    constexpr MyS32 k_BtnBullet_3_x1 = k_BtnBullet_1_x1;
    constexpr MyS32 k_BtnBullet_3_y1 = 220;
    constexpr MyS32 k_BtnBullet_3_x2 = k_BtnBullet_1_x2;
    constexpr MyS32 k_BtnBullet_3_y2 = k_BtnBullet_3_y1 + 50;

    /*! プレイヤー定義 */
    constexpr MyS32   k_PlayerBulletWait_1  =    5;
    constexpr MyS32   k_PlayerBulletWait_2  =    7;
    constexpr MyS32   k_PlayerBulletWait_3  =   10;
    constexpr MyFloat k_PlayerBulletSpeed   = 5.0f;
    constexpr MyS32   k_PlayerBulletOffsetY =   50;
    constexpr MyS32   k_PlayerDrawOffsetX   =    5;
    constexpr MyS32   k_PlayerDrawOffsetY   =   40;

    constexpr MyS32   k_BulletDrawOffsetX = 3;
    constexpr MyS32   k_BulletDrawOffsetY = 3;

    /*! 背景定義 */
    constexpr MyFloat k_ScrollSpeed     = 1.0f; /*!< 背景スクロールスピード */

}

/*! ラジアン角との相互変換 */
#define ToRadian(x) (x / 180.0f * DX_PI)
#define ToDegree(x) (x / DX_PI * 180.0f)

#endif //GAMEDEFINE_H
