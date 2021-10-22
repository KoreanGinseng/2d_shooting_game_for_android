/******************************************************************************/
/*! @file       SceneManager.h
    @brief      シーン管理クラス定義ファイル
*******************************************************************************/

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <unordered_map>
#include "SceneRegister.h"
#include "SceneChanger.h"
#include <DxLib.h>

namespace Shooting2D
{
    /******************************************************************************/
    /*! @class ISceneManager
        @brief  シーン管理クラスインターフェース
    *******************************************************************************/
    class ISceneManager : public ISceneChanger, public ISceneRegister
    {
    public:
        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        virtual ~ISceneManager() = default;

        /******************************************************************************/
        /*! 更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Update() = 0;

        /******************************************************************************/
        /*! 描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Draw() = 0;

        /******************************************************************************/
        /*! 解放
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Release() = 0;
    };
    /*! ポインタ置き換え */
    using SceneManagerPtr = std::shared_ptr<ISceneManager>;

    /******************************************************************************/
    /*! @class CSceneManager
        @brief  シーン管理クラス
    *******************************************************************************/
    class CSceneManager : public ISceneManager
    {
    public:

        /******************************************************************************/
        /*! @class CSceneCreator
            @brief  シーン生成クラス
        *******************************************************************************/
        template < class T >
        class CSceneCreator : public ISceneCreator
        {
        public:
            /******************************************************************************/
            /*! シーンの生成
                @return         生成されたシーンクラス
            *******************************************************************************/
            virtual ScenePtr Create() override
            {
                return std::make_shared<T>();
            }
        };

    private:

        /*! 現在のシーン */
        ScenePtr m_CurrentScene;
        /*! 過去のシーン */
        ScenePtr m_PrevScene;
        /*! 現在のシーン画像ID */
        MyInt m_CurrentSceneImage;
        /*! 過去のシーン画像ID */
        MyInt m_PrevSceneImage;
        /*! シーン変更エフェクト */
        SceneChangeEffectPtr m_ChangeEffect;
        /*! 各シーン */
        std::unordered_map<SceneKey, SceneCreatorPtr> m_SceneMap;

    public:

        /******************************************************************************/
        /*! コンストラクタ
        *******************************************************************************/
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

        /******************************************************************************/
        /*! デストラクタ
        *******************************************************************************/
        ~CSceneManager()
        {
        }

        /******************************************************************************/
        /*! シーンの登録
            @param[in]      key          登録シーンキー
            @param[in]      creator      生成シーン
        *******************************************************************************/
        virtual MyVoid Regist(RKMy(SceneKey) key, SceneCreatorPtr creator) override
        {
            m_SceneMap[key] = std::move(creator);
        }

        /******************************************************************************/
        /*! シーンの登録
            @param[in]      key          登録シーンキー
        *******************************************************************************/
        template < class T >
        MyVoid Regist(RKMy(SceneKey) key)
        {
            Regist(key, std::make_unique<CSceneCreator<T>>());
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      key          変更先シーンキー
            @return         true 成功, false 失敗
        *******************************************************************************/
        virtual MyBool Change(RKMy(SceneKey) key) override
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
            return true;
        }

        /******************************************************************************/
        /*! 更新
            @param[in]      key          変更先シーンキー
            @param[in]      effect       変更エフェクト
            @return         true 成功, false 失敗
        *******************************************************************************/
        virtual MyBool Change(RKMy(SceneKey) key, SceneChangeEffectPtr effect) override
        {
            if (m_ChangeEffect)
            {
                return false;
            }
            // 古いシーンとエフェクトを保存
            if (m_CurrentScene)
            {
                m_ChangeEffect = effect;
                m_PrevScene = m_CurrentScene;
                m_CurrentScene.reset();
            }
            Change(key);
            return true;
        }

        /******************************************************************************/
        /*! 更新
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
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

        /******************************************************************************/
        /*! 描画
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
        virtual MyS32 Draw() override
        {
            if (m_CurrentScene && m_PrevScene && m_ChangeEffect)
            {
                m_ChangeEffect->Draw(m_PrevScene, m_PrevSceneImage, m_CurrentScene, m_CurrentSceneImage);
            }
            else if (m_CurrentScene) { return m_CurrentScene->Draw(); }
            return k_Success;
        }

        /******************************************************************************/
        /*! 解放
            @return         成功 k_Success, 失敗 それ以外
        *******************************************************************************/
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
