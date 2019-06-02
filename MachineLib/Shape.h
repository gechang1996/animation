/**
 * \file Shape.h
 *
 * \author Chang Ge
 *
 *The class for building the shape
 */
#pragma once
#include "Component.h"

 /**
  *The class for building the shape
  */
class CShape:public CComponent
{
public:
	CShape();
	virtual ~CShape();
	/**
	 *	 calculate the position
	 * \param rollerposition calculate the shape pos by roller pos
	 */
	void CalculatPosition(Gdiplus::Point rollerposition);
	/** \brief Copy constructor disabled */
	CShape(const CShape &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CShape &) = delete;


};

