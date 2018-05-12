#pragma once
#include "gg.h"
class Vector3f {
public:
	float x, y, z;
	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) :x(_x), y(_y), z(_z) {};
	Vector3f operator+(Vector3f&r);
	Vector3f operator-(Vector3f&r);
	Vector3f operator*(float scaler);
	float operator*(Vector3f&r);
	void operator=(Vector3f&r);
	void Normalize();
	float Magnitude();

};
Vector3f Cross(Vector3f v1, Vector3f v2);