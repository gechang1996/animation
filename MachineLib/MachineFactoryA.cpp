#include "stdafx.h"
#include "MachineFactoryA.h"
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

CMachineFactoryA::CMachineFactoryA()
{
}


CMachineFactoryA::~CMachineFactoryA()
{
}

/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CMachineUse> CMachineFactoryA::CreateMachine()
{
	
	shared_ptr<CMachineUse> MachineUse = make_shared<CMachineUse>();
	
	

	auto My_Machine = MachineUse->GetMachineConstructor();

	auto flag = make_shared<CShape>();
	flag->SetImage(L"images/flag.png",false);
	flag->AddPoint(-85,0);
	flag->AddPoint(-85, -150);
	flag->AddPoint(5, -150);
	flag->AddPoint(5, 0);
	flag->SetPosition(Point(341, 400));
	


	auto Motor = make_shared<CMotor>();
	Motor->SetPosition(Point(400,500));
	Motor->CenteredSquare(20);
	Motor->SetBaseMotor(L"images/motor2.png");
	Motor->SetImage(L"images/shaft.png");
	
	auto Pulley1 = make_shared<CPulley>();
	Pulley1->SetPosition(Point(400, 500));
	Pulley1->CenteredSquare(30);
	Pulley1->SetRadius(15);
	Pulley1->SetImage(L"images/pulley.png");

	auto Pulley2 = make_shared<CPulley>();
	Pulley2->SetPosition(Point(340, 400));
	Pulley2->CenteredSquare(80);
	Pulley2->SetRadius(40);
	Pulley2->SetImage(L"images/pulley.png");

	auto Pulley3 = make_shared<CPulley>();
	Pulley3->SetPosition(Point(340, 400));
	Pulley3->CenteredSquare(25);
	Pulley3->SetImage(L"images/pulley.png");

	auto Pulley4 = make_shared<CPulley>();
	Pulley4->SetPosition(Point(340, 400));
	Pulley4->CenteredSquare(25);
	Pulley4->SetImage(L"images/pulley.png");
	Pulley4->SetRadius(12.5);


	auto Pulley5 = make_shared<CPulley>();
	Pulley5->SetPosition(Point(485, 400));
	Pulley5->CenteredSquare(70);
	Pulley5->SetRadius(35);
	Pulley5->SetImage(L"images/pulley2.png");

	auto Pulley6 = make_shared<CPulley>();
	Pulley6->SetPosition(Point(555, 400));
	Pulley6->CenteredSquare(70);
	Pulley6->SetRadius(35);
	Pulley6->SetImage(L"images/pulley2.png");

	auto Pulley7 = make_shared<CPulley>();
	Pulley7->SetPosition(Point(625, 400));
	Pulley7->CenteredSquare(70);
	Pulley7->SetRadius(35);
	Pulley7->SetImage(L"images/pulley2.png");

	auto Pulley8 = make_shared<CPulley>();
	Pulley8->SetPosition(Point(695, 400));
	Pulley8->CenteredSquare(70);
	Pulley8->SetRadius(35);
	Pulley8->SetImage(L"images/pulley2.png");

	auto Pulley9 = make_shared<CPulley>();
	Pulley9->SetPosition(Point(765, 400));
	Pulley9->CenteredSquare(70);
	Pulley9->SetRadius(35);
	Pulley9->SetImage(L"images/pulley2.png");

	auto Ground = make_shared<CShape>();
	Ground->SetImage(L"images/base.png");
	Ground->Rectangle(260, 588, 600, 50);

	auto shape1 = make_shared<CShape>();
	shape1->SetColor(Color::Blue);
	shape1->Rectangle(330, 550,20,150);

	auto shape2 = make_shared<CShape>();
	shape2->SetColor(Color::Red);
	shape2->Rectangle(475, 550, 20, 150);

	auto shape3 = make_shared<CShape>();
	shape3->SetColor(Color::Red);
	shape3->Rectangle(475+70, 550, 20, 150);

	auto shape4 = make_shared<CShape>();
	shape4->SetColor(Color::Red);
	shape4->Rectangle(475+140, 550, 20, 150);

	auto shape5 = make_shared<CShape>();
	shape5->SetColor(Color::Red);
	shape5->Rectangle(475+210, 550, 20, 150);

	auto shape6 = make_shared<CShape>();
	shape6->SetColor(Color::Red);
	shape6->Rectangle(475+280, 550, 20, 150);


	auto cam1 = make_shared<CCam>();
	cam1->SetPosition(Point(485, 400));
	cam1->SetImage(L"images/hammered-copper1.png", true);
	cam1->SetPossiblePins(24);
	cam1->SetPinSize(6);
	cam1->SetRadius(20);
	cam1->Addpin(2);
	cam1->Addpin(10);
	cam1->Addpin(13);
	cam1->Addpin(20);
	cam1->Addpin(14);
	cam1->Build();

	auto roller1 = make_shared<CRoller>();
	roller1->SetImage(L"images/roller.png");
	roller1->CenteredSquare(10);
	roller1->SetPosition(Point(485, 400));
	cam1->AddRoller(roller1);
	roller1->GetMallet()->SetImage(L"images/mallet.png");
	roller1->GetMallet()->Rectangle(-5, 0,10,150);
	



	auto cam2 = make_shared<CCam>();
	cam2->SetPosition(Point(485+70, 400));
	cam2->SetImage(L"images/hammered-copper1.png", true);
	cam2->SetPossiblePins(24);
	cam2->SetPinSize(6);
	cam2->SetRadius(20);
	cam2->Addpin(2);
	cam2->Addpin(7);
	cam2->Addpin(9);
	cam2->Addpin(11);
	cam2->Addpin(19);
	cam2->Build();



	auto roller2 = make_shared<CRoller>();
	roller2->SetImage(L"images/roller.png");
	roller2->CenteredSquare(10);
	roller2->SetPosition(Point(485+70, 400));
	cam2->AddRoller(roller2);

	roller2->GetMallet()->SetImage(L"images/mallet.png");
	roller2->GetMallet()->Rectangle(-5, 0, 10, 150);

	auto cam3 = make_shared<CCam>();
	cam3->SetPosition(Point(485+140, 400));
	cam3->SetImage(L"images/hammered-copper1.png", true);
	cam3->SetPossiblePins(24);
	cam3->SetPinSize(6);
	cam3->SetRadius(20);
	cam3->Addpin(10);
	cam3->Addpin(19);
	cam3->Addpin(22);
	cam3->Build();

	auto roller3 = make_shared<CRoller>();
	roller3->SetImage(L"images/roller.png");
	roller3->CenteredSquare(10);
	roller3->SetPosition(Point(485+140, 400));
	cam3->AddRoller(roller3);

	roller3->GetMallet()->SetImage(L"images/mallet.png");
	roller3->GetMallet()->Rectangle(-5, 0, 10, 150);

	auto cam4 = make_shared<CCam>();
	cam4->SetPosition(Point(485+210, 400));
	cam4->SetImage(L"images/hammered-copper1.png", true);
	cam4->SetPossiblePins(24);
	cam4->SetPinSize(6);
	cam4->SetRadius(20);
	cam4->Addpin(4);
	cam4->Addpin(10);
	cam4->Addpin(14);
	cam4->Addpin(16);
	cam4->Addpin(123);
	cam4->Build();

	auto roller4 = make_shared<CRoller>();
	roller4->SetImage(L"images/roller.png");
	roller4->CenteredSquare(10);
	roller4->SetPosition(Point(485+210, 400));
	cam4->AddRoller(roller4);

	roller4->GetMallet()->SetImage(L"images/mallet.png");
	roller4->GetMallet()->Rectangle(-5, 0, 10, 150);

	auto cam5 = make_shared<CCam>();
	cam5->SetPosition(Point(485+280, 400));
	cam5->SetImage(L"images/hammered-copper1.png", true);
	cam5->SetPossiblePins(24);
	cam5->SetPinSize(6);
	cam5->SetRadius(20);
	cam5->Addpin(3);
	cam5->Addpin(9);
	cam5->Addpin(21);
	cam5->Addpin(13);
	cam5->Addpin(18);
	cam5->Build();

	auto roller5 = make_shared<CRoller>();
	roller5->SetImage(L"images/roller.png");
	roller5->CenteredSquare(10);
	roller5->SetPosition(Point(485+280, 400));
	cam5->AddRoller(roller5);

	roller5->GetMallet()->SetImage(L"images/mallet.png");
	roller5->GetMallet()->Rectangle(-5, 0, 10, 150);

	
	roller1->SetInitialPos(Point(470 + 3, 400));
	roller2->SetInitialPos(Point(470 + 3 + 70, 400));
	roller3->SetInitialPos(Point(470 + 3 + 140, 400));
	roller4->SetInitialPos(Point(470 + 3 + 210, 400));
	roller5->SetInitialPos(Point(470 + 3 + 280, 400));

	Motor->SetSource();
	Motor->SetSink(Pulley1);
	Pulley1->SetSource();
	Pulley2->SetSource();
	Pulley3->SetSource();
	Pulley4->SetSource();
	Pulley5->SetSource();
	Pulley6->SetSource();
	Pulley7->SetSource();
	Pulley8->SetSource();
	Pulley9->SetSource();
	Pulley1->SetSink(Pulley2);
	Pulley2->AddPolley(Pulley1);
	Pulley2->SetSink(Pulley3);
	Pulley2->SetSink(flag);
	Pulley3->SetSink(Pulley4);
	Pulley4->SetSink(Pulley5);
	Pulley5->AddPolley(Pulley4);
	Pulley5->SetSink(cam1);

	Pulley5->SetSink(Pulley6);
	Pulley6->AddPolley(Pulley5);
	Pulley6->SetSink(cam2);
	Pulley6->SetSink(Pulley7);
	Pulley7->AddPolley(Pulley6);
	Pulley7->SetSink(cam3);
	Pulley7->SetSink(Pulley8);
	Pulley8->AddPolley(Pulley7);
	Pulley8->SetSink(cam4);
	Pulley8->SetSink(Pulley9);
	Pulley9->AddPolley(Pulley8);
	Pulley9->SetSink(cam5);




	auto bar1 = make_shared<CBell>();
	bar1->SetImage(L"images/bar-blu.png");
	bar1->Rectangle(470+3, 300,25,120);
	My_Machine->AddComponent(bar1);
	bar1->SetChannel(L"audio/bell-a1.wav");
	roller1->SetBell(bar1);
	
	auto bar2 = make_shared<CBell>();
	bar2->SetImage(L"images/bar-red.png");
	bar2->Rectangle(470+70+3, 300, 25, 120);
	My_Machine->AddComponent(bar2);
	bar2->SetChannel(L"audio/bell-b1.wav");
	roller2->SetBell(bar2);
	
	auto bar3 = make_shared<CBell>();
	bar3->SetImage(L"images/bar-yel.png");
	bar3->Rectangle(470+140+3, 300, 25, 120);
	My_Machine->AddComponent(bar3);
	bar3->SetChannel(L"audio/bell-c1.wav");
	roller3->SetBell(bar3);
	

	auto bar4 = make_shared<CBell>();
	bar4->SetImage(L"images/bar-pur.png");
	bar4->Rectangle(470+210+3, 300, 25, 120);
	My_Machine->AddComponent(bar4);
	bar4->SetChannel(L"audio/bell-d1.wav");
	roller4->SetBell(bar4);

	auto bar5 = make_shared<CBell>();
	bar5->SetImage(L"images/bar-grn.png");
	bar5->Rectangle(470+280+3, 300, 25, 120);
	My_Machine->AddComponent(bar5);
	bar5->SetChannel(L"audio/bell-e1.wav");
	roller5->SetBell(bar5);




	My_Machine->AddComponent(shape1);
	My_Machine->AddComponent(shape2);
	My_Machine->AddComponent(shape3);
	My_Machine->AddComponent(shape4);
	My_Machine->AddComponent(shape5);
	My_Machine->AddComponent(shape6);

	My_Machine->AddComponent(Motor);
	My_Machine->AddComponent(Pulley1);
	My_Machine->AddComponent(Pulley2);
	My_Machine->AddComponent(Pulley3);
	My_Machine->AddComponent(Pulley5);
	My_Machine->AddComponent(cam1);
	My_Machine->AddComponent(Pulley6);
	My_Machine->AddComponent(cam2);
	My_Machine->AddComponent(Pulley7);
	My_Machine->AddComponent(cam3);
	My_Machine->AddComponent(Pulley8);
	My_Machine->AddComponent(cam4);
	My_Machine->AddComponent(Pulley9);

	My_Machine->AddComponent(cam5);
	
	My_Machine->AddComponent(Ground);
	My_Machine->AddComponent(flag);
	My_Machine->AddMotor(Motor);

	return MachineUse;
}