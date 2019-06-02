/**
 * \file MachineFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "MachineFactoryA.h"
#include "MachineFactoryB.h"
#include "MachineUse.h"

using namespace std;
using namespace Gdiplus;


/**
 * Constructor
 */
CMachineFactory::CMachineFactory()
{
}


/**
 * Destructor
 */
CMachineFactory::~CMachineFactory()
{
}


/**
 * Create a machine object
 * \param machineNum use this to check which machine i need 
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachine> CMachineFactory::CreateMachine(int machineNum)
{
	//shared_ptr<CMachine> Machine = make_shared<CMachine>();
	CMachineFactoryA factoryA;
	CMachineFactoryB factoryB;
	
	shared_ptr<CMachine> MachineA = factoryA.CreateMachine();
	shared_ptr<CMachine> MachineB = factoryB.CreateMachine();


	
	if(machineNum==1)
	{
		return MachineA;
	}
	else
	{
		return MachineB;
	}
}

