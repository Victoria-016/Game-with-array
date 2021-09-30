#include <windows.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include "Level.h"
#include "Player.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Item.h"
#include "PlaceActor.h"



using namespace std;

constexpr char WAL = (char)219;



Level::Level()

	: m_pLevelData(nullptr)
	, m_height(0)
	, m_width(0)

{

}
Level::~Level()
{
	if (m_pLevelData != nullptr)
	{
		delete[] m_pLevelData;
		m_pLevelData = nullptr;
	}
	while (!m_pActors.empty())
	{
		delete m_pActors.back();
		m_pActors.pop_back();
	}
}
bool Level::Load(std::string levelName, int* playerX, int* playerY)
{
	levelName.insert (0, "../");
	ifstream levelFile;
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "Opening file failed" << endl;
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];
		
		levelFile.getline(temp, tempSize, '\n');
		m_width = atoi(temp);

		levelFile.getline(temp, tempSize, '\n');
		m_height = atoi(temp);
		

		m_pLevelData = new char[m_width * m_height];
		levelFile.read(m_pLevelData, (long long)m_width * (long long)m_height);
		
		bool anyWarnings = Convert(playerX, playerY);

		if (anyWarnings)
		{
			cout << "There are some warnings with the level data, see above." << endl;
			system("pause");
		}
		return true;

	}

}
void Level::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, kRegularColor);

	for (int y = 0; y < GetHeight(); ++y)
	{ 
		for (int x = 0; x < GetWidth(); x++)
		{
			int indexToPrint = GetIndexFromCoordinates(x, y);
			cout << m_pLevelData[indexToPrint];
		}
		cout << endl;
	}


	COORD actorCursorPosition;

	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		if ((*actor)->m_IsActive())
		{
			actorCursorPosition.X = (*actor)->GetXPosition();
			actorCursorPosition.Y = (*actor)->GetYPosition();
			SetConsoleCursorPosition(console, actorCursorPosition);
			(*actor)->Draw();
		}
	}
}
bool Level::IsSpace(int x, int y)
{
	return m_pLevelData[GetIndexFromCoordinates(x, y)] == ' ';
}

bool Level::IsWall(int x, int y)
{
	return m_pLevelData[GetIndexFromCoordinates(x, y)] == WAL;
}
bool Level::Convert(int* playerX, int* playerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			int index = GetIndexFromCoordinates(x, y);

			switch (m_pLevelData[index])
			{
			case '+':
			case '-':
			case '|':
				m_pLevelData[index] = WAL;
				break;
			case 'r':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y.kRedColor));
				break;
			case 'g':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y.kGreenColor));
				break;
			case 'b':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Key(x, y.kBlueColor));
				break;
			case 'R':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, kRedColor, kRedColorSolid));
				break;
			case 'G':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, kGreenColor, kGreenColorSolid));
				break;
			case 'B':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Door(x, y, kBlueColor, kBlueColorSolid));
				break;
			case 'x':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Goal(x, y));
				break;
			case '$':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Item(x, y));
				break;
			case '@':
				m_pLevelData[index] = ' ';
				if (playerX != nullptr && playerY != nullptr)
				{
					*playerX = x;
					*playerY = y;
				}
				break;
			case 'e':
				m_pActors.push_back(new Enemy(x, y));
				m_pLevelData[index] = ' ';
				break;
			case 'h':
				m_pActors.push_back(new Enemy(x, y, 3, 0));
				m_pLevelData[index] = ' ';
				break;
			case 'v':
				m_pLevelData[index] = ' ';
				m_pActors.push_back(new Enemy(x, y, 2, 0));
				m_pLevelData[index] = ' ';
				break;
				break;
			case ' ':
				break;
			default:

				cout << "Invalid character in level file:" << m_pLevelData[index] << endl;
				anyWarnings = true;
				break;



			}
		}
	}
	return anyWarnings;
}

int Level::GetIndexFromCoordinates(int x, int y)
{
	return x + y * m_width;

}

PlaceActor* Level::UpdateActors(int x, int y)
{
	PlaceActor* collidedActor = nullptr;
	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		(*actor)->Update();

		if (x == (*actor)->GetPosition() && y == (*actor)->GetPosition())
		{
			assert(collidedActor == nullptr);
			collidedActor = (*actor);

		}
	}
	return collidedActor;
}