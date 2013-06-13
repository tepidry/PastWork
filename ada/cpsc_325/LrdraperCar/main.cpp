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

vec4 eye = vec4( 0.0 ,0.0, 18.0 ,6.0); // camera location
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

    program = InitShader( "ada/rdraper/cpsc_325/LrdraperCar/vertex.glsl", "ada/rdraper/cpsc_325/LrdraperCar/fragment.glsl" );
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

//Draw the Truck Functions
//x,y,z  rotates the plane of trucks on the respective plane
//c, a, u rotates in the opposite direction of x,y,z respectively
//d makes the car drive in the direction of the positive x plane with the wheels moving as if the trucks were really moving
//b makes the cars back up on the plane
//i makes the robot arms spin
//--------------------------------------------------------------------------------------+++

//Draws the Front Part of the truck which is traslated off the origin and Scaled to the a correct size
//pre front of the truck doesn't exist
//post front of the truck does exist
//usage drawHood(mv,hoodTranslate, hoodScale, color);
void
drawHood(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Windows on the truck which is traslated off the origin and Scaled to the a correct size
//pre Windows of the truck doesn't exist
//post Windows of the truck does exist
//usage drawWindows(mv,windowTranslate, windowScale, color);
void
drawWindows(mat4& mv, vec4 translate, vec4 scale)
{
    //side windows
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x / 1.6, scale.y / 1.6, scale.z * 1.1);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(vec4(1,1,1,0.0));
    mv = mvMatrixStack.popMatrix();

    //windshield
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x - .15, translate.y - .1, translate.z) * Scale(scale.x, scale.y , scale.z * .99 );
    mv = mv * RotateZ(55);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );

    drawCube(vec4(1,1,1,0.0));
    mv = mvMatrixStack.popMatrix();
}

