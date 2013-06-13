//ADT Cylinder: data object - a cylinder centered at the origin
//                 and centered about the y-axis with a given height and radius
//   operations: constructor, destructor, copy constructor, assignment,
//               create vertex array object, and draw the cylinder

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Angel.h"

class Cylinder
{
    public:
        //creates a cylinder with default 12 slices, radius 1, height 1
        //    but allows for other values for slices, radius, and height
        //pre slices, radius, and height are assigned or default values are used
        //post creates the cylinder for the geometric entity GL_TRIANGLE_STRIP
        //param slices
        //param radius
        //param height
        Cylinder(int slices = 12,float radius = 1, float height = 1);

        //destroys a cylinder object
        //pre cylinder object exists
        //post cylinder object does not exist
        virtual ~Cylinder();

        //creates a new cylinder as a copy of another
        //pre other cylinder object exists
        //post object is a copy of cylinder
        //param other
        //usage Cylinder myCyl(yourCyl);
        Cylinder(const Cylinder& other);

        //copies a cylinder to an existing cylinder
        //pre other cylinder object exists
        //post object is a copy of cylinder
        //param other
        //usage aCylinder = bCylinder;
        Cylinder& operator=(const Cylinder& other);

        GLint vao;

        //creates vertex array object with associated buffers
        // and shader variables
        //pre _vao and _program are assigned
        //post all necessary buffers are readied and shader variables assigned
        //param _vao
        //param _program
        //usage myCylinder.createVAO(vao[0],program);
        void createVAO(GLint _vao, GLint _program );


        vec4 *points;
        vec4 *colors;
        vec4 *normals;

        //these are the same as the number of points
        int numVertices;

        //draws the cylinder using GL_TRIANGLE_STRIP
        //pre cylinder object exists
        //post cylinder object is rendered in the window
        //usage myCyl.draw();
        void draw();
 };

#endif // CYLINDER_H
