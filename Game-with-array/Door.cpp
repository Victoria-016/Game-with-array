#include <iostream>
#include <windows.h>
#include "Door.h"


Door::Door(int x, int y, int color, int closedColor)
	: PlaceActor(x, y, color)
	, m_IsOpen(false)
	, m_closedColor(closedColor)

{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_IsOpen)
	{
		SetConsoleTextAttribute(console, kOpenDoorColor);
	}
	else
	{
		std::cout << "|";
		SetConsoleTextAttribute(console, kRegularColor);
	}
}