#include "stdafx.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Actor.h"
#include "Picture.h"
#include "Timeline.h"
#include "MachineDlg.h"
CMachineDrawable::CMachineDrawable(const std::wstring &name) : CDrawable(name)
{
	
}


CMachineDrawable::~CMachineDrawable()
{
}


/** \brief Draw the drawable
	 * \param graphics Graphics object to draw on */
void CMachineDrawable::Draw(Gdiplus::Graphics *graphics)
{
	
	auto channel = GetAngleChannel();
	auto timeline = channel->GetTimeline();
	auto curFrame = timeline->GetCurrentFrame();
	auto time = timeline->GetCurrentTime();
	if (time >= mStartTime && time <= mEndTime)
	{
		mMachine->SetMachineFrame(curFrame);
	}
	
	mMachine->DrawMachine(graphics);
	timeline->SetTimeDuration(int(mStartTime), int(mEndTime));
	
}



void CMachineDrawable::SetTimeline(CTimeline *timeline)
{
	CDrawable::SetTimeline(timeline);
	timeline->SetMachineDrawable(this);


}
void CMachineDrawable::SetKeyframe()
{
	CDrawable::SetKeyframe();
	auto channel = GetAngleChannel();
	auto timeline = channel->GetTimeline();
	auto time = timeline->GetCurrentTime();
	if (time < mStartTime)
	{
		mStartTime = time;
	}
	else if (time > mEndTime)
	{
		mEndTime = time;
	}
	
	
}
void CMachineDrawable::GetKeyframe()
{
	CDrawable::GetKeyframe();
	auto channel = GetAngleChannel();
	auto timeline = channel->GetTimeline();
	mStartTime = timeline->GetStartTime();
	mEndTime = timeline->GetEndTime();
	
}
void CMachineDrawable::ChangeMachineNum()
{
	CMachineDlg dlg(mMachine);
	if (dlg.DoModal() == IDOK)
	{
	}
}

void CMachineDrawable::SetMachine(std::shared_ptr<CMachine> machine)
{ 
	mMachine = machine; 
	//CDrawable::GetActor()->GetPicture()->SetMachine(mMachine);

}