#ifndef FRACTALLANDSHAPE_H
#define FRACTALLANDSHAPE_H


#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Angel.h"
#include "FractalLandHeights.h"

#include <iostream>
using std::cout;

class FractalLandShape
{
    public:
        FractalLandShape();
        FractalLandShape(int s, float _xzscale, float _yscale);
        virtual ~FractalLandShape();
        FractalLandHeights fractalHeights;
        vec4 *points;
        vec4 *colors;
        vec4 *normals;
        int numVertices;
        float xzscale;
        float yscale;
        GLuint vao;
        void createVAO(GLint program );
        void draw();

    protected:
    private:
        int index(int row, int col) ;
        vec4 getColor(float ht);
        vec4 calcNormals(int i, int j);
        float getHeight(int i, int j);
        void makeVertices();
        vec4 *makeColors();
        vec4 *makeNormals();
};

#endif // FRACTALLANDSHAPE_H
