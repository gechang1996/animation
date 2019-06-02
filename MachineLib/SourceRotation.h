/**
 * \file SourceRotation.h
 *
 * \author Chang Ge
 *
 *The class for SourceRotation
 */
#pragma once
#include<vector>
#include<memory>
#include "SinkRotation.h"

class CComponent;
/**
 *The class for SourceRotation
 */
class CSourceRotation
{
public:
	CSourceRotation();
	virtual ~CSourceRotation();

	/** \brief Copy constructor disabled */
	CSourceRotation(const CSourceRotation &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSourceRotation &) = delete;

	/**
	* Rotation for the source
	* \param rotation rotation for the source component
	*/
	void SetRotation(double rotation) { mRotation = rotation; }
	/**
	* Get Rotation for the source
	* \return rotation rotation for the source component
	*/
	double GetRotation() { return mRotation; }
	/**
	* Add Sinkrotation into the vector
	* \param component The Sinkrotation which will be added into the vector
	*/
	void AddSink(std::shared_ptr<CComponent> component);
	/**
	* Call function in the source rotation
	* \param rotation the rotation for the motor
	* \param radius radius of the rotation
	*/
	void DoRotation(double rotation, double radius);

	
private:
	///rotation of the source component
	double mRotation = 0;
	///vector of the sinkrotations
	std::shared_ptr<CSinkRotation> mSinkRoations=std::make_shared<CSinkRotation>();


};

