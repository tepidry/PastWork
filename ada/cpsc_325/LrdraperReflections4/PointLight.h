#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Utilities/Vector3D.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Ray.h"

class PointLight
{
public:

    PointLight(void);

    PointLight(const PointLight& pl);

    PointLight&
    operator= (const PointLight& rhs);

    ~PointLight(void);

    void
    set_intensity(const float b);

    void
    set_color(const float c);

    void
    set_color(const RGBColor& c);

    void
    set_color(const float r, const float g, const float b);

    void
    set_location(Vector3D d);

    void
    set_location(float dx, float dy, float dz);

    Vector3D
    get_location();

    float
    get_intensity();

    RGBColor
    get_color();

    Vector3D
    get_direction(ShadeRec& sr);

    Ray
    get_shadowray(ShadeRec& sr);

public:

    float		intensity;			// intensity scaling factor
    RGBColor	color;              // color of light
    Vector3D	location   ;		// location of light
};


// inlined access functions


// ------------------------------------------------------------------------------- set_intensity

inline void
PointLight::set_intensity(const float b)
{
    intensity = b;
}

// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const float c)
{
    color.r = c;
    color.g = c;
    color.b = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const RGBColor& c)
{
    color = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
PointLight::set_color(const float r, const float g, const float b)
{
    color.r = r;
    color.g = g;
    color.b = b;
}


// ---------------------------------------------------------------------- set_location

inline void
PointLight::set_location(Vector3D p)
{
    location = p;
}


// ---------------------------------------------------------------------- set_location

inline void
PointLight::set_location(float px, float py, float pz)
{
    location.x = px;
    location.y = py;
    location.z = pz;
}

// ---------------------------------------------------------------------- get_location

inline Vector3D
PointLight::get_location()
{
    return (location);
}

// ---------------------------------------------------------------------- get_intensity

inline float
PointLight::get_intensity()
{
    return (intensity);
}

// ---------------------------------------------------------------------- get_color
inline RGBColor
PointLight::get_color()
{
    return (color);
}


#endif

