/**
 * \file SinkRotation.h
 *
 * \author Chang Ge
 *
 *The class for SinkRotation
 */
#pragma once
#include <memory>
#include <vector>

class CComponent;
/**
 *The class for SinkRotation
 */
class CSinkRotation
{
public:
	CSinkRotation();
	virtual ~CSinkRotation();

	/** \brief Copy constructor disabled */
	CSinkRotation(const CSinkRotation &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CSinkRotation &) = delete;
	/**
	* GetSinkRotation
	* \param sourcerotation sourcerotation for the source component
	* \param speed speed for the sink one
	*/
	void SetSinkRotation(double sourcerotation,double speed);
	/**
	* Calculate the ratio of the speed
	* \param SourceRadius 
	* \param SinkRadius 
	* \return Speed of the sinkrotation
	*/
	double CalculateSpeed(double SourceRadius, double SinkRadius);
	/**
	* Add the component
	* \param component add this into the vector
	*/
	void SetComponent(std::shared_ptr<CComponent> component) { mComponents.push_back(component); }
	/**
	* Do the rotation of the compoennt
	* \param rotation rotation of the component 
	* \param radius radius of the component
	*/
	void DoRotation(double rotation, double radius);

	
private:
	///the ratio between souce roation and sink roation
	double mSpeed = 1;
	///the component associated with the sinkroation
	std::vector<std::shared_ptr<CComponent>> mComponents;
};

