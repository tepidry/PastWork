//@file Camera.cpp
//@date June 2012
//@author Dr O

//ADT Camera: data object: a camera placed in the world
//            It's location is at the origin of the world's coordinate system
//    operations: creates, destroy,
//       calculate the u,v,n camera orientation vectors (page 5 of ray tracing notes),
//       computation of the ray from the camera to an (i, j) pixel

#include "Camera.h"

//@initializes camera's coordinate axes u, v, n; location;
//   its distance from the viewplane, the width and height of the viewplane,
//   the image array and its horizontal and vertical resolution
//@post camera object exists with orientation the same as the world's coordinate system,
//      resolution 640 by 480, image a three dimensional array for the given resolution
Camera::Camera()
	:  	loc(0,0,0),
        u(1,0,0),
        v(0,1,0),
        n(0,0,1),
        dist(10),
        width(4),
        height(3),
        hres(640),
		vres(480),
		image(NULL)
{
   image = new GLfloat[ hres * vres * 3];
}

//@copies a camera with a given resolution
//@pre horizontal resolution xr and vertical resolution yr are assigned
//@post a camera exists with the resolution given by xr and yr
//@usage Camera cam(640, 480);
Camera::Camera(int xr, int yr)
	:  	loc(0,0,0),
        u(1,0,0),
        v(0,1,0),
        n(0,0,1),
        dist(10),
        width(4),
        height(3),
        hres(xr),
		vres(yr),
		image(NULL)
{
   image = new GLfloat[ hres * vres * 3];
}

//@destroys the camera
//@pre camera object exists
//@post camera object does not exist
Camera::~Camera()
{
    if (image) {
       delete[] image;
       image = NULL;
    }
}

//@ creates a copy of a camera
//@pre rhscam exists
//@post object is a copy of rhscam
//@usage Camera myCamera(yourCamera);
Camera::Camera(const Camera& rhscam)
	:  	loc(rhscam.loc),
        u(rhscam.u),
        v(rhscam.v),
        n(rhscam.n),
        dist(rhscam.dist),
        width(rhscam.width),
        height(rhscam.height),
        hres(rhscam.hres),
		vres(rhscam.vres),
		image(NULL)
{
    image = new GLfloat[ hres * vres * 3];
}

//@ copies a camera
//@pre rhscam exists
//@post object is a copy of rhscam
//@usage Camera myCamera(yourCamera);
Camera& Camera::operator=(const Camera& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    loc				= rhs.loc;
	u				= rhs.u;
	v				= rhs.v;
	n				= rhs.n;
	dist			= rhs.dist;
	width			= rhs.width;
	height			= rhs.height;
	hres			= rhs.hres;
	vres			= rhs.vres;
	if (image) {
	   delete [] image;
	   image = NULL;
    }
    image = new GLfloat[ hres * vres * 3];
    return *this;
}

//@ calculates the u, v, n coordinate unit vectors for the camera's orientation
//@pre VPN (the normal to the viewplane) and VUP (the up direction of the camera) are assigned
//@post n is the normal to the viewplane (same direction as VPN)
//@     u is the unit vector in the same direction as VUP
//@     u is the unit vector in the right direction
//@     (u, v, n) form an orthogonal coordinate system with the camera's orientation
//@usage camera_ptr -> calcUVN(VPN, VUP);
void
Camera::calculateUVN(const Vector3D &VPN, const Vector3D &VUP) {
    // see page 5 of raytracing notes
     n = VPN;
     n.normalize();

     u = VUP ^ VPN;  // cross product
     u.normalize();

     v = n ^ u;
}

//@determines the ray from the camera to a pixel on the viewplane
//@pre pixel in the ith COLUMN and jth ROW are assigned
//@post returns a ray starting at the camera's location with direction toward pixel (i, j)
//@usage ray = camera_ptr -> pixRay(row, col);
Ray
Camera::pixelRay(int icol, int jrow) const {
    //see page 5 of raytracing notes

   float alpha = -width / 2 + width * icol / (hres - 1.);
   float beta = -height / 2 + height * jrow / (vres - 1.);

   Vector3D dirP1minusP0 = alpha * u + beta * v - dist * n;
   dirP1minusP0.normalize();
   Ray rayFromCameraToPixel(loc,dirP1minusP0);
   return rayFromCameraToPixel;
}
