#include "qoTeleportationBullet.h"
#include "qoCollider.h"
#include "ArchitectureInclude.h"

namespace qo
{
	TeleportationBullet::TeleportationBullet(Vector3 Dir)
		: Bullet(Dir)
	{
	}

	TeleportationBullet::~TeleportationBullet()
	{
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