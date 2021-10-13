//
// Created by akasu on 2021/10/12.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include "SceneRegister.h"
#include "SceneChanger.h"
#include <DxLib.h>

namespace Shooting2D
{
    class ISceneManager : public ISceneChanger, public ISceneRegister
    {
    public:
        virtual ~ISceneManager() = default;

        virtual MyS32 Update() = 0;
        virtual MyS32 Draw() = 0;
        virtual MyS32 Release() = 0;
    };
    using SceneManagerPtr = std::shared_ptr<ISceneManager>;

    class CSceneManager : public ISceneManager
    {
    public:
        template < class T >
        class CSceneCreator : public ISceneCreator
        {
        public:
            virtual ScenePtr Create() override
            {
                return std::make_shared<T>();
            }
        };
    private:
        ScenePtr m_CurrentScene;
        ScenePtr m_PrevScene;
        MyInt m_CurrentSceneImage;
        MyInt m_PrevSceneImage;
        SceneChangeEffectPtr m_ChangeEffect;
        std::unordered_map<SceneKey, SceneCreatorPtr> m_SceneMap;
    public:
        CSceneManager()
            : m_CurrentScene()
            , m_PrevScene()
            , m_SceneMap()
            , m_CurrentSceneImage(-1)
            , m_PrevSceneImage(-1)
            , m_ChangeEffect()
        {
            // 画面用画像の作成
            MyInt w, h, bit;
            DxLib::GetScreenState(&w, &h, &bit);
            m_CurrentSceneImage = DxLib::MakeScreen(w, h);
            m_PrevSceneImage    = DxLib::MakeScreen(w, h);
        }

        ~CSceneManager()
        {
        }

        virtual MyVoid Regist(RKMy(SceneKey) key, SceneCreatorPtr creator) override
        {
            m_SceneMap[key] = std::move(creator);
        }

        template < class T >
        MyVoid Regist(RKMy(SceneKey) key)
        {
            Regist(key, std::make_unique<CSceneCreator<T>>());
        }

        virtual MyVoid Change(RKMy(SceneKey) key) override
        {
            // 新しいシーンを作成
            ScenePtr scene_tmp = m_SceneMap[key]->Create();
            // 新しいシーンの読み込み
            scene_tmp->Load();
            // 新しいシーンの初期化
            scene_tmp->Initialize();
            // 古いシーンの破棄
            if (m_CurrentScene) { m_CurrentScene->Release(); }
            // 新しいシーンを代入
            m_CurrentScene = scene_tmp;
        }

        virtual MyVoid Change(RKMy(SceneKey) key, SceneChangeEffectPtr effect) override
        {
            // 古いシーンとエフェクトを保存
            if (m_CurrentScene)
            {
                m_ChangeEffect = effect;
                m_PrevScene = m_CurrentScene;
                m_CurrentScene.reset();
            }
            Change(key);
        }

        virtual MyS32 Update() override
        {
            if (m_CurrentScene && m_PrevScene && m_ChangeEffect)
            {
                m_CurrentScene->Update();
                m_ChangeEffect->Update();
                if (m_ChangeEffect->IsEnd())
                {
                    m_PrevScene->Release();
                    m_PrevScene.reset();
                    m_ChangeEffect.reset();
                }
            }
            else if (m_CurrentScene) { return m_CurrentScene->Update(); }
            return k_Success;
        }

        virtual MyS32 Draw() override
        {
            if (m_CurrentScene && m_PrevScene && m_ChangeEffect)
            {
                m_ChangeEffect->Draw(m_PrevScene, m_PrevSceneImage, m_CurrentScene, m_CurrentSceneImage);
            }
            else if (m_CurrentScene) { return m_CurrentScene->Draw(); }
            return k_Success;
        }

        virtual MyS32 Release() override
        {
            if (m_PrevScene)
            {
                m_PrevScene->Release();
                m_PrevScene.reset();
            }
            if (m_CurrentScene)
            {
                m_CurrentScene->Release();
                m_CurrentScene.reset();
            }
            return k_Success;
        }
    };
}

#endif //SCENEMANAGER_H
