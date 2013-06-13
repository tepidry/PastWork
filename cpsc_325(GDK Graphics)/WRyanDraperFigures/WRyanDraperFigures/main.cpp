//date August 27, 2012
//file main.cpp
//description: This program draws?

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
using namespace std;

const  int WIDTH = 720;
const  int HEIGHT = 720;
GLfloat  image[HEIGHT][WIDTH][3];   // a 3-dim static array of 720 rows and 720 columns of color

/* GLUT callback Handlers */


void drawSquare(int a, int b)
{
    for(int sideRow= a; sideRow < b; sideRow++){
        for (int sideCol= a; sideCol < b; sideCol++){
            image[sideRow][sideCol][0] = 0;
            image[sideRow][sideCol][1] = 1;
            image[sideRow][sideCol][2] = 0;
        }
    }

}

void drawSquareTop_Bottom(int start, int wide)
{
    for(int sideRow = start; sideRow < wide; sideRow++){
        if (sideRow < start + 10 || sideRow  >= wide - 10){
            for (int sideCol = start; sideCol <= wide; sideCol++){
                image[sideRow][sideCol][0] = 1;
                image[sideRow][sideCol][1] = 0;
                image[sideRow][sideCol][2] = 0;
            }
        }
    }
}

void drawSquareSides(int startX, int startY, int wide)
{
    for(int sideRow = startY; sideRow <= wide - 10; sideRow++){
        for(int sideCol = startX; sideCol <= wide; sideCol++){
            if(sideCol <= startY || sideCol + 1 > wide - 10){
                image[sideRow][sideCol][0] = 1;
                image[sideRow][sideCol][1] = 0;
                image[sideRow][sideCol][2] = 0;
            }
        }
    }

}

void drawTriangle(int xStart, int yStart, int size)
{

    int count = yStart+size;
    for (int row = xStart; row < yStart+size ; row++){
        for (int col = yStart; col < count; col++) {
            image[row][col][0] = 0;  //what color is this?
            image[row][col][1] = 1;
            image[row][col][2] = 1;
        }
        count = count - (xStart/yStart);

    }
}

void drawTriangleRAdjacent(int xStart, int yStart, int size)
{
        int x = xStart +size;
        for (int row = xStart -1; row < x+2; row++)
        {
            image[row][yStart - 1][0] = 1;  //what color is this?
            image[row][yStart - 1][1] = 1;
            image[row][yStart - 1][2] = 0;
        }
}

void drawTriangleLAdjacent(int xStart, int yStart, int size)
{
        int x = yStart +size;
        for (int col = yStart -1; col < x+2; col++)
        {
            image[xStart - 1][col][0] = 1;  //what color is this?
            image[xStart - 1][col][1] = 1;
            image[xStart - 1][col][2] = 0;
        }
}

void drawOpposite(int xStart, int yStart, int size)
{
    int count = yStart+size;
    for (int row = xStart; row <= yStart+size ; row++){
        for (int col = yStart; col <= count; col++) {
            if (col == count)
            {
                image[row][col][0] = 1;  //what color is this?
                image[row][col][1] = 1;
                image[row][col][2] = 0;
            }

        }
        count = count - (xStart/yStart);

    }
}

void makeSquare()
{
    int squareStart = 70;
    int figureSize = 250;

    drawSquare(squareStart, figureSize);
    drawSquareTop_Bottom(squareStart-10, figureSize+10);
    drawSquareSides(squareStart-10, squareStart, figureSize+10);
}

void makeTriangle()
{
    int triangleStartX = 350;
    int triangleStartY =350;
    int size = 200;

    drawTriangle(triangleStartX, triangleStartY, size);
    drawTriangleRAdjacent(triangleStartX, triangleStartY, size);
    drawTriangleLAdjacent(triangleStartX, triangleStartY, size);
    drawOpposite(triangleStartX, triangleStartY, size);
}

void fillBackground()
{
    for (int row = 0; row < HEIGHT; row++) {
       for (int col = 0; col < WIDTH; col++) {
            image[row][col][0] = 0;  //what color is this?
            image[row][col][1] = 0;
            image[row][col][2] = 0;
       }
    }
}

static void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);
    fillBackground();
    makeSquare();
    makeTriangle();

    glDrawPixels(WIDTH,HEIGHT,GL_RGB, GL_FLOAT, image);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Figures");


    glutDisplayFunc(display);


    glClearColor(1.5,1,.5,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
