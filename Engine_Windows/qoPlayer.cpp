#include "qoPlayer.h"
#include "qoGun.h"
#include "qoGunScript.h"
#include "qoSuperpositionGunScript.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"
#include "qoResourceManager.h"
#include "qoSuperpositionGun.h"

namespace qo
{
	Player::Player()
		: mGuns{}
		, mActiveGun(nullptr)
		, mState(ePlayerState::Idle)
		, mHp(100)
		, mSpeed(1.f)
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

	void Player::AddGun(eGunType type)
	{
		// �÷��̾� ��ü ����
		Transform* PlayerTransform = GetComponent<Transform>();
		Vector3 PlayerPos = PlayerTransform->GetPosition();

		// ================================
		// �� ��ü ����
		// ================================
		if (type == eGunType::Superposition)
		{
			SuperpositionGun* gun = new SuperpositionGun(type, this, 10);
			Vector3 GunPos = PlayerPos + Vector3(0.2f, 0.f, 0.f);

			Transform* GunTransform = gun->AddComponent<Transform>();
			GunTransform->SetPosition(GunPos);
			GunTransform->SetScale(Vector3(0.1f, 0.1f, 0.f));
			GunTransform->SetColor(Vector4(0.f, 0.f, 0.f, 0.f));

			MeshRenderer* meshRenderer = gun->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"RectangleMesh"));
			meshRenderer->SetShader(ResourceManager::Find<Shader>(L"ColorTestShader"));

			gun->AddComponent<GunScript>();
			gun->AddComponent<SuperpositionGunScript>();

			gun->Initialize();

			mGuns.push_back(gun);
			mActiveGun = gun;
		}
		else if(type == eGunType::Entanglement)
		{

		}
		else if (type == eGunType::Teleportation)
		{

		}
	}

	void Player::TakeHit(int DamageAmount, math::Vector3 HitDir)
	{
	}
}