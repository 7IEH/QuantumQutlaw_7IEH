#include "qoLabTurret.h"

namespace qo
{
    LabTurret::LabTurret()
    {
        SetType(eRanged);
        SetStage(eSearch);
        SetHP(80);
        SetMovementSpeed(0);
        SetATK(15);
    }

    LabTurret::~LabTurret()
    {
    }

    void LabTurret::Search()
    {
        // ���� �ۼ�
    }

    void LabTurret::Chase()
    {
        // ���� �ۼ�
    }

    void LabTurret::Attack()
    {
        // ���� �ۼ�
    }

    void LabTurret::Dead()
    {
    }

    void LabTurret::TakeHit(int DamageAmount, math::Vector3 HitDir)
    {
    }
}
