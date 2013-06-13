//file Box.cpp
//author Ryan Draper
//date Oct 2, 2012

//ADT Box is-a Geometric Object:
//   data object is a plane that synthetically exists in the world
//   operations: create, copy, destroy, copies, sets point and/or normal of a Box, and
//               hit (does a ray hit the object and where)


#include "Box.h"
#include "math.h"
#include <iostream>
#include "Utilities/Vector3D.h"

const double Box::kEpsilon = 0.001;

// ---------------------------------------------------------------- default constructor
//@Creates a default Box
//@pre world has been created
//@post Box exists
//@usage Box* box_ptr = new Box();
Box::Box(void)
    : 	GeometricObject()
{
    for (int i = 0; i < 6; i++)
    {
        Sides[i].set_point(0,0,0);
        Sides[i].set_normal(0, 0, 0);
    }
}


// ---------------------------------------------------------------- constructor
//@Creates a new box with a known point and normal
//@pre world exists and has been created
//@post Box exists
//@param inSides
//@      size_rhs
//@usage Box* box_ptr = new Box(Plane(Vector3D(), Vector3D()), size)
Box::Box(Plane inSides, double size_rhs)
    : 	GeometricObject()
{
    Sides[0].set_point(inSides.point);
    Sides[0].set_normal(inSides.normal);

    size = size_rhs;
    fillArray();
}


//----------------------------------------------------------------- clone
//@a new pointer to a Box is created
//@pre world exists
//@post a new box has been created
//@returns boxes and Vectors normal and point
//@usage Box* box_ptr = new Box(Vector3D(), Vector3D(), size)
Box*
Box::clone(void) const
{
    return (new Box(*this));
}


// ---------------------------------------------------------------- copy constructor
//@Copies an instance on a box
//@pre world exist and a box has been already been created
//@post another box with the same normal and point exists
//@param box
//@usage Box(box());
Box::Box (const Box& box)
    : 	GeometricObject(box)
{
    for (int i = 0; i < 6; i++)
    {
        Sides[i] = box.Sides[i];
    }
    size = box.size;
}



// ---------------------------------------------------------------- assignment operator
//@makes two boxes equal
//@pre rhs is a box and world has been created
//@post the box on the left side of the = is equivalent of rhs
//@returns the pointer object box
//@param rhs
//@usage box = box_rhs;
Box&
Box::operator= (const Box& rhs)
{
    if (this == &rhs)
        return (*this);

    GeometricObject::operator= (rhs);
    for (int i = 0; i < 6; i++)
    {
        Sides[i] = rhs.Sides[i];
    }
    size = rhs.size;

    return (*this);
}


// ---------------------------------------------------------------- destructor
//@deconstructs box
//@pre Box exists
//@post Box doesn't
//@usage called automatically
Box::~Box(void) {}

//---------------------------------------------------------------- fill array
//@takes the original given point and creates a normal and point for each Plane in sides[]
//@pre world and box exists
//@post sides[] has been filled
//@usage fillArray();
void
Box::fillArray()
{
    Vector3D boxSize(1, 0, 0);
    Vector3D boxSize2(0, 1, 0);

    Sides[2].normal = Sides[0].normal;
    Sides[1].normal = boxSize;
    Sides[3].normal = boxSize;
    Sides[4].normal = boxSize2;
    Sides[5].normal = boxSize2;

    Sides[2].point = Sides[0].point;
    Sides[2].point.z = Sides[0].point.z - (size * 2);
    Sides[1].point.x = Sides[0].point.x - size;
    Sides[1].point.y = Sides[0].point.y;
    Sides[1].point.z = Sides[0].point.z - size;
    Sides[3].point.x = Sides[0].point.x + size;
    Sides[3].point.y = Sides[0].point.y;
    Sides[3].point.z = Sides[0].point.z - size;
    Sides[4].point.x = Sides[0].point.x;
    Sides[4].point.y = Sides[0].point.y + size;
    Sides[4].point.z = Sides[0].point.z - size;
    Sides[5].point.x = Sides[0].point.x;
    Sides[5].point.y = Sides[0].point.y - size;
    Sides[5].point.z = Sides[0].point.z - size;

    //boxSize()

}

//---------------------------------------------------------------- hitcalculating a cubes hit point
//@returns a boolean value if a ray hits the box at any point
//@pre a world and box exists
//@post true or false is returned if the box is in the view box
//@param ray
//@      tmin
//@      sr
//@returns a boolean value
//@usage box.hit(ray, t, sr)
bool
Box::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{

    double 		t;
    Vector3D    local;
    bool xGreater, yGreater, zGreater;
    double      numerator;
    double      denominator;
    double      cosDirectionAndNormal;

    for (int i = 0; i < 6; i++)
    {


        numerator = Sides[i].normal * (Sides[i].point - ray.o);
        denominator = Sides[i].normal * ray.d;
        cosDirectionAndNormal = ray.d * Sides[i].normal;


        t = numerator / denominator;
        local = ray.o + t * ray.d;
        xGreater = local.x > (Sides[i].point.x + size) || local.x < (Sides[i].point.x - size);
        yGreater = local.y > (Sides[i].point.y + size) || local.y < (Sides[i].point.y - size);
        zGreater = local.z > (Sides[i].point.z + size) || local.z < (Sides[i].point.z - size);

        if (denominator == 0)
        {
            return false;
        }
        else if (t > kEpsilon)
        {
            tmin = t;
            if (cosDirectionAndNormal < 0)
            {
                sr.normal = Sides[i].normal;
            }
            else if (cosDirectionAndNormal > 0)
            {
                sr.normal = -1 * Sides[i].normal;
            }
            sr.normal.normalize();
            sr.local_hit_point = ray.o + tmin * ray.d;
            if (xGreater || yGreater || zGreater)
            {
            }
            else
            {
                i = 6;
                return true;
            }

        }
    }
    return false;
}







