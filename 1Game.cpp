#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>

#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Item.h"
#include "Goal.h"


using namespace std;
// can use in place of W A S D
constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;

Game::Game()
	:m_isGameOver(false)
{

}
Game::~Game()
{

}
bool Game::Load()
{
	return m_level.Load("Level1.txt", m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}
void Game::Run()
{
	Draw();

	m_isGameOver = Update();

	if (m_isGameOver)
	{
		Draw();
	}
}

bool Game::IsGameOver()
{
	return m_isGameOver;
}

bool Game::Update()
{
	int Input = _getch();
	int arrowInput = 0;
	int newPlayerX = m_player.GetXPosition();
	int newPlayerY = m_player.GetYPosition();

	if (Input == kArrowInput)
	{
		arrowInput = _getch();
	}

	if ((Input == kArrowInput && arrowInput == kLeftArrow) ||
		(char)Input == 'A' || (char)Input == 'a')
			{
			 newPlayerX --;
			}
	else if ((Input == kArrowInput && arrowInput == kRightArrow)||
		(char)Input == 'D' || (char)Input == 'd')
			{
			newPlayerX ++;
			}
	else if ((Input == kArrowInput && arrowInput == kUpArrow)||
		(char)Input == 'W' || (char)Input == 'w')
			{
			newPlayerY --;
			}
	else if ((Input == kArrowInput && arrowInput == kDownArrow)||
		(char)Input == 'S' || (char)Input == 's')
			{
			newPlayerY ++;
			}
	else if (Input == kEscapeKey)
		
			{
		m_UserQuit = true;
		return true;
			}
	else if ((char)Input == 'Z' || (char)Input == 'z')
			{
			m_player.DropKey();
			}
	if (newPlayerX == m_player.GetXPosition() && newPlayerY == m_player.GetXPosition())
			{
			return false;
			}
	else
			{
			return HandleCollision(newPlayerX, newPlayerY);
			}
	}
bool Game::HandleCollision(int newPlayerX, int newPlayerY)
{
	PlaceActor* collidedActor = m_level.UpdateActor(newPlayerX, newPlayerY);
	if (collidedActor != nullptr && collidedActor->isActive());
	{
		Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
		if (collidedEnemy)
		{
			collidedEnemy->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);

			m_player.DecrementLives();
			if (m_player.GetLives() < 0)
			{
				return true;
			}
		}
		Item* collidedItem = dynamic_cast<Item*>(collidedActor);
		if (collidedItem)
		{
			collidedItem->Remove();
			m_player.AddItem(collidedItem->HealthBuff());
			m_player.SetPosition(newPlayerX, newPlayerY);
		}
		Key* collidedKey = dynamic_cast<Key*>(collidedActor);
		if (collidedKey)
		{
			if (!m_player.HasKey())
			{
				m_player.PickUpKey(collidedKey);
				collidedKey->Remove();
				m_player.AddItem(collidedItem->HealthBuff());
				m_player.SetPosition(newPlayerX, newPlayerY);
			}

		}
		Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
		if (collidedDoor)
		{
			if (!collidedDoor->IsOpen())
			{
				if (m_player.HasKey(collidedDoor->GetColor()))
				{
					collidedDoor->Open();
					collidedDoor->Remove();
					m_player.UseKey();
					m_player.SetPosition(newPlayerX, newPlayerY);
					//PlayDoorOpenSound();
				}
				else
				{
					//PlayClosedDoorSound();
				}
			}
			else
			{
				m_player.SetPosition(newPlayerX, newPlayerY);
			}
		}
		Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
		if (collidedGoal)
		{
			collidedGoal->Remove();
			m_player.SetPosition(newPlayerX, newPlayerY);
			return true;
		}

		else if (m_level.IsSpace(newPlayerX, newPlayerY))
		{
			m_player.SetPosition(newPlayerX, newPlayerY);
		}
		else if (m_level.IsWall(newPlayerX, newPlayerY))
		{
			//wall collision
		}
		return false;
	}
}
void Game::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	m_level.Draw();

	COORD actorCursorPosition;
	actorCursorPosition.X = m_player.GetXPosition();
	actorCursorPosition.Y = m_player.GetYPosition();
	SetConsoleCursorPosition(console, actorCursorPosition);
	m_player.Draw();

	COORD currentCursorPosition;
	currentCursorPosition.X = 0;
	currentCursorPosition.Y = m_level.GetHeight();
	SetConsoleCursorPosition(console, currentCursorPosition);

}
