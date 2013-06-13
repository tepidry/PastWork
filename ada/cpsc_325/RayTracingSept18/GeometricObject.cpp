// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// this file contains the definition of the class GeometricObject

#include "Utilities/Constants.h"
#include "Material.h"
#include "GeometricObject.h"


// ---------------------------------------------------------------------- default constructor

GeometricObject::GeometricObject(void)
	: 	material_ptr(NULL)//,
	//	shadows(true)
{}


// ---------------------------------------------------------------------- copy constructor

GeometricObject::GeometricObject (const GeometricObject& object)
{

    material_ptr = NULL;
}


// ---------------------------------------------------------------------- assignment operator

GeometricObject&
GeometricObject::operator= (const GeometricObject& rhs) {
	if (this == &rhs)
		return (*this);

	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}

	if (rhs.material_ptr)
		material_ptr = rhs.material_ptr;

	//shadows = rhs.shadows;

	return (*this);
}


// ---------------------------------------------------------------------- destructor

GeometricObject::~GeometricObject (void) {
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}


// ---------------------------------------------------------------------- add_object
// required for Compound objects
/*
void
GeometricObject::add_object(GeometricObject* object_ptr) {}


// ----------------------------------------------------------------------- get_normal

Vector3D
GeometricObject::get_normal(void) const{
	return (Vector3D());
}

*/
// ----------------------------------------------------------------------- set_material

void
GeometricObject::set_material(Material* mPtr) {
	material_ptr = mPtr;
}


// ----------------------------------------------------------------------- get_material

Material*
GeometricObject::get_material(void) const {
	return (material_ptr);
}



// ----------------------------------------------------------------------- compute_normal

//Vector3D
//GeometricObject::get_normal(const Vector3D& p) {
//	return (Vector3D());
//}



