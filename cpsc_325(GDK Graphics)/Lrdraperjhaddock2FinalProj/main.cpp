//edited by:    Jamie Haddock, Ryan Draper
//file:         main.cpp
//date:         December 4 2012

//description: The game ZAG Shooter uses classes MatrixXtack, Shapes, BBallCourt, Basketball, and ScoreBoard to simulate the act of shooting a basketball.
//             Just you and the ball take your time breathe and shoot.  move side to side and line your shot up otherwise you'll miss
//             ZagShooter will also keep Score for you from 0 - 9 on the scoreboard.


// Displays a car at the origin. The purpose of this program is to add a light source
// to naviation capabilities - "fly through"  or "Maya controls - tumble, dolly, track.

#include "Angel.h"
#include <iostream>
using namespace std;

#include "MatrixStack.h"
#include "Shapes.h"
#include "BBallCourt.h"
#include "Basketball.h"
#include "ScoreBoard.h"
#include "FractalLandHeights.h"
#include "FractalLandShape.h"

#include <cmath>

//********  These are available as extern variables in Globals.h **************
GLuint  projection; // projection matrix uniform shader variable location
GLuint  model_view;  // model-view matrix uniform shader variable location
GLuint  model_color;  // model-view matrix uniform shader variable location

GLuint program;  // shader programs

MatrixStack mvMatrixStack;  // stores the movel view matrix stack

//********  End extern variables in Globals.h **************
BBallCourt court;
Basketball myBasketball;
ScoreBoard myScore;
Shapes shapes;
FractalLandShape land(7, 6, 1);

vec4 light_position(10, 20, -8, 1);
vec4 lightStart = light_position;

// Camera projection transformation parameters
GLfloat  fovy = 100.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;

// Camera location and orientation parameters
vec4 eyeStart = vec4(0.0, 5.0, 4.0, 1.0);
vec4 eye = eyeStart; // camera location
vec4 VPN(0,.5,1,0);  // used as starting value for setting uvn
vec4 VUP(0,1,0,1);  // used as starting value for setting uvn

mat4 viewRotation;  // rotational part of matrix that transforms between World and Camera coordinates
vec4 tumblePoint;

mat4 moveRotation;
mat4 shootRotation;
mat4 ident; //identity matrix used to reset the transformation matrices

float dist;
float spin = 0;
float xChange = 0;
float yChange = 0;
float d = 11; // fixed distance of tumble point in front of camera

int timer;
int startTimer = 100;
int toggle = 0;
int sCount = 0;
int moveCount = 0;
int dribbleCount = 0;
int dribbleDirection = -1;
int score = 0;
int xStart = 0.0, yStart = 0.0;

bool birdsEye = false;

// For controlling Mouse Actions:
enum  actions { DRIBBLE, SIDETOSIDE, ROTATE };
GLint   action;

void lightSetUp();
void idle();

//---------------------------------------------------------------------------- printControls

//prints the controls for you including if your animation or birds eye view is toggled for you
//pre Controls are not printed in the command line
//post Controls are printed in the command line
//usage printControls();
void printControls()
{
    cout << endl;
    cout << "********************************************************************************" << endl;
    cout << "*                             Welcome to ZagShooter!                           *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                       Play as John Stockton or Courtney                      *" << endl;
    cout << "*                        Vandersloot in  this three-point                      *" << endl;
    cout << "*                         drill! Score 9 buckets to win.                       *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "********************************************************************************" << endl;
    cout << endl;
    cout << "**********************************  Controls  **********************************" << endl;
    cout << "                             Left mouse: slide left or right" << endl;
    cout << "                           Middle mouse: toggle player pause" << endl;
    cout << "                            Right mouse: rotate left or right" << endl;
    cout << "                                      D: dribble" << endl;
    cout << "                                      S: shoot" << endl;
    cout << "                                      T: toggle animations" << endl;
    cout << "                                      C: celebrate!" << endl;
    cout << "                                      R: reset shot" << endl;
    cout << "                                      B: toggle birds-eye view" << endl;
    cout << endl;
    if (toggle == 0)
        cout << "Animations: Off" << endl;
    else
        cout << "Animations: On" << endl;
    if (birdsEye)
        cout << "Birds-Eye View: On -- toggle off to play" << endl;
    else
        cout << "Birds-Eye View: Off"<< endl;


}

