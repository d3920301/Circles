#pragma once

#include "Vector.h"
#include "Framework.h"
#include <cstdlib>

class Shape
{
protected:
	Vector2i pos, fPos;
	Vector2 dir, fDir;
	int speed;
	Vector4 col;

public:
	Shape(Vector2i nPos = Vector2i(100, 200), Vector2 nDir = Vector2(1.0f, 1.0f), int nSpeed = 5, Vector4 nCol = Vector4(255, 255, 255, 255));

	virtual void Draw();
	virtual void Update();

	// Randomise Methods
	// Randomise circle position based on window dimensions. We need to know the radius(circles)/width(rects) so we will have to override it from child classes.
	virtual void RandomisePosition();
	void RandomiseDirection();
	void RandomiseSpeed(int minSpeed = 1, int maxSpeed = 20);
	void RandomiseColour();

	// Get Set
	Vector2i GetPos() const { return pos; }
	void SetPos(Vector2i nPos) { pos = nPos; }
	Vector2 GetDir() const { return dir; }
	void SetDir(Vector2 nDir) { dir = nDir; }
};

