/******************************************************************************/
/*! @file       TurretPlayerPointer.h
    @brief      弾発射機能装飾クラス定義ファイル
*******************************************************************************/

#ifndef TURRETPLAYERPOINTER_H
#define TURRETPLAYERPOINTER_H

#include "TurretDecorator.h"
#include "GameDefine.h"
#include "Player.h"
#include "SingletonBlackboard.h"

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CTurretPlayerPointer
        @brief  弾発射機能装飾クラス
    *******************************************************************************/
    class CTurretPlayerPointer : public CTurretDecorator
    {
    protected:

        /*! 弾の発射位置 */
        MyFloat m_PosX;
        MyFloat m_PosY;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
        explicit CTurretPlayerPointer()
            : CTurretDecorator()
            , m_PosX(0.0f)
            , m_PosY(0.0f)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CTurretPlayerPointer() override
        {
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      px    対象の座標X
            @param[in]      py    対象の座標Y
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update(MyFloat px, MyFloat py) override
        {
            if (IsFire())
            {
                // ターゲットとするプレイヤーの取得
                auto& player = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
                m_PosX = player.GetPosX();
                m_PosY = player.GetPosY();
            }
            return CTurretDecorator::Update(m_PosX, m_PosY);
        }
    };
}

#endif //TURRETPLAYERPOINTER_H
