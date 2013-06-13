//@author Ryan Draper
//@file Cylinder.h
//@date October 16, 2012

// ADT Cylinder:
//    Creates a cylinder using the GL geometric shape GL_Triangles
//    operations creates, destroys, operator=, copies, colors a cylinder and creates a side

#include "Cylinder.h"
#include <cmath>
#include <iostream>

using namespace std;


//creates a cylinder
//pre world coordinates have been created
//post cylinder has been created
//usage Cylinder myCylinder
Cylinder::Cylinder()
{
    float angle = 2 * M_PI / 50.000000;

    for (int j = 0; j < 50; j++){
       vertices[j] = vec4(0.5 * cos(j * angle), -1.0, 0.5 * sin(j * angle), 1.0);
    }

    for (int k = 50; k <= 100; k++){
       vertices[k] = vec4(0.5 * cos(k * angle), 1.0, 0.5 * sin(k * angle), 1.0);
    }

    sixColors[0] = vec4(0.0, 0.0, 0.0, 1.0);
    sixColors[1] = vec4(0.0, 1.0, 1.0, 1.0);
    sixColors[2] = vec4(1.0, 0.0, 1.0, 1.0);
    sixColors[3] = vec4(1.0, 1.0, 0.0, 1.0);
    sixColors[4] = vec4(0.0, 1.0, 0.0, 1.0);

    index = -1;

    colorCylinder();
}

//destroys the cylinder
//pre cylinder existed
//post cylinder was destroyed
Cylinder::~Cylinder(){}

//creates a copy of the other to another Cylinder
//pre other existed as a Cylinder
//post a copy of the Cylinder other has bee created
//usage myCylinder.Cylinder(cylinderNew);
Cylinder::Cylinder(const Cylinder& other){
   for (int i = 0; i < 300; i++)
    {
        points[i] = other.points[i];
        colors[i] = other.colors[i];
        normals[i] = other.normals[i];
    }

    for (int h = 0; h < 5; h++)
    {
        sixColors[h] = other.sixColors[h];
    }
    index = other.index;
}

//creates a copy of a cylinder to another cylinder by means of =
//pre two cylinders exist
//post both cylinders are the same
//usage cylinder1 = cylinder;
Cylinder& Cylinder::operator=(const Cylinder& rhs){
    if (this == &rhs)
    {
            return *this;
    }
    for (int i = 0; i < 300; i++)
    {
        points[i] = rhs.points[i];
        colors[i] = rhs.colors[i];
        normals[i] = rhs.normals[i];
    }
    colorCylinder();
    index = rhs.index;

}

//assigns a color to each bar of the 30 sided cylinder
//pre each cylinder exists
//post cylinder has a color per bar of cylinder
//usage colorCylinder();
void Cylinder::colorCylinder(){

    int color;
    for (int i = 0, color = 0; i <= 49; i++, color = (color + 1) % 5){
        slice(i, (i + 1) % 50, ((i + 1) % 50) + 50, color);
    }

    for (int j = 0, color = 0; j <= 49; j++, color = (color +1) % 5){
        slice(j, ((j + 1) % 50) + 50, j + 50, color);
    }
    numPoints = index + 1;
}

//creates one side of a cylinder called by colorCylinder
//pre cylinder exists
//post cylinder has color for ever side of the cylinder
//usage slice(0, 1, 2, 0);
void Cylinder::slice(int a, int b, int c, int col)
{
   index++;
   points[index] = vertices[a];
   normals[index] = cylinderNormals[index % 49];
   colors[index] = sixColors[col];

   index++;
   points[index] = vertices[b];
   normals[index] = cylinderNormals[index % 49];
   colors[index] = sixColors[col];

   index++;
   points[index] = vertices[c];
   normals[index] = cylinderNormals[index % 49];
   colors[index] = sixColors[col];
}
