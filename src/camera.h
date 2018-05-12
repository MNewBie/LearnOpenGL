#pragma once
#include "vector3f.h"
class Camera {
public:
	Camera();
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack;

	int mViewportWdith, mViewprotHeight;

	void Update(float deltaTime);
	void Pitch(float angle); // 上下移动
	void Yaw(float angle); // 左右移动

	void RoateView(float angle, float x, float y, float z);

	void SwithcTo3D();
	void SwithcTo2D();
};