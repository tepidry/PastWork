//   FractalLandHeights.cpp
//
//  This class uses the  diamond-square algoritm
//        See http://www.gameprogrammer.com/fractal.html#diamond
//  to generate a 2D array of heights for a fractal landscape.  The height
//  values are between 0 and 1. Use the method getH(i,j) to access
//  the heights by row and column.
//
//  The 2D array of heights is actually stored as a 1D array of GLfloats of length
//                 (gridSize+1)x(gridSize+1)
//  where gridSize must be a power of 2.  The constructor takes
//  as input s = the power of 2
//  The default is s=3, so that the default gridSize is 8=2^3, and thus the array length is 9x9
//
// The values in the 1D heights array can be accessed directly, but it is more convenient to use getH(i,j),
// which returns the height value associated with the row i and column j of the landscape.  The getH method not
// only does the conversion from the 1D array to the 2D row & colum value, but also has
// the safety feature that if i or j are out of range, it just returns the closest
// edge value.
//

// *******   SCALING AND CREATING THE WATER ********
// After the heights are initally generated using the diamond-square algorithm,
// the heights are scaled to be in the range from 0 to 1.
// All values below the "waterLevel" are then set to the waterLevel, to give the appearance of
// a flat body of water.  Then the heights are rescaled again so that they are between 0 and 1.
// This way, it is easy to create a color map: a height equal to zero is the water (e.g. blue) and
// a height equal to 1 must be a mountain top (e.g. white). The heights can, of course, be rescaled
// in the openGL program but, depending on where this is done, it is important to remember that
// the color map must also be adjusted.

#include "FractalLandHeights.h"

float waterLevel = .3;

//creates a default grid of 8 by 8  and generates heights
FractalLandHeights::FractalLandHeights()
{
    gridSize =           ;
    srand((unsigned)time(0));
    makeTerrain();
}

//creates a grid of a desired size and generates heights
//pre s is assigned
//post grid is 2^s by 2^s with heights generated
FractalLandHeights::FractalLandHeights(int s)
{
    srand((unsigned)time(0));
    if (s < 1) s = 2;     //  minimal size of grid is 4x4
    if (s > 8) s = 8;     //  maximum size of grid is s^8 = 256 (change this if you want bigger)
    gridSize =        ;   // grid size is 2^s
    makeTerrain();
}

//releases memory for the grid
FractalLandHeights::~FractalLandHeights()
{
    delete[] heights; heights = NULL;
}

// Convert a row & col value into the appropropriate one-dim index
int FractalLandHeights::index(int col, int row)
{
     return ( );
}

