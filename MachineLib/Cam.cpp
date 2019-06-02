#include "stdafx.h"
#include "Cam.h"
#include "Shape.h"
using namespace Gdiplus;
using namespace std;
const int SubSteps = 3;
const int OffsetX = 60;
const int OffsetY = 100;
CCam::CCam()
{
	
}


CCam::~CCam()
{
}
/**
 * Build the cam after all of the pins have been set.
 */
void CCam::Build()
{
	for (int i = 0; i < mSteps * SubSteps; i++)
	{
		double angle = 2 * M_PI * i / double(mSteps * SubSteps);
		double radius = mRadius;

		for (auto pin : mPins)
		{
			if (pin * SubSteps == i || pin * SubSteps == (i - 1))
			{
				radius = mRadius + mPinSize;
				break;
			}
		}

		AddPoint(radius * cos(angle), radius * -sin(angle));
	}
}
/**
* Do the rolling
*/
void CCam::DoRolling()
{

}

double CCam::GetDistanceFromCenterToRoller()
{
	return 0;
}

void CCam::SetRadius(double radius)
{
	CComponent::SetRadius(0);
	mRadius = radius;
}

/**
	* Draw the component
	* \param graphics For drawing
	*/
void CCam::Draw(Gdiplus::Graphics *graphics)
{
	CComponent::Draw(graphics);
	PointF intersection;
	if (Intersection(0.25, intersection))
	{
		float fx = intersection.X + GetPos().X ;
		float fy = intersection.Y + GetPos().Y ;

		for (auto roller : mRollers)
		{
			roller->SetPosition(Gdiplus::Point(int(fx)-OffsetX, int(fy)- OffsetY));
			roller->DrawPolygon(graphics, int(fx)- OffsetX, int(fy)- OffsetY);
			roller->GetMallet()->SetPosition(Point(int(fx)- OffsetX, int(fy)- OffsetY));
			roller->GetMallet()->DrawPolygon(graphics, int(fx)- OffsetX, int(fy)- OffsetY);
			roller->PlayBell();
		}
		
	}
}