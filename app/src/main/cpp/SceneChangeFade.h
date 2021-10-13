//
// Created by akasu on 2021/10/13.
//

#ifndef SCENECHANGEFADE_H
#define SCENECHANGEFADE_H

#include "SceneChangeEffect.h"
#include <DxLib.h>

namespace Shooting2D
{
    class CSceneChangeEffectFade : public ISceneChangeEffect
    {
    private:
        MyS32 m_CurrentFrame;
        MyS32 m_EndFrame;
        MyS32 m_PrevBlend;
        MyS32 m_CurrentBlend;
    public:
        CSceneChangeEffectFade(MyS32 t)
            : m_CurrentFrame(0)
            , m_EndFrame(t)
            , m_PrevBlend(255)
            , m_CurrentBlend(0)
        {
        }

        virtual ~CSceneChangeEffectFade() = default;

        virtual MyS32 Update() override
        {
            m_CurrentFrame++;
            MyFloat t = (MyFloat)m_CurrentFrame / (MyFloat)m_EndFrame;
            m_PrevBlend = 255 * (1 - t);
            m_CurrentBlend = 255 * t;
            return k_Success;
        }

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

        virtual MyBool IsEnd() const noexcept override
        {
            return m_CurrentFrame >= m_EndFrame;
        }
    };
}

#endif //SCENECHANGEFADE_H
