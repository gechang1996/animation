/**
 * \file MachineFactoryB.h
 *
 * \author Chang Ge
 *
 * Machine factory class. Creates The second machine
 */
#pragma once
#include <memory>
#include "MachineFactory.h"
class CMachineUse;

/**
 * Machine factory class. Creates second machine
 *
 */
class CMachineFactoryB :public CMachineFactory
{
public:
	CMachineFactoryB();
	virtual ~CMachineFactoryB();

	std::shared_ptr<CMachineUse> CreateMachine();

	
};

