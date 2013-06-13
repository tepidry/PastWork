//Edited by Ryan Draper
//October 23, 2012
//file LrdraperCar

//
// Displays a robot riding in the bed of a truck.  the Colors are seperated into 4 different regions byt the cartesian plane. The user can rotate around the
//    x and y axis by pressing the "x", "y" and 'z' keys, or hit "r", 'q', and 'esc' to reset.  And the reverse Respectively with c, u, a
//    The truck will drive forward on the negative x axis direction with 'd' and back with 'b' the wheels will turn as you do this; correctly.

#include "Angel.h"
#include <iostream>
using std::cout;

#include "Cube.h"
#include "WireCube.h"
#include "Disk.h"
#include "WireDisk.h"
#include "Cylinder.h"
#include "WireCylinder.h"

#include "MatrixStack.h"

// Viewing transformation parameters
GLfloat theta = 0.0;
GLfloat phi = 0.0;
GLfloat alpha = 0.0;
GLfloat t = 0.0;
GLfloat RoboY = 0.0;

Cube myCube;  // generates the vertices, colors, normals of a cube.
WireCube myWireCube;

Disk myDisk(24,1.0);
WireDisk myWireDisk(24,1.0);

Cylinder myCylinder(24, 1.0, 0.5);
WireCylinder myWireCylinder(24, 1.0, 0.5);

// Camera projection transformation parameters
GLfloat  fovy = 45.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;

GLuint  projection; // projection matrix uniform shader variable location

// Camera location and orientation parameters

vec4 eye = vec4( 0.0 ,0.0, 6.0 ,2.0); // camera location
vec4  at( 0.0, 0.0, 0.0, 0.0 );
vec4  vup( 0.0, 1.0, 0.0, 0.0);

GLuint  model_view;  // model-view matrix uniform shader variable location
GLuint  model_color;  // model-view matrix uniform shader variable location

MatrixStack mvMatrixStack;  // stores the model view matrix stack

//----------------------------------------------------------------------------
GLuint program;
// OpenGL initialization
void
init()
{

    program = InitShader( "/ada/rdraper/cpsc_325/LrdraperCar/vertex.glsl", "/ada/rdraper/cpsc_325/LrdraperCar/fragment.glsl" );
    glUseProgram( program );

    // Uniform variables: color and viewing parameters
    model_color = glGetUniformLocation( program, "model_color" );
    model_view = glGetUniformLocation( program, "model_view" );
    projection = glGetUniformLocation( program, "projection" );

    // Create multiple vertex array objects
    GLuint vao[10];                                                                       //an Array of objects
    glGenVertexArrays( 10, vao );

    //********  Create the VAOs ************//

    myCube.createVAO(vao[0],program);
    myWireCube.createVAO(vao[1],program);
    myDisk.createVAO(vao[2],program);
    myWireDisk.createVAO(vao[3],program);
    myDisk.createVAO(vao[4],program);
    myWireDisk.createVAO(vao[5], program);
    myDisk.createVAO(vao[6],program);
    myWireDisk.createVAO(vao[7],program);
    myCylinder.createVAO(vao[8],program);
    myWireCylinder.createVAO(vao[9], program);

    glUniform4fv( model_color, 1,vec4(1,1,1,1) ); // set color to white initially

    glLineWidth(4);
    glEnable( GL_DEPTH_TEST );
    glClearColor( 0.5, 0.5, 0.5, 1.0 );
}

// draws solid cube and wire cube together. The wire color is always black
void drawCube(vec4 color)
{
    glUniform4fv( model_color, 1, color );
    myCube.draw();
    glUniform4fv( model_color, 1, vec4(0,0,0,1) );
    myWireCube.draw();
}

// draws solid Disk and wire Disk together. The wire color is always black
void drawDisk(vec4 color)
{
    glUniform4fv( model_color, 1,color );
    myDisk.draw();
    glUniform4fv( model_color, 1,vec4(0,0,0,1) );
    myWireDisk.draw();
}

