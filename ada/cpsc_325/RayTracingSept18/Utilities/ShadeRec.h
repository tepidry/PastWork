#ifndef __SHADE_REC__
#define __SHADE_REC__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Ray.h"
#include "../Material.h"
#include "RGBColor.h"

class ShadeRec {
	public:

		bool				hit_an_object;		// did the ray hit an object?
		Material* 			material_ptr;		// pointer to the nearest object's material
		Vector3D			local_hit_point;	// world coordinates of hit point on untransformed object (used for texture transformations)
		Vector3D			normal;				// normal at hit point
		Ray					ray;				// required for specular highlights and area lights
	//	RGBColor			color;				// used only before shading is calculated
		double				t;					// ray parameter

        ShadeRec();
		ShadeRec(const ShadeRec& sr);			// copy constructor
		~ShadeRec(void);						// destructor
};

#endif
