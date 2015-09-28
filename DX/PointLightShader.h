// Light shader.h
// Basic single light shader setup
#ifndef _POINT_LIGHTSHADER_H_
#define _POINT_LIGHTSHADER_H_

#include "BaseShader.h"
#include "light.h"
#include "Camera.h"

using namespace std;
using namespace DirectX;

#define NUM_LIGHTS 2

class PointLightShader : public BaseShader
{
private:
	struct LightBufferType
	{
		// Ambient colour is global and defined by light[0]
		XMFLOAT4 ambient;
		XMFLOAT4 diffuse[NUM_LIGHTS];
		XMFLOAT4 position[NUM_LIGHTS];

		XMFLOAT4 specular[2];

		float specularPower[2];
		float padding[2];
	};

	struct CameraBufferType
	{
		XMFLOAT3 position;
		float padding;
	};

public:

	PointLightShader(ID3D11Device* device, HWND hwnd);
	~PointLightShader();

	void SetShaderParameters( ID3D11DeviceContext* deviceContext,
							  const XMMATRIX &world,
							  const XMMATRIX &view,
							  const XMMATRIX &projection,
							  ID3D11ShaderResourceView* texture,
							  Camera* camera,
							  Light* light[2]);

	void Render(ID3D11DeviceContext* deviceContext, int vertexCount);

private:
	void InitShader(WCHAR*, WCHAR*);

private:
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_lightBuffer;
	ID3D11Buffer* m_cameraBuffer;
};

#endif