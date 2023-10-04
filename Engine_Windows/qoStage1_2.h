#pragma once
#include "..\\Engine_SOURCE\\qoScene.h"
#include "ArchitectureInclude.h"
#include "qoGameObject.h"

namespace qo
{
	class Stage1_2 : public Scene
	{
	public:
		Stage1_2();
		virtual ~Stage1_2();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		// Ư�� tag ���� ���� ��� ���� �����ִ� �Լ�
		void UnlockDoor(int tag);

	private:
		static const int EventSwitchCount = 2;
		DoorSwitch* EventSwitch[EventSwitchCount];
		static const int EventDoorCount = 3;
		LockedDoor* EventTrap;
		LockedDoor* EventDoor[EventDoorCount];
	};
}
