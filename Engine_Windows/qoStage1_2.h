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
		// ��ü�� Transform, MeshRenderer, Collider�� �Է��� ���� ���� �ڵ����� ���ִ� �Լ�
		void CreateAndSetUpGameObject(GameObject* object, LAYER objectLayer,float xPixels, float yPixels, float widthInPixels, float heightInPixels, const Vector4& color);

	private:
		DoorSwitch* OpenSwitch;
		LockedDoor* Goal;
	};
}
