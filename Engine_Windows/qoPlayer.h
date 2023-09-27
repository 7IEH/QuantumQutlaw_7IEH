#pragma once
#include "qoGameObject.h"

namespace qo
{
    class Gun;
    class Player : public GameObject
    {
    public:
        Player();
        virtual ~Player();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void LateUpdate() override;
        virtual void Render() override;

        void AddGun();

    private:
        Gun*                mActiveGun; // ���� Ȱ��ȭ�� ��
        std::vector<Gun*>   mGuns;      // �÷��̾ �����ϰ��ִ� ��
    };
}

