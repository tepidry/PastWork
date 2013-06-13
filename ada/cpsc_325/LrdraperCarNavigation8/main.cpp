//name Ryan Draper rdraper
//date Nov. 13, 2012
//file main.cpp
//Project LrdraperCarNavigation8

// Displays a car at the origin. The purpose of this program is to demonstate
//    naviation capabilities - "fly through"  or "Maya controls - tumble, dolly, track.

#include "Angel.h"
#include <iostream>
using namespace std;

#include "MatrixStack.h"
#include "Shapes.h"
#include "Car.h"

//********  These are available as extern variables in Globals.h **************
GLuint  projection; // projection matrix uniform shader variable location
GLuint  model_view;  // model-view matrix uniform shader variable location
GLuint  model_color;  // model-view matrix uniform shader variable location
GLuint program;  // shader program

MatrixStack mvMatrixStack;  // stores the movel view matrix stack

Shapes shapes;
//********  End extern variables in Globals.h **************

Car car;

// Camera projection transformation parameters
GLfloat  fovy = 45.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;
bool f;
// Camera location and orientation parameters
vec4 eyeStart = vec4( 0.0 ,20.0, 30.0 ,1.0); // initial camera location
vec4 eye = eyeStart; // initial camera location - used when reseting parameters
vec4 VPN(0, 0.5, 1,0);  // used as starting value for setting uvn and the viewRotation
vec4 VUP(0, 1, 0, 1);  // used as starting value for setting uvn and the viewRotation
mat4 viewRotation;  // rotational part of matrix V that transforms between World and Camera coordinates

float alpha = 1.0;  // used to control the amount of a turn during the flythrough

// For controlling Mouse Actions:
enum  actions { TUMBLE, TRACK, DOLLY };
GLint   action;
int     xStart = 0.0, yStart = 0.0;
int t = 0;    // toggles the tumble point between the origin and fixed distance (d) from eye. Starts out at origin
float d = 30; // fixed distance of tumble point in front of camera

//---------------------------------------------------------------------------- printControls

void printControls()
{
    cout << "\n\n************  Controls **************" << "\n";
    cout << "q or Q ............ quit" << "\n";
    cout << "f ................. move car forward" << "\n";
    cout << "b ................. move car backward" << "\n";
    cout << "r ................. reset parameters" << "\n";
    cout << "Up arrow .......... turn up" << "\n";
    cout << "Down arrow ........ turn down" << "\n";
    cout << "Right arrow ....... turn right" << "\n";
    cout << "Insert key ........ roll left" << "\n";
    cout << "Page Up ........... roll right" << "\n";
    cout << "Home key .......... move camera forward" << "\n";
    cout << "End key ........... move camera backward" << "\n";
    cout << "Right Mouse drag .. pan up/down/left/right" << "\n";
    cout << "Middle Mouse drag . zoom in/out" << "\n";
    cout << "Left Mouse drag ... tumble about origin or white cube" << "\n";
    cout << "t ................. toggles the tumble point between origin and fixed distance"  << "\n";
    cout << "                    in front of camera. Starts at origin." << "\n";
}

// calculate viewRotation from VPN and VUP using orthogonal camera frame u, v, n
//pre: VPN (View Plane Normal) and VUP (approximate up vector) are assigned
//post assigns global viewRotation matrix which is the rotation part of the V matric
//usage calcUVN(VPN, VUP);
void calcUVN(const vec4& VPN, const vec4& VUP)
{
    //a = vec4(cross(b,c),0);
    vec4 n = normalize(VPN);
    vec4 u = normalize(vec4(cross(VUP, VPN), 0));
    vec4 v = vec4(cross(n, u), 0);


    viewRotation = mat4(u, v, n, vec4(0,0,0,1));
}

//---------------------------------------------------------------------------- init
// OpenGL initialization
void
init()
{
    calcUVN(VPN, VUP);

    program = InitShader( "/home/GONZAGA/rdraper/Desktop/Ada/LrdraperCarNavigation8/vertex.glsl", "/home/GONZAGA/rdraper/Desktop/Ada/LrdraperCarNavigation8/fragment.glsl" );
    glUseProgram( program );
    // Uniform variables: color and viewing parameters
    model_color = glGetUniformLocation( program, "model_color" );
    model_view = glGetUniformLocation( program, "model_view" );
    projection = glGetUniformLocation( program, "projection" );

    shapes.createVAO(program);

    glUniform4fv( model_color, 1,vec4(1,1,1,1) ); // set color to white initially

    glLineWidth(1);
    glEnable( GL_DEPTH_TEST );
    glClearColor( 0.5, 0.5, 0.5, 1.0 );
    printControls();
}

