//author  Ryan Draper
//date  Sept 20 2012

//ADT Plane is-a Geometric Object:
//   data object is a plane that synthetically exists in the world
//   operations: create, copy, destroy, copies, sets point and/or normal of a plane, and
//               hit (does a ray hit the object and where)
#include "checkerPlane.h"
#include "math.h"

const double CheckerPlane::kEpsilon = 0.001;

//@Creates a default Plane
//@pre world has been created
//@post Plane exists
//@usage Plane* plane_ptr = new Plane();
CheckerPlane::CheckerPlane(void)
    : 	GeometricObject(),
    point(0.0, 0.0, 0.0),
    normal(0.0, 0.0, 0.0)
{}

//@Creates a new plane with a know point and normal
//@pre world exists and has been created
//@post Plane exists
//@param plane_point
//@      plane_normal
//@usage Plane* plane_ptr = new Plane(Vector3D(), Vector3D())
CheckerPlane::CheckerPlane(const Vector3D& plane_point, const Vector3D plane_normal)
    : 	GeometricObject(),
    point(plane_point),
    normal(plane_normal)
{}

//@Copies an instance on a plane
//@pre world exist and a plane has been already been created
//@post another plane with the same normal and point exists
//@param plane
//@usage Plane(plane());
CheckerPlane::CheckerPlane(const CheckerPlane& plane)
    : 	GeometricObject(plane),
    point(plane.point),
    normal(plane.normal)
{}

//@a new pointer to a Plane is created
//@pre world exists
//@post a new plane has been created
//@returns planes and Vectors normal and point
//@usage Plane* plane_ptr = new Plane(Vector3D(), Vector3D())
CheckerPlane*
CheckerPlane::clone(void) const
{
    return (new CheckerPlane(*this));
}

//@makes two planes equal
//@pre rhs is a plane and world has been created
//@post the plane on the left side of the = is equivalent of rhs
//@returns the pointer object plane
//@param rhs
//@usage plane = plane_rhs
CheckerPlane&
CheckerPlane::operator= (const CheckerPlane& rhs)
{
    if (this == &rhs)
        return (*this);

    GeometricObject::operator= (rhs);

    point 	= rhs.point;
    normal	= rhs.normal;

    return (*this);
}

//@deconstructs plane
//@pre Plane exists
//@post Plane doesn't
//@usage called automatically
CheckerPlane::~CheckerPlane(void) {}

//@returns a boolean value if a ray hits the plane at any point
//@pre a world and plane exists
//@post true or false is returned if the plane is in the view plane
//@param ray
//@      tmin
//@      sr
//@returns a boolean value
//@usage plane.hit(ray, t, sr)
bool
CheckerPlane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
    int size = 5;
    bool yGreater, xGreater, zGreater;
    Vector3D    local;
    Vector3D    posNormal = (abs(normal.x), abs(normal.y), abs(normal.z));
    double 		t;
    double      numerator = normal * (point - ray.o);
    double      denominator = normal * ray.d;
    double      cosDirectionAndNormal = denominator;
    //int      xx = point.x;

    t = numerator / denominator;
    local = ray.o + t * ray.d;
    int      xx = abs(local.x);
    int     yy = abs(local.y);
    int     zz = abs(local.z);
    xGreater = local.x == (xx % 10);
    yGreater = local.y < (point.y + size) || local.y > (point.y - size);
    zGreater = local.z < (point.z + size) || local.z > (point.z - size);

    if (denominator == 0.0)
    {
        return false;
    }
    else if (t > kEpsilon)
    {
        tmin = t;
        if (cosDirectionAndNormal < 0)
        {
            sr.normal = normal;
        }
        else
        {
            sr.normal = -1 * normal;
        }
        sr.normal.normalize();
        sr.local_hit_point = ray.o + tmin * ray.d;
        if (xx % 5 == 1 || zz % 5)
        {
            return true;
        }
    }
    return (false);
}














