/**
 * \file Roller.h
 *
 * \author Chang Ge
 *
 *The class for building the roller
 */
#pragma once
#include "Component.h"
#include "Bell.h"
#include "Shape.h"
#include <memory>
 /**
  *The class for building the roller
  */
class CRoller:public CComponent
{
public:
	CRoller();
	virtual ~CRoller();


	/** \brief Copy constructor disabled */
	CRoller(const CRoller &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CRoller &) = delete;
	/**
	 * Get the distance from the center of the roller to the center of the cam
	 * \return distance
	 */
	double GetDistance();
	/**
	*Play the video
	*/
	void PlayBell();
	/**
	* Get the mallet
	* \return mallet
	*/
	std::shared_ptr<CShape> GetMallet() { return mMallet; }
	/**
	 * set bell
	 * \param bell
	 */
	void SetBell(std::shared_ptr<CBell> bell) { mBell = bell; }
	/**
	 * set initial pos
	 * \param pos initial pos 
	 */
	void SetInitialPos(Gdiplus::Point pos) { mInitialPos =Gdiplus::Point(pos.X-60,pos.Y-100); }
private:
	///bell
	std::shared_ptr<CBell> mBell = nullptr;
	///mallet
	std::shared_ptr<CShape> mMallet = std::make_shared<CShape>();
	///0 means up, 1 means down
	int mState = 0;
	///check if we need to play it 
	bool mPlay = true;

	///intial position
	Gdiplus::Point mInitialPos;
};

