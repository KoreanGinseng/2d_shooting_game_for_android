/******************************************************************************/
/*! @file       Turret.h
    @brief      タレットクラス定義ファイル
*******************************************************************************/

#ifndef TURRET_H
#define TURRET_H

#include <algorithm>
#include "Bullet.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{

    /******************************************************************************/
    /*! @class ITurret
        @brief  タレットクラス
    *******************************************************************************/
    class ITurret : public std::enable_shared_from_this<ITurret>
    {
    public:

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~ITurret() = default;

        /******************************************************************************/
        /*! タレットの初期化
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Initialize() = 0;

        /******************************************************************************/
        /*! タレットの更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) = 0;

        /******************************************************************************/
        /*! 装飾
            @return         ポインタ
        *******************************************************************************/
        template < typename T, typename... Types >
        std::shared_ptr<T> Decorate(Types&&... _Args)
        {
            auto result = std::make_shared<T>(_Args...);
            result->SetTurret(shared_from_this());
            return result;
        }

        /******************************************************************************/
        /*! オフセット位置Xの取得
            @return         オフセット位置X
        *******************************************************************************/
        virtual MyFloat GetOffsetX() const noexcept = 0;

        /******************************************************************************/
        /*! オフセット位置Yの取得
            @return         オフセット位置Y
        *******************************************************************************/
        virtual MyFloat GetOffsetY() const noexcept = 0;

        /******************************************************************************/
        /*! スピードXの取得
            @return         スピードX
        *******************************************************************************/
        virtual MyFloat GetSpeedX() const noexcept = 0;

        /******************************************************************************/
        /*! スピードYの取得
            @return         スピードY
        *******************************************************************************/
        virtual MyFloat GetSpeedY() const noexcept = 0;

        /******************************************************************************/
        /*! オフセット位置の設定
            @param[in]      sx    設定するオフセットX
            @param[in]      sy    設定するオフセットY
        *******************************************************************************/
        virtual MyVoid SetOffset(MyFloat sx, MyFloat sy) = 0;

        /******************************************************************************/
        /*! スピードの設定
            @param[in]      sx    設定するスピードX
            @param[in]      sy    設定するスピードY
        *******************************************************************************/
        virtual MyVoid SetSpeed(MyFloat sx, MyFloat sy) = 0;

        /******************************************************************************/
        /*! このフレームでの発射判定
            @return         発射フラグ
        *******************************************************************************/
        virtual MyBool IsFire() const noexcept = 0;
    };

    /*! ポインタ置き換え */
    using TurretPtr   = std::shared_ptr<ITurret>;
    /*! 配列置き換え */
    using TurretArray = std::vector<TurretPtr>;
}

#endif //TURRET_H
