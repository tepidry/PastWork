//
// Displays a cube with different colored sides. The user can rotate around the
//    x, y, and z axis by pressing the "x" and "y" and "z" keys, or hit "r" to reset.
//  The x rotation is done first, followed by y, then z

#include "Angel.h"
#include <iostream>
using std::cout;

#include "Cube.h"

// Viewing transformation parameters
GLfloat theta = 0.0;
GLfloat phi = 0.0;
GLfloat alpha = 0.0;

Cube myCube;  // generates the vertices, colors, normals of a cube.

// Cmamera projection transformation parameters
GLfloat  fovy = 45.0;  // Field-of-view in Y direction angle (in degrees)
GLfloat  aspect;       // Viewport aspect ratio
GLfloat  zNear = 0.5, zFar = 100.0;

GLuint  projection; // projection matrix uniform shader variable location

// Camera location and orientation parameters
vec4 eye = vec4( 0.0 ,0.0, 2.0 ,1.0); // camera location
vec4  u( 1.0, 0.0, 0.0, 0.0);
vec4  v( 0.0, 1.0, 0.0, 0.0);
vec4  n( 0.0, 0.0, 1.0, 0.0 );  // camera looks along -n

GLuint  model_view;  // model-view matrix uniform shader variable location

//----------------------------------------------------------------------------
GLuint program;
// OpenGL initialization
void
init()
{
    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );

    int csize = sizeof(myCube.points);
    glBufferData( GL_ARRAY_BUFFER, 2*csize,
                  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, csize, myCube.points );
    glBufferSubData( GL_ARRAY_BUFFER, csize, csize, myCube.colors );
    // glBufferSubData( GL_ARRAY_BUFFER, 2*csize, csize, myCube.normals );

    program = InitShader( "/home/GONZAGA/rdraper/CubeFund/cpsc_325/vertex.glsl", "/home/GONZAGA/rdraper/cpsc_325/fragment.glsl" );
    glUseProgram( program );

    // set up shader variables
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(0) );

    GLuint vColor = glGetAttribLocation( program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(csize) );

    // GLuint vNormal = glGetAttribLocation( program, "vNormal" );
    // glEnableVertexAttribArray( vNormal );
    // glVertexAttribPointer( vNormal, 4, GL_FLOAT, GL_FALSE, 0,
    //		   BUFFER_OFFSET(2*csize) );

    // VIEWING PARAMETERS
    model_view = glGetUniformLocation( program, "model_view" );
    projection = glGetUniformLocation( program, "projection" );

    glEnable( GL_DEPTH_TEST );
    glClearColor( 0.5, 0.5, 0.5, 1.0 );
}

//----------------------------------------------------------------------------

void
display( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // set camera location and orientation
    vec4 t = vec4(0.0, 0.0, 0.0, 1.0);
    mat4 c = mat4(u, v, n, t);
    mat4 mv =  c * Translate( -eye );  // camera location
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    //cout << " mv = \n" << mv << "\n";

    // set camera projection parameters
    mat4  p  = Perspective( fovy, aspect, zNear, zFar );
    glUniformMatrix4fv( projection, 1, GL_TRUE, p );

    mv = mv*RotateZ(alpha);   // rotate about y axis
    mv = mv*RotateY(theta);   // rotate about y axis
    mv = mv*RotateX(phi);     // rotate about x axis
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv ); // set mtrix in shader

    glDrawArrays( GL_TRIANGLES, 0, myCube.numVertices );  //GL draws the points

    glutSwapBuffers();
}

//----------------------------------------------------------------------------

void
keyboard( unsigned char key, int x, int y )
{

    float inc = 1.0;
    switch( key )
    {
    case 033: // Escape Key
    case 'q':
    case 'Q':
        exit( EXIT_SUCCESS );
        break;

    case 'y':   // rotate around y
        theta += 5;
        break;
    case 'x':     // rotate around x  (this is always applied second)
        phi += 5;
        break;
    case 'z':     // rotate around z  (this is always applied second)
        alpha += 5;
        break;
    case 'r':     // reset
        phi = 0;
        theta = 0;
        alpha = 0;
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
    glutInitContextVersion( 3, 2 );
    glutInitContextProfile( GLUT_CORE_PROFILE );
    glutCreateWindow( "Cube Test" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );

    glutMainLoop();
    return 0;
}
