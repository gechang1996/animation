/**
 * \file PropFactory.h
 *
 * \author Chang Ge
 *
 * \brief Abstract base class for actor factories.
 */
#pragma once
#include "ActorFactory.h"

 /**
  * \brief Abstract base class for prop factories.
  */
class CPropFactory:
	public CActorFactory
{
public:
	CPropFactory();
	virtual ~CPropFactory();

	std::shared_ptr<CActor> Create();
};

