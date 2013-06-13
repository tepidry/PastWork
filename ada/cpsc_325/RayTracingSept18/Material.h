//@file Material.h
//@date June, 2012
//@author Dr O

//ADT Material: data object is the material of an object's surface. It contains
//              its three coefficients of reflection (ambient, diffuse, specular)
//              and its three rgb color components (ambient, diffuse, specular)
//              and its specularity and reflection coefficient
// See page 8 of RayTracing notes and section

#ifndef __MATERIAL__
#define __MATERIAL__

#include "Utilities/RGBColor.h"

class Material {

    public:

		float ka;     // coefficient of ambient reflection of surface
		float kd;     // coefficient of diffuse reflection of surface
		float ks;     // coefficient of specular reflection of surface
		RGBColor ca;  // ambient rgb color components of surface
		RGBColor cd;  // diffuse rgb color compoents of surface
		RGBColor cs;  // specular rgb color components of surface
		float sp;     // specularity
		float kr;     // reflection coef - for reflections only


	public:

		Material();

		Material(const Material& rhsm);

		~Material();

		Material&
		operator= (const Material& rhsm);

		void set_AmbColor(const RGBColor& c);

		void set_DifColor(const RGBColor& c);

		void set_SpecColor(const RGBColor& c);

		void setAmbColor(float r, float g, float b);

		void setDifColor(float r, float g, float b);

		void setSpecColor(float r, float g, float b);

		void setAllColor(float r, float g, float b);

        RGBColor getAmbColor() const;

        RGBColor getDifColor() const;

        RGBColor getSpecColor() const;

		void setKa(float k);

		void setKd(float k);

		void setKs(float k);

		void setSp(float s);

		void setKr(float k);

		void setAllK(float a, float d, float s);

};

// -------------------------------------------------------------------------------

inline void
Material::setAmbColor(float r, float g, float b) {
	ca.r = r;  ca.g = g;  ca.b = b;
}

inline void
Material::setDifColor(float r, float g, float b) {
	cd.r = r;  cd.g = g;  cd.b = b;
}

inline void
Material::setSpecColor(float r, float g, float b) {
	cs.r = r;  cs.g = g;  cs.b = b;
}

inline void
Material::setAllColor(float r, float g, float b) {
    ca.r = r;  ca.g = g;  ca.b = b;
    cd.r = r;  cd.g = g;  cd.b = b;
	cs.r = r;  cs.g = g;  cs.b = b;
}


inline void
Material::set_AmbColor(const RGBColor& c) {
    ca = c;
}

inline void
Material::set_DifColor(const RGBColor& c) {
    cd = c;
}

inline void
Material::set_SpecColor(const RGBColor& c) {
    cs = c;
}

inline void
Material::setKa(float k) {
	ka = k;
}

inline void
Material::setKd(float k) {
	kd = k;
}

inline void
Material::setKs(float k) {
	ks = k;
}

inline void
Material::setKr(float k) {
	kr = k;
}

inline void
Material::setAllK(float a, float d, float s) {
	ka = a; kd = d; ks = s;
}

inline void
Material::setSp(float specularity) {
	sp  = specularity;
}


inline RGBColor
Material::getAmbColor() const {
	return ca;
}

inline RGBColor
Material::getDifColor() const {
	return cd;
}

inline RGBColor
Material::getSpecColor() const {
	return cs;
}



#endif
