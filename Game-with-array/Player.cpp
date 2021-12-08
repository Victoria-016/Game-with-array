#include "Player.h"
#include <iostream>

using namespace std;

constexpr char kPlayerSymbol = '@';


Player::Player()
	:m_hasKey(false)
	,m_hasDamage(false)

{

}

Player::~Player()
{

}

void Player::SetPosition(int x, int y)
{
	if (m_hasDamageInLevel)
	{
		m_health - +1;
	}
	
	m_position.x = x;
	m_position.y = y;
}

bool Player::HasKey()
{
	return m_hasKey = true;
}
void Player::PickUpKey()
{
	m_hasKey = true;
}
void Player::UseKey()
{
	m_hasKey = false;
}
void Player::Draw()
{
	cout << kPlayerSymbol;
}
void Player::PlayerHealth(int health)
{
	int playerHealth = 100;
}
void Player::PickUpDamage()
{
	m_hasDamage = true;
}
void Player::HasDamage()
{
	if (m_hasDamage)
	{
		m_health - +5;
	}
	m_hasDamage = true;
}
