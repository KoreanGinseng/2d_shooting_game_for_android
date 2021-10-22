/******************************************************************************/
/*! @file       ClearScene.cpp
    @brief      クリアシーンクラス実装ファイル
*******************************************************************************/

#include "ClearScene.h"
#include "GameDefine.h"

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CClearScene::CClearScene()
        : m_bSceneChange(false)
        , m_Image(-1)
        , m_LogoImage(-1)
        , m_BtnTitle(std::make_shared<CButton>(
                k_StartButtonX, k_StartButtonY,
                k_StartButtonX + k_StartButtonW, k_StartButtonY + k_StartButtonH
                ))
        , m_BtnUI(m_BtnTitle)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CClearScene::~CClearScene()
{
}

/******************************************************************************/
/*! 読み込み
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CClearScene::Load()
{
    // UI生成
    m_Image = DxLib::LoadGraph("image/BackGround/05Background.png");
    m_LogoImage = DxLib::LoadGraph("image/BackGround/GameClear.png");
    MyInt btnImg = DxLib::LoadGraph("image/Button/Title.png");
    m_BtnUI.Load(
            DxLib::DerivationGraph( 0, 0, 30, 15, btnImg),
            DxLib::DerivationGraph(32, 0, 30, 15, btnImg),
            -1, -1
            );
    DxLib::DeleteGraph(btnImg);
    return k_Success;
}

/******************************************************************************/
/*! 初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CClearScene::Initialize()
{
    m_bSceneChange = false;
    return k_Success;
}

/******************************************************************************/
/*! 更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CClearScene::Update()
{
    if (m_bSceneChange)
    {
        return k_Success;
    }
    if (m_BtnTitle->IsPull())
    {
        m_bSceneChange = SceneChangerService::GetService()->Change("Title", std::make_shared<CSceneChangeEffectFade>(30));
    }
    return k_Success;
}

/******************************************************************************/
/*! 描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CClearScene::Draw()
{
    DxLib::DrawExtendGraph(k_SceneOffsetX, k_SceneOffsetY, k_SceneOffsetX + k_SceneWidth, k_SceneOffsetY + k_SceneHeight, m_Image, true);
    DxLib::DrawExtendGraph(k_LogoX, k_LogoY, k_LogoX + k_LogoW, k_LogoY + k_LogoH, m_LogoImage, true);
    m_BtnUI.Draw();
    return k_Success;
}

/******************************************************************************/
/*! 解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CClearScene::Release()
{
    // UI解放
    DxLib::DeleteGraph(m_Image);
    DxLib::DeleteGraph(m_LogoImage);
    m_BtnUI.Release();
    return k_Success;
}
