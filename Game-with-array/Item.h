#pragma once
#include "PlaceActor.h"

class Item : public PlaceActor
{
public:
	Item(int x, int y, int reduceDOT);

		int HealthBuff() const { return m_reduceDOT; }

	virtual void Draw() override;

private:
	int m_reduceDOT;
};