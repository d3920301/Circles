#pragma once

#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
private:
	int radius;

public:
	Circle(Vector2i nPos = Vector2i(100, 200), Vector2 nDir = Vector2(0.5f, 0.0f), int nSpeed = 5, int nRadius = 20, Vector4 nCol = Vector4(255, 0, 0, 255));

	void Draw() override;
	void Update() override;

	// Randomise Methods
	void RandomisePosition() override;

	// Get Set
	int GetRadius() const { return radius; }
};

