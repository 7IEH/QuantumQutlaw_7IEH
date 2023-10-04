#include "qoEntanglementBullet.h"
#include "qoCollider.h"
#include "ArchitectureInclude.h"
#include "qoEnemy.h"
#include "qoSceneManager.h"
#include "qoMeshRenderer.h"
#include "qoResourceManager.h"
#include "qoBulletScript.h"

namespace qo
{
	EntanglementBullet::EntanglementBullet(Vector3 Dir)
		: Bullet(Dir),
		mIsEntangle(true)
	{
	}

	EntanglementBullet::~EntanglementBullet()
	{
	}

	void EntanglementBullet::Initialize()
	{
		GameObject::Initialize();
	}

	void EntanglementBullet::Update()
	{
		GameObject::Update();
	}

	void EntanglementBullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void EntanglementBullet::Render()
	{
		GameObject::Render();
	}

	void EntanglementBullet::OnCollisionEnter(Collider* other)
	{
		Wall* wall = dynamic_cast<Wall*> (other->GetOwner());
		DestuctibleWall* destuctibleWall = dynamic_cast<DestuctibleWall*> (other->GetOwner());
		Enemy* enemy = dynamic_cast<Enemy*>(other->GetOwner());

		// �浹�� ��ü�� �ش� ��ü�� Bullet ����
		/*if (wall == nullptr
			&& destuctibleWall == nullptr)
			return;*/

		// ���ʹ� �浹��
		if (mIsEntangle)
		{
			float Range = 1.f;

			if (enemy != nullptr)
			{
				// �浹�� ���ʹ� ��ü�� ������
				Vector3 first = enemy->GetComponent<Transform>()->GetPosition();

				// ���� �� ���ʹ̿� ����� ���ʹ� Ž��
				Scene* ActiveScene = SceneManager::GetActiveScene();
				std::vector<GameObject*> enemies = ActiveScene->GetLayer((UINT)LAYER::MONSTER)->GetGameObjects();
				long double min = 1.f;

				GameObject* target = nullptr;

				for (GameObject* enemyobj : enemies)
				{
					if (enemy == enemyobj)
						continue;
					Vector3 compare = enemyobj->GetComponent<Transform>()->GetPosition();
					long double Distance = sqrt(pow(static_cast<long double>(first.x) - static_cast<long double>(compare.x), 2) +
						pow(static_cast<long double>(first.x) - static_cast<long double>(compare.x), 2));
					if (static_cast<long double>(Range) > Distance && static_cast<long double>(min) > Distance)
					{
						min = Distance;
						target = enemyobj;
					}
				}

				// Ÿ���� ã�Ҵٸ� ���� ����
				if (target != nullptr)
				{
					Vector3 Dir = Vector3(0.f, 0.f, 0.f);
					Vector3 targetPosition = target->GetComponent<Transform>()->GetPosition();
					Dir.x = targetPosition.x - first.x;
					Dir.y = targetPosition.y - first.y;

					EntanglementBullet* bullet = new EntanglementBullet(Dir);
					bullet->SetEntangle(false);
					bullet->SetFirst(enemy);
					Transform* tr = bullet->AddComponent<Transform>();
					tr->SetPosition(first); // �Ѿ� ������ġ�� ����ġ�� ����
					tr->SetScale(Vector3(0.1f, 0.1f, 0.1f));

					MeshRenderer* meshRenderer = bullet->AddComponent<MeshRenderer>();
					meshRenderer->SetMesh(ResourceManager::Find<Mesh>(L"CircleMesh"));
					meshRenderer->SetShader(ResourceManager::Find<Shader>(L"CircleShader"));

					Collider* col = bullet->AddComponent<Collider>();
					col->SetScale(Vector3(0.1f, 0.1f, 0.1f));

					bullet->AddComponent<BulletScript>();
					bullet->Initialize();

					SceneManager::GetActiveScene()->AddGameObject(bullet, LAYER::BULLET);
				}
			}
		}
		else
		{
			if (mFirst == enemy)
				return;
		}

		Destroy(this);
	}

	void EntanglementBullet::OnCollisionStay(Collider* other)
	{
	}

	void EntanglementBullet::OnCollisionExit(Collider* other)
	{
	}
}