//@file Core.h
//@date December 3, 2012 -- adapted from Wire Sphere created by Jamie Haddock in November 2012
//@authors Jamie Haddock, Ryan Draper

// ADT Core:
//    data object: Core is a virtual (almost) wire sphere.
//    operations: creates, destroys, operator=, copies, create vao, draw

#ifndef Core_H
#define Core_H

#include "Angel.h"

class Core
{
    public:
        //@creates an instance of Core
        //@post: Core has been created
        //@param: int longitudinalLines, int latitudinalLines, float radius
        //@usage: Core myCore(100, 100, 1.0);
        Core(int longitudinalLines, int latitudinalLines,float radius);

        //@deletes an instance of Core
        //@pre: Core exists
        //@post: Core doesn't exist
        virtual ~Core();

        //@copies a Core
        //@pre: other exists
        //@post: Core identical to other is created
        //@param: Core other
        //@usage: Core myCore(otherCore);
        Core(const Core& other);

        //@sets a Core equal to another
        //@pre: rhs Core and this Core exist
        //@post: this Core is equal to rhs
        //@param: Core rhs
        //@usage: myCore = rhsCore;
        Core& operator=(const Core& other);

        GLint vao;

        //@calls functions necessary to rasterize the Core
        //@pre: Core exists
        //@post: Core is ready to be displayed
        //@param: GLint _vao, GLint program
        //@usage: createVAO(vao, program);
        void createVAO(GLint _vao, GLint _program );

        vec4 *vertices;
        vec4 *colors;
        vec4 *normals;
        vec4 center;
        int numVertices;

        //@draws the Core
        //@pre: Core exists
        //@post: Core has been drawn
        //@usage: myCore.draw();
        void draw();
    protected:
    private:
};

#endif // Core_H
