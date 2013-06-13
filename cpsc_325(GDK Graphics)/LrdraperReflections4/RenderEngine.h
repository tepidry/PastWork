//@file RenderEngine.h
//@ authors Original classes by K.S. then redesigned by Dr. O and Dr. Y
//@ June 22, 2012

// ADT RenderEngine
//    data object: the engine that renders a world of objects and lights and camera
//    operations: create, destroy, render a scene and its helpers

#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <vector>

#include "World.h"
#include "Utilities/Ray.h"
#include "Utilities/Vector3D.h"
#include "Utilities/RGBColor.h"
#include "Camera.h"
#include "PointLight.h"
#include "GeometricObject.h"
#include "Utilities/ShadeRec.h"

class RenderEngine
{
public:
    World* world_ptr;

public:

    //@creates a rendering engine
    RenderEngine();

    //@ assigns a world to the render engine and creates it
    //@pre w_ptr points to an existing world of objects, lights, and camera
    //@post world_ptr also points to that world
    //@usage  engine_ptr = new RenderEngine(the_world_ptr);
    RenderEngine(World* w_ptr);

    //@destroys a rendering engine
    ~RenderEngine();

    //@creates a shallow copy of a rendering engine
    RenderEngine(const RenderEngine& other);

    //@copies a rendering engine
    RenderEngine& operator=(const RenderEngine& other);

    //@sets the world in a rendering engine
    void set_world(World* w_ptr);

    //@renders a scene composed of objects, lights, and a camera
    //@pre a world of objects, lights, and camera has been created
    //@post renders the world scene into an image
    //@usage renderEngine.render_scene();
    void render_scene();

private:
    RGBColor trace_ray(const Ray& ray, ShadeRec& sr, int rayDepth);
    RGBColor calc_reflected(const Ray& ray, ShadeRec& sr, int rayDepth);
    RGBColor calc_shade(const Ray& ray, const ShadeRec& sr);
    RGBColor max_to_one(const RGBColor& c) const;
    RGBColor clamp_to_color(const RGBColor& c) const;
    bool inShadow(Vector3D hit_point, PointLight* light) const;
};

#endif // RENDERENGINE_H
