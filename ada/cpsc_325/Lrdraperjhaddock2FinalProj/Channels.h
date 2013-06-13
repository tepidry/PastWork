//@file Channels.cpp
//@date December 3, 2012 -- adapted from wire sphere created by Jamie Haddock in November 2012
//@authors Jamie Haddock, Ryan Draper

// ADT Channels:
//    data object: Channels is a virtual (almost) wire sphere consisting of only latitudinal lines.
//    operations: creates, destroys, operator=, copies, create vao, draw

#ifndef Channels_H
#define Channels_H

#include "Angel.h"

class Channels
{
    public:
        //@creates an instance of Channels
        //@post: Channels has been created
        //@param: int longitudinalLines, int latitudinalLines, float radius
        //@usage: Channels myChannels(100, 100, 1.0);
        Channels(int longitudinalLines, int latitudinalLines,float radius);

        //@deletes an instance of Channels
        //@pre: Channels exists
        //@post: Channels doesn't exist
        virtual ~Channels();

        //@copies a Channels
        //@pre: other exists
        //@post: Channels identical to other is created
        //@param: Channels other
        //@usage: Channels myChannels(otherChannels);
        Channels(const Channels& other);

        //@sets a Channels equal to another
        //@pre: rhs Channels and this Channels exist
        //@post: this Channels is equal to rhs
        //@param: Channels rhs
        //@usage: myChannels = rhsChannels;
        Channels& operator=(const Channels& other);

        GLint vao;

        //@calls functions necessary to rasterize the Channels
        //@pre: Channels exists
        //@post: Channels is ready to be displayed
        //@param: GLint _vao, GLint program
        //@usage: createVAO(vao, program);
        void createVAO(GLint _vao, GLint _program );

        vec4 *vertices;
        vec4 *colors;
        vec4 *normals;
        int numVertices;

        //@draws the Channels
        //@pre: Channels exists
        //@post: Channels has been drawn
        //@usage: myChannels.draw();
        void draw();
    protected:
    private:
};

#endif // Channels_H
