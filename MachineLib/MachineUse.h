/**
 * \file MachineUse.h
 *
 * \author Chang Ge
 *
 * Class that represents a machine.
 *
 */
#pragma once
#include "Machine.h"
#include "MachineConstructor.h"
#include <memory>

 /**
  *Class that represents a machine.
  */
class CMachineUse:public CMachine
{
public:
	CMachineUse();
	virtual ~CMachineUse();

	/** \brief Copy constructor disabled */
	CMachineUse(const CMachineUse &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineUse &) = delete;

	/**
	* Set the position for the root of the machine
	* \param x X location (pixels)
	* \param y Y location (pixels)
	*/
	void SetLocation(int x, int y)override;

	/**
	* Draw the machine at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawMachine(Gdiplus::Graphics *graphics)override;

	/**
	* Set the current machine animation frame
	* \param frame Frame number
	*/
	void SetMachineFrame(int frame)override;

	/**
	 * Set the expected frame rate in frames per second
	 * \param rate Frame rate in frames per second
	 */
	void SetFrameRate(double rate)override;

	/**
	* Set  the bend angle
	* \param speed Speed from 0 to 1, where 1 is full speed
	*/
	void SetSpeed(double speed)override;

	/**
	* Set the machine number
	* \param machine An integer number. Each number makes a different machine
	*/
	void SetMachineNumber(int machine)override;

	/**
	 * Get the current machine number
	 * \return Machine number integer
	 */
	int GetMachineNumber()override;
	/**
	 * Get the frame
	 * \return Machine frame
	 */
	int GetMachineFrame() { return mFrameNumber; }
	/**
	 * \return Machine frame rate
	 */
	double GetFrameRate() { return mFrameRate; }
	/**
	 * \return Machine constrctor
	 */
	std::shared_ptr<CMachineConstructor> GetMachineConstructor() { return mMachineConstructor; }
	/**
	 * \return Machine time
	 */
	double GetTime() { return mTime; }

	

	

private:
	///This is the frame rate
	double mFrameRate = 30;
	///This is the current frame name
	int mFrameNumber = 0;
	///This is the location of the whole machine
	Gdiplus::Point mLocation = Gdiplus::Point(0, 0);
	///This is the current time
	double mTime;
	///This the machineConstructor for building the whole machine
	std::shared_ptr<CMachineConstructor> mMachineConstructor;
	/// speed of the machine use
	double mSpeed = 1;
	
	
};

