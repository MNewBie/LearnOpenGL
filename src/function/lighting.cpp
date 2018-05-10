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
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 设置颜色 rgba 0.0 ~ 1.0
	glClear(GL_COLOR_BUFFER_BIT); // 擦除颜色缓冲区

	// 方向光
	/*
	glEnable(GL_LIGHTING); // 开启光照算法
	glEnable(GL_LIGHT0); // 启用一盏灯， 0 ~ 7
	float lightPos[] = { 0.0f, 1.0f, 0.0f, 0.0f }; // 其次坐标(x,y,z,w) 真实位置是(x/w, y/w, z/w); w=0 光源在无穷远即方向光（平行光）
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos); // 设置位置
	DrawModel();
	*/


	// 环境参数 , 看不到效果
	glEnable(GL_LIGHTING); 
	glEnable(GL_LIGHT0); 
	glEnable(GL_CULL_FACE);
	float lightPos[] = { 0.0f, 1.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	float whiteColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float ambientMat[] = { 0.07f, 0.07f, 0.07f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor); // 环境光颜色 r,g,b,a
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat); // 反射系数 mr, mg, mb, ma 
	DrawModel();									// 最终反射为 r*mr, r*mg, r*mb, r*ma

}