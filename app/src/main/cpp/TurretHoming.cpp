/******************************************************************************/
/*! @file       TurretHoming.cpp
    @brief      標的を追跡する砲台クラスの実装ファイル
*******************************************************************************/
#include "TurretHoming.h"
#include "BulletHoming.h"
#include "EnemyManager.h"
#include "Player.h"

using namespace Shooting2D;

/******************************************************************************/
/*! 更新
    @param[in]      px    対象の座標X
    @param[in]      py    対象の座標Y
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CTurretHoming::Update(MyFloat px, MyFloat py)
{
    // ウェイトの減少
    m_Wait--;
    // ウェイトがある場合待機
    if (m_Wait > 0)
    {
        return k_failure;
    }
    // 次の発射までのウェイトを設定
    m_Wait = m_Interval;
    // プレイヤーから一番近い敵を検索
    auto& enemyManager = CSingletonBlackboard<CEnemyManager>::GetInstance().Get<CEnemyManager>("EnemyManager");
    auto& player       = CSingletonBlackboard<CPlayer>::GetInstance().Get<CPlayer>("Player");
    GameObjectPtr target = nullptr;
    MyFloat       length = k_SceneWidth * k_SceneWidth + k_SceneHeight * k_SceneHeight;
    for (auto& enemy : enemyManager.GetEnemyList())
    {
        MyFloat dx = enemy->GetPosX() - player.GetPosX();
        MyFloat dy = enemy->GetPosY() - player.GetPosY();
        MyFloat d = dx * dx + dy * dy;
        if (d < length)
        {
            length = d;
            target = enemy;
        }
    }
    // 弾を発射
    auto& list = CSingletonBlackboard<BulletList>::GetInstance().Get<BulletList>(m_listName);
    auto blt = std::make_shared<CBulletHoming>(target);
    blt->Initialize(px + m_OffsetX, py + m_OffsetY, m_SpeedX, m_SpeedY, m_ImageWidth, m_ImageHeight, m_BulletImage);
    list.push_back(blt);
    return k_Success;
}