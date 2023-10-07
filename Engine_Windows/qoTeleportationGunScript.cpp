#include "qoTeleportationGunScript.h"
#include "qoInput.h"
#include "qoApplication.h"
#include "qoGun.h"
#include "qoTransform.h"
#include "qoMeshRenderer.h"
#include "qoSceneManager.h"
#include "qoResourceManager.h"
#include "qoBulletScript.h"
#include "qoCollider.h"
#include "qoTeleportationGun.h"
#include "qoTeleportationBullet.h"
#include "qoCamera.h"
#include "qoRigidbody.h"

extern qo::Application application;


namespace qo
{
	TeleportationGunScript::TeleportationGunScript()
	{
	}

	TeleportationGunScript::~TeleportationGunScript()
	{
	}

	void TeleportationGunScript::Initialize()
	{
	}

	void TeleportationGunScript::Update()
	{
		TeleportationGun* teleportationGun = dynamic_cast<TeleportationGun*>(GetOwner());

		if (teleportationGun == nullptr)
			return;

		// ==========================
		// �Ѿ� �߻�
		// ==========================
		if (Input::GetKeyState(KEY_CODE::LBTN) == KEY_STATE::DOWN)
		{
			if (teleportationGun->GetCurBulletCount() > 0)
			{
				if (teleportationGun->BulletConsumption(1))
				{
					Shoot();
					Camera::ShakeCam(0.1f, ShakeDir::Horizontal, 0.01f, 50.f);
				}
			}
		}

		// ==========================
		// TargetBullet ��ġ�� �����̵�
		// ==========================
		if (Input::GetKeyState(KEY_CODE::RBTN) == KEY_STATE::DOWN)
		{
			TeleportationBullet* targetBullet = teleportationGun->GetTargetBullet();

			if (targetBullet != nullptr)
			{
				Player* player = teleportationGun->GetPlayer();

				Transform* playerTransform = player->GetComponent<Transform>();
				playerTransform->SetPosition(targetBullet->GetComponent<Transform>()->GetPosition()); // �÷��̾� ��ġ�� �Ѿ��� ��ġ�� ����
				
				Rigidbody* playerRigidbody = player->GetComponent<Rigidbody>();
				playerRigidbody->SetVelocity(Vector3::Zero);

				// �Ѿ� ���� �� TargetBullet �ʱ�ȭ
				Destroy(targetBullet);
				teleportationGun->SetTargetBullet(nullptr);
			}
		}
	}

	void TeleportationGunScript::LateUpdate()
	{
	}

	void TeleportationGunScript::Render()
	{
	}

	void TeleportationGunScript::Shoot()
	{
		TeleportationGun* teleportationGun = dynamic_cast<TeleportationGun*>(GetOwner());

		if (teleportationGun != nullptr)
		{
			// ==============================================
			// �Ѿ� ���� ���� Gun ��ġ �� ���� ���콺 ��ġ�� �߻�
			// ==============================================
			Vector2 mousePos = Input::GetMousPosition();
			Vector3 GunPos = teleportationGun->GetComponent<Transform>()->GetPosition();

			// ����ġ �޼� ��ǥ�� ��ǥ���� ��ġ�� ����
			GunPos = Camera::CaculatePos(GunPos);

			// ������ ��ǥ�� �� �޼� ��ǥ�� ����ȭ
			mousePos.x -= application.GetWidth() / 2.f;
			mousePos.y -= application.GetHeight() / 2.f;

			mousePos.x /= (application.GetWidth() / 2.f);
			mousePos.y /= (application.GetHeight() / 2.f);

			mousePos.y *= -1.f;
	
			// Gun ��ġ �� ���� ���콺 ��ġ
			Vector3 Dir = Vector3(0.f, 0.f, 0.f);
			Dir.x = mousePos.x - GunPos.x;
			Dir.y = mousePos.y - GunPos.y;

			// Gun ��ġ �缳��
			GunPos = teleportationGun->GetComponent<Transform>()->GetPosition();

			// ================================================
			// �Ѿ� ����
			// ================================================
			TeleportationBullet* bullet = new TeleportationBullet(teleportationGun, Dir);
			Transform* tr = bullet->AddComponent<Transform>();
			tr->SetPosition(GunPos); // �Ѿ� ������ġ�� ����ġ�� ����
			tr->SetScale(Vector3(0.1f, 0.1f, 0.1f));
			tr->SetColor(teleportationGun->GetGunColor());

			MeshRenderer* meshRenderer = bullet->AddComponent<MeshRenderer>();
			meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"CircleMesh"));
			meshRenderer->SetShader(ResourceManager::Find<Shader>(L"CircleShader"));

			Collider* col = bullet->AddComponent<Collider>();
			col->SetScale(Vector3(0.1f, 0.1f, 0.1f));

			bullet->AddComponent<BulletScript>();

			bullet->Initialize();

			SceneManager::GetActiveScene()->AddGameObject(bullet, LAYER::BULLET);

			// TargetBullet ����
			teleportationGun->SetTargetBullet(bullet);
		}
	}
}