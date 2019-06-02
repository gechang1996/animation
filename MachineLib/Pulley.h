/**
 * \file Pulley.h
 *
 * \author Chang Ge
 *
 *The class for building the pulley
 */
#pragma once
#include "Component.h"
#include "SourceRotation.h"
#include <memory>
#include <vector>
 /**
  *The class for building the pulley
  */
class CPulley:public CComponent
{
public:
	CPulley();
	virtual ~CPulley();

	/** \brief Copy constructor disabled */
	CPulley(const CPulley &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CPulley &) = delete;
	/**
	* Draw the component
	* \param graphics For drawing
	*/
	void Draw(Gdiplus::Graphics *graphics)override;
	/**
	* Draw the Belt between two pulley
	* \param graphics for drawing
	* \param radius for drawing
	* \param point pos of the sink pulley
	*/
	void DrawBelt(Gdiplus::Graphics *graphics, double radius, Gdiplus::Point point)override;
	/**
	* Set Sink
	* \param component set the sink to component
	*/
	void SetSink(std::shared_ptr<CComponent> component);
	/**
	* Set source
	*/
	void SetSource() { mSourceRotation = std::make_shared<CSourceRotation>(); }
	/**
	* Do the rotation
	* \param rotation rotation of the pulley
	*/
	void DoRotation(double rotation)override;
	/**
	* Add pulley into this pulley
	* \param pulley pulley pointer
	*/
	void AddPolley(std::shared_ptr<CPulley> pulley) { mPulleys.push_back(pulley); }
private:
	///sourcerotation
	std::shared_ptr<CSourceRotation> mSourceRotation=nullptr;
	///pulleys
	std::vector<std::shared_ptr<CPulley>> mPulleys;
};

