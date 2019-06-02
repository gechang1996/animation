#include "stdafx.h"
#include "Roller.h"


CRoller::CRoller()
{
}


CRoller::~CRoller()
{
}
/**
* Get the distance from the center of the roller to the center of the cam
* \return distance
*/
double CRoller::GetDistance()
{
	return 0;
}
/**
*Play the video
*/
void CRoller::PlayBell()
{

	if ((abs(GetPos().Y -mInitialPos.Y) >=23 ) && (abs(GetPos().Y - mInitialPos.Y) <=24) && mPlay==true &&mState==0)
	{
		mBell->PlayNotes();
		mPlay = false;
		mState = 1;
	}
	else if ((abs(GetPos().Y - mInitialPos.Y) >24)  && mPlay == false )
	{
		
		mPlay = true;
		mState = 1;

	}
	else if ((abs(GetPos().Y - mInitialPos.Y) < 23))
	{
		mPlay = true;
		mState = 0;
	}
}