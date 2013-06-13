//@file Material.cpp
//@date June, 2012
//@author Dr O

//ADT Material: data object is the material of an object's surface. It contains
//              its three coefficients of reflection (ambient, diffuse, specular)
//              and its three rgb color components (ambient, diffuse, specular)
//              and its specularity and reflection coefficient
// See page 8 of RayTracing notes and section


#include "Material.h"

// ---------------------------------------------------------------- default constructor
Material::Material()
    : ka(.2),
      kd(.6),
      ks(.4),
      ca(1,1,1),
      cd(1,0,1),
      cs(1,1,1),
      sp(10),
      kr(.2)
{}

// ---------------------------------------------------------------- copy constructor
Material::Material(const Material& rhsm) {
   operator=(rhsm);
}

// ---------------------------------------------------------------- assignment operator

Material&
Material::operator= (const Material& rhsm) {
	if (this == &rhsm)
		return (*this);

    ka = rhsm.ka;
    kd = rhsm.kd;
    ks = rhsm.ks;
    ca = rhsm.ca;
    cd = rhsm.cd;
    cs = rhsm.cs;
    sp = rhsm.sp;
    kr = rhsm.kr;

	return *this;
}

// ---------------------------------------------------------------- destructor
Material::~Material()
{}



