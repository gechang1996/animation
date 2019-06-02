/**
 * \file ActorFactory.h
 *
 * \author Chang Ge
 *
 * \brief Abstract base class for actor factories.
 */
#pragma once
#include "ActorFactory.h"

 /**
  * \brief Abstract base class for prop2 factories.
  */
class CPropFactory2
{
public:
	CPropFactory2();
	virtual ~CPropFactory2();

	std::shared_ptr<CActor> Create();
};

