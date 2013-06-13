//
// Displays a car at the origin. The purpose of this program is to add a light source
// to naviation capabilities - "fly through"  or "Maya controls - tumble, dolly, track.

#include "Angel.h"
#include <iostream>

#include "FractalLandHeights.h"
#include "FractalLandShape.h"
#include "MatrixStack.h"
#include "Shapes.h"
#include "Car.h"
#include "BBallCourt.h"

//********  These are available as extern variables in Globals.h **************
GLuint  projection; // projection matrix uniform shader variable location
GLuint  model_view;  // model-view matrix uniform shader variable location
GLuint  model_color;  // model-view matrix uniform shader variable location

GLuint program;  // shader programs

MatrixStack mvMatrixStack;  // stores the movel view matrix stack

Shapes shapes;
//********  End extern variables in Globals.h **************

//Car car;
FractalLandShape land(7, 6, 1);
//BBallCourt court;

vec4 light_position(10, 20, -8, 1); // we will experiment with this position
vec4 lightStart = light_position;

// Camera projection transformation parameters
GLfloat  fovy = 100.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;

// Camera location and orientation parameters
vec4 eyeStart = vec4( 0.0 , 5.0, 4.0 ,1.0); // initial camera location
vec4 eye = eyeStart; // camera location
vec4 VPN(0,.5,1,0);  // used as starting value for setting uvn
vec4 VUP(0,1,0,1);  // used as starting value for setting uvn
mat4 viewRotation;  // rotational part of matrix that transforms between World and Camera coordinates


int timer;
int total = 100;

float alpha = 1.0;  // used to control the amount of a turn during the flythrough

// For controlling Mouse Actions:
enum  actions { TUMBLE, TRACK, DOLLY };
GLint   action;
int     xStart = 0.0, yStart = 0.0;
int t = 0;    // toggles the tumble point between the origin and fixed distance (d) from eye. Starts out at origin
float d = 30; // fixed distance of tumble point in front of camera

void lightSetUp();

//---------------------------------------------------------------------------- printControls

void printControls()
{
    cout << "\n\n************  Controls **************" << "\n";
    cout << "q or Q ............ quit" << "\n";
    cout << "l or L ............ move light around" << "\n";
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
    cout << "Middle Mouse dhttp://www.google.com/rag . zoom in/out" << "\n";
    cout << "Left Mouse drag ... tumble about origin or white cube" << "\n";
    cout << "t ................. toggles the tumble point between origin and fixed distance"  << "\n";
    cout << "                    in front of camera. Starts at origin." << "\n";
}

// calculate u, v, n from VPN and VUP
void calcUVN(vec4 VPN, vec4 VUP)
{
    //  NEED TO IMPLEMENT !http://www.google.com/!!
    // Be careful when doing matrix and vector operations with homogenous coordinates
    // For example, to cross two *vectors* (not points) stored as vec4's and to save result in a vec4 requires following:
    // a = vec4(cross(b,c),0);

    vec4 n = normalize(VPN);
    vec4 u = vec4(cross(VUP,n),0);
    u = normalize(u);
    vec4 v = vec4(cross(n,u),0);
    viewRotation = mat4(u,v,n,vec4(0,0,0,1));
}

//---------------------------------------------------------------------------- init
// OpenGL initialization
void
init()
{
    calcUVN(VPN, VUP);

    // program = InitShader( "vertex.glsl", "fragment.glsl" );    // no  shading
    program = InitShader( "/ada/rdraper/CarLightingProj/vshader53.glsl", "/ada/rdraper/CarLightingProj/fshader53.glsl" );  // gouraud shading
    //program = InitShader( "vShader56.glsl", "fShader56.glsl" );  // phong shading
    glUseProgram( program );
    // Uniform variables: color and viewing parameters

    model_color = glGetUniformLocation( program, "model_color" );
    model_view = glGetUniformLocation( program, "model_view" );
    projection = glGetUniformLocation( program, "projection" );

    lightSetUp();

    shapes.createVAO(program);
    land.createVAO(program);
    //court.createVAO(program);

    glUniform4fv( model_color, 1,vec4(1,1,1,1) ); // set color to white initially

    glLineWidth(1);
    glEnable( GL_DEPTH_TEST );
    glClearColor( 0.5, 0.5, 0.5, 1.0 );
    printControls();
}

