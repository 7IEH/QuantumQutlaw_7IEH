#include "qoBulletScript.h"
#include "qoBullet.h"
#include "qoTransform.h"
#include "qoTime.h"

namespace qo
{
	BulletScript::BulletScript()
	{
	}

	BulletScript::~BulletScript()
	{
	}

	void BulletScript::Initialize()
	{
	}

	void BulletScript::Update()
	{
		Bullet* bullet = dynamic_cast<Bullet*>(GetOwner());
		
		// Bullet�� �����ִ� �������� �ʴ� 5.f �� �ӵ��� �̵�
		if (bullet != nullptr)
		{
			Transform* tr = bullet->GetComponent<Transform>();
			Vector3 dir = bullet->mDir;

			Vector3 pos = tr->GetPosition();

			dir.Normalize();

			pos += dir * 5.f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void BulletScript::LateUpdate()
	{
	}

	void BulletScript::Render()
	{
	}
}