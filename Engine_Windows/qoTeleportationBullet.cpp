#include "qoTeleportationBullet.h"
#include "qoCollider.h"
#include "ArchitectureInclude.h"
#include "qoTeleportationGun.h"

namespace qo
{
	TeleportationBullet::TeleportationBullet(TeleportationGun* onwer, Vector3 Dir)
		: Bullet(Dir)
		, mOwner(onwer)
	{
	}

	TeleportationBullet::~TeleportationBullet()
	{
		// �Ѿ� ������ Onwer �� Ÿ���� �� �Ѿ��̸� nullptr�� �ʱ�ȭ
		if (mOwner->GetTargetBullet() == this)
		{
			mOwner->SetTargetBullet(nullptr);
		}
	}

	void TeleportationBullet::Initialize()
	{
		GameObject::Initialize();
	}

	void TeleportationBullet::Update()
	{
		GameObject::Update();
	}

	void TeleportationBullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void TeleportationBullet::Render()
	{
		GameObject::Render();
	}

	void TeleportationBullet::OnCollisionEnter(Collider* other)
	{
		Wall* wall = dynamic_cast<Wall*> (other->GetOwner());
		DestuctibleWall* destuctibleWall = dynamic_cast<DestuctibleWall*> (other->GetOwner());

		// �浹�� ��ü�� �ش� ��ü�� Bullet ����
		if (wall == nullptr
			&& destuctibleWall == nullptr)
			return;

		Destroy(this);
	}

	void TeleportationBullet::OnCollisionStay(Collider* other)
	{
	}

	void TeleportationBullet::OnCollisionExit(Collider* other)
	{
	}
}