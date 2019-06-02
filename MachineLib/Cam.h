/**
 * \file Cam.h
 *
 * \author Chang Ge
 *
 *The class for building the cam
 */
#pragma once
#include "Component.h"
#include "Roller.h"
#include <vector>
#include <memory>
 /**
  *The class for building the cam
  */
class CCam:public CComponent
{
public:
	CCam();
	virtual ~CCam();

	/** \brief Copy constructor disabled */
	CCam(const CCam &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CCam &) = delete;

	/**
	* Add pins into the vecor
	* \param pin pin for adding into the vector
	*/
	void Addpin(int pin) { mPins.push_back(pin); }
	/**
* Build the cam by pins vector
*/
	void Build();
	/**
* Do the rolling 
*/
	void DoRolling();
	/**
	* Get the distance from the center of the cam to the roller
	* \return distance from the center of the cam to the roller
	*/
	double GetDistanceFromCenterToRoller();
	/**
	* Set The possible number of pins
	* \param pinNum 
	*/
	void SetPossiblePins(double pinNum) { mSteps = pinNum; }
	/**
	* Set The radius of the cam
	* \param radius radius to be setted
	*/
	void SetRadius(double radius)override;
	/**
	* Set The size of the pin
	* \param size set the size of the pin
	*/
	void SetPinSize(double size) { mPinSize = size; }

	/**
	* Draw the component
	* \param graphics For drawing
	*/
	void Draw(Gdiplus::Graphics *graphics)override;
	/**
	* Add roller into cam
	* \param roller roller to be added
	*/
	void AddRoller(std::shared_ptr<CRoller> roller) { mRollers.push_back(roller); }
private:
	///This is for storing the pins
	std::vector<int> mPins;
	///The is the possiable of the total pins
	double mSteps=0;
	///radius of the cam
	double mRadius=0;
	///The is the size of the pin
	double mPinSize = 0;
	///rollers
	std::vector<std::shared_ptr<CRoller>> mRollers;
};

