#include <iostream>
#include "Goal.h"

Goal::Goal(int x, int y)
	:PlaceActor(x, y, kRedColor)
{

}

void Goal::Draw()
{
	std::cout << "X";
}