void printWin(){
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*              Congratulations! You have won!!! Play again?                    *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "*                                                                              *" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    cout << "********************************************************************************" << endl;
    sleep(1);
}

// calculate u, v, n from VPN and VUP and puts them into the view Rotation matrix
//pre VPN is a approximation of n and VUP is an approximation of v
//post u,v, and n are all unit vectors that work as the cameras x, y, and z
//usage calUVN(VPN, VUP);
void calcUVN(vec4 VPN, vec4 VUP)
{
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

    program = InitShader( "/home/GONZAGA/rdraper/Desktop/Ada/Lrdraperjhaddock2FinalProj/vshader53.glsl", "//home/GONZAGA/rdraper/Desktop/Ada/Lrdraperjhaddock2FinalProj/fshader53.glsl" );  // gouraud shading

    glUseProgram( program );

    // Uniform variables: color and viewing parameters
    model_color = glGetUniformLocation( program, "model_color" );
    model_view = glGetUniformLocation( program, "model_view" );
    projection = glGetUniformLocation( program, "projection" );

    lightSetUp();
    myBasketball.createVAO(program);
    shapes.createVAO(program);
    land.createVAO(program);

    glUniform4fv( model_color, 1,vec4(1,1,1,1) ); // set color to white initially

    glLineWidth(1);
    glEnable( GL_DEPTH_TEST );
    glClearColor( 0.5, 0.5, 0.5, 1.0 );
    printControls();
    cout << "Shooter Pause: On -- press middle mouse button to toggle off" << endl;
}

//initialize light color, and ambient, specular and diffuse properties based on the Phong model
void lightSetUp()
{
    // Initialize shader lighting parameters

    vec4 light_ambient( 1.0, 1.0, 1.0, 1.0 );
    vec4 light_diffuse( 1.5, 1.5, 1.5, 1.0 );
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

//__________________________________________________________________-
//sets the location of the basketball relative to the camera and allows certain actions to be done to that basketball to simulate the game
//pre basketball does not exit in view plane
//post basketball is a set distance from the camera and the hoop
//param mv
//usage tranformDrawBasketball(mv);
void transformDrawBasketball(mat4& mv){
    mvMatrixStack.pushMatrix(mv);

    tumblePoint =   eye - dist * viewRotation[2];
    tumblePoint[3] = 1;

    mv = mv * Translate(tumblePoint -vec4(0,0,4, 1)) * shootRotation
            * Translate(-(tumblePoint - vec4(0,0, 4, 1)));
    mv = mv * Translate(eye) * moveRotation * Translate(-eye);
    mv = mv * Translate(yChange * viewRotation[1]);
    mv = mv * Translate(eye.x, eye.y - 7, eye.z-4);
    mv = mv * RotateX(-spin);
    mv = mv * RotateZ(90);
    mv = mv * Scale(1.2,1.2,1.2);

    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    myBasketball.drawBasketball();
    mv = mvMatrixStack.popMatrix();
}

//puts the BBallcourt into the viewMatrix and allows it to be placed seperate from the eye in world coordinates so that the camer and ball may move seperately in relation
//pre BBallcourt is not drawn in the view plane but it does exist
//post BBallcourt is created in the view plane
//param mv
//usage transformDrawCourt(mv);
void transformDrawCourt(mat4& mv){
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0, 5, 7);
    mv = mv * Translate(eye) * moveRotation * Translate(-eye);
    glUniformMatrix4fv(model_view, 1, GL_TRUE, mv);
    court.drawBBallCourt(mv);
    mv = mvMatrixStack.popMatrix();
}

//This makes the scoreboard attatched to the upper right corner of the camera allowing you to view your score at all times
//pre Scoreboard exists but is not created in the view plas
//post Scoreboard exists and has been created in the view plas
//param mv
//usage drawScoreboard(mv);
void drawScoreboard(mat4& mv){
    glUniformMatrix4fv(model_view, 1, GL_TRUE, mv);
    myScore.drawScoreBoard(mv);
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


    drawScoreboard(mv);

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate( light_position );
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    mv = mvMatrixStack.popMatrix();

    vec4 lightInEye_position = mv * light_position;  // translate to eye position for shader calculation
    glUniform4fv( glGetUniformLocation(program, "LightPosition"), 1, lightInEye_position );
    mv =  viewRotation * Translate( -eye );

    transformDrawBasketball(mv);


    transformDrawCourt(mv);

    glBindVertexArray( 0 );
    glutSwapBuffers();
}

