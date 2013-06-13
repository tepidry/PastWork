// //@file   World.cpp
//@ authors Original classes by K.S. then redesigned by Dr. O and Dr. Y
//@ June 22, 2012   Revised June 24 to include object and operations of the ViewPlane class

// ADT World
//    data object: a world of objects consisting of the background color of the world,
//                 a reference to the camera in the world, a list of objects in the world,
//                 a list of lights in the world, and the depth levels of reflections considered
//    operations: create, destroy, add an object to a list, add a light to a list, build the world,
//                set the camera and set the depth of reflectionsthis file contains the definition of the World class

#include "Sphere.h"
#include "Plane.h"
#include "Box.h"


#include "Utilities/Constants.h"
#include "Utilities/Ray.h"
#include "Utilities/Vector3D.h"
#include "Utilities/ShadeRec.h"
#include "Material.h"

#include "World.h"

//@builds the world of objects and background color,
//    lights, and camera with depth of reflections
//@post objects and lights now exist in the world with camera and associated viewplane assigned
//@usage world_ptr -> build();
void
World::build(void)
{
    background_color = black;
    depth = 4;  // levels of reflection. 0 for no reflections.

    camera_ptr = new Camera();

    Sphere* sphere_ptr = new Sphere;
    sphere_ptr -> set_center(-2, 3, -140);
    sphere_ptr -> set_radius(3.0);
    Material* mat_ptr = new Material();
    mat_ptr -> setAllColor(1,1,1);       // red
    mat_ptr -> kr = 0;
    sphere_ptr -> set_material(mat_ptr);
    add_object(sphere_ptr);

    sphere_ptr = new Sphere(Vector3D(-5, 6, -85), 2);
    mat_ptr = new Material();
    mat_ptr -> setAllColor(1,0,0);             // yellow
    sphere_ptr -> set_material(mat_ptr);
    add_object(sphere_ptr);

    Plane* plane_ptr = new Plane(Vector3D(-10, -3, -100), Vector3D(0, -1, -.03));
    mat_ptr = new Material();
    mat_ptr -> setAllColor(1,0,1);       // red
    mat_ptr -> kr = .5;
    plane_ptr -> set_material(mat_ptr);
    add_object(plane_ptr);

    Box* box_ptr = new Box(Plane(Vector3D(-10, 5, -10), Vector3D(0, 0, 1)), 4);
    mat_ptr = new Material();
    mat_ptr -> setAllColor(1,1,1);       // red
    mat_ptr -> kr = 0;
    box_ptr -> set_material(mat_ptr);
    add_object(box_ptr);

    PointLight* light_ptr = new PointLight();
    light_ptr -> set_color(1,1,1);
    light_ptr -> set_intensity(1.5);
    light_ptr -> set_location(-100,400,1000);
    add_light(light_ptr);

}


//@ creates a world of a black background, no camera, and no reflections
World::World()
    :  	background_color(black),
        camera_ptr(NULL), depth(0)
{}

//@destroys the world
World::~World(void)
{
   if (camera_ptr) {
      delete camera_ptr;
      camera_ptr = NULL;
   }
   delete_objects();
   delete_lights();
}

//------------------------------------------------------------------ delete_objects

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty

void
World::delete_objects(void)
{
    int num_objects = objects.size();

    for (int j = 0; j < num_objects; j++)
    {
        delete objects[j];
        objects[j] = NULL;
    }

    objects.erase (objects.begin(), objects.end());
}

//------------------------------------------------------------------ delete_lights

void
World::delete_lights(void)
{
    int num_lights = lights.size();

    for (int j = 0; j < num_lights; j++)
    {
        delete lights[j];
        lights[j] = NULL;
    }

    lights.erase (lights.begin(), lights.end());
}

