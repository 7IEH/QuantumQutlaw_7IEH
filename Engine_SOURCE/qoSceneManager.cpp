#include "qoSceneManager.h"

#include "qoResourceManager.h"

#include "qoGameObject.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"

namespace qo
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};

	void SceneManager::Initialize()
	{
		//mActiveScene = new Scene();



		//{
		//	GameObject* object = new GameObject();
		//	Transform* tr = new Transform();
		//	tr->SetPosition(Vector3(-0.5f, -0.2f, 0.0f));
		//	object->AddComponent(tr);

		//	MeshRenderer* meshRenderer = new MeshRenderer();
		//	meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"TriangleMesh"));
		//	meshRenderer->SetShader(ResourceManager::Find<Shader>(L"TriangleShader"));
		//	object->AddComponent(meshRenderer);

		//	mActiveScene->AddGameObject(object, LAYER::NONE);
		//}
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}
	
	void SceneManager::Release()
	{
		for (auto iter : mScenes)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}

	Scene* SceneManager::LoadScene(const std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;
		mActiveScene->Exit();
		mActiveScene = iter->second;
		mActiveScene->Enter();
		return iter->second;
	}
}
