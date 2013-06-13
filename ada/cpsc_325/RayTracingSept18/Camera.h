//@file Camera.h
//@date June 2012
//@author Dr O with modifications by Dr Y

//ADT Camera: data object: a camera placed in the world
//            It's location is at the origin of the world's coordinate system
//    operations: creates, destroy,
//       calculate the u,v,n camera orientation vectors (page 5 of ray tracing notes),
//       computation of the ray from the camera to an (i, j) pixel

#ifndef CAMERA_H
#define CAMERA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Utilities/Vector3D.h"
#include "Utilities/Ray.h"

class Camera
{
   public:
      //@initializes camera's coordinate axes u, v, n; location;
      //   its distance from the viewplane, the width and height of the viewplane,
      //   the image array and its horizontal and vertical resolution
      //@post camera object exists with orientation the same as the world's coordinate system,
      //      resolution 640 by 480, image a three dimensional array for the given resolution
      Camera();

      //@copies a camera with a given resolution
      //@pre horizontal resolution xr and vertical resolution yr are assigned
      //@post a camera exists with the resolution given by xr and yr
      //@usage Camera cam(640, 480);
      Camera(int xr, int yr);

      //@destroys the camera
      //@pre camera object exists
      //@post camera object does not exist
      ~Camera();

      //@ creates a copy of a camera
      //@pre rhscam exists
      //@post object is a copy of rhscam
      //@usage Camera myCamera(yourCamera);
      Camera(const Camera& rhscam);

      //@ copies a camera
      //@pre rhscam exists
      //@post object is a copy of rhscam
      //@usage Camera myCamera(yourCamera);
      Camera&
      operator=(const Camera& rhscam);

      //@ calculates the u, v, n coordinate unit vectors for the camera's orientation
      //@pre VPN (the normal to the viewplane) and VUP (the up direction of the camera) are assigned
      //@post n is the normal to the viewplane (same direction as VPN)
      //@     u is the unit vector in the same direction as VUP
      //@     u is the unit vector in the right direction
      //@     (u, v, n) form an orthogonal coordinate system with the camera's orientation
      //@usage camera_ptr -> calcUVN(VPN, VUP);
      void
      calculateUVN(const Vector3D &VPN, const Vector3D &VUP);

      //@determines the ray from the camera to a pixel on the viewplane
      //@pre pixel in the ith COLUMN and jth ROW are assigned
      //@post returns a ray starting at the camera's location with direction toward pixel (i, j)
      //@usage ray = camera_ptr -> pixRay(row, col);
      Ray
      pixelRay(int icol, int jrow) const;

    public:
		Vector3D        loc;        // camera location
		Vector3D        u;          // unit vector, to camera's right
		Vector3D        v;          // unit vector, looking up from camera
		Vector3D        n;          // unit vector pointing opposite camera direction
		float           dist;          // distance between camera and view plane
		float           width;          // width of view plane
		float           height;          // height of view plane
		int 	    	hres;   	// horizontal image resolution
		int 	    	vres;       // vertical image resolution
		GLfloat         *image;
};

#endif // CAMERA_H
