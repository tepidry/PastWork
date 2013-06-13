//file Plane.h
//author Ryan Draper
//date Sept 20, 2012


//ADT Plane is-a Geometric Object:
//   data object is a plane that synthetically exists in the world
//   operations: create, copy, destroy, copies, sets point and/or normal of a plane, and
//               hit (does a ray hit the object and where)

#ifndef PLANE_H
#define PLANE_H

#include "GeometricObject.h"
//#include "Vector3D.h"


class Plane: public GeometricObject
{

public:

    //@Creates a default Plane
    //@pre world has been created
    //@post Plane exists
    //@usage Plane* plane_ptr = new Plane();
    Plane(void);

    //@Creates a new plane with a know point and normal
    //@pre world exists and has been created
    //@post Plane exists
    //@param plane_point
    //@      plane_normal
    //@usage Plane* plane_ptr = new Plane(Vector3D(), Vector3D())http://www.google.com/
    Plane(const Vector3D& plane_point, const Vector3D plane_normal);

    //@Copies an instance on a plane
    //@pre world exist and a plane has been already been created
    //@post another plane with the same normal and point exists
    //@param plane
    //@usage Plane(plane());
    Plane(const Plane& plane);

    //@a new pointer to a Plane is created
    //@pre world exists
    //@post a new plane has been created
    //@returns planes and Vectors normal and point
    //@ Plane* plane_ptr = new Plane(Vector3D(), Vector3D())
    virtual Plane*
    clone(void) const;

    //@deconstructs plane
    //@pre Plane exists
    //@post Plane doesn't
    //@usage called automatically
    virtual
    ~Plane(void);

    //@makes two planes equal
    //@pre rhs is a plane and world has been created
    //@post the plane on the left side of the = is equivalent of rhs
    //@param plane
    //@returns the pointer object plane
    //@usage plane = plane_rhs
    Plane&
    operator= (const Plane& plane);

    //@sets the point in a plane to the rhs_point
    //@pre the world and a plane exists
    //@post the planes point coordinates are equal to rhs_point
    //@param rhs_point
    //@usage plane.set_point(point);
    void
    set_point(const Vector3D& rhs_point);

    //@sets the point in a plane to the x,y,z
    //@pre the world and a plane existshttp://www.google.com/
    //@post the planes point coordinates are equal to x,y,z
    //@param x
    //@      yhttp://www.google.com/
    //@      z
    //@usage plane.set_point(1,2,3);
    void
    set_point(const double x, const double y, const double z);

    //@sets the normal in a plane to the rhs_point
    //@pre the world and a plane exists
    //@post the planes normal coordinates are equal to rhs_point
    //@param rhs_normalhttp://www.google.com/
    //@usage plane.set_normal(point);
    void
    set_normal(const Vector3D& rhs_normal);

    //@sets the normal in a plane to the x,y,z
    //@pre the world and a plane exists
    //@post the planes normal coordinates are equal to x,y,z
    //@param x
    //@      y
    //@      z
    //@usage plane.set_normal(1,1,0);
    void
    set_normal(const double x, const double y, const double z);

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


//@sets the point in a plane to the rhs_point
//@pre the world and a plane exists
//@post the planes point coordinates are equal to rhs_point
//@param rhs_point
//@usage plane.set_point(point);
inline void
Plane::set_point(const Vector3D& rhs_point)
{
    point = rhs_point;
}

//@sets the point in a plane to the x,y,z
//@pre the world and a plane exists
//@post the planes point coordinates are equal to x,y,z
//@param x
//@      y
//@      z
//@usage plane.set_point(1,2,3);
inline void
Plane::set_point(const double x, const double y, const double z)
{
    point.x = x;
    point.y = y;
    point.z = z;
}

//@sets the normal in a plane to the rhs_point
//@pre the world and a plane exists
//@post the planes normal coordinates are equal to rhs_point
//@param rhs_normal
//@usage plane.set_normal(point);
inline void
Plane::set_normal(const Vector3D& rhs_normal)
{
    normal = rhs_normal;
}

//@sets the normal in a plane to the x,y,z
//@pre the world and a plane exists
//@post the planes normal coordinates are equal to x,y,z
//@param x
//@      y
//@      z
//@usage plane.set_normal(1,1,0);
inline void
Plane::set_normal(const double x, const double y, const double z)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
}

#endif
