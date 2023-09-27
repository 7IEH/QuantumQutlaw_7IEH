#include "qoPlayScene.h"
#include "qoResourceManager.h"
#include "qoCollisionManager.h"

#include "qoGameObject.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"
#include "qoCollider.h"
#include "qoRigidbody.h"
#include "qoPlayerScript.h"
#include "qoLabGuard.h"
#include "qoLabGuardScript.h"

#include "qoGuard.h"

namespace qo
{
	PlayScene::PlayScene()
	{
	}


	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		{
			GameObject* object = new GameObject();
			Transform* tr = object->AddComponent<Transform>();
			tr->SetPosition(Vector3(0.5f, 0.2f, 0.0f));
			tr->SetScale(Vector3(2.0f, 2.0f, 1.0f));

			MeshRenderer* meshRenderer = object->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"TriangleMesh"));
			meshRenderer->SetShader(ResourceManager::Find<Shader>(L"TriangleShader"));

			AddGameObject(object, LAYER::NONE);
			object->AddComponent<PlayerScript>();
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render()
	{
		Scene::Render();
	}
}
