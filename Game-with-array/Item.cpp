#include <iostream>
#include "Item.h"

Item::Item(int x, int y, int reduceDOT)
	: PlaceActor(x, y)
	, m_reduceDOT(reduceDOT)
{

}
void Item::Draw()
{
	std::cout << "$";
}