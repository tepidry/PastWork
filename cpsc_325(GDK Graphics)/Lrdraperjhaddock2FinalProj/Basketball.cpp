#include "Basketball.h"
#include "Globals.h"

//authors: Jamie Haddock, Ryan Draper
//date: December 3, 2012
//file: Basketball.h

//ADT Basketball:
//	data object: a virtual basketball
//      data structure: a wire sphere for the core and a modified wire sphere for the channels
//	operations: constructor, destructor, createVAO, drawBasketball -- for GLUT purposes

//creates instance of a basketball
//pre: basketball does not exist
//post: basketball exists
//usage: Basketball myBall;
Basketball::Basketball()
     : myChannels(100,100,1.015), myCore(100,100,1)
{
     center = myCore.center;
}

//destroys the basketball
//pre: basketball exists
//post: basketball does not exist
Basketball::~Basketball()
{
    //dtor
}

//creates the VAO for the ball
//pre: has not processed the ball arrays
//post: has process ball arrays
//param: GLint program
//usage: myBall.createVAO(program);
void
Basketball::createVAO(GLint program) {

     // Create multiple vertex array objects
    GLuint vao[2];
    glGenVertexArrays( 2, vao );
    myCore.createVAO(vao[0], program);
    myChannels.createVAO(vao[1], program);
}

//draws the basketball
//pre: basketball has not been drawn into world
//post: basketball has been drawn into world
//usage: myBall.drawBasketball();
void Basketball::drawBasketball()
{
    glUniform4fv( model_color, 1, vec4(1.0,1.0,1.0,1.0));
    myCore.draw();
    glUniform4fv(model_color, 1, vec4(2.0,0,0,1.0));
    myChannels.draw();
}