//used to reset the camera, the ball and certain global variables that keep track  of the location of the ball relative to the camera and the rim
//pre the ball exists in the world yet in a location
//post the ball exists in the world in the preset default location
//usage reset();
void reset(){
    birdsEye = false;
    dist = 0;
    xChange = 0;
    yChange = 0;
    sCount = 0;
    moveCount = 0;
    spin = 0;
    moveRotation = ident;
    shootRotation = ident;
    eye = eyeStart; // camera location
    calcUVN(VPN,VUP);
    xStart = 0.0;
    yStart = 0.0;
    light_position = lightStart;
    glutKeyboardFunc( NULL );
    printControls();
    cout << "Shooter Pause: On -- press middle mouse button to toggle off" << endl;
}

//transforms the ball to simulate dribbling up and down with the press of the 'd' button
//pre the ball is between 2 points on the y axis in the world
//post the ball then moves up and down between these two point depending which direction it was moving before
//usage dribble();
void dribble(){
    shootRotation = ident;
    sCount = 0;
        if (dribbleDirection == -1){
            yChange -= 0.5;
            dribbleCount += 1;
        }
        if (dribbleDirection == 1){
            yChange += 0.5;
            dribbleCount += 1;
        }
        if (dribbleCount == 5){
            dribbleCount = 0;
            if (dribbleDirection == 1)
                dribbleDirection -= 2;
            else
                dribbleDirection += 2;
        }
}

//Tranlates the camera in the world frame to give you a birds eye view
//pre the eye is in the default location
//post the eye is translete up on the y axis and rotated downward to view the court from a new and interesting angle
//usage birdsEyeView();
void birdsEyeView(){
    moveRotation = RotateX(40) * Translate(0, -20, 0);
    birdsEye = true;
    printControls();
    cout << "Shooter Pause: Off" << endl;
}

//sets the variable to control the idle function so that the small amount of animation can be turned on or off
//pre the toggle is either on or off and the glut function idle is set to null or the idle
//post the toggle is either on or off and the glut function idle is set to null or the idle
//usage toggleCelebration();
void toggleCelebration(){
    toggle = (toggle + 1) % 2;
    if(toggle == 0)
    {
        glutIdleFunc(NULL);
    } else {
        glutIdleFunc(idle);
    }
    printControls();
    cout << "Shooter Pause: Off" << endl;
}

//In context to the camera the ball will rotate about the center point between the camera and the rim
//it will also rotate to simulate a shot as it rotate positively about the x axis
//pre the ball exists
//posts the ball exists and the is closer to the hoop unless you have made or missed the basket at which point it will reset
//param dy
//      rx
//      y
//usage shoot(dy, rx, y);
void shoot(float dy, mat4 rx, int x, int y){
    yChange = 0;
    spin -= 25;
    if (sCount < 26){
        dy -= 0.5;
        rx = RotateX(10 * dy);
        shootRotation = shootRotation * rx;

        dist = 0.5 * sqrtf(4 * (d * d) + xChange * xChange);
        tumblePoint =   eye - dist * viewRotation[2];
        tumblePoint[3] = 1;
        xStart = x;
        yStart = y;
        sCount += 1;
    }

    else{
        if (abs(moveRotation[2][0] * 2 * dist - xChange) <= 0.7){
            if (sCount < 29){ //allows the ball to go into the basket before incrementing the score if the ball is within the radius of the rim
                dy = -0.5;
                rx = RotateX(10*dy);
                shootRotation = shootRotation * rx;

                dist = 0.5 * sqrtf(4 * (d * d) + xChange * xChange);
                tumblePoint =   eye - dist * viewRotation[2];
                tumblePoint[3] = 1;
                xStart = x;
                yStart = y;
                sCount += 1;
            }
            else{
                score = (score + 1) % 10;
                if (score == 9)
                {
                    printWin();
                }
                myScore.addPointToScore();
                startTimer = 0;
                usleep(500000);
                reset();

            }
        }
        else{
            usleep(500000);
            reset();
        }
    }
}

