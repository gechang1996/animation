/**
 * \file Drawable.h
 *
 * \author Charles B. Owen
 *
 * \brief Abstract base class for drawable elements of our picture
 */

#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Machine.h"
#include "AnimChannelAngle.h"

class CActor;


/**
 * \brief Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class CDrawable
{
public:
    virtual ~CDrawable();

    /** \brief Default constructor disabled */
    CDrawable() = delete;
    /** \brief Copy constructor disabled */
    CDrawable(const CDrawable &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CDrawable &) = delete;
	/** \brief SetActor override function

	/** \brief Set the drawable position
     * \param actor The new drawable position*/
    virtual void SetActor(CActor *actor);

    /** \brief Draw the drawable 
     * \param graphics Graphics object to draw on */
    virtual void Draw(Gdiplus::Graphics *graphics) = 0;

    void Place(Gdiplus::Point offset, double rotate);
    void AddChild(std::shared_ptr<CDrawable> child);

    /** \brief Test to see if we have been clicked on by the mouse
     * \param pos Position to test
     * \returns true if clicked on */
    virtual bool HitTest(Gdiplus::Point pos) = 0;

    /** \brief Is this a movable drawable? 
     * \returns true if movable */
    virtual bool IsMovable() { return false; }
    void Move(Gdiplus::Point delta);

	/** \brief GetActor
	 * \returns actor this is the drawable's actor */
	CActor *GetActor() { return mActor; }

    /** \brief Set the drawable position
     * \param pos The new drawable position*/
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    /** \brief Get the drawable position
     * \returns The drawable position*/
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** \brief Set the rotation angle in radians
    * \param r The new rotation angle in radians*/
    void SetRotation(double r) { mRotation = r; }
    
    /** \brief Get the rotation angle in radians
    * \returns The rotation angle in radians*/    
    double GetRotation() const { return mRotation; }

    /** \brief Get the drawable name
    * \returns The drawable name */
    std::wstring GetName() const { return mName; }
    
    /** \brief Set the drawable parent 
     * \param parent New parent pointer */
    void SetParent(CDrawable *parent) { mParent = parent; }

    /** \brief Get the drawable parent
     * \returns Parent pointer */
    CDrawable *GetParent() { return mParent; }
	/** \brief Change the number of the machine*/
	virtual void ChangeMachineNum() {}
	/** \brief Set the offset
	 * \param point the offset of machine drawable */
	virtual void SetOffset(Gdiplus::Point point) {}

	
    /** \brief Iterator that iterates over the children of this drawable */
    class ChildIter
    {
    public:
        /** \brief Constructor
        * \param drawable Picture we are iterating
        * \param pos Starting position */
        ChildIter(CDrawable *drawable, int pos) : mDrawable(drawable), mPos(pos) {}

        /** \brief Test for end of the iterator
        * \param other Other object to test against
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ChildIter &other) const
        {
            return mPos != other.mPos;
        }

        /** \brief Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CDrawable> operator *() const { return mDrawable->mChildren[mPos]; }

        /** \brief Increment the iterator
        * \returns Reference to this iterator */
        const ChildIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CDrawable *mDrawable;   ///< Drawable we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** \brief Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    ChildIter begin() { return ChildIter(this, 0); }

    /** \brief Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    ChildIter end() { return ChildIter(this, mChildren.size()); }

	
    virtual void SetTimeline(CTimeline *timeline);
    virtual void SetKeyframe();
    virtual void GetKeyframe();
	

    /** \brief The angle animation channel 
     * \returns Pointer to animation channel */
    CAnimChannelAngle *GetAngleChannel() { return &mChannel; }

protected:
    CDrawable(const std::wstring &name);
    Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);


    /// The actual postion in the drawing
    Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);

    /// The actual rotation in the drawing
    double mPlacedR = 0;



private:
    /// The drawable name
    std::wstring mName;

    /// The position of this drawable relative to its parent
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    /// The rotation of this drawable relative to its parent
    double mRotation = 0;

    /// The actor using this drawable
    CActor *mActor = nullptr;

    /// The parent drawable
    CDrawable *mParent = nullptr;

    /// The child drawables
    std::vector<std::shared_ptr<CDrawable>> mChildren;

    /// The animation channel for animating the angle of this drawable
    CAnimChannelAngle mChannel;
};