void lightSetUp()
{
    // Initialize shader lighting parameters

    vec4 light_ambient( 1.0, 1.0, 1.0, 1.0 );
    vec4 light_diffuse( 1.0, .0, .0, 1.0 );
    vec4 light_specular( 1.0, 1.0, 1.0, 1.0 );

//  These are set to gray because the colors are set elsewhere.  One can use these as a
//  way of specifying ka, kd, and ks
    vec4 material_ambient( .4, .4, .4, 1.0 );
    vec4 material_diffuse( 1, 1, 1, 1.0 );
    vec4 material_specular( 0.8, 0.8, 0.8, 1.0 );
    float  material_shininess = 100.0;

    vec4 ambient_product = light_ambient * material_ambient;
    vec4 diffuse_product = light_diffuse * material_diffuse;
    vec4 specular_product = light_specular * material_specular;

    glUniform4fv( glGetUniformLocation(program, "AmbientProduct"),
                  1, ambient_product );
    glUniform4fv( glGetUniformLocation(program, "DiffuseProduct"),
                  1, diffuse_product );
    glUniform4fv( glGetUniformLocation(program, "SpecularProduct"),
                  1, specular_product );

    glUniform4fv( glGetUniformLocation(program, "LightPosition"),
                  1, light_position );

    glUniform1f( glGetUniformLocation(program, "Shininess"),
                 material_shininess );
}

//---------------------------------------------------------------------------- drawAxes
// Draw coordinate axes - x is red, y is green, and z is blue
void drawAxes(mat4 &mv)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Scale(.1,30,.1);
    mv = mv * Translate(0,.5,0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1,vec4(0,1,0,1) );
    shapes.myCylinder.draw();               // y axis
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * RotateX(-90);
    mv = mv * Scale(.1,30,.1);
    mv = mv * Translate(0,.5,0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1,vec4(0,0,1,1) );
    shapes.myCylinder.draw();   // z axis
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * RotateZ(-90);
    mv = mv * Scale(.1,30,.1);
    mv = mv * Translate(0,.5,0);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    glUniform4fv( model_color, 1,vec4(1,0,0,1) );
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


    // Set the View matrix which controls the camera orientation and location
    mvMatrixStack.loadIdentity();


    glUniformMatrix4fv(model_view, 1, GL_TRUE, mv);

    //court.drawBBallCourt(mv);

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate( light_position );
    //glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    //shapes.drawCube(vec4(2, 2, 0, 1));   // draw a cube at the light position
    mv = mvMatrixStack.popMatrix();

    vec4 lightInEye_position = mv * light_position;  // translate to eye position for shader calculation

    glUniform4fv( glGetUniformLocation(program, "LightPosition"),
                  1, lightInEye_position );

    mv =  viewRotation * Translate( -eye );

    vec4 color(2,1,0,1);
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,-2, 0);
    mv = mv * Scale(2,2,2);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    //shapes.drawCube(color);
    land.draw();
    mv = mvMatrixStack.popMatrix();



    //drawAxes(mv); // draw coordinate axis that are centered at the origin of the World Coordinate System.

    // Draw the car
    //car.drawCar(mv);
    // End: car

    // Draw the ground
    //mv = mv * Translate(0, -.1, 0);
    //mv = mv * Scale(20, .2, 20);
    //glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    //shapes.drawCube(vec4(.6, .4, .3, 1));http://www.google.com/
    // End: ground
    //mv = mv * Scale(6, 6, 6);

    //shapes.drawSteiner(vec4(1,0,0,1));
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
    case 'h':

        break;
    case 'Q':
        exit( EXIT_SUCCESS );
        break;
    case 'n':     //increase light's x position
        light_position[0] += 2;
        break;
    case 'm':     //decrease light's x position
        light_position[0] -= 2;
        break;

    case 'j':     //increase light's y position
        light_position[1] += 2;
        break;
    case 'k':     //decrease light's y position
        light_position[1] -= 2;
        break;
       // decrease light's z position
    case 'u':               //decrease light's z position
        light_position[2] += 2;
        break;
    case 'i':
        light_position[2] -= 2;
       // decrease light's z position
        break;
    case 'f':     // drive car forward
        //car.wheelAngle += 5;
        //car.xLoc -= 2*M_PI*2.*5/360.;
        break;
    case 'b':     // drive car forward
        total = 0;
        //car.wheelAngle -= 5;
        //car.xLoc += 2 * M_PI * 2.0 * 5 / 360.0;
        break;
    case 't':     // toggle tumblepoint
        t = (t + 1) % 2;
        break;
    case 'r':     // reset
        t = 0;  // tumble point at origin
        //car.wheelAngle = 0;
        //car.xLoc = 0;
        eye = eyeStart; // camera location
        calcUVN(VPN,VUP);
        xStart = 0.0;
        yStart = 0.0;
        light_position = lightStart;
        break;
    }

    glutPostRedisplay();
}
//---------------------------------------------------------------------------- keySpecial
void
keySpecial( int key, int x, int y )
{
    switch( key )  // all rotations down in camera frame. Note the pre multiplication
    {
    case GLUT_KEY_UP:   // rotate around u
        viewRotation = RotateX(alpha) * viewRotation;
        break;
    case GLUT_KEY_DOWN:     // rotate around u
        viewRotation = RotateX(-alpha) * viewRotation;
        break;
    case GLUT_KEY_LEFT:     // rotate around v
        viewRotation = RotateY(-alpha) * viewRotation;
        break;
    case GLUT_KEY_RIGHT:
        viewRotation = RotateY(alpha) * viewRotation;
        break;
    case GLUT_KEY_HOME: // forward
        eye = eye - alpha * viewRotation[2]; // along n
        break;
    case GLUT_KEY_END:
        eye = eye + alpha * viewRotation[2];
        break;
    case GLUT_KEY_INSERT:
        viewRotation = RotateZ(alpha) * viewRotation;
        break;
    case  GLUT_KEY_PAGE_UP :
        viewRotation = RotateZ(-alpha) * viewRotation;
        break;
    }

    glutPostRedisplay();
}

