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

        vec4 points[24];
        vec4 colors[24];
        vec4 normals[24];
        int numPoints;

        void colorDisk();
    protected:
        vec4 diskNormal;
        vec4 vertices[9];
        vec4 twoColors[2];
        int index;
        void slice(int a, int b, int c, int col);
    private:
};

#endif // DISK_H
