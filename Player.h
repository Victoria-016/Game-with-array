#pragma once
#include "PlaceActor.h"


class Key;

class Player : public PlaceActor
{
public:
	Player();


	bool HasKey();
	bool HasKey(int color);
	bool PickUpKey(Key* key);
	void UseKey();
	void DropKey();
	
	void AddItem(int item) { m_item += item;  }
	int GetItem() { return m_item;  }

	int GetLives() { return m_lives;  }
	void DecrementLives() { m_lives--; }

	virtual void Draw() override;
private:
	Key* m_pCurrentKey;
	int m_item;
	int m_lives;
};