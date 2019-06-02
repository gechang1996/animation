#include "stdafx.h"
#include "SinkRotation.h"
#include "Component.h"

CSinkRotation::CSinkRotation()
{
}


CSinkRotation::~CSinkRotation()
{
}
/**
	* GetSinkRotation
	* \param sourcerotation sourcerotation for the source component
	* \param speed speed for the sink one
	*/
void CSinkRotation::SetSinkRotation(double sourcerotation, double speed)
{

}

double CSinkRotation::CalculateSpeed(double SourceRadius,double SinkRadius)
{
	if (SourceRadius == 0 || SinkRadius == 0)
	{
		return 1;
	}
	else
	{
		return double(SourceRadius) / double(SinkRadius);
	}
}

void CSinkRotation::DoRotation(double rotation, double radius)
{
	for (auto sink : mComponents)
	{
		double speed=CalculateSpeed(radius, sink->GetRadius());
		
		sink->SetRotation(rotation*speed);
		
		sink->DoRotation(rotation*speed);
		
	}
}
