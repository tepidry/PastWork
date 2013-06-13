//@file Core.cpp
//@date November 6, 2012
//@authors Jamie Haddock

// ADT Core:
//    data object: Core is a virtual (almost) wire Core.
//    data structure: array for vertices and colors, number of vertices
//    operations: creates, destroys, operator=, copies, create vao, draw

#include "Core.h"
#include <iostream>
using namespace std;

//@creates an instance of Core
//@post: Core has been created
//@param: int longitudinalLines, int latitudinalLines, float radius
//@usage: Core myCore(100, 100, 1.0);
Core::Core(int longitudinalLines, int latitudinalLines, float radius)
{
    numVertices = (2 * longitudinalLines + 1) * latitudinalLines + 1 + (2 * latitudinalLines + 1) * longitudinalLines;  // using a GL_LINE_STRIP

    vertices = new vec4[numVertices];
    colors = new vec4[numVertices];
    normals = new vec4[numVertices];
    vec4 black(0,0,0,1);
    float phiDelta = M_PI / latitudinalLines;
    float thetaDelta = M_PI / longitudinalLines;
    float phi;
    float theta;
    int vertexIndex = 0;


    for (int i=0 ; i < latitudinalLines; i++) //set latitudinal line vertices
    {
        phi = M_PI / 2 - i * phiDelta;
        for (int j = 0; j < 2 * longitudinalLines; j++)
        {
            theta = 0 + j * thetaDelta;
            vertices[vertexIndex] = vec4(radius * cos(phi) * cos(theta), radius * sin(phi), radius * cos(phi) * sin(theta), 1.0);
            vertexIndex++;
        }
        vertices[vertexIndex] = vec4(radius * cos(phi), radius * sin(phi), 0.0, 1.0);
        vertexIndex++;
    }
    vertices[vertexIndex] = vec4(0.0, -radius, 0.0, 1.0); //needed to get to "south" pole
    vertexIndex++;

    for (int l = 0; l < longitudinalLines; l++) //set longitudinal line vertices
    {
        theta = 0 + l * thetaDelta;
        for (int m = 0; m < 2 * latitudinalLines; m++)
        {
            phi = -M_PI / 2 + m * phiDelta;
            vertices[vertexIndex] = vec4(radius * cos(phi) * cos(theta), radius * sin(phi), radius * cos(phi) * sin(theta), 1.0);
            vertexIndex++;
        }
        vertices[vertexIndex] = vec4(0, -radius, 0, 1.0);
        vertexIndex++;
    }

    ///*
    vertices[vertexIndex] = (vertices[0] + vertices[latitudinalLines * (2 * longitudinalLines + 1)]) / 2;
    int centerIndex = vertexIndex;
    vertexIndex = 0;



    for (int i=0 ; i < latitudinalLines; i++) //set latitudinal line vertices
    {
        phi = M_PI / 2 - i * phiDelta;
        for (int j = 0; j < 2 * longitudinalLines; j++)
        {
            theta = 0 + j * thetaDelta;
            normals[vertexIndex] = vertices[vertexIndex] - vertices[centerIndex];
            vertexIndex++;
        }
        normals[vertexIndex] = vertices[vertexIndex] - vertices[centerIndex];
        vertexIndex++;
    }
    normals[vertexIndex] = vertices[vertexIndex] - vertices[centerIndex];
    vertexIndex++;

    for (int l = 0; l < longitudinalLines; l++) //set longitudinal line vertices
    {
        theta = 0 + l * thetaDelta;
        for (int m = 0; m < 2 * latitudinalLines; m++)
        {
            phi = -M_PI / 2 + m * phiDelta;
            normals[vertexIndex] = vertices[vertexIndex] - vertices[centerIndex];
            vertexIndex++;
        }
        normals[vertexIndex] = vertices[vertexIndex] - vertices[centerIndex];
        vertexIndex++;
    }
    //*/
}

//@deletes an instance of Core
//@pre: Core exists
//@post: Core doesn't exist
Core::~Core()
{
    delete[] vertices;
    //delete[] normals;
    delete[] colors;
}

//@copies a Core
//@pre: other exists
//@post: Core identical to other is created
//@param: Core other
//@usage: Core myCore(otherCore);
Core::Core(const Core& other)
{
    for (int i=0; i < numVertices; i++)
    {
        vertices[i]=other.vertices[i];
        //normals[i] = other.normals[i];
        colors[i]=other.colors[i];
    }
    numVertices = other.numVertices;
}

//@sets a Core equal to another
//@pre: rhs Core and this Core exist
//@post: this Core is equal to rhs
//@param: Core rhs
//@usage: myCore = rhsCore;
Core& Core::operator=(const Core& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;

    for (int i=0; i < numVertices; i++)
    {
        vertices[i]=rhs.vertices[i];
        //normals[i] = rhs.normals[i];
        colors[i]=rhs.colors[i];
    }
    numVertices = rhs.numVertices;
}

//@calls functions necessary to rasterize the Core
//@pre: Core exists
//@post: Core is ready to be displayed
//@param: GLint _vao, GLint program
//@usage: createVAO(vao, program);
/*
void
Core::createVAO(GLint _vao, GLint program )
{
    vao = _vao;
    glBindVertexArray( vao );
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    int csize = sizeof((*vertices))* numVertices;
    glBufferData( GL_ARRAY_BUFFER, 2*csize,
                  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, csize, *vertices );
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
*/

void
Core::createVAO(GLint _vao, GLint program )
{
    vao = _vao;
    glBindVertexArray( vao );
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    int csize = sizeof(*vertices) * numVertices;
    //cout << "Cube csize " << csize << "\n";
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

//@draws the Core
//@pre: Core exists
//@post: Core has been drawn
//@usage: myCore.draw();
void Core::draw() {
    glBindVertexArray( vao );
    glLineWidth(1.0);
    glDrawArrays( GL_LINE_STRIP, 0, numVertices );
    glBindVertexArray( 0 );
}
