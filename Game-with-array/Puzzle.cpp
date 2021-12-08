#include <iostream>
#include <windows.h>

#include "Puzzle.h"
#include "Game.h"

void PuzzleInstance::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, m_color);

	std::cout << "&";
	SetConsoleTextAttribute(console, kRegularColor);



};

