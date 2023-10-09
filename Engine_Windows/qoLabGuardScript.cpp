#include "qoLabGuardScript.h"
#include "qoTransform.h"
#include "qoTime.h"

namespace qo
{
	LabGuardScript::LabGuardScript()
		: mLabGuard(nullptr)
	{

	}

	LabGuardScript::~LabGuardScript()
	{
	}

	void LabGuardScript::Initialize()
	{
		mLabGuard = dynamic_cast<LabGuard*>(GetOwner());

		assert(mLabGuard);
	}

	void LabGuardScript::Update()
	{
		switch (mLabGuard->GetStage())
		{
		case eStage::eSearch:
			Search();
			break;
		case eStage::eChase:
			mLabGuard->Chase();
			break;
		case eStage::eAttack:
			mLabGuard->Attack();
			break;
		case eStage::eHit:
			//mLabGuard->TakeHit();
			break;
		case eStage::eDead:
			mLabGuard->Dead();
			break;
		default:
			break;
		}

		LabGuard* obj = dynamic_cast<LabGuard*>(GetOwner());

		if (obj != nullptr)
		{
			std::cout << "null";
		}
	}

	void LabGuardScript::LateUpdate()
	{
	}

	void LabGuardScript::Render()
	{
	}

	void LabGuardScript::Search()
	{
		Transform* tr = mLabGuard->GetComponent<Transform>();
		Vector3 LabGuardPos = tr->GetPosition();

		if (mLabGuard->Dir == -1)
		{
			LabGuardPos.x -= mLabGuard->GetMovementSpeed() * Time::DeltaTime();
			
			//if (mLabGuard->pos.x + 0.3f < LabGuardPos.x)
			//{
			//	mLabGuard->Dir *= -1;
			//}
		}

		else if (mLabGuard->Dir == 1)
		{
			LabGuardPos.x += mLabGuard->GetMovementSpeed() * Time::DeltaTime();
			//
			//if (mLabGuard->pos.x - 0.3f > LabGuardPos.x)
			//{
			//	mLabGuard->Dir *= -1;
			//}
		}

		tr->SetPosition(LabGuardPos);

		// monster�� wall�̶� �浹ó���Ǹ� dir * -1 �ؼ� ���� ��ȯ�ϱ�
	}

	void LabGuardScript::Chase()
	{
		// player ��ġ �޾Ƽ� ���󰡱�
	}

	void LabGuardScript::Attack()
	{
		// ������ ��Ʈ�ڽ� �ȿ� �÷��̾� �����ϸ� �����ϱ�
	}

	void LabGuardScript::Hit()
	{
		// �÷��̾ �����ϸ� ���ݹ���
	}

	void LabGuardScript::Dead()
	{
		// hp 0�Ǹ� dead
	}

}
