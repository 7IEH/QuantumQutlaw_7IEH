#include "qoPlayer.h"
#include "qoGun.h"
#include "qoGunScript.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"
#include "qoResourceManager.h"

namespace qo
{
	Player::Player()
		: mGuns{}
		, mActiveGun(nullptr)
	{
	}

	Player::~Player()
	{
		// �÷��̾� �Ҹ�� �÷��̾ �����ϴ� Guns �޸� ����
		for (Gun* gun : mGuns)
		{
			if (gun != nullptr)
			{
				delete gun;
				gun = nullptr;
			}
		}
	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();

		// ���� Ȱ��ȭ �Ǿ��ִ� �Ѹ� Update �����ش�.
		if (mActiveGun != nullptr)
		{
			mActiveGun->Update();
		}
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		// ���� Ȱ��ȭ �Ǿ��ִ� �Ѹ� LateUpdate �����ش�.
		if (mActiveGun != nullptr)
		{
			mActiveGun->LateUpdate();
		}
	}

	void Player::Render()
	{
		GameObject::Render();

		// ���� Ȱ��ȭ �Ǿ��ִ� �Ѹ� Render �����ش�.
		if (mActiveGun != nullptr)
		{
			mActiveGun->Render();
		}
	}

	void Player::AddGun()
	{
		// �÷��̾� ��ü ����
		Transform* PlayerTransform = GetComponent<Transform>();
		Vector3 PlayerPos = PlayerTransform->GetPosition();

		// ============
		// �� ��ü ����
		// ============
		Gun* gun = new Gun(this, 50);

		Transform* GunTransform = gun->AddComponent<Transform>();
		GunTransform->SetPosition(PlayerPos);
		GunTransform->SetScale(Vector3(0.3f, 0.3f, 0.3f));

		MeshRenderer* meshRenderer = gun->AddComponent<MeshRenderer>();
		meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectangleMesh"));
		meshRenderer->SetShader(ResourceManager::Find<Shader>(L"TriangleShader"));

		gun->AddComponent<GunScript>();
		
		gun->Initialize();

		mGuns.push_back(gun);
		mActiveGun = gun;		
	}
}