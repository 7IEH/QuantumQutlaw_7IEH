#pragma once
#include "qoGameObject.h"

namespace qo
{
	class Guard : public GameObject
	{
	public:
		enum class eState
		{
			Serch,	// �¿�� �����̸鼭 �÷��̾� ã��
			Follow,	// �÷��̾� ã���� ���󰡱�
			Attack,
			Hit,
			Death,
			End,
		};

		Guard();
		virtual ~Guard();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		//virtual int Hp override;
	private:
		eState mState;
	};
}