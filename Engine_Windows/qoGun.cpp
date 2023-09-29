#include "qoGun.h"

namespace qo
{
	Gun::Gun(eGunType type, Player* owner, UINT bulletCount)
		: mGunType(type)
		, mPlayer(owner)
		, mBulletCount(bulletCount)
	{
	}

	Gun::~Gun()
	{
	}

	bool Gun::BulletConsumption(UINT amount)
	{
		// �Ҹ�Ǵ� ���� �����ִ� ź�˺��� ���ٸ� ����ó��
		if(mBulletCount - amount < 0)
			return false;

		mBulletCount -= amount;
		return true;
	}
}