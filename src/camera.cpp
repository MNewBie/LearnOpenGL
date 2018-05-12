#include "camera.h"

Camera::Camera() :mPos(0.0f, 0.0f, 0.0f), mViewCenter(0.0, 0.0f, -1.0f), mUp(0.0f, 1.0f, 0.0f),
mbMoveLeft(false), mbMoveRight(false), mbMoveForward(false), mbMoveBack(false)
{

}

void Camera::Update(float deltaTime)
{
	float moveSpeed = 10.0f;
	Vector3f forwardDriection = mViewCenter - mPos;
	forwardDriection.Normalize();
	Vector3f rightDirection = Cross(forwardDriection, mUp);
	rightDirection.Normalize();
	if (mbMoveLeft)
	{
		Vector3f delta = rightDirection*deltaTime*moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
	}
	if (mbMoveRight)
	{
		Vector3f delta = rightDirection*deltaTime*moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
	}
	if (mbMoveForward)
	{
		Vector3f delta = forwardDriection*deltaTime*moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
	}
	if (mbMoveBack)
	{
		Vector3f delta = forwardDriection*deltaTime*moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
	}

	/*if (mbMoveLeft) //ʹ���������
	{
		float delta = deltaTime * moveSpeed;
		mPos.x -= delta;
		mViewCenter.x -= delta;
	}
	if (mbMoveRight)
	{
		float delta = deltaTime * moveSpeed;
		mPos.x += delta;
		mViewCenter.x += delta;
	}
	if (mbMoveForward)
	{
		float delta = deltaTime * moveSpeed;
		mPos.z -= delta;
		mViewCenter.z -= delta;
	}
	if (mbMoveBack)
	{
		float delta = deltaTime * moveSpeed;
		mPos.z += delta;
		mViewCenter.z += delta;
	}*/
	glLoadIdentity();
	gluLookAt(mPos.x, mPos.y, mPos.z,
		mViewCenter.x, mViewCenter.y, mViewCenter.z,
		mUp.x, mUp.y, mUp.z);
}

void Camera::Pitch(float angle)
{
	Vector3f forwardDriection = mViewCenter - mPos;
	forwardDriection.Normalize();
	Vector3f rightDirection = Cross(forwardDriection, mUp);
	rightDirection.Normalize();
	RoateView(angle, rightDirection.x, rightDirection.y, rightDirection.z);
}
void Camera::Yaw(float angle)
{
	RoateView(angle, mUp.x, mUp.y, mUp.z);
}

void Camera::RoateView(float angle, float x, float y, float z)
{
	Vector3f viewDirection = mViewCenter - mPos;
	Vector3f newDirection(0.0f, 0.0f, 0.0f);

	float C = cosf(angle); // ������ת
	float S = sinf(angle);
	Vector3f tempX(C + x*x*(1 - C), x*y*(1 - C) - z*S, x*z*(1 - C) + y*S);
	newDirection.x = tempX*viewDirection;
	Vector3f tempY(x*y*(1 - C) + z*S, C + y*y*(1 - C), y*z*(1 - C) - x*S);
	newDirection.y = tempY*viewDirection;
	Vector3f tempZ(x*z*(1 - C) - y*S, y*z*(1 - C) + x*S, C + z*z*(1 - C));
	newDirection.z = tempZ*viewDirection;
	mViewCenter = mPos + newDirection;
}

void  Camera::SwithcTo3D()
{
	glMatrixMode(GL_PROJECTION); // ���þ����ʽ -��ͶӰ����
	glLoadIdentity();
	gluPerspective(50.0f, (float)mViewportWdith / (float)mViewprotHeight, 0.1f, 1000.0f); // ��ֱ�ӽǡ�������߱ȡ���������ľ��롢��Զ��������
	glMatrixMode(GL_MODELVIEW); // ģ���ӿھ���
	glLoadIdentity(); // ������λ���ݲ��޸�
}
void Camera::SwithcTo2D()
{
	glMatrixMode(GL_PROJECTION); // ���þ����ʽ -��ͶӰ����
	glLoadIdentity();
	 // ���ҡ��¡��� �߽�
	gluOrtho2D( -mViewportWdith / 2, mViewportWdith / 2, -mViewprotHeight / 2, mViewprotHeight / 2);
	glMatrixMode(GL_MODELVIEW); // ģ���ӿھ���
	glLoadIdentity(); // ������λ���ݲ��޸�
}