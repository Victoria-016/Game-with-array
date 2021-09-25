#include <iostream>
#include "Game.h"


// I am looking to add text in between each level, also want to add moving obsticales that cause daamage and damage over time coordinates on the map. Also want to use the level editor created to create map.

using namespace std;


int main()
{

	Game myGame;

	if (myGame.Load())
	{
		while (!myGame.IsGameOver())
		{
			myGame.Run();
		}

		if (myGame.DidUserQuit())
		{
			cout << "You have quit, thanks for playing. Goodbye!" << endl;
		}
		else if (myGame.GetPlayerLives() < 0)
		{
			cout << "You Lose!" << endl;
		}
		else
		{
			cout << "You Win!" << endl;
		}
	}
	else
	{
		cout << "Game did not load. Terminating now, please try again later." << endl;
	}
}


//}
//void PlayDoorCloseSound()
//{
//	Beep(500, 75);
//	Beep(500, 75);
//}
//void PlayDoorOpenSound()
//{
//	Beep(1568, 200);
//}
//void PlayPickUpKeySound()
//{
//	Beep(1568, 200);
//}
//void PlayWinSound()
//{
//	Beep(1568, 200);
//	Beep(1568, 200);
//	Beep(1568, 200);
//	Beep(1245, 1000);
//	Beep(1397, 200);
//	Beep(1397, 200);
//	Beep(1397, 200);
//	Beep(1397, 200);
//	Beep(1175, 1000);
//}