//generates the heights for the fractal landscape
//pre grid exists
//post heights at grid points are generated
//usage land.makeTerrain();
//Note: Uses the diamond-square algorithm to generate a fractal landscape.
//     See http://www.gameprogrammer.com/fractal.html#diamond
void
FractalLandHeights::FractalLandHeights::makeTerrain()
{
    heights = new GLfloat[ (gridSize + 1) * (gridSize + 1)];

    //initialize all heights to 0
    for (int i = 0; i <=           ; i++)
        for (int j = 0; j <=           ; j++)
            heights[          ] = 0.0;

    //set four corners to height 0.1
    heights[                     ] = 0.1;
    heights[                     ] = 0.1;
    heights[                     ] = 0.1;
    heights[                     ] = 0.1;

    int inc = gridSize;
    float x;
    while (inc > 1)
    {
        // Square Step
        for (int i = 0; i < gridSize; i = i + inc)
        {
            for (int j = 0; j < gridSize; j = j + inc)
            {

                float midpoint = (getHeight(i, j)       + getHeight(i + inc, j) +
                                  getHeight(i, j + inc) + getHeight(i + inc, j + inc)) / 4.f;
                x = getRand(inc);
                int k = i + inc / 2, m = j + inc / 2;
                heights[index(k, m)] = x + midpoint;
            }
        }

        // Diamond Step
        for (int i = 0; i < gridSize; i = i + inc)
        {
            for (int j = 0; j < gridSize; j = j + inc)
            {
                int k = i + inc / 2, m = j;
                x = getRand(inc);
                float midpoint = (getHeight(k - inc / 2, m) + getHeight(k + inc / 2, m) +
                                  getHeight(k, m + inc / 2) + getHeight(k, m - inc / 2)) / 4.f;
                heights[index(k, m)] = midpoint + x;

                k = i + inc / 2;
                m = j + inc;
                x = getRand(inc);
                midpoint = (getHeight(k - inc / 2, m) + getHeight(k + inc / 2, m) +
                            getHeight(k, m + inc / 2) + getHeight(k, m - inc / 2)) / 4.f;
                heights[index(k, m)] = midpoint + x;

                k = i;
                m = j + inc / 2;
                x = getRand(inc);
                midpoint = (getHeight(k - inc / 2, m) + getHeight(k + inc / 2, m) +
                            getHeight(k, m + inc / 2) + getHeight(k, m - inc / 2)) / 4.f;
                heights[index(k, m)] = midpoint + x;

                k = i + inc;
                m = j + inc / 2;
                x = getRand(inc);
                midpoint = (getHeight(k - inc / 2, m) + getHeight(k + inc / 2, m) +
                            getHeight(k, m + inc / 2) + getHeight(k, m - inc / 2)) / 4.f;
                heights[index(k, m)] = midpoint + x;
            }
        }
        inc = inc / 2;
    }

    scaleHeights();
   // cout << " grid size = " << gridSize << ",   heights\n" ;
   // printHeights();
}

void
FractalLandHeights::printHeights()
{
    for (int i = 0; i <= gridSize; i++)
    {
        cout << "i=" << i <<":\n";
        for (int j = 0; j <= gridSize; j++)
        {
            cout << heights[index(i,j)] << " ";
        }
        cout << "\n";
    }
}

void
FractalLandHeights::scaleHeights()
{
    // find min and max values
    float ymax = -10000, ymin = 10000;
    for (int i = 0; i <= gridSize; i++)
    {
        for (int j = 0; j <= gridSize; j++)
        {
            if (heights[index(i,j)] > ymax)
            {
                ymax = heights[index(i,j)];
            }
            else if (heights[index(i,j)] < ymin)
            {
                ymin = heights[index(i,j)];
            }
        }
    }
    //
    // scale heights so they are between 0 and 1 and then, if the height is less than the waterlevel, set the
    // height to waterlevel.  Then scale again so that the height is between 0 and  1
    // then waterLevel and 1

    for (int i = 0; i <= gridSize; i++)
    {
        for (int j = 0; j <= gridSize; j++)
        {
            float scaledValue = (heights[index(i,j)] - ymin) / (ymax - ymin);
            if (scaledValue < waterLevel)
            {
                heights[index(i,j)] = 0;
            }  else {
                heights[index(i,j)] = (scaledValue - waterLevel)/(1.0 - waterLevel);
            }
        }
    }
}

//get the height at grid row i and grid column j
//pre i and j are assigned
//post if i and j are in the correct range
//        returns the height at row i and column j
//     else reassigns i and j to correct range and
//        returns the height at reassigned values
//usage height = getHeight(2,3);
float
FractalLandHeights::getHeight(int i, int j)
{
    if (i < 0)
    {
        i = 0;
    }
    else if (i > gridSize)
    {
        i = gridSize;
    }
    if (j < 0)
    {
        j = 0;
    }
    else if (j > gridSize)
    {
        j = gridSize;
    }
    return heights[index(i,j)];
}

//generates a random number
//pre inc is assigned
//post returns a number between 0 and ___________
float
FractalLandHeights:: getRand(int inc)
{
    float r = 1.0 * rand() / RAND_MAX;
    return (float) (inc * r - inc / 2.);
}


