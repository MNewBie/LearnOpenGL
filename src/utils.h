#pragma once
#include "gg.h"

unsigned char* LoadFileContent(const char* path, int& fileSize); // 读取数据
unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int & height); // 解码数据
GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type); // 创建纹理
GLuint CreateTexture2DFromBMP(const char* bmpPath);
GLuint CreateDisplayList(std::function<void()>foo); // 显示列表

float GetFrameTime(); //得到每帧时间

GLuint CreateTexture2DFromPNG(const char*imgFilePath, bool invertY = true);

GLuint CreateProcedureTexture(int size); // 生成程序纹理, 即不是读入的，是由代码生成的