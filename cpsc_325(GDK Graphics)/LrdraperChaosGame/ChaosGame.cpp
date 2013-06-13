//@file ChaosGame.cpp
//@date Sept 9, 2012
//@author: Ryan Draper

// ADT ChaosGame:
//    data object a inherited array of ints that are a vector from Vector3D to set pixels on a display window and create a Sierpinski triangle
//@   data structure: a one dimensional dynamic array that is used to set the pixels in the display window which is the size of
//@                   the public data members height and width
//@   operations: creator, deconstructor, PickRandomPoint, PickRandomVertex, fillBackground, PlayGame, SetVertices, storePixel

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "ChaosGame.h"
#include <cmath>
using namespace std;


//@ creates an instance of ChaosGame
//@ post sets the image to null and the size of the window 600 x 600
//@ usage ChaosGame game;
ChaosGame::ChaosGame() :height(600), width(600)
{
    image = new GLfloat[width * height * 3];
}

//@ creates an instance of ChaosGame and sets height to _h and width
//@ post the public data member image is a new GLfloat and height and width are assigned to the incoming passed variable
//@ usage ChaosGame game(800, 800);ChaosGame::ChaosGame(int _h, int _w)
	: height(_h), width(_w)
{
    image = new GLfloat[width * height * 3];
}

//@ destroys instance of ChaosGame
//@ pre: ChaosGame exists
//@ post: ChaosGame object does not exist
//@ usage: automatically called at the end of scope
ChaosGame::~ChaosGame()
{
    delete [] image;
    image = NULL;
}

//@ chooses a random point inside of the isosceles triangle
//@ pre: ChaosGame exists
//@ post: a point is returned with a random x and y value that is inside of the vertices
//@ uses: operator<, operator=
//@ usage: point = PickRandomPoint();
Vector3D ChaosGame::PickRandomPoint()
{
    Vector3D randPoint;

    randPoint.x = (rand() % (width- 30) + 15);
    if (randPoint.x  < vertices[0].x)    //left
    {
        int count = ((randPoint.x * height) / (width / 2));
        randPoint.y = (rand() % (count  - 30) + 15);

    } else {     //right
        int inverse = abs(randPoint.x - width);
        int count = (inverse * height) / (width/ 2);
        randPoint.y = (rand() % (count  - 30) + 15);
    }
    return (randPoint);
}

//@ returns a random Vertex of the Isosceles Triangle
//@ pre: ChaosGame exists with the array vertices[] filled with three Vertex3D
//@ post: returns the random vertex that is a Vector3D
//@ usage: randomV = PickRandomVertex();
Vector3D ChaosGame::PickRandomVertex()
{
    return (vertices[(rand() % 3)]);
}

//@ finds a midpoint between two given points that are of class Vector3D
//@ pre: ChaosGame exists
//@ post: returns a Vector3D point that is in the middle of v and w
//@ uses: operator/
//@ usage: point = FindMidPoint(point, randomV);
Vector3D ChaosGame::FindMidPoint(const Vector3D& v, const Vector3D& w)
{
    return ((v + w) / 2);
}

//@ fills the background of the window for Chaos Game with black
//@ pre: Chaos Game exists and height and width are instatiated with ints
//@ post: the window exists to specified size with storePixel() filling the pixels with black for the background
//@ usage: FillBackground();
void ChaosGame::FillBackground()
{
    for (int row = 0; row < height; row++) {
       for (int col = 0; col < width; col++) {
            StorePixel(row, col, 0, 0);
            StorePixel(row, col, 1, 0);
            StorePixel(row, col, 2, 0);
       }
    }
}

//@ Plays the game ChaosGame as specified
//@ pre: ChaosGame exists
//@ post: you have a sierpinski triangle in a window that is under height and width with as many number of dots as gameNumbers + 1 entails
//@ usage: game.PlayGame(10000);
void ChaosGame::PlayGame(int gameNumber)
{
    Vector3D point, randomV;
    FillBackground();
    SetVertices();
    point = PickRandomPoint();

    for (int i = 0; i < gameNumber; i++)
    {
        StorePixel(point.y, point.x, 0, 1);
        StorePixel(point.y, point.x, 1, 1);
        StorePixel(point.y, point.x, 2, 1);
        randomV = PickRandomVertex();
        point = FindMidPoint(point, randomV);
    }
}

//@ sets vertices to three points that make a isosceles triangle inside the view window
//@ pre: ChaosGame exists
//@ post: vertices[] has three Vector3D's in it
//@ usage: SetVertices();
void ChaosGame::SetVertices()
{
    Vector3D zero((width /2), height - 15, 0.0);
    Vector3D one(width -15, 15.0,  0.0);
    Vector3D two(15.0, 15.0, 0.0);
    vertices[0] = zero;
    vertices[1] = one;
    vertices[2] = two;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            StorePixel(zero.y, zero.x, j, 1);
        }
        if (zero.x == one.x && zero.y == zero.y) {
            zero = two;
        } else {
            zero = one;
        }
    }
}

//@ sends a value to a particular pixel that specifies a particular color
//@ pre: ChaosGame exists image is a pointer to a dynamic one dimensional array size [height * width * 3]
//@ post: particular address of the array image is assigned a color by number
//@ usage: storePixel(point.y, point.x, 0, 1);
void ChaosGame::StorePixel(int row, int col, int num, GLfloat color)
{
    image[(row * width * 3) + (col * 3) + num] = color;
}
