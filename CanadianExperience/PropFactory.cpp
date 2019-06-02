/**
 * \file PropFactory.cpp
 *
 * \author Chang Ge
 */
#include "stdafx.h"
#include "PropFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Machine.h"
#include "Actor.h"
#include "Picture.h"
#include "MachineDrawable.h"
using namespace Gdiplus;
using namespace std;

CPropFactory::CPropFactory()
{
}


CPropFactory::~CPropFactory()
{
}
/** \brief This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CPropFactory::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Machine1");

	

	auto machineDrawable = make_shared<CMachineDrawable>(L"Machine1");
	CMachineFactory factory;
	auto machine = factory.CreateMachine(1);
	actor->SetMachine(machine);
	machineDrawable->SetMachine(machine);
	actor->AddDrawable(machineDrawable);


	return actor;
}