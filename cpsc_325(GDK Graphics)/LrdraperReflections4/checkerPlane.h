#ifndef __CHECKERPLANE__
#define __CHECKERPLANE__


#include "GeometricObject.h"
#include "Plane.h"


class CheckerPlane: public GeometricObject
{

public:

    //@Creates a default Plane
    //@pre world has been created
    //@post Plane exists
    //@usage Plane* plane_ptr = new Plane();
    CheckerPlane(void);

    //@Creates a new plane with a know point and normal
    //@pre world exists and has been created
    //@post Plane exists
    //@param plane_point
    //@      plane_normal
    //@usage Plane* plane_ptr = new Plane(Vector3D(), Vector3D())http://www.google.com/
    CheckerPlane(const Vector3D& checkerPlane_point, const Vector3D checkerPlane_normal);

    //@Copies an instance on a plane
    //@pre world exist and a plane has been already been created
    //@post another plane with the same normal and point exists
    //@param plane
    //@usage Plane(plane());
    CheckerPlane(const CheckerPlane& checkerPlane);

    //@a new pointer to a Plane is created
    //@pre world exists
    //@post a new plane has been created
    //@returns planes and Vectors normal and point
    //@ Plane* plane_ptr = new Plane(Vector3D(), Vector3D())
    virtual CheckerPlane*
    clone(void) const;

    //@deconstructs plane
    //@pre Plane exists
    //@post Plane doesn't
    //@usage called automatically
    virtual
    ~CheckerPlane(void);

    //@makes two planes equal
    //@pre rhs is a plane and world has been created
    //@post the plane on the left side of the = is equivalent of rhs
    //@param plane
    //@returns the pointer object plane
    //@usage plane = plane_rhs
    CheckerPlane&
    operator= (const CheckerPlane& checkerPlane);


    //@returns a boolean value if a ray hits the plane at any point
    //@pre a world and plane exists
    //@post true or false is returned if the plane is in the view plane
    //@param ray
    //@      tmin
    //@      sr
    //@returns a boolean value
    //@usage plane.hit(ray, t, sr)
    virtual bool
    hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

public:

    Vector3D 	point;   			// Plane's given as a point
    Vector3D    normal;				// the normal of a plane

    static const double kEpsilon;   // for shadows and secondary rays
};



#endif
