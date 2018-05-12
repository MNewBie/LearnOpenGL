#pragma once
#include "gg.h"
// -- 基类
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

// 方向光
class DirectionLight : public Light {
public:
	DirectionLight(GLenum light);
	void SetPosition(float x, float y, float z);
};

// 点光源
class PointLight : public Light {
	float mPosition[3]; // 解决摄像机移动时，光源跟着移动
public:
	PointLight(GLenum light);
	void SetPosition(float x, float y, float z);
	void SetConstAttenuation(float v);
	void SetLineAttenuation(float v);
	void SetQuadricAttenuation(float v);
	
	void Update(float x, float y, float z); // 传入摄像机坐标
};
// 探照灯
class SpoltLight : public PointLight {
public:
	SpoltLight(GLenum light);
	void SetDirection(float x, float y, float z); // 方向
	void SetExponent(float v); // 聚光度 
	void SetCutoff(float v); //照射范围, 角度
};