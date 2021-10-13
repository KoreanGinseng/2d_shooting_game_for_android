//
// Created by akasu on 2021/10/13.
//

#include "OverScene.h"
#include "GameDefine.h"

using namespace Shooting2D;

COverScene::COverScene()
    : m_bPressReturn(false)
    , m_bSceneChange(false)
    , m_Image(-1)
    , m_FontHandle(-1)
{
}

COverScene::~COverScene()
{
}

MyS32 COverScene::Load()
{
    // UI生成
    m_Image = DxLib::LoadGraph("image/BackGround/05Background.png");
    m_FontHandle = DxLib::LoadFontDataToHandle("fonts/MS_Mincho.dft", 0);
    if (m_FontHandle == -1) { return k_failure; }
    return k_Success;
}

MyS32 COverScene::Initialize()
{
    m_bPressReturn = false;
    m_bSceneChange = false;
    return k_Success;
}

MyS32 COverScene::Update()
{
    if (m_bSceneChange)
    {
        return k_Success;
    }
    MyS32 touchNum = DxLib::GetTouchInputNum();
    if (touchNum > 0)
    {
        if (!m_bPressReturn)
        {
            MyInt posX = 0, posY = 0;
            DxLib::GetTouchInput(touchNum - 1, &posX, &posY, nullptr, nullptr);
            if (posX > k_StartButtonX && posX < k_StartButtonX + k_StartButtonW &&
                posY > k_StartButtonY && posY < k_StartButtonY + k_StartButtonH)
            {
                m_bPressReturn = true;
            }
        }
    }
    else if (m_bPressReturn)
    {
        m_bPressReturn = false;
        m_bSceneChange = true;
        SceneChangerService::GetService()->Change("Title", std::make_shared<CSceneChangeEffectFade>(30));
    }
    return k_Success;
}

MyS32 COverScene::Draw()
{
    DxLib::DrawExtendGraph(k_SceneOffsetX, k_SceneOffsetY, k_SceneOffsetX + k_SceneWidth, k_SceneOffsetY + k_SceneHeight, m_Image, true);
    MyU32 colorWhite = DxLib::GetColor(255, 255, 255);
    MyU32 colorGray  = DxLib::GetColor(128, 128, 128);
    MyU32 colorBlack = DxLib::GetColor(  0,   0,   0);
    DxLib::DrawBox(k_StartButtonX - 2, k_StartButtonY - 2, k_StartButtonX + k_StartButtonW + 2, k_StartButtonY + k_StartButtonH + 2, colorBlack, true);
    DxLib::DrawBox(k_StartButtonX, k_StartButtonY, k_StartButtonX + k_StartButtonW, k_StartButtonY + k_StartButtonH, (m_bPressReturn ? colorGray : colorWhite), true);
    DxLib::DrawStringToHandle(k_StartButtonX, k_StartButtonY, "title", colorBlack, m_FontHandle);
    DxLib::DrawStringToHandle(0, 0, "GameOver", colorWhite, m_FontHandle);
    return k_Success;
}

MyS32 COverScene::Release()
{
    // UI解放
    DxLib::DeleteGraph(m_Image);
    DxLib::DeleteFontToHandle(m_FontHandle);
    return k_Success;
}