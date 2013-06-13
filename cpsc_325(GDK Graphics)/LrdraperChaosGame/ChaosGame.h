//@file ChaosGame.h
//@date Sept 9, 2012
//@author: Ryan Draper

// ADT ChaosGame:
//    data object a inherited array of ints that are a vector from Vector3D to set pixels on a display window

#ifndef __Chaos_Game__
#define __Chaos_Game__
#include <iostream>
#include "stdlib.h"
#include "Vector3D.h"

using namespace std;


class ChaosGame {

   public:

        GLfloat* image ;
        int height, width;

   public:

    //@ creates an instance of ChaosGame
    //@ post sets the image to null and the size of the window 600 x 600
    //@ usage ChaosGame game;
    ChaosGame();

    //@ creates a window using the GLfloat image that is set to height as _h and width _w
    //@ post the window is filled in with the method fillBackground to the color specified in fillBackground
    //@ usage ChaosGame game(800, 800);
    ChaosGame(int _h, int _w);

    //@ destroys ChaosGame
    //@ pre: ChaosGame exists
    //@ post: ChaosGame object does not exist
    //@ usage: automatically called at the end of scope
    ~ChaosGame ();

    //@ chooses a random point inside of the isosceles triangle
    //@ pre: ChaosGame exists
    //@ post: a point is returned with a random x and y value that is inside of the vertices
    //@ uses: operator<, operator=
    //@ usage: point = PickRandomPoint();
    Vector3D PickRandomPoint();

    //@ returns a random Vertex of the Isosceles Triangle
    //@ pre: ChaosGame exists with the array vertices[] filled with three Vertex3D
    //@ post: returns the random vertex that is a Vector3D
    //@ usage: randomV = PickRandomVertex();
    Vector3D PickRandomVertex();

    //@ finds a midpoint between two given points that are of class Vector3D
    //@ pre: ChaosGame exists
    //@ post: returns a Vector3D point that is in the middle of v and w
    //@ uses: operator/
    //@ usage: point = FindMidPoint(point, randomV);
    Vector3D FindMidPoint(const Vector3D& v, const Vector3D& w);

    //@ fills the background of the window for Chaos Game with black
    //@ pre: Chaos Game exists and height and width are instatiated with ints
    //@ post: the window exists to specified size with storePixel() filling the pixels with black for the background
    //@ usage: fillBackground();
    void FillBackground();

    //@ Plays the game ChaosGame as specified
    //@ pre: ChaosGame exists
    //@ post: you have a sierpinski triangle in a window that is under height and width with as many number of dots as gameNumbers + 1 entails
    //@ usage: game.PlayGame(10000);
    void PlayGame(int gameNumber);

    //@ sets vertices to three points that make a isosceles triangle inside the view window
    //@ pre: ChaosGame exists
    //@ post: vertices[] has three Vector3D's in it
    //@ usage: SetVertices();
    void SetVertices();

    //@ sends a value to a particular pixel that specifies a particular color
    //@ pre: ChaosGame exists image is a pointer to a dynamic one dimensional array size [height * width * 3]
    //@ post: particular address of the array image is assigned a color by number
    //@ usage: storePixel(point.y, point.x, 0, 1);
    void StorePixel(int row, int col, int num, GLfloat color);

    private:

        Vector3D vertices[3];
};

#endif // CHAOSGAME_H_INCLUDED
