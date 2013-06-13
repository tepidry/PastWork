#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include "Camera.h"
#include "World.h"
#include "RenderEngine.h"

RenderEngine engine;

/* GLUT callback Handlers */

static void init()
{
    World *new_world_ptr = new World();
    new_world_ptr -> build();
    engine.set_world(new_world_ptr);
    engine.render_scene();
}

static void resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    Camera* c_ptr = engine.world_ptr -> camera_ptr;
    glDrawPixels(c_ptr -> hres, c_ptr -> vres, GL_RGB, GL_FLOAT, c_ptr -> image);
    glFlush();
}

int main(int argc, char *argv[])
{
    init(); // create engine, world, camera, and then generate the image

    glutInit(&argc, argv);

    Camera* c_ptr = engine.world_ptr -> camera_ptr;
    glutInitWindowSize(c_ptr -> hres, c_ptr -> vres);

    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Ray Tracer");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glClearColor(.5,.5,1,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
