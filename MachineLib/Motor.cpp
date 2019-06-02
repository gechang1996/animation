#include "stdafx.h"
#include "Motor.h"

const int OffsetX = 60;
const int OffsetY = 100;
CMotor::CMotor()
{
}


CMotor::~CMotor()
{
}

/**
	* Calculate the rotation of the motor
	* \param time time for calculating the speed
	*/
void CMotor::CalculateRotation(double time)
{
	CPolygon::SetRotation(time*mSpeed);
}

/**
	* Draw the component
	* \param graphics For drawing
	*/
void CMotor::Draw(Gdiplus::Graphics *graphics)
{
	mPoly.DrawPolygon(graphics, GetPos().X-OffsetX, GetPos().Y-OffsetY);
	CComponent::Draw(graphics);
	
}
/**
	* Call function in the source rotation
	* \param rotation the rotation for the motor
	*/
void CMotor::DoRotation(double rotation)
{
	mSourceRotation->DoRotation(rotation, GetRadius());
	CPolygon::SetRotation(rotation);
}
void CMotor::SetBaseMotor(std::wstring filename)
{
	mPoly.CenteredSquare(80);
	mPoly.SetImage(filename);
	
}

void CMotor::SetSink(std::shared_ptr<CComponent> component)
{
	mSourceRotation->AddSink(component);
}