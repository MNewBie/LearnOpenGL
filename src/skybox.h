#pragma once
#include "gg.h"
class SkyBox {
	GLuint mTextures[6];
	GLuint mFastDrawCall; // �洢��ʾ�б�,��һϵ�в������
public:
	void Init(const char* imageDir);
	void DrawCommand();
	void Draw(float x, float y, float z);
};