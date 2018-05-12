#include "utils.h"
#include <Windows.h>
#include "soil.h"

unsigned char* LoadFileContent(const char* path, int& fileSize)
{
	unsigned char* fileContent = nullptr;
	fileSize = 0;
	FILE* pFile = fopen(path, "rb");
	if (pFile)
	{
		fseek(pFile, 0, SEEK_END);
		int nLen = ftell(pFile);
		if (nLen > 0) {
			rewind(pFile);
			fileContent = new unsigned char[nLen + 1]; // \0
			fread(fileContent, sizeof(unsigned char), nLen, pFile);
			fileContent[nLen] = '\0';
			fileSize = nLen;
		}
		fclose(pFile);
	}
	return fileContent;
}

unsigned char* DecodeBMP(unsigned char* bmpFileData, int& width, int & height)
{
	if (0x4D42 == *((unsigned short*)bmpFileData))
	{
		int pixelDataOffset = *((int*)(bmpFileData + 10));
		width = *((int*)(bmpFileData + 18));
		height = *((int*)(bmpFileData + 22));
		unsigned char* pixelData = bmpFileData + pixelDataOffset;
		for (int i = 0; i < width*height * 3; i += 3) // (bmp) bgr - > rgb (opengl)
		{
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i + 2];
			pixelData[i + 2] = temp;
		}
		return pixelData;
	}
	return nullptr;
}

GLuint CreateTexture2D(unsigned char* pixelData, int width, int height, GLenum type)
{
	GLuint texture;
	glGenTextures(1, &texture); // ������Դ
	glBindTexture(GL_TEXTURE_2D, texture); // ��
	// GL_LINEAR�� ���Բ�ֵ
	// GL_NEAREST�� ȡ�����
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // �Ŵ������˲�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // ��С�����˲�
	// GL_CLAMP: ��������ȡ�߽�
	// GL_REPEAT: �ظ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // �������꣨0~1��������1.0�������ڱ߽�ȡ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);  // �� GL_CLAMP ��պб߽��нӷ�
	glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixelData);
	glBindTexture(GL_TEXTURE_2D, 0); // ����ǰ����������Ϊ0�ţ������Ժ��޸�
	return texture;
}

GLuint CreateTexture2DFromBMP(const char* bmpPath)
{
	int nFileSize = 0;
	unsigned char *bmpFileContent = LoadFileContent(bmpPath, nFileSize);
	if (bmpFileContent == nullptr)
	{
		return 0;
	}
	int bmpWidth = 0, bmpHeight = 0;
	unsigned char* pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
	if (bmpWidth == 0)
	{
		delete bmpFileContent;
		return 0;
	}
	GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
	delete bmpFileContent;
	return texture;
}

GLuint CreateDisplayList(std::function<void()>foo)
{
	GLuint displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	foo(); // �������еĲ�������������ʾ�б�
	glEndList();
	return displayList;
}

float GetFrameTime()
{
	static unsigned long lastTime = 0 , timeSinceComputerStart = 0;
	timeSinceComputerStart = GetTickCount(); // ����
	unsigned long frameTime = lastTime == 0 ? 0 : timeSinceComputerStart - lastTime;
	lastTime = timeSinceComputerStart;
	return float(frameTime) / 1000.0f;
}

// ����SOIL���ȡpngͼƬ
GLuint CreateTexture2DFromPNG(const char*imgFilePath, bool invertY)
{
	int nFileSize = 0;
	unsigned char *fileContent = LoadFileContent(imgFilePath, nFileSize);
	if (fileContent == nullptr)
	{
		return 0;
	}
	unsigned int flags = SOIL_FLAG_POWER_OF_TWO;
	if (invertY)
	{
		flags |= SOIL_FLAG_INVERT_Y;
	}
	GLuint texture = SOIL_load_OGL_texture_from_memory(fileContent, nFileSize, 0, 0, flags);
	delete fileContent;
	return texture;
}

GLuint CreateProcedureTexture(int size)
{
	unsigned char* imageData = new unsigned char[size * size * 4]; // size ��С rgba
	float halfSize = (float)size / 2.0f;
	float maxDistance = sqrtf(halfSize*halfSize + halfSize*halfSize);
	float centerX = halfSize;
	float centerY = halfSize;
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			int currentPixelOffset = (x + y*size) * 4;
			imageData[currentPixelOffset] = 255;
			imageData[currentPixelOffset + 1] = 255;
			imageData[currentPixelOffset + 2] = 255;
			float deltaX = (float)x - centerX;
			float deltaY = (float)y - centerY;
			float distance = sqrtf(deltaX*deltaX + deltaY*deltaY);
			float alpha = powf(1.0f - distance / maxDistance, 8.0f) ; // ���÷�����
			alpha = alpha > 1.0f ? 1.0f : alpha;
			imageData[currentPixelOffset + 3] = (unsigned char)(alpha*255.0f);
		}
	}
	GLuint texture = CreateTexture2D(imageData, size, size, GL_RGBA);
	delete imageData;
	return texture;
}