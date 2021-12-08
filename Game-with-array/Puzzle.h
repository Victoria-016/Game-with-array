#pragma once
#include "PlaceActor.h"

class PuzzleInstance : public PlaceActor
{
public:
	int Puzzle (int x, int y);

	virtual void Draw() override;
};
