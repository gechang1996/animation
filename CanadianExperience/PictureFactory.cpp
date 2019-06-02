/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "PropFactory.h"
#include "ImageDrawable.h"
#include "PropFactory2.h"
#include "Machine.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

	

	//Create and add prop1
	CPropFactory pfactory;
	auto p = pfactory.Create();
	auto machine1 = p->GetMachine();
	p->SetPosition(Point(100, 300));
	picture->AddActor(p);
	picture->SetMachine1(machine1);

	//create and add prop2
	CPropFactory2 pfactory2;
	auto p2 = pfactory2.Create();
	auto machine2 = p2->GetMachine();
	p2->SetPosition(Point(100,300));
	picture->AddActor(p2);
	picture->SetMachine2(machine2);
    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(850, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(120, 500));
    picture->AddActor(sparty);

	



    return picture;
}
