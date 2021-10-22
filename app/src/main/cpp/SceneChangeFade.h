/******************************************************************************/
/*! @file       SceneChangeFade.h
    @brief      シーン変更クラス定義ファイル
*******************************************************************************/

#ifndef SCENECHANGEFADE_H
#define SCENECHANGEFADE_H

#include "SceneChangeEffect.h"
#include <DxLib.h>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class CSceneChangeEffectFade
        @brief  シーン変更インターフェース
    *******************************************************************************/
    class CSceneChangeEffectFade : public ISceneChangeEffect
    {
    private:

        /*! カウンタ */
        MyS32 m_CurrentFrame;
        MyS32 m_EndFrame;
        MyS32 m_PrevBlend;
        MyS32 m_CurrentBlend;

    public:

        /******************************************************************************/
        /*! コンストラクタ
            @param[in]      t          タイマー
        *******************************************************************************/
        CSceneChangeEffectFade(MyS32 t)
            : m_CurrentFrame(0)
            , m_EndFrame(t)
            , m_PrevBlend(255)
            , m_CurrentBlend(0)
        {
        }

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~CSceneChangeEffectFade() = default;

        /******************************************************************************/
        /*! 更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update() override
        {
            m_CurrentFrame++;
            MyFloat t = (MyFloat)m_CurrentFrame / (MyFloat)m_EndFrame;
            m_PrevBlend = 255 * (1 - t);
            m_CurrentBlend = 255 * t;
            return k_Success;
        }

        /******************************************************************************/
        /*! 描画
            @param[in]      prev          前シーン
            @param[in]      prevImg       前シーン用画像ID
            @param[in]      current       現在のシーン
            @param[in]      currentImg    現在のシーン用画像ID
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Draw(ScenePtr& prev, MyInt prevImg, ScenePtr& current, MyInt currentImg) override
        {
            DxLib::SetDrawScreen(prevImg);
            DxLib::ClearDrawScreen();
            prev->Draw();

            DxLib::SetDrawScreen(currentImg);
            DxLib::ClearDrawScreen();
            current->Draw();

            DxLib::SetDrawScreen(DX_SCREEN_BACK);
            DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_PrevBlend);
            DxLib::DrawGraph(0, 0, prevImg, true);
            DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_CurrentBlend);
            DxLib::DrawGraph(0, 0, currentImg, true);
            DxLib::SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            return k_Success;
        }

        /******************************************************************************/
        /*! シーン終了フラグ
            @return         シーン終了フラグ
        *******************************************************************************/
        virtual MyBool IsEnd() const noexcept override
        {
            return m_CurrentFrame >= m_EndFrame;
        }
    };
}

#endif //SCENECHANGEFADE_H
