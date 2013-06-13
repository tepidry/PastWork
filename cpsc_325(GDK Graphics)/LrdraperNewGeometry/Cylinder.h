//@author Ryan Draper
//@file Cylinder.h
//@date October 16, 2012

// ADT Cylinder:
//    Creates a cylinder using the GL geometric shape GL_Triangles
//    operations creates, destroys, operator=, copies, colors a cylinder and creates a side

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Angel.h"

class Cylinder
{
    public:
        //creates a cylinder
        //pre world coordinates have been created
        //post cylinder has been created
        //usage Cylinder myCylinder
        Cylinder();

        //destroys the cylinder
        //pre cylinder existed
        //post cylinder was destroyed
        virtual ~Cylinder();

        //creates a copy of the other to another Cylinder
        //pre other existed as a Cylinder
        //post a copy of the Cylinder other has bee created
        //usage myCylinder.Cylinder(cylinderNew);
        Cylinder(const Cylinder& other);

        //creates a copy of a cylinder to another cylinder by means of =
        //pre two cylinders exist
        //post both cylinders are the same
        //usage cylinder1 = cylinder;
        Cylinder& operator=(const Cylinder& other);

        vec4 points[300];
        vec4 colors[300];
        vec4 normals[300];
        int numPoints;

        //assigns a color to each bar of the 30 sided cylinder
        //pre each cylinder exists
        //post cylinder has a color per bar of cylinder
        //usage colorCylinder();
        void colorCylinder();
    protected:
        vec4 cylinderNormals[50];
        vec4 vertices[100];  //300
        vec4 sixColors[5];
        int index;

        //creates one side of a cylinder called by colorCylinder
        //pre cylinder exists
        //post cylinder has color for ever side of the cylinder
        //usage slice(0, 1, 2, 0);
        void slice(int a, int b, int c, int col);
    private:
};

#endif // CYLINDER_H
