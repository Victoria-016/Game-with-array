#include "Damage.h"
#include <iostream>
#include <windows.h>

void Damage::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, m_color);

	std::cout << "#";
	SetConsoleTextAttribute(console, kRegularColor);



}


