#pragma once
#include "qoComponent.h" 

namespace qo
{
	class Collider : public Component
	{
	public:
		Collider();
		virtual ~Collider();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetScale(math::Vector3 scale) { mScale = scale; }
		math::Vector3 GetScale() { return mScale; }

		math::Vector3 SetAffectedCamera(bool affectedcamera) { mAffectedCamera = affectedcamera; }

		void SetOffset(math::Vector3 offset) { mOffset = offset; }
		math::Vector3 GetOffset() { return mOffset; }

	private:
		math::Vector3 mScale;
		math::Vector3 mOffset;
		bool mbisCollision;
		bool mAffectedCamera;
	};
}

