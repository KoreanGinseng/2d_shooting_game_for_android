/******************************************************************************/
/*! @file       GameApplication.cpp
    @brief      ゲームアプリケーションクラス実装ファイル
*******************************************************************************/
#include "GameApplication.h"

using namespace Shooting2D;

/******************************************************************************/
/*! アプリケーションの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameApplication::Initialize()
{
    m_SceneManager = std::make_shared<CSceneManager>();
    m_SceneManager->Regist<CTitleScene>("Title");
    m_SceneManager->Regist<CGameScene>("Game");
    m_SceneManager->Regist<CClearScene>("Clear");
    m_SceneManager->Regist<COverScene>("Over");
    m_SceneManager->Change("Title");
    SceneChangerService::SetService(m_SceneManager);

    return k_Success;
}

/******************************************************************************/
/*! アプリケーションの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameApplication::Update()
{
    return m_SceneManager->Update();
}

/******************************************************************************/
/*! アプリケーションの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameApplication::Draw()
{
    return m_SceneManager->Draw();
}

/******************************************************************************/
/*! アプリケーションの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CGameApplication::Release()
{
    m_SceneManager->Release();
    SceneChangerService::Release();
    return k_Success;
}

