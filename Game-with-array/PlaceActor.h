#pragma once
#include "Point.h"

constexpr int kGreenColor = 10;
constexpr int kGreenColorSolid = 34;
constexpr int kRedColor = 12;
constexpr int kRedColorSolid = 68;
constexpr int kBlueColor = 9;
constexpr int kBlueColorSolid = 153;
constexpr int kRegularColor = 7;
constexpr int kOpenDoorColor = 10;
constexpr int kClosedDoorColor = 12;


class PlaceActor
{
public:
	PlaceActor(int x, int y, int color);
	virtual ~PlaceActor();

	int GetXPosition();
	int GetYPosition();
	int* GetXPositionPointer();
	int* GetYPositionPointer();
	void SetPosition(int x, int y);

	int GetColor() { return m_color; }

	void Remove() { m_IsActive = false; }
	bool isActive() { return m_IsActive; }
	void Place(int x, int y);

	virtual void Draw() = 0;
	virtual void Update()
	{

	}
protected:
	Point* m_pPosition;

	bool m_IsActive;
	int m_color;
};