#pragma once
#include "qoGameObject.h"

namespace qo
{
    // FSM State Script ���� ������
    enum class ePlayerState
    {
        Idle,
        Walk,
        Jump,
        Dead,
    };

    class Gun;
    class Player : public GameObject
    {
        friend class PlayerScript;
    public:
        Player();
        virtual ~Player();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

        void AddGun();
        virtual void TakeHit(int DamageAmount, math::Vector3 HitDir = Vector3::Zero);

    private:
        Gun*                mActiveGun; // ���� Ȱ��ȭ�� ��
        std::vector<Gun*>   mGuns;      // �÷��̾ �����ϰ��ִ� ��

        ePlayerState        mState;

        int                 mHp;
        float               mSpeed;
    };
}

