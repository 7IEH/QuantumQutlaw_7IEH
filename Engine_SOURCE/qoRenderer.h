#pragma once
#include "qoEnums.h"
#include "CommonInclude.h"
#include "qoEngine.h"
#include "qoMath.h"
#include "qoGraphicsDevice_DX11.h"

#include "qoMesh.h"
#include "qoShader.h"
#include "qoConstantBuffer.h"

using namespace qo::graphics;
using namespace qo::enums;
using namespace qo::math;

namespace qo::renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Vector3 pos;
		int padd1;

		Vector3 scale;
		int padd2;

		Vector4 color;
	};

	// Color Test �뵵
	CBUFFER(ColorSetCB, CBSLOT_ColorSet)
	{
		Vector4 pos;
		Vector4 scale;
		Vector4 color;
	};

	extern Mesh* TriangleMesh;
	extern Mesh* RectangleMesh;
	extern Mesh* CircleMesh;
	
	extern Shader* shader;
	extern Shader* ColorTestShader;
	extern Shader* CircleShader;

	// Basic Collider
	extern Mesh* BasicRectangleMesh;
	extern Shader* ColorTestShader2;

	// Constant Buffer
	extern ConstantBuffer* constantBuffers[];

	// Initialize the renderer
	void Initialize();
	void Release();
}
