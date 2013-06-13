#ifndef __BOX__
#define __BOX__

// This file contains the declaration of the class Sphere

#include "Plane.h"
#include "GeometricObject.h"

//-------------------------------------------------------------------------------- class Sphere

class Box: public GeometricObject {

	public:

		Box(void);   									// Default constructor

		Box(Plane inSides, int s);					// Constructor

		Box(const Box& box); 						// Copy constructor

		virtual Box* 									// Virtual copy constructor
		clone(void) const;

		virtual												// Destructor
		~Box(void);

		Box& 											// assignment operator
		operator= (const Box& box);
/*
		void
		set_center(const Vector3D& c);

		void
		set_center(const double x, const double y, const double z);

		void
		set_radius(const double r);
*/
        void fillArray();

		virtual bool
		hit(const Ray& ray, double& t, ShadeRec& s) const;

	public:

		Plane 	Sides[6];
		int size;		// center coordinates as a point


		static const double kEpsilon;   // for shadows and secondary rays
};


/*
inline void
Sphere::set_center(const Vector3D& c) {
	center = c;
}

inline void
Sphere::set_center(const double x, const double y, const double z) {
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void
Sphere::set_radius(const double r) {
	radius = r;
}*/

#endif
