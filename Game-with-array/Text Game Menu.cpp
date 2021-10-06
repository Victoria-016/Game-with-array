#include <iostream>
#include "TextGame.h"

using namespace std;


void TextGame::DisplayText()
{
	constexpr int kPlayMenu = 1;
	constexpr int kQuitMenu = 2;

	cout << "Welcome!\n";
	//cout << ".\n"; this will be game title 
	cout << "	1) Start.\n";
	cout << "	2) Quit.\n";
	cout << "Please press 1 or 2:\n";

	int input;
	cin >> input;

	switch (input)
	{
		case kPlayMenu:
		{
			cout << "Welcome!\n";
			break;
		}
			case kQuitMenu:
		{
			cout << "You have selected QUIT, Goodbye!\n";
			break;
		}
	}
}




