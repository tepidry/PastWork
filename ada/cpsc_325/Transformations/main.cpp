//
// Displays          with different colored triangle regions. The user can rotate around the
//    x and y axis by pressing the "x" and "y" keys, or hit "r" to reset.

#include "Angel.h"
#include <iostream>
using std::cout;

#include "Cube.h"
#include "WireCube.h"
#include "Disk.h"
#include "WireDisk.h"

#include "MatrixStack.h"

// Viewing transformation parameters
GLfloat theta = 0.0;
GLfloat phi = 0.0;
GLfloat alpha = 0.0;
GLfloat t = 0.0;

Cube myCube;  // generates the vertices, colors, normals of a cube.
WireCube myWireCube;

Disk myDisk(24,1.0);
WireDisk myWireDisk(24,1.0);

// Camera projection transformation parameters
GLfloat  fovy = 45.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;

GLuint  projection; // projection matrix uniform shader variable location

// Camera location and orientation parameters

vec4 eye = vec4( 0.0 ,0.0, 3.0 ,1.0); // camera location
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

    program = InitShader( "/ada/rdraper/cpsc_325/Transformations/vertex.glsl", "/ada/rdraper/cpsc_325/Transformations/fragment.glsl" );
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
    myDisk.createVAO(vao[8],program);
    myWireDisk.createVAO(vao[9], program);

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


//----------------------------------------------------------------------------

void
display( void )
{
    // clear the color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // calculate camera projection parameters:
    mat4  p  = Perspective( fovy, aspect, zNear, zFar );
    // set the value of the projection matrix uniform variable for current shader program:
    glUniformMatrix4fv( projection, 1, GL_TRUE, p );
    // initialize the modelview matrix stack
    mvMatrixStack.loadIdentity();
    // calculate view transformations:  camera location and orientation -
    mat4 mv = LookAt( eye, at, vup );  //
    // calculate model transformations -sn
    mv = mv * Translate(t, 0, t);   //key t


    //mv = mv * RotateZ(alpha);   // rotate about z axis
    mv = mv * RotateY(theta);   // rotate about y axis
    //mv = mv * RotateX(phi);     // rotate about x axis

    // save the current modelview matrix on the stack
    mvMatrixStack.pushMatrix(mv);                              //Above this is the transformation for all of Laurne


    //tranformations for the body ->
    mv - mv * Translate (0, 0.25, 0);
    mv = mv * Scale(0.5, 1, 0.5);

    //mv = mv * Scale(.5, .2, .5);
       // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    // draw the cube - the parameter is the cube color
    drawCube(vec4(1,0,1,1));                                            //cabin of Car

    mv = mvMatrixStack.popMatrix();  //backs up
    // save the current modelview matrix on the stack
    mvMatrixStack.pushMatrix(mv);

    //Transformations for the head


    mv = mv * Translate(0, 0.75, 0);
    mv = mv * RotateY(phi);  //xkey and c
    mv = mv * RotateZ(alpha);  //z and a key

    mv = mv * RotateX(90);
    mv = mv * Scale(0.25, 0.25, 0.25);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawDisk(vec4(0,0,1,1));                                            //body of Car
    mv = mvMatrixStack.popMatrix();  //backs up

    /*
    //mv = mv * Translate(0, -.3, 0) * Scale(.8, .4, .5);
       // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    // draw the cube - the parameter is the cube color
    drawCube(vec4(1,0,1,1));                                            //body of Car
    mv = mvMatrixStack.popMatrix();  //backs up

    mvMatrixStack.pushMatrix(mv);

    // append a translation (along x) onto the  modelview matrix
    mv = mv * Translate(-.2,-.5,.27) * Scale(.2, .2, .2);     //translates on unit of the x axis. //Scale from origin
    mv = mv * RotateX(90);
    //mv = mv * Scale(.5, .5, .5);
    // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    // draw the cylinder - the parameter is the cylinder color
    drawDisk(vec4(0,1,1,1) );

    // retreive the modelview matrix previously stored on the stack
    mv = mvMatrixStack.popMatrix();
    mvMatrixStack.pushMatrix(mv);
    // append a translation (along -x) onto the  modelview matrix
    mv = mv * Translate(.2,-.5,.27) * Scale(.2, .2, .2);

    // draw the disk
    // append a rotation (about x) onto the  modelview matrix
    mv = mv * RotateX(90);
    // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv ); // set matrix in shader
    // draw the disk - the parameter is the disk color
    drawDisk(vec4(0,1,1,1) );

    mv = mvMatrixStack.popMatrix();
    mvMatrixStack.pushMatrix(mv);

    // append a translation (along x) onto the  modelview matrix
    mv = mv * Translate(-.2,-.5,-.27) * Scale(.2, .2, .2);     //translates on unit of the x axis. //Scale from origin
    mv = mv * RotateX(90);
    //mv = mv * Scale(.5, .5, .5);
    // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    // draw the cylinder - the parameter is the cylinder color
    drawDisk(vec4(0,1,1,1) );

    // retreive the modelview matrix previously stored on the stack
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    // append a translation (along x) onto the  modelview matrix
    mv = mv * Translate(.2,-.5, -.27) * Scale(.2, .2, .2);     //translates on unit of the x axis. //Scale from origin
    mv = mv * RotateX(90);
    //mv = mv * Scale(.5, .5, .5);
    // set the value of the modelview matrix uniform variable for current shader program:
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    // draw the cylinder - the parameter is the cylinder color
    drawDisk(vec4(0,1,1,1) );*/

    // retreive the modelview matrix previously stored on the stack
    //mv = mvMatrixStack.popMatrix();

    // unbind the current vertex array buffer
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
    case 't': //move lauren around
        t += 0.1;
        break;
    case 'g':
        t -= 0.1;
        break;
    case 'y':   // rotate around y
        theta += 5;
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
    case 'r':     // reset
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
    glutCreateWindow( "Transformations" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}
