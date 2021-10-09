#include "PlaceActor.h"

PlaceActor::PlaceActor(int x, int y, int color)
	: m_pPosition(new Point(x, y))
	, m_IsActive(true)
	, m_color(color)
{


}
PlaceActor::~PlaceActor()
{
	delete m_pPosition;
	m_pPosition = nullptr;
}

int PlaceActor::GetXPosition()
{
	return m_pPosition->x;
}

int PlaceActor::GetYPosition()
{
	return m_pPosition->y;
}


int* PlaceActor::GetXPositionPointer()
{
	return &(m_pPosition->x);

}

int* PlaceActor::GetYPositionPointer()
{
	return &(m_pPosition->y);
	

}

void PlaceActor::SetPosition(int x, int y)
{
	m_pPosition->x = x;
	m_pPosition->y = y;
}

void PlaceActor::Place(int x, int y)
{
	m_pPosition->x = x;
	m_pPosition->y = y;
	m_IsActive = true;
}