/**
 * \file PropFactory2.cpp
 *
 * \author Chang Ge
 */
#include "stdafx.h"
#include "PropFactory2.h"
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

CPropFactory2::CPropFactory2()
{
}


CPropFactory2::~CPropFactory2()
{
}

/** \brief This is a concrete factory method that creates our Harold actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CPropFactory2::Create()
{
	shared_ptr<CActor> actor = make_shared<CActor>(L"Machine2");



	auto machineDrawable = make_shared<CMachineDrawable>(L"Machine2");
	CMachineFactory factory;
	auto machine = factory.CreateMachine(2);
	actor->SetMachine(machine);
	machineDrawable->SetMachine(machine);
	actor->AddDrawable(machineDrawable);

	return actor;
}