//---------------------------------------------------------------------------- drawAxes
// Draw coordinate axes - x is red, y is green, and z is blue
//pre mv has been assigned
//post vm has been changed as necessary to draw the axes but is left as its original matrix
//usage drawAxes(mv);
void drawAxes(mat4 &mv)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Scale(.1, 30, .1);
    mv = mv * Translate(0,.5, 0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1,vec4(0, 1, 0, 1) );
    shapes.myCylinder.draw();               // y axis
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * RotateX(-90);
    mv = mv * Scale(.1,30,.1);
    mv = mv * Translate(0, .5, 0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1, vec4(0, 0, 1, 1) );
    shapes.myCylinder.draw();   // z axis
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv *RotateZ(-90);
    mv = mv * Scale(.1, 30, .1);
    mv = mv * Translate(0, .5, 0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1, vec4(1, 0, 0, 1) );
    shapes.myCylinder.draw();   // x axis
    mv = mvMatrixStack.popMatrix();
}

//---------------------------------------------------------------------------- display

void
display( void )
{
    // clear the color and depth buffers
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // calculate and set camera projection parameters:
    mat4  p  = Perspective( fovy, aspect, zNear, zFar );
    glUniformMatrix4fv( projection, 1, GL_TRUE, p );

    mat4 mv;  // modelview matrix

    // Draw a cube which is *always* a distance d in front of the camera.
    // This cube is for reference only.  TUMBLE rotations can be about this point.
    // Do you see why the cube needs to be drawn *before* we move and orient the camera (i.e. before the View is set).
    mv = mv * Translate(0, 0, -d);
    glUniformMatrix4fv( model_view, 1, GL_TRUE,mv  );http://www.google.com/
    shapes.drawCube(vec4(1, 1, 1, 1));
    drawAxes(mv);  // draw coordinate axis that are centered on the reference cube
    // End: reference cube

    // Set the View matrix which controls the camera orientation and location
    mvMatrixStack.loadIdentity();

    // SET THE CAMERA VIEW MATRIX:
    //  NEED TO IMPLEMENT !!!  Initialize mv with V = view matrix
    //mv =  V = viewRotation times EyeTranslation
    mv = viewRotation * Translate(-eye);


    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    drawAxes(mv); // draw coordinate axis that are centered at the origin of the World Coordinate System.

    // Draw the car
    car.drawCar(mv);
    // End: car

    // Draw the groundhttp://www.google.com/
    mv = mv  *Translate(0, -.1, 0);
    mv = mv  *Scale(20, .2, 20);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(vec4(.6, .4, .3, 1));
    // End: ground

    glBindVertexArray( 0 );
    glutSwapBuffers();
}

//---------------------------------------------------------------------------- keyboard

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
    case 'f':     // drive car forward
        car.wheelAngle += 5;
        car.xLoc -= 2 * M_PI * 2.0 * 5/360.0;
       break;
    case 'b':     // drive car backward
        car.wheelAngle -= 5;
        car.xLoc += 2 * M_PI * 2.0 * 5 / 360.;
        break;
    case 't':     // toggle tumblepoint
        t = (t + 1) % 2;
        break;

    case 'r':     // reset
        t = 0;  // tumble point at origin
        car.wheelAngle = 0;
        car.xLoc = 0;
        eye = eyeStart; // camera location
        calcUVN( VPN, VUP);
        xStart = 0.0;
        yStart = 0.0;
        break;
    }

    glutPostRedisplay;
}

//---------------------------------------------------------------------------- keySpecial
void
keySpecial( int key, int x, int y )
{
    switch( key )
    {
    case GLUT_KEY_UP: // rothttp://www.google.com/ate around x
        //  cout << " you pressed  up \n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateX(-alpha) * viewRotation;
        break;
    case GLUT_KEY_DOWN:     // rotate around x  (this is always applied second)
        //  cout << " you pressed  down \n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateX(alpha) * viewRotation;
        break;
    case GLUT_KEY_LEFT:     // rotate around z  (this is always applied second)
        //   cout << " you pressed  left \n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateY(-alpha) * viewRotation;
        break;
    case GLUT_KEY_RIGHT:
        //   cout << " you pressed  right\n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateY(alpha) * viewRotation;
        break;
    case GLUT_KEY_HOME: // forward
        //   cout << " you pressed  forward\n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        //viewRotation = Translate(0,0,alpha) * viewRotation;
        eye = eye - alpha * viewRotation[2];
        break;
    case GLUT_KEY_END:
        //  cout << " you pressed  backward\n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        //viewRotation = Translate(0,0,-alpha) * viewRotation;
        eye = eye + alpha * viewRotation[2];
        break;
    case GLUT_KEY_INSERT:
        //   cout << " you pressed bank left \n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateZ(-alpha) * viewRotation;
        break;
    case  GLUT_KEY_PAGE_UP :
        //  cout << " you pressed bank right\n";
        //  NEED TO IMPLEMENT !!!   Update eye and/or viewRotation...
        viewRotation = RotateZ(alpha) * viewRotation;
        break;
    }

    glutPostRedisplay();
}

