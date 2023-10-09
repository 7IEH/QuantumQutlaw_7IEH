#include "qoGunScript.h"
#include "qoGun.h"
#include "qoTransform.h"
#include "qoInput.h"

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

		if (owner == nullptr)
			return;

		Transform* GunTransform = owner->GetComponent<Transform>();
		Transform* PlayerTransform = owner->GetPlayer()->GetComponent<Transform>();
		Vector3 GunPos = PlayerTransform->GetPosition();

		if(owner->GetPlayer()->GetDirection() == eDirection::LEFT)
		{
			GunPos -= Vector3(0.1f, 0.f, 0.f);
		}
		else if (owner->GetPlayer()->GetDirection() == eDirection::RIGHT)
		{
			GunPos += Vector3(0.1f, 0.f, 0.f);
		}		

		GunTransform->SetPosition(GunPos);

		// =======================
		// ź�� ���� �Ҹ�� ���󺯰�
		// =======================
		if (owner->GetCurBulletCount() <= 0)
		{
			GunTransform->SetColor(Vector4::Zero);
		}

		// =======================
		// ź�� ������
		// =======================
		if (Input::GetKeyState(KEY_CODE::R) == KEY_STATE::DOWN)
		{
			owner->ReLoad();
		}
	}

	void GunScript::LateUpdate()
	{
	}

	void GunScript::Render()
	{
	}
}