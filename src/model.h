#pragma once
#include "gg.h"

struct VertexData { // opengl 绘制数据
	float position[3];
	float normal[3];
	float texcoord[2];
};

class Model{
	VertexData* mVertexes;
	unsigned short* mIndexes; // 点绘制面
	int mIndexCount;

	// 模型材质， 即不同的反射系数
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];
public:
	GLuint mTexture;
	Model();
	void Init(const char* modelPath);
	void Draw();

	void SetAmbientMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);

};