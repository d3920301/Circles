#pragma once

struct Vector2
{
	float x{ 0 }, y{ 0 };

	//Vector2() { x = 0; y = 0; } <- I think we're fine with just default perams instead of needing another constructor
	Vector2(float nX = 0, float nY = 0) : x(nX), y(nY) {}
};

struct Vector2i
{
	int x{ 0 }, y{ 0 };

	//Vector2() { x = 0; y = 0; } <- I think we're fine with just default perams instead of needing another constructor
	Vector2i(int nX = 0, int nY = 0) : x(nX), y(nY) {}
};

struct Vector4
{
	int w, x, y, z;

	// Vector4() { w = 0, x = 0, y = 0, z = 0; }
	Vector4(int nW = 0, int nX = 0, int nY = 0, int nZ = 0) : w(nW), x(nX), y(nY), z(nZ) {}
};