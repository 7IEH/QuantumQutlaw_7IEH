#include "qoLabTurretScript.h"
#include "qoLabTurret.h"
#include "qoTransform.h"
#include "qoRigidbody.h"
#include "qoPlayer.h"

namespace qo
{
	LabTurretScript::LabTurretScript()
		: mLabTurret(nullptr)
		, mTransform(nullptr)
		, mRigidbody(nullptr)
	{

	}

	LabTurretScript::~LabTurretScript()
	{
	}

	void LabTurretScript::Initialize()
	{
		mLabTurret = dynamic_cast<LabTurret*>(GetOwner());
		mTransform = mLabTurret->GetComponent<Transform>();
		mRigidbody = mLabTurret->GetComponent<Rigidbody>();
		LabTurretPos = mTransform->GetPosition();

		mPlayer = dynamic_cast<LabTurret*>(GetOwner())->mPlayer;
		mPlayerTr = mPlayer->GetComponent<Transform>();

		assert(mLabTurret);
	}

	void LabTurretScript::Update()
	{
		switch (mLabTurret->GetStage())
		{
		case eStage::eSearch:
			Search();
			break;
		case eStage::eFall:
			Fall();
			break;
		case eStage::eAttack:
			Attack();
			break;
		case eStage::eHit:
			//mEnemy->TakeHit();
			break;
		case eStage::eDead:
			Dead();
			break;
		default:
			break;
		}

		PlayerPos = mPlayerTr->GetPosition();

		LabTurret* obj = dynamic_cast<LabTurret*>(GetOwner());

		if (obj != nullptr)
		{
			std::cout << "null";
		}
	}

	void LabTurretScript::LateUpdate()
	{
	}

	void LabTurretScript::Render()
	{
	}

	void LabTurretScript::Search()
	{
		if (!mRigidbody->GetGround())
		{
			mLabTurret->SetStage(eStage::eFall);
		}

		// +-0.5 ���� ���� �÷��̾ �����ϸ� attack �Լ���
		if ((LabTurretPos.x - 0.5f <= PlayerPos.x) && (LabTurretPos.x + 0.5f >= PlayerPos.x))
		{
			mLabTurret->SetStage(eStage::eAttack);
		}
	}

	void LabTurretScript::Fall()
	{
		if (mRigidbody->GetGround())
		{
			mLabTurret->SetStage(eStage::eSearch);
		}
	}

	void LabTurretScript::Attack()
	{
		// �Ѿ� ����� (���� �����ְ�)
		// +- 0.5 ���� ���� �÷��̾ �����ϸ� �����Ѵ�
		if ((LabTurretPos.x - 0.5f <= PlayerPos.x) && (LabTurretPos.x + 0.5f >= PlayerPos.x))
		{

		}

		// +- 0.5 ���� ���� �÷��̾ �������� ������ search
		else
		{
			mLabTurret->SetStage(eStage::eSearch);
		}
	}

	void LabTurretScript::Hit()
	{
		// �������� ��Ʈ�Լ��� �Ȱ���
	}

	void LabTurretScript::Dead()
	{
	}

}
