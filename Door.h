#pragma once
#include "PlaceActor.h"

class Door : public PlaceActor
{
public:
	Door(int x, int y, int color, int consoleColor);
	virtual void Draw() override;

	bool IsOpen() { return m_IsOpen; }
	void Open() { m_IsOpen = true;  }

private:
	bool m_IsOpen;
	int m_closedColor;

};