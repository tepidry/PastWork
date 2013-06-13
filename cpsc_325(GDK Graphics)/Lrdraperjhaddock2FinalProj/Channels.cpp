//@file Channels.cpp
//@date December 3, 2012 -- adapted from wire sphere created by Jamie Haddock in November 2012
//@authors Jamie Haddock, Ryan Draper

// ADT Channels:
//    data object: Channels is a virtual (almost) wire sphere consisting of only latitudinal lines.
//    data structure: array for vertices and colors, number of vertices
//    operations: creates, destroys, operator=, copies, create vao, draw

#include "Channels.h"
#include <iostream>
using namespace std;

//@creates an instance of Channels
//@post: Channels has been created
//@param: int longitudinalLines, int latitudinalLines, float radius
//@usage: Channels myChannels(100, 100, 1.0);
Channels::Channels(int longitudinalLines, int latitudinalLines, float radius)
{
    numVertices = (4) * (2 * latitudinalLines + 1);  // using a GL_LINE_STRIP

    vertices = new vec4[numVertices];
    colors = new vec4[numVertices];
    normals = new vec4[numVertices];
    vec4 black(0,0,0,1);
    float phiDelta = M_PI / latitudinalLines;
    float thetaDelta = M_PI / longitudinalLines;
    float phi;
    float theta;
    int vertexIndex = 0;

    for (int l = 0; l < longitudinalLines; l++) //set longitudinal line vertices
    {
        theta = 0 + l * thetaDelta;
        for (int m = 0; m < 2 * latitudinalLines; m++)
        {
            phi = -M_PI / 2 + m * phiDelta;
            if (l % (longitudinalLines / 4) == 0){
                vertices[vertexIndex] = vec4(radius * cos(phi) * cos(theta), radius * sin(phi), radius * cos(phi) * sin(theta), 1.0);
                vertexIndex++;
            }
        }
        vertices[vertexIndex] = vec4(0, -radius, 0, 1.0);
        vertexIndex++;
    }


}

//@deletes an instance of Channels
//@pre: Channels exists
//@post: Channels doesn't exist
Channels::~Channels()
{
    delete[] vertices;
    delete[] normals;
    delete[] colors;
}

//@copies a Channels
//@pre: other exists
//@post: Channels identical to other is created
//@param: Channels other
//@usage: Channels myChannels(otherChannels);
Channels::Channels(const Channels& other)
{
    for (int i=0; i < numVertices; i++)
    {
        vertices[i]=other.vertices[i];
        normals[i] = other.normals[i];
        colors[i]=other.colors[i];
    }
    numVertices = other.numVertices;
}

//@sets a Channels equal to another
//@pre: rhs Channels and this Channels exist
//@post: this Channels is equal to rhs
//@param: Channels rhs
//@usage: myChannels = rhsChannels;
Channels& Channels::operator=(const Channels& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;

    for (int i=0; i < numVertices; i++)
    {
        vertices[i]=rhs.vertices[i];
        normals[i] = rhs.normals[i];
        colors[i]=rhs.colors[i];
    }
    numVertices = rhs.numVertices;
}

//@calls functions necessary to rasterize the Channels
//@pre: Channels exists
//@post: Channels is ready to be displayed
//@param: GLint _vao, GLint program
//@usage: createVAO(vao, program);
void
Channels::createVAO(GLint _vao, GLint program )
{
    vao = _vao;
    glBindVertexArray( vao );
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    int csize = sizeof(*vertices) * numVertices;
    glBufferData( GL_ARRAY_BUFFER, 3*csize,
                  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, csize, *vertices );
    glBufferSubData( GL_ARRAY_BUFFER, csize, csize, *colors );
    glBufferSubData( GL_ARRAY_BUFFER, 2 * csize, csize, *normals );
    // set up shader variables
    GLint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(0) );

    GLint vColor = glGetAttribLocation( program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(csize) );

   GLint vNormal = glGetAttribLocation( program, "vNormal" );
    glEnableVertexAttribArray( vNormal );
    glVertexAttribPointer( vNormal, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(2 * csize) );

    glBindBuffer( GL_ARRAY_BUFFER, 0 );
    glBindVertexArray( 0 );
}

//@draws the Channels
//@pre: Channels exists
//@post: Channels has been drawn
//@usage: myChannels.draw();
void Channels::draw() {
    glBindVertexArray( vao );
    glLineWidth(2.0);
    glDrawArrays( GL_LINE_STRIP, 0, numVertices );
    glBindVertexArray( 0 );
}