//Draws the Bed on the truck which is traslated off the origin and Scaled to the a correct size
//pre Bed of the truck doesn't exist
//post Bed of the truck does exist
//usage drawBed(mv,windowTranslate, windowScale, color);
void
drawBed(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    //bottom bed of truck
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, -scale.y * 2, translate.z) * Scale(scale.x, 0, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();

    //left side of bed of truck
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, scale.z / 2) * Scale(scale.x, scale.y, 0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();

    //right side of bed of truck
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, - scale.z / 2 ) * Scale(scale.x, scale.y, 0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Body on the truck which is traslated off the origin and Scaled to the a correct size
//pre Body of the truck doesn't exist
//post Body of the truck does exist
//usage drawBody(mv,windowTranslate, windowScale, color);
void
drawBody(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Wheel on the truck which is traslated off the origin and Scaled to the a correct size and Rotated 90' about the x axis and t about the z axis when the car moves
//pre Windows of the truck doesn't exist
//post Windows of the truck does exist
//usage drawWindows(mv,windowTranslate, windowScale, color);
void drawWheel(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    mv = mv * RotateX(90);
    mv = mv * RotateZ(t);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCylinder(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    mv = mv * RotateX(90);
    mv = mv * RotateZ(t);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawDisk(color);

    mv = mvMatrixStack.popMatrix();
}

//Draws the Car on the truck
//pre Car of the truck doesn't exist
//post Car of the truck does exist
//usage drawCar(mv,color);
void
drawCar(mat4& mv, vec4 color)
{
    vec4 hoodTranslate(-0.3, -0.1, 0, 0.0), hoodScale(0.3, 0.2, 0.3, 0.0);
    vec4 bodyTranslate(-0.5, -0.3, 0, 0.0), bedBodyScale(0.7, 0.2, 0.3, 0.0);
    vec4 bedTranslate(0.24, -0.3, 0, 0.0);
    vec4 wheelTranslate(.4, .5, .23, 0.0), wheelScale(.2, .2, .2, 0.0);

    drawHood(mv, hoodTranslate, hoodScale,color);
    drawWindows(mv, hoodTranslate, hoodScale);
    drawBody(mv, bodyTranslate, bedBodyScale,color);
    drawBed(mv, bedTranslate, bedBodyScale, color);
    //Rear Left
    drawWheel(mv, vec4(wheelTranslate.x,-1 * wheelTranslate.y,-1 * wheelTranslate.z, 0.0), wheelScale, vec4(1,1,1, 0.0));
    //Rear Right
    drawWheel(mv, vec4(wheelTranslate.x,-1 * wheelTranslate.y, wheelTranslate.z, 0.0), wheelScale, vec4(1,1,1, 0.0));
    //Front Right
    drawWheel(mv, vec4(-1 * wheelTranslate.x,-1 * wheelTranslate.y,-1 * wheelTranslate.z, 0.0), wheelScale, vec4(1,1,1, 0.0));
    //Front Left
    drawWheel(mv, vec4(-1 * wheelTranslate.x,-1 * wheelTranslate.y, wheelTranslate.z, 0.0), wheelScale, vec4(1,1,1, 0.0));
}
//End Draw the Truck Functions
//--------------------------------------------------------------------------------------+++

//i will make the robots arms spin in amazement
//Draw the Robot Functions
//--------------------------------------------------------------------------------------+++

//Draws the Robotbody is traslated off the origin and Scaled to the a correct size
//pre body of the robot doesn't exist
//post body of the robot does exist
//usage drawRobotBody(mv,Translate, Scale, color);
void
drawRobotBody(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the RobotLegs is traslated off the origin and Scaled to the a correct size
//pre legs of the robot doesn't exist
//post legs of the robot does exist
//usage drawRobotLegs(mv,Translate, Scale, color);
void
drawRobotLegs(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, -1 * translate.y, -1 * translate.z) * Scale(scale.x, scale.y, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, -1 *translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Robotarms is traslated off the origin and Scaled to the a correct size and rotate about the y axis if the 'i' key is pressed
//pre arms of the robot doesn't exist
//post arms of the robot does exist
//usage drawRobotArms(mv,Translate, Scale, color);
void
drawRobotArms(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, translate.z) * Scale(scale.x, scale.y, scale.z);
    mv = mv * RotateY(RoboY);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(translate.x, translate.y, -1 * translate.z) * Scale(scale.x, scale.y, scale.z);
    mv = mv * RotateY(RoboY);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Robot head is traslated off the origin and Scaled to the a correct size
//post head of the robot does exist
//usage drawRobotHead(mv,Translate, Scale, color);
void
drawRobotHead(mat4& mv, vec4 translate, vec4 scale, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(.3, 0.25, 0) * Scale(.07, .07, .07);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawCube(color);
    mv = mvMatrixStack.popMatrix();
}

//Draws the Robot
//pre the robot doesn't exist
//post the robot does exist
//usage drawRobot(mv, color);
void
drawRobot(mat4& mv,vec4 color)
{

    vec4 bodyTranslate(.3, 0, 0, 0.0), bodyScale(.2, .3, .2, 0.0);
    vec4 legTranslate(.3, 0.3, 0.1, 0.0), legArmScale(.07, .2, .07, 0.0);
    vec4 armTranslate(.3, 0.25, .15, 0.0);
    vec4 headTranslate(.3, 0.25, 0), headScale(.07, .07, .07);



    drawRobotBody(mv, bodyTranslate, bodyScale, color);
    drawRobotLegs(mv, legTranslate, legArmScale, color);
    drawRobotArms(mv, armTranslate, legArmScale, color);
    drawRobotHead(mv, headTranslate, headScale, color);
}
//End Draw the Robot Functions
//--------------------------------------------------------------------------------------+++


void
display( void )
{
    // clear the color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // calculate camera prescape key is 033 arrow keysojection parameters:
    mat4  p  = Perspective( fovy, aspect, zNear, zFar );
    // set the value of the projection matrix uniform variable for current shader program:
    glUniformMatrix4fv( projection, 1, GL_TRUE, p );
    // initialize the modelview matrix stack
    mvMatrixStack.loadIdentity();
    // calculate view transformations:  camera location and orientation -
    mat4 mv = LookAt( eye, at, vup );  //


    // calculate model transformations -sn
    mv = mv * Translate(t, 0, 0);   //key t
    mv = mv * RotateZ(alpha);   // rotate about z axis
    mv = mv * RotateY(theta);   // rotate about y axis
    mv = mv * RotateX(phi);     // rotate about x axis

    // save the current modelview matrix on the stack
    vec4 color;
    vec4 color2(0,1,0, 0.0);

    for (double i = -20; i <= 20; i += 2)
    {
        for (double j = -20; j <= 20; j += 2)
        {
            color = vec4(i - j, -i - j, -j - i, 0.0);
            mvMatrixStack.pushMatrix(mv);
            mv = mv * Translate(i, 0, j);
            drawCar(mv, color);
            drawRobot(mv, color2);

            mv = mvMatrixStack.popMatrix();
        }
    }


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
        break;
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
    glutCreateWindow( "Moving The Robot" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}


