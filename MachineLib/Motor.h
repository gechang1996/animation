/**
 * \file Motor.h
 *
 * \author Chang Ge
 *
 *The class for building the Motor
 */
#pragma once
#include "Component.h"
#include "SourceRotation.h"
 /**
  *The class for building the Motor
  */

class CMotor:public CComponent
{
public:
	CMotor();
	virtual ~CMotor();

	/** \brief Copy constructor disabled */
	CMotor(const CMotor &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMotor &) = delete;
	/**
	* Set the speed of the motor
	* \param speed speed
	*/
	void SetSpeed(double speed) { mSpeed = speed; }
	/**
	 * Get the speed
	 * \return Motor speed
	 */
	double GetSpeed() { return mSpeed; }
	/**
	* Calculate the rotation of the motor
	* \param time time for calculating the speed
	*/
	void CalculateRotation(double time);
	/**
	* Draw the component
	* \param graphics For drawing
	*/
	void Draw(Gdiplus::Graphics *graphics)override;
	/**
	* Call function in the source rotation
	* \param rotation the rotation for the motor
	*/
	void DoRotation(double rotation)override;
	/**
	* Set Base motor
	* \param filename motor name
	*/
	void SetBaseMotor(std::wstring filename);
	/**
	* Set the component as the sink
	* \param component set the component as the sink
	*/
	void SetSink(std::shared_ptr<CComponent> component);
	/**
	 * Get the Source
	 * \return rotation rotation
	 */
	std::shared_ptr<CSourceRotation> GetSource() { return mSourceRotation; }
	/**
	* Set the source
	*/
	void SetSource() { mSourceRotation = std::make_shared<CSourceRotation>(); }
private:
	///the speed of the machine
	double mSpeed = 1.0;
	///sourcerotation
	std::shared_ptr<CSourceRotation> mSourceRotation=nullptr;
	/// The base for this motor
	CPolygon mPoly;
};

