#include "scene.h"
#include "utils.h"
#include "skybox.h"
#include "model.h"
#include "ground.h"
#include "light.h"
#include "camera.h"
#include "sprite.h"
#include "particle.h"

SkyBox skybox;
Model model;
Ground ground;
Camera camera;
Sprite2D sprite;

GLuint particleTexture; // ��������
Particle particle[1000];

DirectionLight light(GL_LIGHT0);
PointLight light1(GL_LIGHT1), light2(GL_LIGHT2);
SpoltLight light3(GL_LIGHT3);

void Init()
{
	glMatrixMode(GL_PROJECTION); // ���þ����ʽ -��ͶӰ����
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f); // ��ֱ�ӽǡ�������߱ȡ���������ľ��롢��Զ��������
	glMatrixMode(GL_MODELVIEW); // ģ���ӿھ���
	glLoadIdentity(); // ������λ���ݲ��޸�

	skybox.Init("Res/");
	model.Init("Res/Sphere.obj");
	model.mTexture = CreateTexture2DFromBMP("Res/earth.bmp");

	light.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f); // �����
	light.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
	light.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	light.SetPosition(0.0f, 1.0f, 0.0f);

	light1.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f); // ���Դ 1
	light1.SetDiffuseColor(0.8f, 0.8f, 0.8f, 1.0f);
	light1.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	light1.SetPosition(0.0f, 0.0f, 0.0f);
	light1.SetConstAttenuation(1.0f);
	light1.SetLineAttenuation(0.2f);
	light1.SetConstAttenuation(0.0f);

	light2.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f); // ���Դ 2
	light2.SetDiffuseColor(0.1f, 0.4f, 0.6f, 1.0f);
	light2.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	light2.SetPosition(0.0f, 0.0f,-20.0f);
	light2.SetConstAttenuation(1.0f);
	light2.SetLineAttenuation(0.2f);
	light2.SetConstAttenuation(0.0f);

	light3.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f); // ���Դ 1
	light3.SetDiffuseColor(0.0f, 0.8f, 0.0f, 1.0f);
	light3.SetSpecularColor(1.0f, 0.0f, 0.0f, 1.0f);
	light3.SetPosition(10.0f, 50.0f, -30.0f);
	light3.SetDirection(0.0f, -1.0f, 0.0f);
	light3.SetExponent(5.0f);
	light3.SetCutoff(10.0f);
	
	model.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f); // ����ģ�Ͳ���
	model.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
	model.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);

	ground.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f); // ����ģ�Ͳ���
	ground.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
	ground.SetSpecularMaterial(0.0f, 0.0f, 0.0f, 1.0f);

	camera.mViewportWdith = 800.0f;
	camera.mViewprotHeight = 600.0f;

	sprite.SetImage("Res/head.png");
	sprite.SetRect(0.0f, 0.0f, 100.0f, 100.0f);

	particleTexture = CreateProcedureTexture(128);
	/*particle.mHalfSize = 100.0f;
	particle.mTexture = particleTexture;
	particle.Init(220, 150, 50, 255, 10.0f);*/
}

void EmitParticle(float delta)
{
	static float currentSleepTime = 0.0f;
	static float nextParticleTime = 0.016f;
	static int particleCount = 1;
	if (particleCount == 1000)
		return;

	currentSleepTime += delta;
	if (currentSleepTime >= nextParticleTime) {
		currentSleepTime = 0.0f;
	}
	else {
		return;
	}
	particle[particleCount - 1].mHalfSize = 10.0f;
	particle[particleCount - 1].mTexture = particleTexture;
	particle[particleCount - 1].Init(220, 150, 50, 255, 10.0f);
	particleCount++;
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // �����Ȼ������� ��Ȼ���������1.0����Զ���������趨0.1 ~ 1000��
	
	camera.SwithcTo3D();

	float frameTime = GetFrameTime();
	camera.Update(frameTime);

	//light.Enable(); // ���������Զ���������Ӱ��
	light1.Enable();
	light1.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
	light2.Enable();
	light2.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);
	light3.Enable();
	light3.Update(camera.mPos.x, camera.mPos.y, camera.mPos.z);

	skybox.Draw(camera.mPos.x, camera.mPos.y, camera.mPos.z); // ��պ������պб�֤��պ�����Զ��
	model.Draw();
	ground.Draw();

	camera.SwithcTo2D();
	sprite.Draw();
	/*particle.Update(frameTime);
	particle.Draw();*/
	EmitParticle(frameTime);
	for (int i = 0; i < 1000; ++i)
	{
		if (particle[i].mLifeTime != -1.0f) {
			particle[i].Update(frameTime);
			particle[i].Draw();
		}
		else
		{
			break;
		}
	}
}

void OnKeyDown(char code)
{
	switch (code) {
	case 'A':
		camera.mbMoveLeft = true;
		break;
	case 'D':
		camera.mbMoveRight = true;
		break;
	case 'W':
		camera.mbMoveForward = true;
		break;
	case 'S':
		camera.mbMoveBack = true;
		break;
	}
}

void OnKeyUp(char code)
{
	switch (code) {
	case 'A':
		camera.mbMoveLeft = false;
		break;
	case 'D':
		camera.mbMoveRight = false;
		break;
	case 'W':
		camera.mbMoveForward = false;
		break;
	case 'S':
		camera.mbMoveBack = false;
		break;
	}
}

void OnMouseMove(float deltaX, float deltaY)
{
	float angleRotateByup = deltaX / 1000.0f;
	float angleRotateByRight = deltaY / 1000.0f;
	camera.Yaw(-angleRotateByup);
	camera.Pitch(-angleRotateByRight);
}