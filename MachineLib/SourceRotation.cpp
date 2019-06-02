#include "stdafx.h"
#include "SourceRotation.h"


CSourceRotation::CSourceRotation()
{
}


CSourceRotation::~CSourceRotation()
{
}

/**
	* Call function in the source rotation
	* \param rotation the rotation for the motor
	*/
void CSourceRotation::DoRotation(double rotation,double radius)
{
	mSinkRoations->DoRotation(rotation, radius);
}
/**
	* Add Sinkrotation into the vector
	* param Sinkrotation The Sinkrotation which will be added into the vector
	*/
void CSourceRotation::AddSink(std::shared_ptr<CComponent> component)
{
	mSinkRoations->SetComponent(component);
}

