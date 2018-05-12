#pragma once
#include "gg.h"
// -- ����
class Light {
protected:
	GLenum mLightIdentifier;
	Light();
public:
	void SetAmbientColor(float r, float g, float b, float a);
	void SetDiffuseColor(float r, float g, float b, float a);
	void SetSpecularColor(float r, float g, float b, float a);
	void Enable();
};

// �����
class DirectionLight : public Light {
public:
	DirectionLight(GLenum light);
	void SetPosition(float x, float y, float z);
};

// ���Դ
class PointLight : public Light {
	float mPosition[3]; // ���������ƶ�ʱ����Դ�����ƶ�
public:
	PointLight(GLenum light);
	void SetPosition(float x, float y, float z);
	void SetConstAttenuation(float v);
	void SetLineAttenuation(float v);
	void SetQuadricAttenuation(float v);
	
	void Update(float x, float y, float z); // �������������
};
// ̽�յ�
class SpoltLight : public PointLight {
public:
	SpoltLight(GLenum light);
	void SetDirection(float x, float y, float z); // ����
	void SetExponent(float v); // �۹�� 
	void SetCutoff(float v); //���䷶Χ, �Ƕ�
};