#include "ConstantBuffer.hlsli"

struct VTX_IN
{
	float3 vPos : POSITION;
	float4 vColor : COLOR;
};

struct VTX_OUT
{
	float4 vPos : SV_Position;
	float4 vColor : COLOR;
};

VTX_OUT VS(VTX_IN _in)
{
	VTX_OUT output = (VTX_OUT) 0.f;
    
	output.vPos = float4(_in.vPos * Test_Scale.xyz, 1.f);
	output.vPos.xyz += Test_Pos.xyz;
	output.vColor = Test_Color; // ��������� �������� ����
    
	return output;
}
