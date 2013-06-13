//@ file main.cpp
//@ date Sept 9, 2012
//@ name Ryan Draper
//@ description This creates and instance of ChaosGame and plays the game 10,000 times inside a window of 600 X 500

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Vector3D.h"
#include "ChaosGame.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

ChaosGame game(600, 500);

//@ displays the pixels as set by Chaos game and passed by the method PlayGame
//@ post the pixels are set inside the 600X500 window as passed by the class ChaosGame
//@ usage glutDisplayFunc(display);
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    game.PlayGame(10000);

    glDrawPixels(game.width, game.height,GL_RGB, GL_FLOAT, game.image);
    glFlush();
}


//@ Initialzes the Window for the chaos game to be played
int main(int argc, char *argv[])
{
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitWindowSize(game.width, game.height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Chaos_Game");


    glutDisplayFunc(display);


    glClearColor(1.5,1,.5,1);

    glutMainLoop();

    return EXIT_SUCCESS;
}
