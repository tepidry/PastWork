//file Sphere.cpp
//author Ryan Draper
//date Nov. 6, 2012


// Generates the vertices of a unit Sphere
// centered at origin, sides aligned with axes.

#include "Sphere.h"
#include <iostream>
using std::cout;

//@Creates a default Sphere
//@pre world has been created
//@post Sphere exists
//@usage Sphere Sphere(radius);
Sphere::Sphere(float radius)
{
    int latSlices = 16;
    int longSlices = 16;

    numVertices = 2 * latSlices * 2 * longSlices;  // using a GL_LINES
    //cout <<
    points = new vec4[numVertices];
    colors = new vec4[numVertices];
    vec4 black(0,0,0,1);

    float thetaAngle = 2 * M_PI / latSlices;
    float phiAngle = 2 * M_PI / longSlices;

    vec4 verticesLong[numVertices / 2];
    vec4 verticesLat[numVertices / 2];

    int index = 0;
    index++;
    for (int j = 0; j < latSlices + 1; j++){
        for (int i = 0 ; i < longSlices + 1; i++) {
            verticesLat[index]= vec4(radius * cos(j * phiAngle) * cos(i * thetaAngle),  radius * sin(j * phiAngle), radius * cos(j * phiAngle) * sin(i * thetaAngle), 1) ;
            verticesLong[index]= vec4(radius * cos(i * phiAngle) * cos(j * thetaAngle),  radius * sin(i * phiAngle), radius * cos(i * phiAngle) * sin(j * thetaAngle), 1) ;
            index++;
        }
    }

    index = 0;
    for (int k = 0; k < numVertices/2; k++)
    {
        points[index] = verticesLat[k ];
        colors[index] = black;
        index++;
    }

    for (int h = 0; h < numVertices/2; h++)
    {
        points[index] = verticesLong[h];
        colors[index] = black;
        index++;
    }

    cout << "WireSphere: number of vertices = " << index << "\n";
    for (int i = 0; i < numVertices; i++)
    {
        cout << "pts " << i << ": " << points[i] << "\n";
    }
}

//@Destroys a Sphere
//@pre Sphere exists
//@post Sphere and public members have been deleted and released
Sphere::~Sphere()
{
    delete[] points; points = NULL;
    delete[] colors; colors = NULL;
}

//@Creates a copy of a  Sphere
//@pre world has been created and a sphere exists
//@post 2 exact same Spheres exists
//@usage mySphere(otherSphere);
Sphere::Sphere(const Sphere& other)
{
    for (int i = 0; i < numVertices; i++)
    {
        points[i] = other.points[i];
        colors[i] = other.colors[i];
    }
    numVertices = other.numVertices;
}

//@Creates a copy of a  Sphere
//@pre world has been created and a sphere exists
//@post 2 exact same Spheres exists
//@usage mySphere = rhsSphere;
Sphere& Sphere::operator=(const Sphere& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    for (int i = 0; i < numVertices; i++)
    {
        points[i] = rhs.points[i];
        colors[i] = rhs.colors[i];
    }
    numVertices = rhs.numVertices;
    return *this;
}

//@Sets up the Graphics pipeline
//@pre Sphere points are only an array of points[]
//@post points[] have been rasterized
//@usage mySphere.createVAO(vao[10], program);
void
Sphere::createVAO(GLint _vao, GLint program )
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

//@Sphere exists with all of its vertices
//@pre the sphere is not in the world
//@post the sphere is in the world
//@usage mySphere.draw();
void Sphere::draw() {
    glBindVertexArray( vao );
    glDrawArrays( GL_LINE_LOOP, 0, numVertices );
    glBindVertexArray( 0 );
}