//---------------------------------------------------------------------------- mouse
void
mouse( GLint button, GLint state, GLint x, GLint y )
{
    static GLint buttons_down = 0;
    cout << "in mouse" << endl;
    cout << "x = " << x << " y = " << y << endl;
    if (state == GLUT_DOWN)
    {
        // cout << "mouse: button = " << button << "  state = " << state << "  x,y = " << x << "," << y << "\n";

        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            // cout << "     mouse: GLUT_LEFT_BUTTON - TUMBLE\n";
            action = TUMBLE;
            xStart = x;
            yStart = y;
            break;
        case GLUT_MIDDLE_BUTTON:
            //  cout << "     mouse: GLUT_MIDDLE_BUTTON - DOLLY\n";
            action = DOLLY;
            xStart = x;
            yStart = y;
            break;
        case GLUT_RIGHT_BUTTON:
            //  cout << "     mouse: GLUT_RIGHT_BUTTON - TRACK\n";
            action = TRACK;
            xStart = x;
            yStart = y;
            break;
        }
    }
    if (state == GLUT_UP)
    {
        // printControls();
    }
}

//DOESN'T WORK :(
//---------------------------------------------------------------------------- tumble
// tumble about to location tumblePoint in World Coordinate System.
//It will pitch around the world frame or the tumble point
//pre world exists and either tumble point is assigned to origin or the distance from tumble point
//post camera will move around object or world coordinates orgin
//usage tumble(rx, ry, tumblePoint);
//DOESN'T WORK :(
void tumble(const mat4& rotateXAxis, const mat4& rotateYAxis, const vec4 tumblePoint)
{
    mat4 view = viewRotation;
    mat4 newView;
    mat4 xTransform;
    mat4 yTransform;

    yTransform = Translate(tumblePoint) * rotateYAxis * Translate(- tumblePoint);
    xTransform = Translate(tumblePoint) * rotateXAxis * Translate(- tumblePoint);

    newView = xTransform * view * yTransform;
    cout << "old = " << newView << endl;
    mat4 newViewRotationPartInverse = transpose(newView);
    newViewRotationPartInverse[3] = vec4(0,0,0,1);
    cout << "newViewR = " << newViewRotationPartInverse << endl;
    eye = (-1 * newViewRotationPartInverse) * newView * vec4(0,0,0,1);
    newView[3] = vec4(0,0,0,1);
    viewRotation = transpose(newViewRotationPartInverse);
}

//---------------------------------------------------------------------------- motion
void
motion( GLint x, GLint y )
{
    float dx, dy;
    mat4 ry, rx;
    vec4 tumblePoint;
    cout << "in motion" << endl;
    cout << "x = " << x << " y = " << y << endl;
    switch (action)
    {
    case TUMBLE:
        dx = 0.05 * (x - xStart);
        dy = 0.05 * (y - yStart);

        ry = RotateY(10 * dx);
        rx = RotateX(10 * dy);

        // tumble about a point tumblePoint in WCS. Two options currently.
        if (t == 0)   // tumble about origin in  WCS
        {
            tumblePoint =  vec4(0,0,0,1);
        }
        else        // tumble about fixed distance in front of camera in  WCS
        {
            tumblePoint =   eye - d * viewRotation[2];
            tumblePoint[3] = 1;
        }

        tumble(rx, ry, tumblePoint);   //  <----  NEED TO IMPLEMENT this method!!!

        xStart = x;
        yStart = y;
        break;

    case TRACK:  // PAN
        dx = -0.05 * (x - xStart);
        dy = 0.05 * (y - yStart);
         //  NEED TO IMPLEMENT !!!  Update eye same as HOME and END buttons!!
         //     Both x and y will do the motion use both

        eye = eye - (dx) * viewRotation[0];
        eye = eye - (dy) * viewRotation[1];


        xStart = x;
        yStart = y;
        break;

    case DOLLY:
        dy = 0.05 * (y - yStart);
        dx = 0.05 * (x - xStart);
         //  NEED TO IMPLEMENT !!!  Update eye and/or viewRotation...

        eye = eye - dx * viewRotation[2];
        eye = eye - dy * viewRotation[2];

        xStart = x;
        yStart = y;
        break;

    default:
        printf("unknown action %d\n", action);
    }http://www.google.com/

    glutPostRedisplay();
}


//---------------------------------------------------------------------------- reshape

void
reshape( int width, int height )
{
    glViewport( 0, 0, width, height );

    aspect = GLfloat(width)/height;
}

//---------------------------------------------------------------------------- main

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    //glutInitContextVersion( 3, 2 );
    //glutInitContextProfile( GLUT_CORE_PROFILE );
    glutCreateWindow( "Camera Navigation" );http://www.google.com/

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutSpecialFunc(keySpecial);
    glutMouseFunc( mouse );
    glutMotionFunc( motion );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}
