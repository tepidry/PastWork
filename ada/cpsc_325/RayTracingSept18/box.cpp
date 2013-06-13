// This file contains the definition of the class sphere

#include "Box.h"
#include "math.h"
#include <iostream>

const double Box::kEpsilon = 0.001;

// ---------------------------------------------------------------- default constructor

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

Box::Box(Plane inSides, int s)
	: 	GeometricObject()
{
    Vector3D point;
    Vector3D normal;

    Sides[0].point.x = inSides.point.x;
    Sides[0].point.y = inSides.point.y;
    Sides[0].point.z = inSides.point.z;
    Sides[0].normal.x = inSides.point.x;
    Sides[0].normal.y = inSides.point.y;
    Sides[0].normal.z = inSides.point.z;

    size = s;
}


// ---------------------------------------------------------------- clone

Box*
Box::clone(void) const {
	return (new Box(*this));
}


// ---------------------------------------------------------------- copy constructor

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

Box::~Box(void) {}

//---------------------------------------------------------------- fill array

/*void
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

}*/

//---------------------------------------------------------------- hit


bool
Box::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
	double 		t;
	Vector3D    local = ray.o + t * ray.d;
    bool xGreater, yGreater, zGreater;
    bool xLess, yLess, zLess;
	double      numerator;
	double      denominator;
	double      cosDirectionAndNormal;

	for (int i = 0; i < 1; i++)
	{
	    xGreater = local.x > (Sides[i].point.x + size) || local.x < (Sides[i].point.x - size);
        yGreater = local.y > (Sides[i].point.y + size) || local.y < (Sides[i].point.y - size);
        zGreater = local.z > (Sides[i].point.z + size) || local.z < (Sides[i].point.z - size);
        xLess = local.x < (Sides[i].point.x - size);
        yLess = local.y < (Sides[i].point.y - size);
        zLess = local.z < (Sides[i].point.z - size);

        numerator = Sides[i].normal * (Sides[i].point - ray.o);
        denominator = Sides[i].normal * ray.d;
        cosDirectionAndNormal = ray.d * Sides[i].normal;


        t = numerator / denominator;
        if (denominator == 0)
        {
            return false;
        }
        else if (t > kEpsilon) {
            tmin = t;
            if (cosDirectionAndNormal < 0) {
                sr.normal = Sides[i].normal;
            } else if (cosDirectionAndNormal > 0) {
                sr.normal = -1 * Sides[i].normal;
            }

            sr.local_hit_point = ray.o + tmin * ray.d;
            //return true;
            if (xGreater && yGreater || xGreater && zGreater || yGreater && zGreater)
            {
                return false;
            } else {
                return true;
            }

        }
	}
	return false;
}







