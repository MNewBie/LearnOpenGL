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

	// 三角形
	/*
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 255, 255, 255); // 当前颜色 0~255
	glVertex3f(-0.2f, -0.2f, -1.5f); //设置当前点，用当前颜色
	glColor4ub(255, 0, 0, 255); 
	glVertex3f(0.2f, -0.2f, -1.5f); 
	glColor4ub(0, 255, 0, 255);
	glVertex3f(0.0f, 0.2f, -1.5f);  // 点的顺序是逆时针为正面，如果逆时针是反面，若设置不显示则有影响
	glEnd();
	*/

	// 三角形带
	/*
	glBegin(GL_TRIANGLE_STRIP);
	glColor4ub(255, 0, 0, 255); 
	glVertex3f(-0.5f, -0.25f, -2.5f); 
	glColor4ub(0, 0, 255, 255);
	glVertex3f(0.5f, -0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255);
	glVertex3f(-0.5f, 0.25f, -2.5f);  
	glColor4ub(0, 255, 0, 255);
	glVertex3f(0.5f, 0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255);
	glVertex3f(-0.5f, 0.75f, -2.5f);
	glColor4ub(0, 0, 255, 255);      // 绘制一组相连的三角形，对于奇数n，顶点n,n+1和n+2定义了第n个三角形
	glVertex3f(0.5f, 0.75f, -2.5f);  // 对于偶数n,顶点n+1,n和n+2定义了第n个三角形，总共绘制N-2个三角形
	glEnd();
	*/

	// 三角形扇
	glBegin(GL_TRIANGLE_FAN);
	glColor4ub(255, 0, 0, 255);
	glVertex3f(0.0f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255);
	glVertex3f(0.5f, -0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255);
	glVertex3f(0.4f, 0.0f, -2.5f);
	glColor4ub(0, 255, 0, 255);
	glVertex3f(0.2f, 0.15f, -2.5f);
	glColor4ub(0, 0, 255, 255);      // 绘制一组相连的三角形，三角形是由第一个顶点及其后给定的顶点确定
	glVertex3f(0.0f, 0.2f, -2.5f);  // 顶点1、n+1、和n+2定义了第n个三角形，总共绘制N-2个三角形
	glEnd();
}