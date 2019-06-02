#include "stdafx.h"
#include "MachineFactoryB.h"
#include "MachineUse.h"
#include "MachineConstructor.h"
#include "Polygon.h"
#include "Component.h"
#include "Motor.h"
#include "Pulley.h"
#include "Cam.h"
#include "Shape.h"
#include "Roller.h"
#include "Shape.h"
#include "Bell.h"
#include <vector>

using namespace std;
using namespace Gdiplus;
CMachineFactoryB::CMachineFactoryB()
{
}


CMachineFactoryB::~CMachineFactoryB()
{
}

/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachineUse> CMachineFactoryB::CreateMachine()
{
	shared_ptr<CMachineUse> MachineUse = make_shared<CMachineUse>();


	auto My_Machine = MachineUse->GetMachineConstructor();

	auto Motor = make_shared<CMotor>();
	Motor->SetPosition(Point(870, 500));
	Motor->CenteredSquare(20);
	Motor->SetBaseMotor(L"images/motor2.png");
	Motor->SetImage(L"images/shaft.png");
	Motor->SetSource();
	My_Machine->AddComponent(Motor);
	My_Machine->AddMotor(Motor);
	

	return MachineUse;
}