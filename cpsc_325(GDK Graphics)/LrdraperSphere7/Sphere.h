//file Sphere.h
//author Ryan Draper
//date Nov. 6, 2012


// Generates the vertices of a unit Sphere
// centered at origin, sides aligned with axes.


#ifndef SPHERE_H
#define SPHERE_H

#include "Angel.h"
#include <cmath>

class Sphere
{
    public:
        //@Creates a default Sphere
        //@pre world has been created
        //@post Sphere exists
        //@usage Sphere Sphere(radius);
        Sphere(float radius=1);

        //@Creates a copy of a  Sphere
        //@pre world has been created and a sphere exists
        //@post 2 exact same Spheres exists
        //@usage mySphere(otherSphere);
        Sphere(const Sphere& other);

        //@Creates a copy of a  Sphere
        //@pre world has been created and a sphere exists
        //@post 2 exact same Spheres exists
        //@usage mySphere = rhsSphere;
        Sphere& operator=(const Sphere& rhs);

        //@Destroys a Sphere
        //@pre Sphere exists
        //@post Sphere and public members have been deleted and released
        virtual ~Sphere();

        //@Sets up the Graphics pipeline
        //@pre Sphere points are only an array of points[]
        //@post points[] have been rasterized
        //@usage mySphere.createVAO(vao[10], program);
        void createVAO(GLint _vao, GLint _program );

        //@Sphere exists with all of its vertices
        //@pre the sphere is not in the world
        //@post the sphere is in the world
        //@usage mySphere.draw();
        void draw();
        GLint vao;
        vec4 *points;
        vec4 *colors;
        vec4 center;
        int numVertices;

    protected:
    private:
};

#endif // SPHERE_H
