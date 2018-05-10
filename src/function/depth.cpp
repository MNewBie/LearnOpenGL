#include "scene.h"
#include "utils.h"
#include "skybox.h"
SkyBox skybox;

void Init()
{
	glMatrixMode(GL_PROJECTION); // 设置矩阵格式 -》投影矩阵
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f); // 垂直视角、画布宽高比、最近看到的距离、最远看到距离
	glMatrixMode(GL_MODELVIEW); // 模型视口矩阵
	glLoadIdentity(); // 给个单位阵，暂不修改

	skybox.Init("Res/");
}


void Draw()
{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 清空深度缓冲区， 深度缓冲区设置1.0在最远处（上面设定0.1 ~ 1000）
	
	skybox.Draw(); // 清空后绘制天空盒保证天空盒在最远处
	
	glEnable(GL_DEPTH_TEST); // 开启深度测试，解决遮挡问题；会修改深度缓冲区的值，大于的不绘制。
	glBegin(GL_QUADS);
	glColor4ub(0, 50, 200, 255);
	glVertex3f(-0.1f, -0.1f, -10); 
	glVertex3f(0.1f, -0.1f, -10);
	glVertex3f(0.1f, 0.1, -10);
	glVertex3f(-0.1f, 0.1f, -10);
	glEnd();
								 
}