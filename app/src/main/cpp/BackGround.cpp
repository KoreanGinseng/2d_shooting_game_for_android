/******************************************************************************/
/*! @file       BackGround.cpp
    @brief      背景クラス実装ファイル
*******************************************************************************/

#include "BackGround.h"
#include <DxLib.h>

using namespace Shooting2D;

/******************************************************************************/
/*! コンストラクタ
*******************************************************************************/
CBackGround::CBackGround()
    : m_Scroll(0.0f)
    , m_Width(0)
    , m_Height(0)
    , m_Image(-1)
{
}

/******************************************************************************/
/*! デストラクタ
*******************************************************************************/
CBackGround::~CBackGround()
{
}

/******************************************************************************/
/*! 背景クラスの読み込み
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBackGround::Load()
{
    // 画像を読み込む
    m_Image = DxLib::LoadGraph("image/BackGround/01Background.png");
    if (m_Image == -1) { return k_failure; }
    // 画像から幅と高さを取得
    MyInt w,h;
    DxLib::GetGraphSize(m_Image, &w, &h);
    m_Width = w; m_Height = h;
    return k_Success;
}

/******************************************************************************/
/*! 背景クラスの初期化
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBackGround::Initialize()
{
    // スクロールは０から
    m_Scroll = 0.0f;
    return k_Success;
}

/******************************************************************************/
/*! 背景クラスの更新
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBackGround::Update()
{
    // スクロール
    m_Scroll += k_ScrollSpeed;
    return k_Success;
}

/******************************************************************************/
/*! 背景クラスの描画
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBackGround::Draw()
{
    // 同じ画像を繰り返しで画面端を超えるまで描画を行う
    for (MyInt y = ((MyInt)m_Scroll % m_Height) - m_Height;
    y < k_SceneHeight; y += m_Height)
    {
        MyInt dy = k_SceneOffsetY + y;
        DxLib::DrawExtendGraph(k_SceneOffsetX, dy, k_SceneWidth, dy + m_Height, m_Image, true);
    }
    return k_Success;
}

/******************************************************************************/
/*! 背景クラスの解放
    @return         成功 k_Success, 失敗 それ以外
*******************************************************************************/
MyS32 CBackGround::Release()
{
    DxLib::DeleteGraph(m_Image);
    return k_Success;
}
