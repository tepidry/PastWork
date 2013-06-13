//date August 27, 2012
//file main.cpp
//description: This program draws?

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

const  int WIDTH = 640;
const  int HEIGHT = 480;
GLfloat  image[HEIGHT][WIDTH][3];   // a 3-dim static array of 480 rows and 640 columns of color

/* GLUT callback Handlers */

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int row = 0; row < HEIGHT; row++) {
       for (int col = 0; col < WIDTH; col++) {
          if (row  % 2 == 0) {
             image[row][col][0] = 0;  //what color is this?
             image[row][col][1] = 0;
             image[row][col][2] = 1;

          } else {
             image[row][col][0] = 0;  //what color is this?
             image[row][col][1] = 1;
             image[row][col][2] = 0;
          }
      }
   }

    glDrawPixels(WIDTH,HEIGHT,GL_RGB, GL_FLOAT, image);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("First Stripes");


    glutDisplayFunc(display);
    glClearColor(.5,.5,1,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}

