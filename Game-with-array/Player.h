#pragma once
#include "Point.h"
#include "Puzzle.h"

class Player
{
	Point m_position;
	bool m_hasKey;
	bool m_hasDamage;
	const int m_fullHealth = 100;
	int m_health = m_fullHealth;
	bool m_hasDamageInLevel = false;
	int damage = -5;
	

public:
	Player();
	~Player();

	int GetXPosition() { return m_position.x; }
	int GetYPosition() { return m_position.y; }
	int GetHealth() const { return m_health; }


	int* GetXPositionPointer() { return &(m_position.x); }
	int* GetYPositionPointer() { return &(m_position.y); }

	void SetPosition(int x, int y);

	bool HasKey();
	void PickUpKey();
	void UseKey();
	void PickUpDamage();
	void HasDamage();
	void PlayerHealth(int health);

	void Draw();

};