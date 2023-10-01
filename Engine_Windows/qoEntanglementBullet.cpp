#include "qoEntanglementBullet.h"
#include "qoCollider.h"
#include "ArchitectureInclude.h"

namespace qo
{
	EntanglementBullet::EntanglementBullet(Vector3 Dir)
		: Bullet(Dir)
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

		// �浹�� ��ü�� �ش� ��ü�� Bullet ����
		if (wall == nullptr
			&& destuctibleWall == nullptr)
			return;

		Destroy(this);
	}

	void EntanglementBullet::OnCollisionStay(Collider* other)
	{
	}

	void EntanglementBullet::OnCollisionExit(Collider* other)
	{
	}
}