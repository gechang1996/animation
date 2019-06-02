/**
 * \file MachineDrawable.h
 *
 * \author Chang Ge
 *
 * \brief A drawable based on drawing a bitmap image.
 */
#pragma once
#include "Drawable.h"
#include "Machine.h"
#include <memory>
/**
*Class for A drawable based on drawing a bitmap image.
*/
class CMachineDrawable:public CDrawable
{
public:
/**
 * \brief Constructor
 * \param name The drawable name
 */
	CMachineDrawable(const std::wstring &name);
	virtual ~CMachineDrawable();

	/** \brief Default constructor disabled */
	CMachineDrawable() = delete;
	/** \brief Copy constructor disabled */
	CMachineDrawable(const CMachineDrawable &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineDrawable &) = delete;




	/** \brief Set the actor
	 * \param actor Set the actor*/
	void SetActor(CActor *actor)override { CDrawable::SetActor(actor); }

	/** \brief Draw the drawable
	 * \param graphics Graphics object to draw on */
	void Draw(Gdiplus::Graphics *graphics)override;


	/** \brief Test to see if we have been clicked on by the mouse
	 * \param pos Position to test
	 * \returns false  */
	bool HitTest(Gdiplus::Point pos)override { return false; }

	/** \brief Is this a movable drawable?
	 * \returns true if movable */
	bool IsMovable() override{ return false; }
	
	/** get the end time
	 * \returns the end time of the movie*/
	double GetEndTime() { return mEndTime;}
	/** get the end time
	 * \returns the start time of the movie*/
	double GetStartTime() { return mStartTime; }
	/** \brief timeline
	 * \param timeline timeline of the machine */
	void SetTimeline(CTimeline *timeline)override;
	/** \brief SetKeyFrame */
	void SetKeyframe()override;
	/** \brief GetKeyFrame */
	void GetKeyframe()override;
	/** \brief SetENd time
	 * \param time endtime */
	void SetEndTime(double time) { mEndTime = time; }
	/** \brief Set Start time
	 * \param time start time */
	void SetStartTime(double time) { mStartTime = time; }

	/** \brief Change the number of the machine*/
	void ChangeMachineNum()override;
	/** \brief Set machine
	 * \param machine set the machine */
	void SetMachine(std::shared_ptr<CMachine> machine);
private:
	///End time(for stopping the video)
	double mEndTime = 0;
	///Start time(when to start the programe)
	double mStartTime = 10000;
	///Machine1 we gonna use
	std::shared_ptr<CMachine> mMachine;
	
};

