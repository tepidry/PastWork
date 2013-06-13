//file Box.h
//author Ryan Draper
//date Oct 2, 2012


//ADT Box is-a Geometric Object:
//   data object is a plane that synthetically exists in the world
//   operations: create, copy, destroy, copies, sets point and/or normal of a Box, and
//               hit (does a ray hit the object and where)


#ifndef __BOX__
#define __BOX__

// This file contains the declaration of the class Sphere

#include "Plane.h"
#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class Sphere

class Box: public GeometricObject
{

public:
    // ---------------------------------------------------------------- default constructor
    //@Creates a default Box
    //@pre world has been created
    //@post Box exists
    //@usage Box* box_ptr = new Box();
    Box(void);

    // ---------------------------------------------------------------- constructor
    //@Creates a new box with a known point and normal
    //@pre world exists and has been created
    //@post Box exists
    //@param inSides
    //@      size_rhs
    //@usage Box* box_ptr = new Box(Plane(Vector3D(), Vector3D()), size)
    Box(Plane inSides, double s);

    // ---------------------------------------------------------------- assignment operator
    //@makes two boxes equal
    //@pre rhs is a box and world has been created
    //@post the box on the left side of the = is equivalent of rhs
    //@returns the pointer object box
    //@param rhs
    //@usage box = box_rhs;
    Box(const Box& box);

    //----------------------------------------------------------------- clone
    //@a new pointer to a Box is created
    //@pre world exists
    //@post a new box has been created
    //@returns boxes and Vectors normal and point
    //@usage Box* box_ptr = new Box(Vector3D(), Vector3D(), size)
    virtual Box*
    clone(void) const;

    // ---------------------------------------------------------------- destructor
    //@deconstructs box
    //@pre Box exists
    //@post Box doesn't
    //@usage called automatically
    virtual												// Destructor
    ~Box(void);

    // ---------------------------------------------------------------- assignment operator
    //@makes two boxes equal
    //@pre rhs is a box and world has been created
    //@post the box on the left side of the = is equivalent of rhs
    //@returns the pointer object box
    //@param rhs
    //@usage box = box_rhs;
    Box& 											// assignment operator
    operator= (const Box& box);

    //---------------------------------------------------------------- fill array
    //@takes the original given point and creates a normal and point for each Plane in sides[]
    //@pre world and box exists
    //@post sides[] has been filled
    //@usage fillArray();
    void fillArray();

    //---------------------------------------------------------------- hitcalculating a cubes hit point
    //@returns a boolean value if a ray hits the box at any point
    //@pre a world and box exists
    //@post true or false is returned if the box is in the view box
    //@param ray
    //@      tmin
    //@      sr
    //@returns a boolean value
    //@usage box.hit(ray, t, sr)
    virtual bool
    hit(const Ray& ray, double& t, ShadeRec& s) const;

public:

    Plane 	Sides[6];
    double size;		// center coordinates as a point


    static const double kEpsilon;   // for shadows and secondary rays
};



#endif
