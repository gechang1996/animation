/**
 * \file Bell.h
 *
 * \author Chang Ge
 *
 *The class for building the roller
 */
#pragma once
#include "Component.h"
#include "WavChannel.h"
#include <memory>
#include <string>

 /**
  *The class for building the roller
  */
class CBell:public CComponent
{
public:
	CBell();
	virtual ~CBell();


	/** \brief Copy constructor disabled */
	CBell(const CBell &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBell &) = delete;

	/** Play the notes
	*/
	void PlayNotes() { if(mChannel !=nullptr) mChannel->Play(); }
	/** Set the channel between channel and bell
	* \param name name of the input file
	*/
	void SetChannel(std::wstring name);

private:
	///Channel
	std::shared_ptr<CWavChannel> mChannel=nullptr;
};

