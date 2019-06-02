#include "stdafx.h"
#include "Component.h"

const int OffsetX = 60;
const int OffsetY = 100;

CComponent::CComponent()
{
}


CComponent::~CComponent()
{
}
/**
	* Draw the component
	* \param graphics For drawing
	*/
void CComponent::Draw(Gdiplus::Graphics *graphics)
{
	CPolygon::DrawPolygon(graphics,mPosition.X-OffsetX,mPosition.Y- OffsetY);
}
/**
* Draw the component
* \param rotation Position
*/
void CComponent::Update(double rotation)
{

}


void CComponent::SetConstructor(CMachineConstructor* constructor)
{
	mConstructor = constructor;

}