//this will move the eye's location either left or right depending on the mouses action
//pre camera exists in the world
//post dx is updated as your increas the left and right distances from the origin point
//param x
//      y
//      dx
//usage slide(x, y, dx);
void slide(GLint x, GLint y, float dx){
    if(sCount == 0){
        if (moveCount >= -160 && moveCount <= 160){
            dx = -0.05 * (x - xStart);
            xChange = xChange + dx;

            eye = eye + dx * viewRotation[0];
            eye[3]=1;
        }
        moveCount = moveCount + (x - xStart);
        xStart = x;
        yStart = y;
    }

    else{
       reset();
    }
}



//---------------------------------------------------------------------------- keyboard

void
keyboard( unsigned char key, int x, int y )
{
    float dy;
    mat4 rx;

    switch( key )
    {
    case 'b':
        if (not birdsEye){
             birdsEyeView();
        }
        else{
            reset();
        }
        break;
        case 't':
            toggleCelebration();
            break;
        case 'c':
            startTimer = 0;
            break;
        case 's':
            if (not birdsEye){
               shoot(dy, rx, x ,y);
            }
            break;
        case 'd':
            if (not birdsEye)
                dribble();
            break;
        case 'r':     // reset
            reset();
            break;

    }

    glutPostRedisplay();
}

//---------------------------------------------------------------------------- mouse
//The mouse is used to control the eyes location and free the keyboard to shoot and dribble
//pre world exists and you can control the player 's view
//post the players view is in a new location
//param button
//      state
//      x
//      y
//usage glutMouseFunc( mouse );
void
mouse( GLint button, GLint state, GLint x, GLint y )
{
    static GLint buttons_down = 0;

    if (state == GLUT_DOWN)
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            action = SIDETOSIDE;
            xStart = x;
            yStart = y;
            break;
        case GLUT_MIDDLE_BUTTON:
            glutKeyboardFunc( keyboard );
            printControls();
            cout << "Shooter Pause: Off" << endl;
            break;
        case GLUT_RIGHT_BUTTON:
            action = ROTATE;
            xStart = x;
            yStart = y;
            break;
        }
    }
}

//keeps track and rotates the ball with the camera according to the mouse about the Y-axis
//pre camera is in a location
//post the camera has been rotated about the Y-axis
//param x
//      y
//      dx
//usage pivot(x, y, dx);
void pivot(GLint x, GLint y, float dx){
    if(sCount == 0){
        dx = 0.1 * (x - xStart);

        moveRotation = RotateY(dx) * moveRotation;

        eye[3] =
        1;
        xStart = x;
        yStart = y;
    }
    else{
        reset();
    }
}

//used to control the players view according to the mouse movement
//pre the players view is in the view plan
//post the players view has been moved in the view plane either left or right or rotated about the Y-axis
//param x
//      y
//usage glutMotionFunc( motion );
void motion( GLint x, GLint y )
{
    float dx, dy;
    mat4 ry, rx;

    switch (action)
    {

        case SIDETOSIDE:
            if (not birdsEye){
                slide(x, y, dx);
            }
            break;

        case ROTATE:
            if (not birdsEye){
                pivot(x, y, dx);
            }
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

//blinking light
void idle()
{
    if( startTimer < 10)
    {
        timer++;
        timer = timer % 50;
    }

    if (timer == 25 && startTimer < 10)
    {
        startTimer++;
        light_position[1] -= 20;
        court.highlightBoard(true);
    }
    if (timer == 0 && startTimer < 10)
    {
        startTimer++;
        light_position[1] += 20;
        court.highlightBoard(false);
    }

    glutPostRedisplay();
}


//---------------------------------------------------------------------------- main
int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 1000, 1000 );
    glutInitWindowPosition(512,0);
    glutCreateWindow( "ZagShooter" );

    glewInit();

    init();

    glutDisplayFunc( display );

    glutMouseFunc( mouse );
    glutMotionFunc( motion );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}
