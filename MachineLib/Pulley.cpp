#include "stdafx.h"
#include "Pulley.h"
#include <math.h>
using namespace Gdiplus;
using namespace std;
const int OffsetX = 60;
const int OffsetY = 100;
CPulley::CPulley()
{
}


CPulley::~CPulley()
{
}

/**
	* Draw the component
	* \param graphics For drawing
	*/
void CPulley::Draw(Gdiplus::Graphics *graphics)
{
	for (auto pulley : mPulleys)
	{
		DrawBelt(graphics, pulley->GetRadius(), Gdiplus::Point(pulley->GetPos().X-OffsetX, pulley->GetPos().Y-OffsetY));
	}
	CComponent::Draw(graphics);
	
}


/**
	* Draw the Belt between two pulley
	* \param graphics for drawing
	* \param radius for drawing
	* \param point sink pulley pos
	*/
void CPulley::DrawBelt(Gdiplus::Graphics *graphics, double radius,Gdiplus::Point point)
{
	Pen pen(Color::Black, 2.0f);
	double SinkX = GetPos().X-OffsetX;
	double SinkY = GetPos().Y-OffsetY;
	double SourceX = point.X;
	double SourceY = point.Y;
	double SinkRadius = GetRadius();
	double SourceRadius = radius ;
	double theta = atan2(SourceY - SinkY, SourceX - SinkX);
	double beta = theta - asin((SinkRadius - SourceRadius) / abs(sqrt(pow(SourceX-SinkX,2)+pow(SourceY-SinkY,2))))-M_PI/2;
	
	auto saveSM = graphics->GetSmoothingMode();
	graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);
	
	graphics->DrawLine(&pen,int(SinkRadius*cos(beta)+SinkX), int(SinkRadius*sin(beta) + SinkY),int(SourceRadius*cos(beta)+SourceX),int(SourceRadius*sin(beta)+SourceY));
	graphics->DrawLine(&pen, int(-SinkRadius*cos(beta) + SinkX), int(-SinkRadius*sin(beta) + SinkY), int(-SourceRadius*cos(beta) + SourceX), int(-SourceRadius*sin(beta) + SourceY));

	graphics->SetSmoothingMode(saveSM);
}


void CPulley::SetSink(std::shared_ptr<CComponent> component)
{
	mSourceRotation->AddSink(component);
}

void CPulley::DoRotation(double rotation)
{
	if (mSourceRotation != nullptr)
	{
		mSourceRotation->DoRotation(rotation, GetRadius());
	}
	
}