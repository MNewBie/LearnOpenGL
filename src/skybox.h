#pragma once
#include "gg.h"
class SkyBox {
	GLuint mTextures[6];
	GLuint mFastDrawCall; // 存储显示列表,将一系列操作打包
public:
	void Init(const char* imageDir);
	void DrawCommand();
	void Draw(float x, float y, float z);
};