/**
 * \file MachineFactoryA.h
 *
 * \author Chang Ge
 *
 * Machine factory class. Creates The first machine
 */
#pragma once
#include <memory>
#include "MachineFactory.h"
class CMachineUse;

/**
 * Machine factory class. Creates first machine
 *
 */
class CMachineFactoryA:public CMachineFactory
{
public:
	CMachineFactoryA();
	virtual ~CMachineFactoryA();

	std::shared_ptr<CMachineUse> CreateMachine();

	
};

