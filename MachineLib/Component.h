/**
 * \file Component.h
 *
 * \author Chang Ge
 *
 *The class for building the whole machine
 */
#pragma once
#include "Polygon.h"
#include <vector>
#include <memory>

class CPulley;
class CMachineConstructor;
/**
 *The class for building the whole machine
 */
class CComponent:public CPolygon
{
public:
	CComponent();
	virtual ~CComponent();

	/** \brief Copy constructor disabled */
	CComponent(const CComponent &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CComponent &) = delete;
	/**
	* Position for each component
	* \param Pos Position
	*/
	virtual void SetPosition(Gdiplus::Point Pos) { mPosition = Pos; }
	/**
	* \param graphics For drawing
	*/
	virtual void Draw(Gdiplus::Graphics *graphics);
	/**
	* Draw the component
	* \param rotation Position
	*/
	virtual void Update(double rotation);
	/**
	* radius for each component
	* \param radius Radius
	*/
	virtual void SetRadius(double radius) { mRadius = radius; }
	/**
	* Get Radius for the component
	* \return radius radius for the component
	*/
	double GetRadius() { return mRadius; }
	/**
	* Get Position
	* \return position position of the component
	*/
	Gdiplus::Point GetPos() { return mPosition; }
	/**
	* Call function in the source rotation
	* \param rotation the rotation for the motor
	*/
	virtual void DoRotation(double rotation) {}
	
	/**
	* Draw the Belt between two pulley
	* \param graphics For drawing
	* \param radius radius of the component
	* \param point position of the sink pulley
	*/
	virtual void DrawBelt(Gdiplus::Graphics *graphics, double radius, Gdiplus::Point point) {}
	/**
	* SetConstructor
	* \param constructor SetConstructor
	*/
	void SetConstructor(CMachineConstructor* constructor);
	/**
	* Get constructor
	* \return constructor constructor
	*/
	CMachineConstructor* GetConstructor() { return mConstructor; }

private:
	///the position of the component
	Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
	///radius of the component
	double mRadius=0;
	///Constructor
	CMachineConstructor* mConstructor = nullptr;
};

