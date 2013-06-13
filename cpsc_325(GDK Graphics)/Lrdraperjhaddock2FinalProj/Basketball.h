#ifndef Basketball_H
#define Basketball_H

//authors: Jamie Haddock, Ryan Draper
//date: December 3, 2012
//file: Basketball.h

//ADT Basketball:
//	data object: a virtual basketball
//	operations: constructor, destructor, createVAO, drawBasketball -- for GLUT purposes

#include "Core.h"
#include "Channels.h"

class Basketball
{
public:
    //creates instance of a basketball
    //pre: basketball does not exist
    //post: basketball exists
    //usage: Basketball myBall;
    Basketball();

    //destroys the basketball
    //pre: basketball exists
    //post: basketball does not exist
    virtual ~Basketball();

    Core myCore;
    Channels myChannels;

    vec4 center;

    //creates the VAO for the ball
    //pre: has not processed the ball arrays
    //post: has process ball arrays
    //param: GLint program
    //usage: myBall.createVAO(program);
    void createVAO(GLint program);

    //draws the basketball
    //pre: basketball has not been drawn into world
    //post: basketball has been drawn into world
    //usage: myBall.drawBasketball();
    void drawBasketball();

protected:
private:
};

#endif // Basketball_H
