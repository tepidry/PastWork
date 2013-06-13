#ifndef CUBE_H
#define CUBE_H

#include "Angel.h"

class Cube
{
    public:
        Cube();
        Cube(const Cube& other);
        Cube& operator=(const Cube& rhs);

        virtual ~Cube();
        vec4 points[36]; //holds vertices for each point
        vec4 colors[36];
        vec4 normals[36];
        int numVertices;
    protected:
    private:
        void quad( int a, int b, int c, int d , int col, int norm);
        void colorcube();
};

#endif // CUBE_H
