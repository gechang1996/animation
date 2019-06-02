#include "stdafx.h"
#include "MachineConstructor.h"


CMachineConstructor::CMachineConstructor()
{
	
}


CMachineConstructor::~CMachineConstructor()
{
}

/**
* Draw all of the components
*/
void CMachineConstructor::Draw(Gdiplus::Graphics *graphics)
{
	
	for (auto component : mComponents)
	{

		component->Draw(graphics);
	}
}
/**
* Update all of the components rotation and position
*/
void CMachineConstructor::UpdateComponents()
{
	
	for (auto motor : mMotors)
	{
		double rotation = motor->GetSpeed()*mTime;
		motor->DoRotation(rotation);
	}
}

/**
	* Add Component into the Components vector
	* param component The component which will be added into the vector
	*/
void CMachineConstructor::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
	component->SetConstructor(this);
}
void CMachineConstructor::ResetPos(Gdiplus::Point offset)
{
	for (auto component : mComponents)
	{
		Gdiplus::Point pos = Gdiplus::Point(offset.X+ component->GetPos().X, offset.Y + component->GetPos().Y);
		component->SetPosition(pos);
	}

}