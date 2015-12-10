#ifndef _MODEL_H_
#define _MODEL_H_

#include "BaseMesh.h"
#include "TokenStream.h"
#include <vector>

using namespace DirectX;

class Model : public BaseMesh
{
	struct ModelType
	{
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};

	struct NormalVertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
		XMFLOAT3 normal;
	};

public:
	Model(ID3D11Device* device, WCHAR* textureFilename, WCHAR* filename);
	~Model();

	void LoadNormalMap(ID3D11Device* device, WCHAR* filename) { m_Normals = new Texture(device, filename); }	
	void LoadSpecularMap(ID3D11Device* device, WCHAR* filename) { m_Specular = new Texture(device, filename); }
	ID3D11ShaderResourceView* GetNormals() { return m_Normals->GetTexture(); }
	ID3D11ShaderResourceView* GetSpecular() { return m_Specular->GetTexture(); }
	void SendData( ID3D11DeviceContext* deviceContext ) override;

protected:
	void InitBuffers(ID3D11Device* device);
	void LoadModel(WCHAR* filename);
	
	ModelType* m_model;	

	Texture* m_Normals;
	Texture* m_Specular;
};

#endif