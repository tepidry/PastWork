//name: Ryan Draper
//
//date: Sept 5, 2012
//file main.cpp
//description: This program draws two geometric figures in a 720 by 720 pixel window; using a dynamic 3-D array to color each pixel.
//             The bottom left is a square that is 250x250 pixels.  The top left figure is a triangle that is [(200x200)/2].

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
GLfloat*  image = NULL;   // a Null pointer for the dynamic array

/* GLUT callback Handlers */


void storePixel(int row, int col, int num, GLfloat color)
{
    image[(row*3)+(col*HEIGHT*3)+num] = color;
}

}

void drawSquareTop_Bottom(int start, int wide)
{
    for(int sideRow = start; sideRow < wide; sideRow++){
        if (sideRow < start + 10 || sideRow  >= wide - 10){
            for (int sideCol = start; sideCol <= wide; sideCol++){
                storePixel(sideRow, sideCol, 0, 1);
                storePixel(sideRow, sideCol, 1, 0);
                storePixel(sideRow, sideCol, 2, 0);
            }
        }
    }
}

void drawSquareSides(int startX, int startY, int wide)
{
    for(int sideRow = startY; sideRow <= wide - 10; sideRow++){
        for(int sideCol = startX; sideCol <= wide; sideCol++){
            if(sideCol <= startY || sideCol + 1 > wide - 10){
                storePixel(sideRow, sideCol, 0, 1);
                storePixel(sideRow, sideCol, 1, 0);
                storePixel(sideRow, sideCol, 2, 0);
            }
        }
    }

}

void makeSquare()
{
    int squareStart = 70;
    int figureSize = 250;

    drawInsideSquare(squareStart, figureSize);
    drawSquareTop_Bottom(squareStart-10, figureSize+10);
    drawSquareSides(squareStart-10, squareStart, figureSize+10);
}

void drawInsideTriangle(int xStart, int yStart, int size)
{

    int count = yStart+size;
    for (int row = xStart; row < yStart+size ; row++){
        for (int col = yStart; col < count; col++) {
            storePixel(row, col, 0, 0);
            storePixel(row, col, 1, 1);
            storePixel(row, col, 2, 1);

        }
        count = count - (xStart/yStart);

    }
}

void drawTriangleRAdjacent(int xStart, int yStart, int size)
{
        int x = xStart +size;
        for (int row = xStart -1; row < x+2; row++)
        {
            storePixel(row, yStart-1, 0, 1);
            storePixel(row, yStart-1, 1, 1);
            storePixel(row, yStart-1, 2, 0);
        }
}

void drawTriangleLAdjacent(int xStart, int yStart, int size)
{
        int x = yStart +size;
        for (int col = yStart -1; col < x+2; col++)
        {
            storePixel(xStart-1, col, 0, 1);
            storePixel(xStart-1, col, 1, 1);
            storePixel(xStart-1, col, 2, 0);
        }
}

void drawOpposite(int xStart, int yStart, int size)
{
    int count = yStart+size;
    for (int row = xStart; row <= yStart+size ; row++){
        for (int col = yStart; col <= count; col++) {
            if (col == count)
            {
                storePixel(row, col, 0, 1);
                storePixel(row, col, 1, 1);
                storePixel(row, col, 2, 0);
            }

        }
        count = count - (xStart/yStart);

    }
}

void makeTriangle()
{
    int triangleStartX = 350;
    int triangleStartY =350;
    int size = 200;

    drawInsideTriangle(triangleStartX, triangleStartY, size);
    drawTriangleRAdjacent(triangleStartX, triangleStartY, size);
    drawTriangleLAdjacent(triangleStartX, triangleStartY, size);
    drawOpposite(triangleStartX, triangleStartY, size);
}

void drawInsideSquare(int start, int size)
{
    for(int sideRow= start; sideRow < size; sideRow++){
        for (int sideCol= start; sideCol < size; sideCol++){
            storePixel(sideRow, sideCol, 0, 0);
            storePixel(sideRow, sideCol, 1, 1);
            storePixel(sideRow, sideCol, 2, 0);
        }
    }
}

void fillBackground()
{
    for (int row = 0; row < HEIGHT; row++) {
       for (int col = 0; col < WIDTH; col++) {
            storePixel(row, col, 0, 0);
            storePixel(row, col, 1, 0);
            storePixel(row, col, 2, 0);
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


    image = new GLfloat[HEIGHT * WIDTH * 3]; //creates a new instance of a 3 dimensional array with

    glutCreateWindow("Figures");


    glutDisplayFunc(display);


    glClearColor(1.5,1,.5,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
