#include "qoGunScript.h"
#include "qoGun.h"
#include "qoTransform.h"

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
		Transform* PlayerTransform = owner->GetPlayer()->GetComponent<Transform>();

		Vector3 GunPos = PlayerTransform->GetPosition() + Vector3(0.2f, 0.f, 0.f);

		GunTransform->SetPosition(GunPos);
	}

	void GunScript::LateUpdate()
	{
	}

	void GunScript::Render()
	{
	}
}