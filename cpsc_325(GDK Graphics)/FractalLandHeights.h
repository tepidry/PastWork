//data object: a two-dimensional grid of heights for a fractal landscape
//operations: constructors, destructor, make the terrain, print heights,
//            get the height for the ith row and jth column


#ifndef FRACTALLANDHEIGHTS_H
#define FRACTALLANDHEIGHTS_H


#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

#include "Angel.h"


class FractalLandHeights
{
    public:
        //creates a default grid of 8 by 8 and generates heights
        FractalLandHeights();

        //creates a grid of a desired size and generates heights
        //pre s is assigned
        //post grid is 2^s by 2^s with heights generated
        FractalLandHeights(int s);

        //releases memory for the grid
        virtual ~FractalLandHeights();

        //generates the heights for the fractal landscape
        //pre grid exists
        //post heights at grid points are generated
        //usage land.makeTerrain();
        void makeTerrain();

        //prints the heights at each grid point
        //pre grid exists
        //post heights are printed
        //usage land.printHeights();
        void printHeights();

        //get the height at grid row i and grid column j
        //pre i and j are assigned
        //post if i and j are in the correct range
        //        returns the height at row i and column j
        //     else reassigns i and j to correct range and
        //        returns the height at reassigned values
        //usage height = getHeight(2,3);
        float getHeight(int i, int j) ;

        //data member for the grid of heights
        GLfloat *heights;

        //data member for the size of the grid
        int gridSize;
    protected:
    private:

        int index(int row, int col) ;
        float getRand(int inc);
        void scaleHeights();
        vec4 getColor(float ht);
};

#endif // FRACTALLANDHEIGHTS_H
