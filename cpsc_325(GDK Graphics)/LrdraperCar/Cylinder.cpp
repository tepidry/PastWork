// creates a Cylinder of radius r and height h  along the y+ axis and centered at the origin
//ADT Cylinder: data object - a cylinder centered at the origin
//                 and centered about the y-axis with a given height and radius
//   operations: constructor, destructor, copy constructor, assignment,
//               create vertex array object, and draw the cylinder
//data structures: dynamic arrays for points for GL_TRIANGLE_STRIP, colors, and normals

#include "Cylinder.h"
#include <iostream>
using namespace std;

//creates a cylinder with default 12 slices, radius 1, height 1
//    but allows for other values for slices, radius, and height
//pre slices, radius, and height are assigned or default values are used
//post creates the cylinder for the geometric entity GL_TRIANGLE_STRIP
//param slices
//param radius
//param height
Cylinder::Cylinder(int slices, float radius, float height)
{
    numVertices = 2 * slices + 2;  // using a GL_TRIANGLE_STRIP

    points  = new vec4[numVertices];
    colors  = new vec4[numVertices];
    normals = new vec4[numVertices];

    vec4 normal(0,1,0,0);
    vec4 color[4] = {vec4(1,1,0,1),vec4(0,0,1,1),vec4(1,0,0,1),vec4(0,1,0,1)};
    float dAngle = 2 * M_PI/slices;

    int index = 0;

    for (int i = 0; i <= slices ; i++)
    {
        int im = i % slices;
        points[index] = vec4(radius * cos(im * dAngle), height / 2, radius * sin((im * dAngle)), 1);
        colors[index] = color[im % 2];

        vec3 normal(radius * cos(im * dAngle), 0, radius * sin((im * dAngle)));
        normals[index] = vec4(normalize(normal));
        index++;

        points [index] = vec4(radius * cos(im * dAngle),-height / 2, radius * sin((im * dAngle)), 1);
        colors [index] = color[2];
        normals[index] = normal;
        index++;
    }

    cout << "Cylinder: number of vertices = " << index << "\n";
    for (int i = 0; i < index; i++)
    {
       cout << "pts " << i << ": " << points[i] << "\n";
    }
}

//destroys a cylinder object
//pre cylinder object exists
//post cylinder object does not exist
Cylinder::~Cylinder()
{
    delete [] points;  points = NULL;
    delete [] colors;  colors = NULL;
    delete [] normals; normals = NULL;
}

//creates a new cylinder as a copy of another
//pre other cylinder object exists
//post object is a copy of cylinder
//param other
//usage Cylinder myCyl(yourCyl);
Cylinder::Cylinder(const Cylinder& other)
{
    for (int i = 0; i < numVertices; i++)
    {
        points[i]  = other.points [i];
        colors[i]  = other.colors [i];
        normals[i] = other.normals[i];
    }
    numVertices = other.numVertices;
}

//copies a cylinder to an existing cylinder
//pre other cylinder object exists
//post object is a copy of cylinder
//param other
//usage aCylinder = bCylinder;
Cylinder& Cylinder::operator=(const Cylinder& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    for (int i = 0; i < numVertices; i++)
    {
        points[i]  = rhs.points [i];
        colors[i]  = rhs.colors [i];
        normals[i] = rhs.normals[i];
    }
    numVertices = rhs.numVertices;

    return *this;
}

//creates vertex array object with associated buffers
// and shader variables
//pre _vao and _program are assigned
//post all necessary buffers are readied and shader variables assigned
//param _vao
//param _program
//usage myCylinder.createVAO(vao[0],program);
void
Cylinder::createVAO(GLint _vao, GLint program )
{
    vao = _vao;
    glBindVertexArray( vao );
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    int csize = sizeof((*points)) * numVertices;
    glBufferData( GL_ARRAY_BUFFER, 2 * csize,
                  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, csize, *points );
    glBufferSubData( GL_ARRAY_BUFFER, csize, csize, *colors );
    //glBufferSubData( GL_ARRAY_BUFFER, 2 * csize, csize, *normals );

    // set up shader variables
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(0) );
    GLuint vColor = glGetAttribLocation( program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(csize) );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindVertexArray( 0 );
}

//draws the cylinder using GL_TRIANGLE_STRIP
//pre cylinder object exists
//post cylinder object is rendered in the window
//usage myCyl.draw();
void Cylinder::draw() {
    glBindVertexArray( vao );
    glDrawArrays( GL_TRIANGLE_STRIP, 0, numVertices );
    glBindVertexArray( 0 );
}
