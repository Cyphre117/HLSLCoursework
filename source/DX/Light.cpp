// Light class
// Holds data that represents a light source

#include "light.h"

Light::Light()
{
	SetAmbientColour( 0.0f, 0.0f, 0.0f, 1.0f );
	SetDiffuseColour( 0.5f, 0.5f, 0.5f, 1.0f );
	SetSpecularColour( 1.0f, 1.0f, 1.0f, 1.0f );
	SetSpecularPower( 25.0f );
	SetRange( 64.0f );
	setAttenuation( 0.5f, 0.125f, 0.02f );
}

void Light::GenerateViewMatrix()
{
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f);

	//up = XMVectorSetX(up, 0.0f);
	//up = XMVectorSetY(up, 1.0f);
	//up = XMVectorSetZ(up, 0.0f);

	// Create the view matrix from the three vectors.
	m_viewMatrix = XMMatrixLookAtLH(m_position, m_lookAt, up);
}

void Light::GenerateProjectionMatrix(float screenNear, float screenFar)
{
	float fieldOfView, screenAspect;

	// Setup field of view and screen aspect for a square light source.
	fieldOfView = (float)XM_PI / 2.0f;
	screenAspect = 1.0f;

	// Create the projection matrix for the light.
	m_projectionMatrix = XMMatrixPerspectiveFovLH(fieldOfView, screenAspect, screenNear, screenFar);
}

void Light::SetAmbientColour(float red, float green, float blue, float alpha)
{
	m_ambientColour = XMFLOAT4(red, green, blue, alpha);
}

void Light::SetDiffuseColour(float red, float green, float blue, float alpha)
{
	m_diffuseColour = XMFLOAT4(red, green, blue, alpha);
}


void Light::SetDirection(float x, float y, float z)
{
	m_direction = XMFLOAT3(x, y, z);
}

void Light::SetSpecularColour(float red, float green, float blue, float alpha)
{
	m_specularColour = XMFLOAT4(red, green, blue, alpha);
}


void Light::SetSpecularPower(float power)
{
	m_specularPower = power;
}

void Light::SetPosition(float x, float y, float z)
{
	m_position = XMVectorSet(x, y, z, 1.0f);
}

XMFLOAT4 Light::GetAmbientColour()
{
	return m_ambientColour;
}

XMFLOAT4 Light::GetDiffuseColour()
{
	return m_diffuseColour;
}


XMFLOAT3 Light::GetDirection()
{
	return m_direction;
}

XMFLOAT4 Light::GetSpecularColour()
{
	return m_specularColour;
}


float Light::GetSpecularPower()
{
	return m_specularPower;
}

XMFLOAT3 Light::GetPosition()
{
	XMFLOAT3 temp(XMVectorGetX(m_position), XMVectorGetY(m_position), XMVectorGetZ(m_position));
	return temp;
}

XMFLOAT4 Light::GetPosition4()
{
	XMFLOAT4 temp(XMVectorGetX(m_position), XMVectorGetY(m_position), XMVectorGetZ(m_position), 1.0f);
	return temp;
}

void Light::SetLookAt(float x, float y, float z)
{
	m_lookAt = XMVectorSet(x, y, z, 1.0f);
}

XMMATRIX Light::GetViewMatrix()
{
	return m_viewMatrix;
}

XMMATRIX Light::GetProjectionMatrix()
{
	return m_projectionMatrix;
}