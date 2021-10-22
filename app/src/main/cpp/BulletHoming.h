/******************************************************************************/
/*! @file       BulletHoming.h
    @brief      追跡弾クラス定義ファイル
*******************************************************************************/

#ifndef BULLETHOMING_H
#define BULLETHOMING_H

#include "Bullet.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CBulletHoming
        @brief  追跡弾クラス
    *******************************************************************************/
    class CBulletHoming : public CBullet
    {
    private:

        /*! 追跡対象 */
        GameObjectPtr m_Target;

        /*! 最大速度 */
        MyFloat m_MaxSpeed;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      target    追跡対象
        *******************************************************************************/
        explicit CBulletHoming(GameObjectPtr target);

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CBulletHoming() override;

        /******************************************************************************/
        /*! 弾の初期化
            @param[in]      px    初期位置Ｘ
            @param[in]      py    初期位置Ｙ
            @param[in]      sx    スピードＸ
            @param[in]      sy    スピードＹ
            @param[in]      iw    画像幅
            @param[in]      ih    画像高さ
            @param[in]      img   画像ＩＤ
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Initialize(MyFloat px, MyFloat py, MyFloat sx, MyFloat sy, MyS32 iw, MyS32 ih, MyInt img) override;

        /******************************************************************************/
        /*! 弾の更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update() override;
    };
}


#endif //BULLETHOMING_H
