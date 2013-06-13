// A class for storing primitive objects: cylinder, cube, disk, Steiner surface

#include "Basketball.h"
#include "Globals.h"

Basketball::Basketball()
     : myChannels(100,100,1.05), myCore(100,100,1)
{

}

Basketball::~Basketball()
{
    //dtor
}

void
Basketball::createVAO(GLint program) {

     // Create multiple vertex array objects
    GLuint vao[2];
    glGenVertexArrays( 2, vao );
    myCore.createVAO(vao[0], program);
    myChannels.createVAO(vao[1], program);
}

// draws solid cube and wire cube together. The wire color is always black
void Basketball::drawBasketball()
{
    glUniform4fv( model_color, 1, vec4(1.0,1.0,1.0,1.0));
    myCore.draw();
    glUniform4fv(model_color, 1, vec4(1.0,0,0,1.0));
    myChannels.draw();
}
