#pragma once
#include "PlaceActor.h"
#include "Level.h"
#include "windows.h"


class Damage : public PlaceActor
{
public:
	Damage(int x, int y, int color)
		: PlaceActor(x, y, kRedColor)
	{

	}
	virtual void Draw() override;
};
