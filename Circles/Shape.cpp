#include "Shape.h"

Shape::Shape(Vector2i nPos, Vector2 nDir, int nSpeed, Vector4 nCol) : pos(nPos), dir(nDir), speed(nSpeed), col(nCol)
{
}

void Shape::Draw()
{
	return;
}

void Shape::Update()
{
	return;
}

void Shape::RandomisePosition()
{
	return;
}

void Shape::RandomiseDirection()
{
	dir.x = (rand() % 2) * 2 - 1;
	dir.y = (rand() % 2) * 2 - 1;
}

void Shape::RandomiseSpeed(int minSpeed, int maxSpeed)
{
	speed = minSpeed + rand() % maxSpeed;
}

void Shape::RandomiseColour()
{
	col.w = rand() % 255;
	col.x = rand() % 255;
	col.y = rand() % 255;
	col.z = rand() % 255;
}
