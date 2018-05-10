#include "scene.h"
#include "utils.h"
GLuint texture;

void Init()
{
	glMatrixMode(GL_PROJECTION); // 设置矩阵格式 -》投影矩阵
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f); // 垂直视角、画布宽高比、最近看到的距离、最远看到距离
	glMatrixMode(GL_MODELVIEW); // 模型视口矩阵
	glLoadIdentity(); // 给个单位阵，暂不修改

	texture = CreateTexture2DFromBMP("Res/test.bmp");
}

void DrawModel()
{
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);  
	glVertex3f(-0.5f, -0.2f, -5.0f); // 1
	glVertex3f(0.5f, -0.2f, -5.0f); // 2
	glVertex3f(0.5f, -0.2f, -1.0f);  // 3
	glVertex3f(-0.5f, -0.2f, -1.0f); // 4
	glEnd();
}


void Draw()
{
	glClearColor(0.1f, 0.4f, 0.6f, 1.0f); // 设置颜色 rgba 0.0 ~ 1.0
	glClear(GL_COLOR_BUFFER_BIT); // 擦除颜色缓冲区

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	glTexCoord2d(0.0f, 0.0f);
	glVertex3f(-0.1f, -0.1f, -0.4f);
	glTexCoord2d(1.0f, 0.0f);
	glVertex3f(0.1f, -0.1f, -0.4f);
	glTexCoord2d(1.0f, 1.0f);
	glVertex3f(0.1f, 0.1f, -0.4f);
	glTexCoord2d(0.0f, 1.0f);
	glVertex3f(-0.1f, 0.1f, -0.4f);
	glEnd();

}