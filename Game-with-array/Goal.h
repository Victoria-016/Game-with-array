#pragma once 
#include "PlaceActor.h"

class Goal : public PlaceActor
{
public:
	Goal(int x, int y);

	virtual void Draw() override;
};
