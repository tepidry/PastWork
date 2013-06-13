//authors : Ryan Draper Jaimie Haddock

#include "BBallCourt.h"
#include "Car.h"
#include "Shapes.h"
#include "Globals.h"

BBallCourt::BBallCourt():courtLength(40), courtWidth(30)
{}

BBallCourt::~BBallCourt()
{}

void
BBallCourt::drawCourt(mat4& mv)
{
    mvMatrixStack.pushMatrix(mv);
    vec4 color(1.5,1,.3,1);
    mv = mv * Translate(0,-9.8,-4);
    mv = mv * Scale(courtWidth, 0.5, courtLength);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);
    mv = mvMatrixStack.popMatrix();

}


void BBallCourt::drawBackBoard(mat4& mv)
{
    vec4 backBoardColor(1,1,1,1);
    vec4 poleColor(.8,.8,.8,1);
    vec4 rimColor(1,0,0,1);

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0, 5,-15);
    mv = mv * Scale(1, 20, 1);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCylinder(poleColor);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,15,-12);
    mv = mv * Scale(15, 7, .1);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(backBoardColor);

    mv = mvMatrixStack.popMatrix();


    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,12,-9.9);
    mv = mv * Scale(4,.3, 4);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCylinder(rimColor);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,11,-9.9);
    mv = mv * Scale(4,2, 4);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.myWireCylinder.draw();

    mv = mvMatrixStack.popMatrix();


}

void BBallCourt::drawG(mat4& mv, vec4 color)
{
    //G
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1.5,0,0);
    mv = mv * Scale(.3, 2.3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, 1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, -1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-.6, -.6, 0);
    mv = mv * Scale(.3, 1, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-.6,0,0);
    mv = mv * Scale(.5, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();
}

void BBallCourt::drawO(mat4& mv, vec4 color)
{
    //O
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1.5,0,0);
    mv = mv * Scale(.3, 2.3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-.5,0,0);
    mv = mv * Scale(.3, 2.3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, 1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, -1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();


}

void BBallCourt::drawZ(mat4& mv, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1,0,0);
    mv = mv * RotateZ(-30);
    mv = mv * Scale(.3, 2.5, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, 1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, -1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();
}

void BBallCourt::drawA(mat4& mv, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-.5, 0, 0);
    mv = mv * Scale(.9, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1,0,0);
    mv = mv * RotateZ(-25);
    mv = mv * Scale(.3, 2.3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,0,0);
    mv = mv * RotateZ(25);
    mv = mv * Scale(.3, 2.3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

}

void BBallCourt::drawS(mat4& mv, vec4 color)
{
    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, 1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, 0, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1, -1, 0);
    mv = mv * Scale(1, .3, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-1.5, .6, 0);
    mv = mv * Scale(.3, 1, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-.5, -.6, 0);
    mv = mv * Scale(.3, 1, .01);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();
}

void BBallCourt::drawOnBackBoard(mat4& mv)
{

    vec4 color(1,0,0,1);

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(1.5,15,-11.9);

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(-5,0,0);
    drawG(mv, color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(-3.5,0,0);
    drawO(mv, color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(0,0,0);
    drawZ(mv, color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(1,0,0);
    drawA(mv, color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(3.2,0,0);
    drawG(mv, color);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(4.5,0,0);
    drawS(mv, color);
    mv = mvMatrixStack.popMatrix();
    mv = mvMatrixStack.popMatrix();


    //O

    //Z
    //A
    //G
    //
}

void BBallCourt::makeBleachers(mat4& mv, int length, int width, int yLevel, int seatLength, const vec4& color)
{
    //first set of bleachers
    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(0,yLevel, -length/2.0); //(0,5,-25)
    mv = mv * Scale(seatLength, 10, 5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(-width/2.0 ,yLevel ,0);
    mv = mv * RotateY(-90);
    mv = mv * Scale(seatLength, 10, 5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(width/2.0, yLevel, 0);
    mv = mv * RotateY(-90);
    mv = mv * Scale(seatLength, 10, 5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(0, yLevel, length/2.0);
    mv = mv * Scale(seatLength, 10, 10);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

}

void BBallCourt::drawCourtLines(mat4 & mv)
{
    vec4 color(1,0,0,1);

    mv = mv * Translate(0, -9.5, 0);

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,0,-12);
    mv = mv * Scale(28, .1, .2);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(13.9,0,1.6);
    mv = mv * Scale(.2, .1, 26.5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-13.9,0,1.6);
    mv = mv * Scale(.2, .1, 26.5);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);


    mv = mv * Translate(6,0,-5.5);
    mv = mv * Scale(.2, .1, 13.25);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

     mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(-6,0,-5.5);
    mv = mv * Scale(.2, .1, 13.25);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

     mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,0,1.7);
    mv = mv * Scale(12, .4, 10);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCylinder(color);

    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0,0,3);
    mv = mv * Scale(11.5, .1, .2);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(color);

    mv = mvMatrixStack.popMatrix();

}

void BBallCourt::drawBBallCourt(mat4& mv)
{
    vec4 color[3];

    color[0] = vec4(1,1,1,0);
    color[1] = vec4(0,0,1,0);
    color[2] = vec4(1,0,0,0);

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0, 0, -12);
    mv = mv * RotateX(-20);

    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );

    drawCourt(mv);
    drawCourtLines(mv);
    drawBackBoard(mv);
    drawOnBackBoard(mv);

    int length = 40;
    int width = 30;
    int yLevel = -4;
    for (int i = 0; i < 100; i++, length += 5, width += 5, yLevel++)
    {
        makeBleachers(mv, length, width, yLevel, 200, color[1]);
    }

    mvMatrixStack.pushMatrix(mv);

}


