#pragma once
#include "PlaceActor.h"

class Key : public PlaceActor
{
public:
	Key(int x, int y, int color)
		: PlaceActor(x, y, kRedColor)
	{

	}
	virtual void Draw() override;
};
