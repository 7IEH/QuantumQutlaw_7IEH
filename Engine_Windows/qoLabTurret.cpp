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

    void LabTurret::Hit(int damage)
    {
        int currentHP = GetHP();
        currentHP -= damage;
        SetHP(currentHP);
    }

    void LabTurret::Dead()
    {
        // ���� �ۼ�
    }
}
