#ifndef STEINER_H
#define STEINER_H

#include "Angel.h"

class Steiner
{
public:
    Steiner(int rDivisions = 10, int tDivisions=10);
    virtual ~Steiner();
    Steiner(const Steiner& other);
    Steiner& operator=(const Steiner& other);

    GLint vao;
    void createVAO(GLint _vao, GLint _program );
    vec4 *points;
    vec4 *colors;
    vec4 *normals;
    int numVertices;
    void draw();
protected:
private:
    vec4 gradient(float x, float y, float z);
};

#endif // STEINER_H
