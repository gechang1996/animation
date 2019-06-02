/**
 * \file MachineConstructor.h
 *
 * \author Chang Ge
 *
 * Class that build all of the components together
 *
 */
#pragma once
#include <memory>
#include "Component.h"
#include "Motor.h"
#include <vector>
#include "WavPlayer.h"
class CMachineUse;
/**
 *
 * Class that build all of the components together
 *
 */
class CMachineConstructor
{
public:
	CMachineConstructor();
	virtual ~CMachineConstructor();

	
	/** \brief Copy constructor disabled */
	CMachineConstructor(const CMachineConstructor &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CMachineConstructor &) = delete;
	/**
	* Set the current time
	* \param time the current time
	*/
	void SetTime(double time) { mTime = time; }
	/**
	* Draw all of the components
	* \param graphics the grahic we use
	*/
	void Draw(Gdiplus::Graphics *graphics);
	/**
	* Update all of the components rotation and position 
	*/
	void UpdateComponents();
	/**
	* Add Component into the Components vector
	* \param component The component which will be added into the vector
	*/
	void AddComponent(std::shared_ptr<CComponent> component);
	/**
	* Add Motor into the Motor vector
	* \param motor The motor which will be added into the vector
	*/
	void AddMotor(std::shared_ptr<CMotor> motor) { mMotors.push_back(motor); }
	/**
	* Get the player
	* \return wavPlayer Play the sound
	*/
	CWavPlayer* GetPlayer() { return &mWavPlayer; }
	/**
	* Get the machine number
	* \return machine number
	*/
	int GetMachineNum() { return mMachineConstructorNum; }
	/**
	* Set the machine number
	* \param number number need to be setted
	*/
	void SetMachineNum(int number) { mMachineConstructorNum = number; }
	/**
	* Set the machine pos
	* \param offset number need to be setted
	*/
	void ResetPos(Gdiplus::Point offset);
private:
	///the number of machine number of this constructor
	int mMachineConstructorNum;
	///The current time
	double mTime;
	///point to machine use
	std::shared_ptr<CMachineUse> mMachineUse;
	///All of the Components
	std::vector<std::shared_ptr<CComponent>> mComponents;
	///All of the motors
	std::vector<std::shared_ptr<CMotor>> mMotors;
	///wavplayer
	CWavPlayer mWavPlayer;
	
};

