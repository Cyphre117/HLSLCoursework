#ifndef _LIGHT_H_
#define _LIGHT_H_

#include <directxmath.h>

using namespace DirectX;

class Light
{

public:
	void* operator new(size_t i)
	{
		return _mm_malloc(i, 16);
	}

	void operator delete(void* p)
	{
		_mm_free(p);
	}

	Light();

	void GenerateViewMatrix();
	void GenerateProjectionMatrix(float, float);

	// Setters
	void SetAmbientColour(float, float, float, float);
	void SetDiffuseColour(float, float, float, float);
	void SetDirection(float, float, float);
	void SetSpecularColour(float, float, float, float);
	void SetSpecularPower(float);
	void SetPosition(float, float, float);
	void SetLookAt(float, float, float);

	void SetRange( float r ) { range = r; }
	void setAttenuation( float c, float l, float q ) { constantAttenuation = c; linearAttenuation = l; quadraticAttenuation = q; }

	// Getters
	XMFLOAT4 GetAmbientColour();
	XMFLOAT4 GetDiffuseColour();
	XMFLOAT3 GetDirection();
	XMFLOAT4 GetSpecularColour();
	float GetSpecularPower();
	XMFLOAT3 GetPosition();
	XMFLOAT4 GetPosition4();
	XMMATRIX GetViewMatrix();
	XMMATRIX GetProjectionMatrix();

	inline float GetRange() { return range; }
	inline float GetConstantAttenuation() { return constantAttenuation; }
	inline float GetLinearAttenuation() { return linearAttenuation; }
	inline float GetQuadraticAttenuation() { return quadraticAttenuation; }

protected:
	XMFLOAT4 m_ambientColour;
	XMFLOAT4 m_diffuseColour;
	XMFLOAT3 m_direction;
	XMFLOAT4 m_specularColour;
	float m_specularPower;
	XMVECTOR m_position;
	XMMATRIX m_viewMatrix;
	XMMATRIX m_projectionMatrix;
	XMVECTOR m_lookAt; 

	float range;
	float constantAttenuation;
	float linearAttenuation;
	float quadraticAttenuation;
};

#endif