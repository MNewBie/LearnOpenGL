#include "scene.h"

void Init()
{
	glMatrixMode(GL_PROJECTION); // 设置矩阵格式 -》投影矩阵
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f); // 垂直视角、画布宽高比、最近看到的距离、最远看到距离
	glMatrixMode(GL_MODELVIEW); // 模型视口矩阵
	glLoadIdentity(); // 给个单位阵，暂不修改
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 设置颜色 rgba 0.0 ~ 1.0
	glClear(GL_COLOR_BUFFER_BIT); // 擦除颜色缓冲区

	// 移动物体
	/*
	glLoadIdentity(); // 注意当前是模型视口矩阵,参见初始化处
	glTranslatef(0.0f, 0.0f, -2.5f); // x、y、z ,此操作后就可以让以后所有的模型都带一个相应的偏移
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 0, 0, 255);  glVertex3f(-0.5f, -0.25f, 0.0f); // 1
	glColor4ub(0, 0, 255, 255);  glVertex3f(0.5f, -0.25f, 0.0f); // 2
	glColor4ub(0, 255, 0, 255);  glVertex3f(0.0f, 0.5f, 0.0f);  // 3
	glEnd();
	*/

	// 旋转物体
	/*
	glLoadIdentity(); // 注意当前是模型视口矩阵,参见初始化处
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f); // 绕物体坐标系（0，0，1）轴旋转30角度， 此处物体坐标轴仍在世界原点处
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 0, 0, 255);  glVertex3f(-0.5f, -0.25f, -2.5f); // 1
	glColor4ub(0, 0, 255, 255);  glVertex3f(0.5f, -0.25f, -2.5f); // 2
	glColor4ub(0, 255, 0, 255);  glVertex3f(0.0f, 0.5f, -2.5f);  // 3
	glEnd();
	*/

	// 缩放物体
	glLoadIdentity(); // 注意当前是模型视口矩阵,参见初始化处
	glScalef(0.2f, 0.2f, 0.2f); // x、y、z 缩放系数，缩放的是物体坐标系,由于物体坐标轴仍在世界原点处 z轴缩小离视角更近效果可能不会明显
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 0, 0, 255);  glVertex3f(-0.5f, -0.25f, -5.0f); // 1
	glColor4ub(0, 0, 255, 255);  glVertex3f(0.5f, -0.25f, -5.0f); // 2
	glColor4ub(0, 255, 0, 255);  glVertex3f(0.0f, 0.5f, -5.0f);  // 3
	glEnd();

}