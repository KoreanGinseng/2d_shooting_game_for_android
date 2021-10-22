/******************************************************************************/
/*! @file       TurretPlayerLockon.h
    @brief      プレイヤーを標的にする砲台クラスの定義ファイル
*******************************************************************************/

#ifndef TURRETPLAYERLOCKON_H
#define TURRETPLAYERLOCKON_H

#include "TurretDecorator.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretPlayerLockon
        @brief  プレイヤーを標的にする砲台クラスの定義ファイル
    *******************************************************************************/
    class CTurretPlayerLockon : public CTurretDecorator
    {
    protected:

        /*! 弾の移動速度 */
        MyFloat m_Speed;

    public:
        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      speed    スピード
        *******************************************************************************/
        explicit CTurretPlayerLockon(MyFloat speed)
            : CTurretDecorator()
            , m_Speed(speed)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretPlayerLockon() override
        {
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        MyS32 Update(MyFloat px, MyFloat py) override
        {
            // 発射するフレームのみ
            if (IsFire())
            {
                // ターゲットとするプレイヤーの取得
                auto& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
                // プレイヤー方向に飛ぶように速度を算出
                MyFloat sx = player.GetPosX() - (px + m_Turret->GetOffsetX());
                MyFloat sy = player.GetPosY() - (py + m_Turret->GetOffsetY());
                MyFloat d = sqrt(sx * sx + sy * sy);
                sx /= d;
                sy /= d;
                sx *= m_Speed;
                sy *= m_Speed;
                m_Turret->SetSpeed(sx, sy);
            }
            return CTurretDecorator::Update(px, py);
        }
    };
}

#endif //TURRETPLAYERLOCKON_H
