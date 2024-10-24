/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include "Circle.h"
#include <vector>

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

using namespace std;

int main()
{
	// Seed random using time. Static cast to get rid of that stupid warning. We don't need to seed again DONT SEED IN OTHER FILES
	srand(static_cast<int>(time(NULL)));

	cout << "Hello circles" << endl;
	
	// Create and populate circle vector
	int circleAmount{ 1 };
	std::vector<Circle*> circles;
	for (int i = 0; i < circleAmount; i++)
	{
		Circle* c = new Circle;

		// Randomise EVERYTHING!
		c->RandomisePosition();
		c->RandomiseDirection();
		c->RandomiseSpeed(5, 5);
		c->RandomiseColour();

		circles.push_back(c);
	}

	while(UpdateFramework())
	{
		// Update
		// Make circles come to mouse
		if (IsButtonPressed(EButton::eLeft))
		{
			Vector2i mousePos{};
			GetMousePosition(mousePos.x, mousePos.y);
			for (Circle* c : circles)
			{
				// This puts the circles directly on the curser.
				//c->SetPos(Vector2(mousePos.x - c->GetRadius(), mousePos.y - c->GetRadius()));
				
				// For PW5EE2A1 we need to something with the mouse location and the circle direction or something idk
				// TODO: Figure this out
				
				// You could split the screen into 4 squares (MAKE THE MOUSE THE ORIGIN OF THE 4 SQUARES)
				// The issue with that is if it reaches the edge of a square on one axis, it vibrates along that axis until it reaches origin.
				// When it reaches origin, it vibrates even more.
				//if (c->GetPos().x < mousePos.x && c->GetPos().y < mousePos.y)
				//{
				//	c->SetDir(Vector2(1, 1));
				//}
				//else if (c->GetPos().x > mousePos.x && c->GetPos().y < mousePos.y)
				//{
				//	c->SetDir(Vector2(-1, 1));
				//}
				//else if (c->GetPos().x < mousePos.x && c->GetPos().y > mousePos.y)
				//{
				//	c->SetDir(Vector2(1, -1));
				//}
				//else if (c->GetPos().x > mousePos.x && c->GetPos().y > mousePos.y)
				//{
				//	c->SetDir(Vector2(-1, -1));
				//}
				
				// SECOND METHOD
				// We know where the mouse is, and we know where the circle is.
				// 
				float thingToMath1{ static_cast<float>(mousePos.x - (c->GetPos().x + c->GetRadius())) };
				float thingToMath2{ static_cast<float>(mousePos.y - (c->GetPos().y + c->GetRadius())) };
				Vector2 thingsToMath = Vector2(thingToMath1, thingToMath2);

				// Use square magnitude instead? <- I dont think we can in this circumstance
				float result = sqrt((thingToMath1 * thingToMath1) + (thingToMath2 * thingToMath2)); // This is right btw. I have no idea what do what I do from here
				//int result = ((thingToMath1 * thingToMath1) + (thingToMath2 * thingToMath2)); // <- SqrMag. Remember to square the thing you're comparing too!
				if (result > 0)
				{
					c->SetDir(Vector2((thingToMath1 / result), (thingToMath2 / result))); // IT WORKS!!! HAPPY NEW YEAR!!! TODO: Clean this when you get up later today ^^
				}
				// NOTE: We might have an issue with disappearing circles :( needs more testing <- Was only an issue when using SqrMag I think. <- Nope
				// It disapears because the pos overflows to INT_MIN sometimes? idk why. <- Think it was an issue with mag being 0. Fixed !
				// TODO: Look at using the sqrmag instead of sqrt. Maybe multiply the mouse curser location? can we even do this? DO we even have an end location?
				// Lets stick with sqrt
				// ISSUE: Some circles dont move towards mouse. Issue with dir being set too low since we mult speed by this? (0.00~ ect?). Not project breaking. Move on.
				// ISSUE: Some circles move away from mouse. More likely after they've already been pulled and released. Related to above? Move on.
			}
		}
		
		// Create new circles
		if (IsButtonPressed(EButton::eRight))
		{
			Circle* c = new Circle;

			c->RandomisePosition();
			//c->RandomiseDirection();
			c->RandomiseSpeed(1, 5);
			c->RandomiseColour();

			circles.push_back(c);

			//std::cout << c->GetDir().x << std::endl;
		}

		// Replace Update, Draw, and Cleanup for loops with range based for loops
		//for (int i = 0; i < circles.size(); i++)
		for (Circle* c : circles)
		{
			c->Update();
		}

		// Draw
		for (Circle* c : circles)
		{
			c->Draw();
		}

		for (Circle* c : circles)
		{
			if (c->GetDir().x < 0.01 && c->GetDir().x > -0.01)
			{
				std::cout << c->GetDir().x << std::endl;
			}
		}
	}

	// Cleanup
	for (Circle* c : circles)
	{
		delete[] c;
	}

	cout << "Bye bye" << endl;

	return 0;
}

// Pre-class Circle Code:
// Setup
 	//int circlePosX{ 0 };
	//int circlePosY{ 0 };
	//int circleRadius{ 20 };
	//int circleMoveSpeed{ 5 };
	//// (rand() % 2) * 2 - 1 will only produce a -1 or a 1 which means the circle will always move in a direction
	//int xDir{ (rand() % 2) * 2 - 1 };
	//int yDir{ (rand() % 2) * 2 - 1 };
	//circlePosX = 5 + rand() % (gScreenWidth - (circleRadius * 2) - 5);
	//circlePosY = 5 + rand() % (gScreenHeight - (circleRadius * 2) - 5);
// Loop:
		//// Update circle pos
		//circlePosX += circleMoveSpeed * xDir;
		//circlePosY += circleMoveSpeed * yDir;

		//if (!(rand() % 100))
		//{
		//	xDir = -xDir;
		//	yDir = -yDir;
		//}

		//// Check bounds
		//if (circlePosX >= (gScreenWidth - (circleRadius * 2)) || circlePosX <= 0)
		//{
		//	xDir = -xDir;
		//}
		//if (circlePosY >= (gScreenHeight - (circleRadius * 2)) || circlePosY <= 0)
		//{
		//	yDir = -yDir;
		//}

		////std::cout << circlePosX << std::endl;
		////std::cout << (rand() % 2) * 2 - 1 << std::endl;

		//// Draws a circle at 100,200 with radius 20
		//DrawCircle(circlePosX, circlePosY, circleRadius);	