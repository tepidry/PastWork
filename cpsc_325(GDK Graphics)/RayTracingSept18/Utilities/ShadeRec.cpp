// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

// This file contains the definition of the class ShadeRec

#include "Constants.h"
#include "ShadeRec.h"

// ------------------------------------------------------------------ constructor

ShadeRec::ShadeRec()  //  (World& wr)
	: 	hit_an_object(false),
		material_ptr(NULL),
		local_hit_point(),
		normal(),
		ray(),
		t(0.0)
{}

// ------------------------------------------------------------------ copy constructor

ShadeRec::ShadeRec(const ShadeRec& sr)
	: 	hit_an_object(sr.hit_an_object),
		material_ptr(sr.material_ptr),
		local_hit_point(sr.local_hit_point),
		normal(sr.normal),
		ray(sr.ray),
		t(sr.t)
{}


// ------------------------------------------------------------------ destructor

ShadeRec::~ShadeRec(void) {
	if (material_ptr) {
		delete material_ptr;
		material_ptr = NULL;
	}
}




