#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include <math.h>  // a lot of hit functions use use maths functions

#include "Utilities/Constants.h"
#include "Utilities/RGBColor.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Ray.h"
#include "Utilities/ShadeRec.h"

class Material;


//----------------------------------------------------------------------------------------------------- class GeometricObject

class GeometricObject {
	public:

		GeometricObject(void);

		GeometricObject(const GeometricObject& object);

		virtual GeometricObject*
		clone(void) const = 0;

		virtual
		~GeometricObject(void);

		virtual bool
		hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

		virtual void 							// This needs to be virtual so that it can be overridden in Compound
		set_material(Material* mPtr); 			// It therefore shouldn't be inlined

		Material*
		get_material(void) const;


	public:

      mutable Material*   material_ptr;   	// mutable allows the const functions Compound::hit, Instance::hit, and RegularGrid::hit to assign to material_ptr


		GeometricObject&
		operator= (const GeometricObject& rhs);
};


#endif
