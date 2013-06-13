#ifndef DISK_H
#define DISK_H

#include "Angel.h"


class Disk
{
    public:
        Disk();
        virtual ~Disk();
        Disk(const Disk& other);
        Disk& operator=(const Disk& other);

        vec4 points[60];
        vec4 colors[60];
        vec4 normals[60];
        int numPoints;

        void colorDisk();
    protected:
        vec4 diskNormal;
        vec4 vertices[21];
        vec4 twoColors[2];
        int index;
        void slice(int a, int b, int c, int col);
    private:
};

#endif // DISK_H
