#include "FractalLandShape.h"


FractalLandShape::FractalLandShape()
    : fractalHeights(3), xzscale(4), yscale(1)
{
    makeVertices();  // parameters are scaling along xz and y axes
    normals = makeNormals();      // needed for lighting calculations in shaders
    colors = makeColors();
}

FractalLandShape::FractalLandShape(int s, float _xzscale, float _yscale)
    : fractalHeights(s),xzscale(_xzscale), yscale(_yscale)
{
    makeVertices();  // parameters are scaling along xz and y axes
    normals = makeNormals();      // needed for lighting calculations in shaders
    colors = makeColors();
}

FractalLandShape::~FractalLandShape()
{
    delete[] points; points = NULL;
    delete[] normals; normals = NULL;
    delete[] colors; colors = NULL;
}

float
FractalLandShape::getHeight(int i, int j)
{
    return fractalHeights.getHeight(i,j);



    }

void
FractalLandShape::makeVertices()
{
    // we want the entire grid to be width and length xzs
    float dxzscale = xzscale / (fractalHeights.gridSize);
    numVertices = ____ * fractalHeights.gridSize * fractalHeights.gridSize; // number of vertices - each grid square is __ triangles, __ vertices/triangle.
    points = new vec4[numVertices];
    float t = xzscale / 2.;
    int Index = 0;
    for (int i = 1; i <= fractalHeights.gridSize; i++)
    {
        for (int j = 1; j <= fractalHeights.gridSize; j++)
        {
            points[Index++] =  vec4((i - 1 )* dxzscale - t, yscale * (getHeight((i - 1),j)), j      * dxzscale - t, 1);
            points[Index++] =  vec4( i      * dxzscale - t, yscale * (getHeight(i,(j - 1))),(j - 1) * dxzscale - t, 1);
            points[Index++] =  vec4( i      * dxzscale - t, yscale * (getHeight(i, j)     ), j      * dxzscale - t, 1);

            points[Index++] =  vec4((i - 1) * dxzscale - t, yscale * (getHeight((i - 1), j     )), j       * dxzscale - t, 1);
            points[Index++] =  vec4((i - 1) * dxzscale - t, yscale * (getHeight((i - 1),(j - 1)) ),(j - 1) * dxzscale - t,1);
            points[Index++] =  vec4( i      * dxzscale - t, yscale * (getHeight(i,      (j - 1)) ),(j - 1) * dxzscale - t,1);
        }
    }

  /*  cout << "numVertices = " << numVertices << ",    points:\n";
    for (int i=1; i < numVertices; i++)
    {
            cout << points[i]  << "   ";
            if (i % 3 == 2) cout << "\n";
    }*/
}


vec4 *
FractalLandShape::makeColors()
{
    colors = new vec4[numVertices]; //Each poly has 4 vertices. Each vertex has 4 floating point coordinates.

    vec4 red   = vec4( 1.0, 0.0, 0.0, 1.0 );
    vec4 blue  = vec4( 0.0, 0.0, 1.0, 1.0 );
    vec4 green = vec4( 0.0, 1.0, 0.0, 1.0 );

    int Index = 0;
    for (int i = 1; i <= fractalHeights.gridSize; i++)
    {
        for (int j = 1; j <= fractalHeights.gridSize; j++)
        {
            colors[Index++] =  getColor( getHeight(i - 1, j    ));
            colors[Index++] =  getColor( getHeight(i    , j - 1));
            colors[Index++] =  getColor( getHeight(i    , j    ));

            colors[Index++] =  getColor( getHeight(i - 1, j    ));
            colors[Index++] =  getColor( getHeight(i - 1, j - 1));
            colors[Index++] =  getColor( getHeight(i    , j - 1));
        }
    }
    return colors;
}

vec4 *
FractalLandShape::makeNormals()
{
    normals = new vec4[numVertices]; //Each poly has 4 vertices. Each vertex has 4 floating point coordinates.

    int Index = 0;
    for (int i=1; i <= fractalHeights.gridSize; i++)
    {
        for (int j=1; j <= fractalHeights.gridSize; j++)
        {
            normals[Index++] =  calcNormals(i - 1, j    );
            normals[Index++] =  calcNormals(i    , j - 1);
            normals[Index++] =  calcNormals(i    , j    );

            normals[Index++] =  calcNormals(i - 1, j    );
            normals[Index++] =  calcNormals(i - 1, j - 1);
            normals[Index++] =  calcNormals(i    , j - 1);
        }
    }
    return normals;
}

vec4
FractalLandShape::calcNormals(int i, int j)
{
    float dxzscale = xzscale / (fractalHeights.gridSize);
    // if on edge, just calc normal for adjacent point
    if (i == 0) i = 1;
    if (j == 0) j = 1;
    if (i == fractalHeights.gridSize) i = fractalHeights.gridSize - 1;
    if (j == fractalHeights.gridSize) j = fractalHeights.gridSize - 1;

    vec4 a = vec4( i      * dxzscale, getHeight(i,    j + 1) * yscale, (j + 1 ) * dxzscale, 0);
    vec4 b = vec4((i - 1) * dxzscale, getHeight(i - 1,j)     * yscale,  j       * dxzscale, 0);
    vec4 c = vec4((i + 1) * dxzscale, getHeight(i + 1,j)     * yscale,  j       * dxzscale, 0);
    vec4 d = vec4( i      * dxzscale, getHeight(i,    j - 1) * yscale, (j - 1)  * dxzscale, 0);
    vec4 v1 = a - d;
    vec4 v2 = c - b;
    vec4 n = normalize(  vec4(cross(v1,v2), 0)  );
    return n;
}

vec4
FractalLandShape::getColor(float ht)
{
    vec4 myColor = vec4(0,0,0,1);
    vec4 cols[6] =
    {
        vec4(0 , 0, 1, 1),
        vec4(0 , 0, 1, 1),
        vec4(.2, 1,.3, 1),
        vec4(.8,.5,.2, 1),
        vec4( 1, 1, 1, 1),
        vec4( 1, 1, 1, 1)
    }; // colors
    float a[] = {0, .1, .5, .8, .9, 1.0};
    int a_len = 6;
    float diff[a_len - 1];
    for (int i = 0; i < a_len - 1; i++) diff[i] = a[i + 1] - a[i];

    int i = 1;
    while (i < a_len && ht > a[i]) i++;
    i--;
    float alpha = (ht - a[i]) / diff[i];
    for (int j = 0; j < 3; j++)
    {
        myColor[j] = cols[i][j] * (1 - alpha) + cols[i + 1][j] * alpha;
    }
    return myColor;

}

void
FractalLandShape::createVAO(GLint program )
{

// Create a vertex array object
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    int csize = sizeof(float)*4*numVertices;

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, 3*csize,
                  NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, csize, points );
    glBufferSubData( GL_ARRAY_BUFFER, csize, csize, colors );
    glBufferSubData( GL_ARRAY_BUFFER, 2*csize, csize, normals );

    // set up vertex arrays
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(0) );

    GLint vColor = glGetAttribLocation( program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(csize) );

    //  LIGHTING PARAMETERS
    GLuint vNormal = glGetAttribLocation( program, "vNormal" );
    glEnableVertexAttribArray( vNormal );
    glVertexAttribPointer( vNormal, 4, GL_FLOAT, GL_FALSE, 0,
                           BUFFER_OFFSET(2*csize) );
}

void FractalLandShape::draw()
{
    glBindVertexArray( vao );
    glDrawArrays( GL_TRIANGLES, 0, numVertices );
    glBindVertexArray( 0 );
}


