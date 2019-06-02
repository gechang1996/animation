#include "stdafx.h"
#include "MachineUse.h"
#include "MachineFactoryA.h"
#include "MachineFactoryB.h"

CMachineUse::CMachineUse()
{
	mMachineConstructor = std::make_shared<CMachineConstructor>();
}


CMachineUse::~CMachineUse()
{
}


void CMachineUse::SetLocation(int x, int y)
{
	CMachine::SetLocation(x, y);
}

void CMachineUse::DrawMachine(Gdiplus::Graphics *graphics)
{
	
	mMachineConstructor->Draw(graphics);
}


void CMachineUse::SetMachineFrame(int frame)
{
	CMachine::SetMachineFrame(frame);
	mFrameNumber = frame;
	mTime = mSpeed * (double(mFrameNumber) / double(mFrameRate));

	
	mMachineConstructor->SetTime(mTime);
	mMachineConstructor->UpdateComponents();

}




void CMachineUse::SetSpeed(double speed)
{
	CMachine::SetSpeed(speed);
	mSpeed = speed;
}

void CMachineUse::SetFrameRate(double rate)
{
	mFrameRate = rate;
}


void CMachineUse::SetMachineNumber(int seed)
{
	
	if (seed == 1)
	{
		CMachineFactoryA factoryA;
		auto machine1=factoryA.CreateMachine();
		mMachineConstructor = machine1->GetMachineConstructor();
		mMachineConstructor->ResetPos(Gdiplus::Point(0, 0));
		
	}
	else if (seed == 2)
	{
		CMachineFactoryB factoryB;
		auto machine2 = factoryB.CreateMachine();
		mMachineConstructor = machine2->GetMachineConstructor();
		mMachineConstructor->ResetPos(Gdiplus::Point(-200, 0));
	}
	else
	{
		return;
	}
	CMachine::SetMachineNumber(seed);
}

int CMachineUse::GetMachineNumber()
{
	return CMachine::GetMachineNumber();
}
