#include <iostream>
#include "Goal.h"

Goal::Goal(int x, int y)
	:PlaceActor(x, y)
{

}

void Goal::Draw()
{
	std::cout << "X";
}