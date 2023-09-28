#include "qoGunScript.h"
#include "qoGun.h"
#include "qoBullet.h"
#include "qoInput.h"
#include "qoTransform.h"
#include "qoPlayer.h"
#include "qoBullet.h"
#include "qoApplication.h"
#include "qoMeshRenderer.h"
#include "qoResourceManager.h"
#include "qoSceneManager.h"
#include "qoBulletScript.h"

extern qo::Application application;


namespace qo
{
	GunScript::GunScript()
	{
	}

	GunScript::~GunScript()
	{
	}

	void GunScript::Initialize()
	{
	}

	void GunScript::Update()
	{
		// Gun�� ��ġ�� �÷��̾� ��ġ�� �����Ѵ�.
		Gun* owner = dynamic_cast<Gun*>(GetOwner());

		Transform* GunTransform = owner->GetComponent<Transform>();		
		Transform* PlayerTransform = owner->mPlayer->GetComponent<Transform>();

		Vector3 GunPos = PlayerTransform->GetPosition() + Vector3(0.2f, 0.f, 0.f);

		GunTransform->SetPosition(GunPos);

		// �Ѿ� �߻�
		if (Input::GetKeyState(KEY_CODE::LBTN) == KEY_STATE::DOWN)
		{
			if (owner->mBulletCount > 0)
			{
				--owner->mBulletCount;				
				Shoot();
			}
		}
	}

	void GunScript::LateUpdate()
	{
	}

	void GunScript::Render()
	{
	}

	void GunScript::Shoot()
	{
		Gun* owner = dynamic_cast<Gun*>(GetOwner());
		
		if (owner != nullptr)
		{
			// ==============================================
			// �Ѿ� ���� ���� Gun ��ġ �� ���� ���콺 ��ġ�� �߻�
			// ==============================================
			Vector2 mousePos = Input::GetMousPosition();
			Vector3 GunPos = owner->GetComponent<Transform>()->GetPosition();

			// ������ ��ǥ�� �� �޼� ��ǥ�� ���� ��ȯ
			GunPos.x += application.GetWidth() / 2.f;
			GunPos.y += application.GetHeight() / 2.f;

			// Gun ��ġ �� ���� ���콺 ��ġ
			Vector3 Dir = Vector3(0.f, 0.f, 0.f);
			Dir.x = mousePos.x - GunPos.x;
			Dir.y = mousePos.y - GunPos.y;
			Dir.y *= -1.f; // Window ��ǥ�� �� �޼� ��ǥ�� Y ���� ��ȯ



			// Gun ��ġ �缳��
			GunPos = owner->GetComponent<Transform>()->GetPosition();

			// ================================================
			// �Ѿ� ����
			// ================================================
			Bullet* bullet = new Bullet(Dir);
			Transform* tr = bullet->AddComponent<Transform>();
			tr->SetPosition(GunPos); // �Ѿ� ������ġ�� ����ġ�� ����
			tr->SetScale(Vector3(0.1f, 0.1f, 0.1f));

			MeshRenderer* meshRenderer = bullet->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"CircleMesh"));
			meshRenderer->SetShader(ResourceManager::Find<Shader>(L"CircleShader"));

			bullet->AddComponent<BulletScript>();

			bullet->Initialize();

			SceneManager::GetActiveScene()->AddGameObject(bullet, LAYER::NONE);
		}	
	}
}