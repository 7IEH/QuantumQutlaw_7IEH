#include "qoLabGuard.h"

namespace qo
{
    LabGuard::LabGuard()
    {
        SetType(eMelee);
        SetStage(eSearch);
        SetHP(50);
        SetMovementSpeed(50);
        SetATK(10);
    }

    LabGuard::~LabGuard()
    {
    }

    void LabGuard::Search()
    {
        // ���� �ۼ�
    }

    void LabGuard::Chase()
    {
        // ���� �ۼ�
    }

    void LabGuard::Attack()
    {
        // ���� �ۼ�
    }

    void LabGuard::Dead()
    {
    }

    void LabGuard::TakeHit(int DamageAmount, math::Vector3 HitDir)
    {
    }
}
