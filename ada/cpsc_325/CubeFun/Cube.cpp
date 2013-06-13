// Generates the vertices, colors, and normals of a unit cube
// centered at origin, sides aligned with axes.
//
//    v5----- v6
//   /|      /|
//  v1------v2|              ^ y
//  | |     | |              |
//  | |v4---|-|v7            -->x
//  |/      |/              /
//  v0------v3              z


#include "Cube.h"
#include <iostream>
using std::cout;

Cube::Cube()
{
    colorcube();
    cout << "points:\n";
    for (int i = 0; i < 36; i++)
    {
        cout<< i << ":  " <<  points[i] << "\n";
    }
    cout << "colors:\n";
    for (int i = 0; i < 36; i++)
    {
        cout<< i << ":  " <<  colors[i] << "\n";
    }
    cout << "normals:\n";
    for (int i = 0; i < 36; i++)
    {
        cout<< i << ":  " <<  normals[i] << "\n";
    }
}

Cube::Cube(const Cube& other)
{
    for (int i=0; i < 36; i++)
    {
        points[i]=other.points[i];
        colors[i]=other.colors[i];
        normals[i]=other.normals[i];
    }
    numVertices = other.numVertices;
}

Cube&
Cube::operator=(const Cube& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
       for (int i=0; i < 36; i++)
    {
        points[i]=rhs.points[i];
        colors[i]=rhs.colors[i];
        normals[i]=rhs.normals[i];
    }
    numVertices = rhs.numVertices;
}

Cube::~Cube()
{}

//8 vertices of a cube with the origin (0,0,0)
//    and edges of size 1
vec4 vertices[8] =
{
    vec4( -0.5, -0.5,  0.5, 1.0 ),   // v0
    vec4( -0.5,  0.5,  0.5, 1.0 ),   // v1
    vec4(  0.5,  0.5,  0.5, 1.0 ),   // v2
    vec4(  0.5, -0.5,  0.5, 1.0 ),   // v3
    vec4( -0.5, -0.5, -0.5, 1.0 ),   // v4
    vec4( -0.5,  0.5, -0.5, 1.0 ),   // v5
    vec4(  0.5,  0.5, -0.5, 1.0 ),   // v6
    vec4(  0.5, -0.5, -0.5, 1.0 )    // v7
};

// RGBA olors
vec4 vertex_colors[8] =
{
    vec4( 0.0, 0.0, 0.0, 1.0 ),  // black
    vec4( 1.0, 0.0, 0.0, 1.0 ),  // red
    vec4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    vec4( 0.0, 1.0, 0.0, 1.0 ),  // green
    vec4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    vec4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    vec4( 1.0, 1.0, 1.0, 1.0 ),  // white
    vec4( 0.0, 1.0, 1.0, 1.0 )   // cyan
};

// normals facing "out" of each face
vec4 face_normals[6] =
{
    vec4(  1.0,  0.0,  0.0, 0.0 ),  // +x  0
    vec4( -1.0,  0.0,  0.0, 0.0 ),  // -x  1
    vec4(  0.0,  1.0,  0.0, 0.0 ),  // +y  2
    vec4(  0.0, -1.0,  0.0, 0.0 ),  // -y  3
    vec4(  0.0,  0.0,  1.0, 0.0 ),  // +z  4
    vec4(  0.0,  0.0, -1.0, 0.0 ),  // -z  5
};

int Index = 0;

//col is short for color;
//nor is short for normal;
//a,b,c,d is the order for the vertices of the face (puts an ordering of the vertices that amke up each face)
void
Cube::quad( int a, int b, int c, int d , int col, int norm)
{
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[a];
    normals[Index] = norm;
    Index++;
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[b];
    normals[Index] = norm;
    Index++;
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[c];
    normals[Index] = norm;
    Index++;
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[a];
    normals[Index] = norm;
    Index++;
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[c];
    normals[Index] = norm;
    Index++;
    colors[Index] = vertex_colors[col];
    points[Index] = vertices[d];
    normals[Index] = norm;
    Index++;
}

// generate 12 triangles: 36 vertices and 36 colors
//    v5----- v6
//   /|      /|
//  v1------v2|              ^ y
//  | |     | |              |
//  | |v4---|-|v7            -->x
//  |/      |/              /
//  v0------v3              z
// Always use the Right Hand Rule to generate vertex sequence. We want outward facing normals.
//traversed vertices are counter clockwise
void
Cube::colorcube()
{
    //    vertices   color normal
    quad( 1, 0, 3, 2 , 2,    4);   // front (+z) face
    quad( 2, 3, 7, 6 , 1,    0);   // +x
    quad( 3, 0, 4, 7 , 3,    3);   // -y
    quad( 6, 5, 1, 2 , 4,    2);   // +y
    quad( 4, 5, 6, 7 , 5,    5);   // -z
    quad( 5, 4, 0, 1 , 6,    1);   // -x

    numVertices = Index;
}






