#include "PointLight.h"

// ---------------------------------------------------------------------- default constructor

PointLight::PointLight(void)
	: 	intensity(1.0),
		color(1.0),
		location(0, 1, 0)
{}


// ---------------------------------------------------------------------- copy constructor

PointLight::PointLight(const PointLight& pl)
	: 	intensity(pl.intensity),
		color(pl.color),
		location(pl.location)
{}



// ---------------------------------------------------------------------- assignment operator

PointLight&
PointLight::operator= (const PointLight& rhs)
{
	if (this == &rhs)
		return (*this);

	intensity	= rhs.intensity;
	color 	    = rhs.color;
	location 	= rhs.location;

	return (*this);
}


// ---------------------------------------------------------------------- destructor

PointLight::~PointLight(void) {}


// ---------------------------------------------------------------------- get light direction

Vector3D
PointLight::get_direction(ShadeRec& sr) {
    Vector3D dir = location - sr.local_hit_point;
    dir.normalize();
	return dir;
}

// ---------------------------------------------------------------------- get shadow ray

Ray
PointLight::get_shadowray(ShadeRec& sr) {
    Ray r(location, get_direction(sr));
	return r;
}



