

#include "Disk.h"
#include <iostream>
#include <cmath>

using namespace std;



Disk::Disk()
{
    float angle = 2 * M_PI / 20.00000;  //2pi / 8
    diskNormal = vec4(0, 1, 0,0);
    vertices[0] = vec4(0, 0, 0, 1); //fourth point in homogeneous coordinates
    for (int i = 1; i < 21; i++) {
        vertices[i] = vec4(0.5 * cos(i * angle), 0, 0.5 * sin(i * angle), 1.0);
    }
    for (int k = 1; k < 9; k++) {
        cout << "vertex " << k << " = " << vertices[k] << endl;
    }

    twoColors[0] = vec4(1.0, 0, 0, 1.0);
    twoColors[1] = vec4(0, 0, 1.0, 1.0);

    index = -1;

    colorDisk();

    /*cout << "points:\n";
    for (int i = 0; i < 24; i++)
    {
        cout<< i << ":  " <<  points[i] << "\n";
    }
    cout << "colors:\n";
    for (int i = 0; i < 24; i++)
    {
        cout<< i << ":  " <<  colors[i] << "\n";
    }*/
}

Disk::~Disk()
{}

/*Disk(const Disk& other)
{

}*/

Disk& Disk::operator=(const Disk& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
       for (int i=0; i < 60; i++)
    {
        points[i]=rhs.points[i];
        colors[i]=rhs.colors[i];
        normals[i]=rhs.normals[i];
    }
    diskNormal = rhs.diskNormal;
}
/*
int numPoints;
*/

void
Disk::colorDisk()    //rotates through each slice of the pie
{
    for (int i = 0; i <= 19; i ++)
    {
        slice(i, (i + 1) % 20, ((i + 1) % 20) + 20, i % 2);
    }

    slice(0, 2, 3, 0);
    slice(0, 3, 4, 1);
    slice(0, 4, 5, 0);
    slice(0, 5, 6, 1);
    slice(0, 6, 7, 0);
    slice(0, 7, 8, 1);

    numPoints = index + 1;
}

void
Disk::slice(int a, int b, int c, int col)
{
    index++;
    points[index] = vertices[a];
    normals[index] = diskNormal;
    colors[index] = twoColors[col];

    index++;
    points[index] = vertices[b];
    normals[index] = diskNormal;
    colors[index] = twoColors[col];

    index++;
    points[index] = vertices[c];
    normals[index] = diskNormal;
    colors[index] = twoColors[col];

}



