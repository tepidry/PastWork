//@file   World.h
//@ authors Original classes by K.S. then redesigned by Dr. O and Dr. Y
//@ June 22, 2012   Revised June 24 to include object and operations of the ViewPlane class

// ADT World
//    data object: a world of objects consisting of the background color of the world,
//                 a reference to the camera in the world, a list of objects in the world,
//                 a list of lights in the world, and the depth levels of reflections considered
//    operations: create, destroy, add an object to a list, add a light to a list, build the world,
//                set the camera and set the depth of reflections

#ifndef __WORLD__
#define __WORLD__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>
using namespace std;

#include "Utilities/RGBColor.h"
#include "GeometricObject.h"
#include "Utilities/Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "PointLight.h"

class World
{
public:

   RGBColor					background_color;
   Camera*					camera_ptr;
   vector<GeometricObject*>	objects;
   vector<PointLight*> 		lights;
   int                      depth;        // levels of reflection. Set to 0 if no reflections are allowed.

public:
   //@ creates a world of a black background, no camera, and no reflections
    World();

   //@destroys the world
    ~World();

   //@copies a camera to the world's camera
   //@pre c_ptr is assigned a Camera object
   //@post The World's camera pointer is assigned c_ptr;
   //@usage camera_ptr = c_ptr;
    void
    set_camera(Camera* c_ptr);

   //@ sets the depth of reflections
   //@pre d is the desired depth
   //@post world's depth is set to d
   //@usage world_ptr -> set_depth(2);
   void
   set_depth(int d);

   //@builds the world of objects and background color,
   //    lights, and camera with depth of reflections
   //@post objects and lights now exist in the world with camera and associated viewplane assigned
   //@usage world_ptr -> build();
    void
    build();

private:

   void
   add_object(GeometricObject* object_ptr);

   void
   add_light(PointLight* light_ptr);

   void
   delete_objects();

   void
   delete_lights();
};


// ------------------------------------------------------------------ add_object

inline void
World::add_object(GeometricObject* object_ptr)
{
    objects.push_back(object_ptr);
}

// ------------------------------------------------------------------ add_light

inline void
World::add_light(PointLight* light_ptr)
{
    lights.push_back(light_ptr);
}

// ------------------------------------------------------------------ set_camera

inline void
World::set_camera(Camera* c_ptr)
{
    camera_ptr = c_ptr;
}

inline void
World::set_depth(int d)
{
    depth = d;
}

#endif
