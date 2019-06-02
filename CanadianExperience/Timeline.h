/**
 * \file Timeline.h
 *
 * \author Charles B. Owen
 *
 * \brief The animation timeline class.
 */

#pragma once
#include <memory>
#include <vector>
#include "AnimChannel.h"
#include "XmlNode.h"
#include "MachineDrawable.h"
/**
 * \brief The animation timeline class.
 */
class CTimeline
{
public:
    CTimeline();
    virtual ~CTimeline();

    /** \brief Copy constructor disabled */
    CTimeline(const CTimeline &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CTimeline &) = delete;

    /** \brief Get the number of frames in the animation
    * \returns Number of frames in the animation
    */
    int GetNumFrames() const { return mNumFrames; }

    /** \brief Set the number of frames in the animation
    * \param numFrames Number of frames in the animation
    */
    void SetNumFrames(int numFrames) { mNumFrames = numFrames; }

    /** \brief Get the frame rate
    * \returns Animation frame rate in frames per second
    */
    int GetFrameRate() const { return mFrameRate; }

    /** \brief Set the frame rate
    * \param frameRate Animation frame rate in frames per second
    */
    void SetFrameRate(int frameRate) { mFrameRate = frameRate; }

    /** \brief Get the current time
    * \returns Current animation time in seconds
    */
    double GetCurrentTime() const { return mCurrentTime; }
	/** \brief Set the time
	* \param t time
	*/
    void SetCurrentTime(double t);

	/** \brief Set the timeduration
	* \param starttime the start time
	* \param endtime the end time
	*/
	void SetTimeDuration(int starttime, int endtime);
    /*! \brief Get the current frame.
    *
    * This is the frame associated with the current time
    * \returns Current frame
    */
    int GetCurrentFrame() const { return int(mCurrentTime * mFrameRate); }

    /*! \brief Get the animation duration
    * \returns Animation duration in seconds
    */
    double GetDuration() const { return (double)mNumFrames / mFrameRate; }
    void AddChannel(CAnimChannel *channel);
    void ClearKeyframe();

    void Save(std::shared_ptr<xmlnode::CXmlNode> root);
    void Load(std::shared_ptr<xmlnode::CXmlNode> root);

    void Clear();
	/*! \brief Get the start time
   *
   * This is the frame associated with the current time
   * \returns starttime starttime
   */
	int GetStartTime() { return mStartTime; }
	/*! \brief Get the end time
   *
   * This is the frame associated with the current time
   * \returns endtime endtime
   */
	int GetEndTime() { return mEndTime; }
	/** \brief Set machine drawable
	* \param machinedrawable machine drawable
	*/
	void SetMachineDrawable(CMachineDrawable* machinedrawable) {
		mMachineDrawable = machinedrawable
			;
	}

private:
    void XmlChannel(const std::shared_ptr<xmlnode::CXmlNode> &node);

    int mNumFrames = 300;       ///< Number of frames in the animation
    int mFrameRate = 30;        ///< Animation frame rate in frames per second
    double mCurrentTime = 0;    ///< The current animation time

    /// List of all animation channels
    std::vector<CAnimChannel *> mChannels;

	///starTtime
	int mStartTime = 10000;
	///endTIme
	int mEndTime = 0;
	///machinedrawable
	CMachineDrawable* mMachineDrawable;
};

