#pragma once
#include "vector3f.h"
class Camera {
public:
	Camera();
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack;

	int mViewportWdith, mViewprotHeight;

	void Update(float deltaTime);
	void Pitch(float angle); // �����ƶ�
	void Yaw(float angle); // �����ƶ�

	void RoateView(float angle, float x, float y, float z);

	void SwithcTo3D();
	void SwithcTo2D();
};