//---------------------------------------------------------------------------- mouse
void
mouse( GLint button, GLint state, GLint x, GLint y )
{
    cout << "x = " << x << endl;

    static GLint buttons_down = 0;

    if (state == GLUT_DOWN)
    {
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

//---------------------------------------------------------------------------- tumble
// tumble about to location tumblePoint in World Coordinate System.
void tumble(const mat4& rx, const mat4& ry, const vec4& tumblePoint)
{
   mat4 view  =  viewRotation * Translate( -eye );  // current view matrix

   // X Rotate about tumble point in Camera Coord Sys
   vec4 tumblePointInCameraFrame = view * tumblePoint;  // location of tumble point in cam coord
   mat4 translateBack = Translate(tumblePointInCameraFrame);
   mat4 translateToOrigin = Translate(-tumblePointInCameraFrame);
   mat4 xtransform = translateBack * rx * translateToOrigin;

   // Y Rotate about tumble point in WCS
    translateBack = Translate(tumblePoint[0],tumblePoint[1],tumblePoint[2]);
    translateToOrigin = Translate(-tumblePoint);
    mat4 ytransform = translateBack * ry * translateToOrigin;

    mat4 newView = xtransform * view * ytransform;

    viewRotation = newView; // make it purely rotational
    viewRotation[0][3] = 0;
    viewRotation[1][3] = 0;
    viewRotation[2][3] = 0;
    viewRotation[3][3] = 1;
    mat4 rotInverse = transpose(viewRotation); // now the inverse is the transpose
    eye = -(rotInverse * newView * vec4(0,0,0,1)); // - for same reason as Translate(-eye) above
}

//---------------------------------------------------------------------------- motion
void
motion( GLint x, GLint y )
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    //cout << light_position << endl;
    cout << eye << endl;
    float dx, dy;
    mat4 ry, rx;
    vec4 tumblePoint;

    switch (action)
    {
    case TUMBLE:
        dx = 0.05 * (x - xStart);
        dy = 0.05 * (y - yStart);

        ry = RotateY(10 * dx);
        rx = RotateX(10 * dy);

        // tumble about a point tumblePoint in WCS. Two options currently.
//        if (t == 0)   // tumble about origin in  WCS
//        {
//            tumblePoint =  vec4(0,0,0,1);
//        }
//        else        // tumble about fixed distance in front of camera in  WCS
//        {
            tumblePoint =   eye - 14 * viewRotation[2];
            tumblePoint[3] = 1;
        //}
        tumble(rx, ry, tumblePoint);

        xStart = x;
        yStart = y;
        break;
    case TRACK:  // PAN
        dx = -0.05 * (x - xStart);
        dy = 0.05 * (y - yStart);

        eye = eye + dx * viewRotation[0] + dy * viewRotation[1];
        eye[3]=1;
        xStart = x;
        yStart = y;
        break;
    case DOLLY:
        dy = 0.05 * (y - yStart);
        dx = 0.05 * (x - xStart);

        eye = eye - (dy + dx) * viewRotation[2];
        eye[3] =
        1;
        xStart = x;
        yStart = y;
        break;
    default:
        printf("unknown action %d\n", action);
    }

    glutPostRedisplay();
}


//---------------------------------------------------------------------------- reshape

void
reshape( int width, int height )
{
    glViewport( 0, 0, width, height );

    aspect = GLfloat(width) / height;
}

//---------------------------------------------------------------------------- main

void idle()
{
    if( total < 10)
    {
        timer++;
        timer = timer%100;
    }

    if (timer == 50 && total < 10)
    {
        total++;
        light_position[1] -= 20;
    }
    if (timer == 0 && total < 10)
    {
        total++;
        light_position[1] += 20;
    }

    glutPostRedisplay();
}

int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 512, 512 );
    glutCreateWindow( "zag shooter" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutSpecialFunc(keySpecial);
    glutMouseFunc( mouse );
    glutMotionFunc( motion );
    glutReshapeFunc( reshape );
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}
