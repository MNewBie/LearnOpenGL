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

	// 点
	/*
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f); // 1
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f); // 2
	glColor4ub(0, 255, 0, 255); glVertex3f(0.0f, 0.5f, -2.5f); // 3
	glEnd();
	*/

	// 线
	// GL_LINES: 两个点一条线
	// GL_LINE_LOOP: 所有点首尾相接连成一个封闭的环, 最后连第一个
	// GL_LINE_STRIP： 所有点首尾相接连成一个折线，与loop不同，非封闭
	/*
	glLineWidth(10.f);
	glBegin(GL_LINES); // 两个点一条线
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f); // 1
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f); // 2

	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f); // 3
	glColor4ub(0, 255, 0, 255); glVertex3f(1.0f, 0.5f, -2.5f); // 4
	glEnd();
	*/

	// 四边形
	// GL_QUADS: 四边形，4个点一组
	// GL_QUADS： 四边形带，每个四边形由一对顶点及气候给定的一对顶点共同确定
	//            顶点2n-1、2n、2n+2、和2n+1定义了第n个四边形，总共绘制N/2-1个四边形
	/*
	glBegin(GL_QUAD_STRIP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.25f, -0.25f, -2.5f); // 1
	glColor4ub(0, 0, 255, 255); glVertex3f(0.25f, -0.25f, -2.5f); // 2
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.25f, 0.25f, -2.5f); // 3
	glColor4ub(0, 255, 0, 255); glVertex3f(0.25f, 0.25f, -2.5f); // 4

	glColor4ub(0, 255, 0, 255); glVertex3f(-0.25f, 0.5f, -2.5f); // 5
	glColor4ub(255, 0, 0, 255); glVertex3f(0.25f, 0.5f, -2.5f); // 6

	glColor4ub(0, 255, 0, 255); glVertex3f(-0.25f, 0.75f, -2.5f); // 7
	glColor4ub(255, 0, 0, 255); glVertex3f(0.25f, 0.75f, -2.5f); // 8
	glEnd();
	*/

	// 多边形
	glBegin(GL_POLYGON); // 只能凸多边形
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f); // 1
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f); // 2
	glColor4ub(0, 255, 0, 255); glVertex3f(1.0f, 0.5f, -2.5f); // 3
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.5f, -2.5f); // 4
	glColor4ub(0, 255, 0, 255); glVertex3f(0.0f, 0.25f, -2.5f); // 5
	glEnd();

}