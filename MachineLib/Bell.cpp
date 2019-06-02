#include "stdafx.h"
#include "Bell.h"
#include "MachineConstructor.h"

CBell::CBell()
{
}


CBell::~CBell()
{
}

void CBell::SetChannel(std::wstring name)
{
	mChannel = GetConstructor()->GetPlayer()->CreateChannel(name);
}