//author Ryan Draper
//file LrdraperVectorTest
//date Sept. 11 2012
//Description: testing classsVector3D fuctions
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Vector3D.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Vector3D a(5.0);
    Vector3D w(1.0, 0.0, 0.0);
    Vector3D v(0.0, 1.0, 0.0);
    Vector3D u;

    cout << "A vector with a one value of 5 passed to the constructor a = " << a << endl;
    cout << "A vector with a no value passed to the constructor u = " << u << endl;

    u = w + v;
    cout << "w = " << w << endl;
    cout << "v = " << v << endl;
    cout << "w + v = " << u << endl;

    cout << "w * 2 = " << w * 2 << endl;
    cout << "v * 2 = " << v * 2 << endl;
    cout << "w / 2 = " << w / 2 << endl;
    cout << "v / 2 = " << v / 2 << endl;
    cout << "w * 3 = " << 3 * w << endl;

    w = Vector3D(3.0, 4.0, 0.0);

    cout << "length of v" << v << " is = " << v.length() << endl;
    cout << "lenth of vector w" << w << " is = " << w.length() << endl;
    cout << "length squared for w = " << w.len_squared() << endl;
    w.normalize();
    cout << "w after normalization" << w << endl;


    u = v.hat();
    cout << "normalized v" << v << " is the vector = " << v.hat() << endl;
    cout << "dot product of (u" << u << " . v " << v << " ) = " << v * u << endl;
    w = Vector3D(0, 1, 0);
    v = Vector3D(1, 0, 0);
    cout << "cross product of w" << w << " X v" << v << " = " << (w ^ v) << endl;
    cout << "cross product of v" << v << " X w" << w <<  " = " << (v ^ w) << endl;
    u = Vector3D(1.0, 1.0, 1.0);
    cout << "distance of point (0,0,0) to point (1, 1, 1) " << u.distance(Vector3D(0.0, 0.0, 0.0)) << endl;
    u = Vector3D(0.0, 0.0, 0.0);
    cout << "distance of point " << u << " to point " << v << " = " << v.distance(u) << endl;
    return EXIT_SUCCESS;
}