// draws solid Cylinder and wire Cylinder together. The wire color is always black
//pre scene camera and an instance of Cylinder class exists
//post Cylinder is drawn
//usage myCylinder.drawCylinder(color);
void drawCylinder(vec4 color)
{
    glUniform4fv( model_color, 1,color );
    myCylinder.draw();
    glUniform4fv( model_color, 1,vec4(0,0,0,1) );
    myWireCylinder.draw();
}


void
drawRotationAxes(mat4& mv)
{
    glUniform4fv( model_color, 1, vec4(0, 1, 1, 0));
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv);
    glBegin(GL_LINE_STRIP);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(2.5, 1.5, 1.5);
    glEnd();
}

void
display( void )
{
    // clear the color and depth buffersglBegin(GL_LINES);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(50.0f, 50.0f, 50.0f);
glEnd();
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // calculate camera prescape key is 033 arrow keysojection parameters:
    mat4  p  = Perspective( fovy, aspect, zNear, zFar );
    // set the value of the projection matrix uniform variable for current shader program:
    glUniformMatrix4fv( projection, 1, GL_TRUE, p );
    // initialize the modelview matrix stack
    mvMatrixStack.loadIdentity();
    // calculate view transformations:  camera location and orientation -
    mat4 mv = LookAt( eye, at, vup );  //


    drawRotationAxes(mv);


    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(.5, .5, .5);

    mv = mv * mat4(1, 0, 0, 0, 0, 1/sqrt(2), -1/sqrt(2), 0, 0, 1/sqrt(2), 1/sqrt(2), 0, 0, 0, 0, 1);
    mv = mv * mat4(1/sqrt(5), 0, -2/sqrt(5), 0, 0, 1, 0, 0, 2/sqrt(5), 0, 1/sqrt(5), 0, 0, 0, 0, 1);
    mv = mv * RotateZ(phi);
    mv = mv * RotateY(-63.47);
    mv = mv * mat4(1, 0, 0, 0, 0, 1/sqrt(2), 1/sqrt(2), 0, 0, -1/sqrt(2), 1/sqrt(2), 0, 0, 0, 0, 1);


    mv = mv * Scale(.5, .5, .5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(vec4(0.0, 1.0, 0.0, 0.0));

    mv = mvMatrixStack.popMatrix();



    glBindVertexArray( 0 );
    glutSwapBuffers();
}

//----------------------------------------------------------------------------


void
keyboard( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 033: // Escape Key
    case 'q':
    case 'Q':
        exit( EXIT_SUCCESS );
        break;
    case 'i': //move lauren around
        RoboY += 5;
        break;
    case 'd': //move lauren around
        t -= 0.1;
        break;glBegin(GL_LINES);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(50.0f, 50.0f, 50.0f);
glEnd();
    case 'b':
        t += 0.1;
        break;
    case 'y':   // rotate around y
        theta += 5;
        break;
    case 'u':   // rotate around y
        theta -= 5;
        break;
    case 'x':     // rotate around x  (this is always applied second)
        phi += 5;
        break;
    case 'c':
        phi -= 5;
        break;
    case 'z':     // rotate around z  (this is always applied second)
        alpha += 5;
        break;
    case 'a':
        alpha -= 5;
        break;
    case 'r':     // resetglBegin(GL_LINES);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(50.0f, 50.0f, 50.0f);
glEnd();
        phi = 0;
        theta = 0;
        alpha = 0;
        t = 0;
        break;
    }

    glutPostRedisplay();
}


//----------------------------------------------------------------------------

void
reshape( int width, int height )
{
    glViewport( 0, 0, width, height );

    aspect = GLfloat(width)/height;
}

//----------------------------------------------------------------------------

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );

   // glutInitContextVersion( 3, 2 );
  //  glutInitContextProfile( GLUT_CORE_PROFILE );
    glutCreateWindow( "Moving The Robot" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}


