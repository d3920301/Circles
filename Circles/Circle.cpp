#include "Circle.h"

Circle::Circle(Vector2i nPos, Vector2 nDir, int nSpeed, int nRadius, Vector4 nCol) : Shape(nPos, nDir, nSpeed, nCol), radius(nRadius)
{
	//RandomiseColour(); <- Test to see if the method worked
}

void Circle::Draw()
{
	ChangeColour(col.w, col.x, col.y, col.z);
	DrawCircle(pos.x, pos.y, radius);
}

void Circle::Update()
{
	// TODO: Buffer movement <- DONE! Does this stop the out of bounds issue we were having? <- I think it does!
	// Check if the dir changes <- We can probably replace this with RandomiseDirection() now. Also is this the best place to have this? Commented out for now.
	/*if (!(std::rand() % 100))
	{
		dir.x = -dir.x;
		dir.y = -dir.y;
	}*/
	// Get what next pos will be
	fPos.x = pos.x + speed * dir.x;
	fPos.y = pos.y + speed * dir.y;
	// Check bounds here instead of later
	// Check bounds
	if (fPos.x >= (GetGScreenWidth() - (radius * 2)) || fPos.x <= 0)
	{
		dir.x = -dir.x;
	}
	if (fPos.y >= (GetGScreenHeight() - (radius * 2)) || fPos.y <= 0)
	{
		dir.y = -dir.y;
	}

	// Update circle pos
	pos.x = fPos.x;
	pos.y = fPos.y;

	//std::cout << "Cur: " << pos.x << "\nNext: " << fPos.x << std::endl;
}

void Circle::RandomisePosition()
{
	pos.x = 5 + rand() % (GetGScreenWidth() - (radius * 2)) - 5;
	pos.y = 5 + rand() % (GetGScreenHeight() - (radius * 2)) - 5;
}
