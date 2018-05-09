#include "scene.h"

void Init()
{
	glMatrixMode(GL_PROJECTION); // 设置矩阵格式 -》投影矩阵
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f); // 垂直视角、画布宽高比、最近看到的距离、最远看到距离
	glMatrixMode(GL_MODELVIEW); // 模型视口矩阵
	glLoadIdentity(); // 给个单位阵，暂不修改
}

void DrawModel()
{
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 0, 0, 255);  glVertex3f(-0.5f, -0.25f, -5.0f); // 1
	glColor4ub(0, 0, 255, 255);  glVertex3f(0.5f, -0.25f, -5.0f); // 2
	glColor4ub(0, 255, 0, 255);  glVertex3f(0.0f, 0.5f, -5.0f);  // 3
	glEnd();
}


void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 设置颜色 rgba 0.0 ~ 1.0
	glClear(GL_COLOR_BUFFER_BIT); // 擦除颜色缓冲区


	glLoadIdentity(); 
	gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f); // 摆放摄像机

	glPushMatrix(); // 将栈顶矩阵拷贝压入栈顶
	glTranslatef(-1.0f, 0.0f, 0.0f); // 修改栈顶矩阵
	DrawModel(); // 绘制模型
	glPopMatrix(); // 删除栈顶矩阵

	
}