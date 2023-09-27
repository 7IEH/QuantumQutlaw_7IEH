#include "qoLabGuard.h"

namespace qo
{
    LabGuard::LabGuard()
        : myTYPE(eMelee)
        , mySTAGE(eSearch)
        , myHP(50)
        , mySPEED(50)
        , myATK(10)
    {
        SetType(myTYPE);
        SetStage(mySTAGE);
        SetHP(myHP);
        SetMovementSpeed(mySPEED);
        SetATK(myATK);
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

    void LabGuard::Hit(int damage)
    {
        myHP -= damage;
    }

    void LabGuard::Dead()
    {
        // ���� �ۼ�
    }
}
