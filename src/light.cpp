#include "light.h"

// ---- 基类
Light::Light()
{

}

void Light::SetAmbientColor(float r, float g, float b, float a)
{
	float ambientColor[] = { r, g, b, a };
	glLightfv(mLightIdentifier, GL_AMBIENT, ambientColor);
}


void Light::SetDiffuseColor(float r, float g, float b, float a)
{
	float diffuseColor[] = { r, g, b, a };
	glLightfv(mLightIdentifier, GL_DIFFUSE, diffuseColor);
}


void Light::SetSpecularColor(float r, float g, float b, float a)
{
	float specularColor[] = { r, g, b, a };
	glLightfv(mLightIdentifier, GL_SPECULAR, specularColor);
}


void Light::Enable()
{
	glEnable(GL_LIGHTING);
	glEnable(mLightIdentifier);
}

// ----- 方向光
DirectionLight::DirectionLight(GLenum light)
{
	mLightIdentifier = light;
}

void DirectionLight::SetPosition(float x, float y, float z)
{
	float pos[] = { x, y, z, 0.0f };
	glLightfv(mLightIdentifier, GL_POSITION, pos);
}

// --- 点光源
PointLight::PointLight(GLenum light)
{
	mLightIdentifier = light;
	memset(mPosition, 0, sizeof(mPosition));
}
void PointLight::SetPosition(float x, float y, float z)
{
	mPosition[0] = x; mPosition[1] = y; mPosition[2] = z;
	/*
	float pos[] = { x, y, z, 1.0f };
	glLightfv(mLightIdentifier, GL_POSITION, pos);
	*/
}
void PointLight::Update(float x, float y, float z)
{
	float pos[] = { mPosition[0] - x, mPosition[1] - y, mPosition[2] - z, 1.0f }; // 减去摄像机偏移
	glLightfv(mLightIdentifier, GL_POSITION, pos);
}

// c：常数衰减因子， l：线性衰减因子， q：平方衰减因子， d：受光点与光源的距离
// f = 1 / (c + l*d + q*q*d)
// 光的亮度 = 初始亮度 * f
void PointLight::SetConstAttenuation(float v) // 默认 1.0
{
	glLightf(mLightIdentifier, GL_CONSTANT_ATTENUATION, v);
}
void PointLight::SetLineAttenuation(float v) // 默认 0.0
{
	glLightf(mLightIdentifier, GL_LINEAR_ATTENUATION, v);
}
void PointLight::SetQuadricAttenuation(float v) // 默认 0.0
{
	glLightf(mLightIdentifier, GL_QUADRATIC_ATTENUATION, v);
}
// ----- 探照灯
SpoltLight::SpoltLight(GLenum light) :PointLight(light) {

}
void SpoltLight::SetDirection(float x, float y, float z)
{
	float dir[] = { x, y, z };
	glLightfv(mLightIdentifier, GL_SPOT_DIRECTION, dir);
}
void SpoltLight::SetExponent(float v)
{
	glLightf(mLightIdentifier, GL_SPOT_EXPONENT, v); 
}
void SpoltLight::SetCutoff(float v)
{
	glLightf(mLightIdentifier, GL_SPOT_CUTOFF, v);
}