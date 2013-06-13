//authors :   Ryan Draper, Jamie Haddock
//date:       December 3, 2012
//file:       BBallCourt.cpp


//description Creates a instance of BBallCourt which uses Shapes.h to create a basketball court
// ADT BBallCourt
//	data structure:	Uses Shapes to create the court through the matrix multiplication
//      data object:	Creates a basketball court where the letters on the backboad GO ZAGS change between two shades of Red
//      operations:	Create, Destroy, drawBBallCourt, highlightBoard

#include "BBallCourt.h"
#include "Shapes.h"
#include "Globals.h"

//Constructs the instance of BBallCourt
//pre BBallCourt did not exist
//post BBallCourt exists and public members courtLength = 40 and courtWidth = 30
//usage BBallCourt court;
BBallCourt::BBallCourt():courtLength(40), courtWidth(30)
{
    lightUpBackBoard = false;
}

//Deconstructor for class BBallCourt
//pre BBallCourt exists
//post BBallCourt does not exist
BBallCourt::~BBallCourt()
{}

//creates the basic court of brown using shapes.h and Cube class
//pre couurt does not exist
//post court does exist relative to the eye frame
//usage drawCourt(mv);
void
BBallCourt::drawCourt(mat4& mv)
{
    vec4 black(0,0,0,1);
    vec4 brown(1.5,1,.3,1);

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Scale(80,80,80);
    mv = mv * RotateX(-10);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(black);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(0,-9.8,-4);
    mv = mv * Scale(courtWidth, 0.5, courtLength);
    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );
    shapes.drawCube(brown);
    mv = mvMatrixStack.popMatrix();

}


//create the backboard in its entirety includeing other private members to create the letters uses Cylinder and Cube from Shapes
//pre the backboard doesn't exist
//post backboard is created in the mv and inside the frustrum
//usgae drawBackBoard(mv);
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


//draws the letter G using the cube class in shapes
//pre G is not in the view matrix
//post class cube allows the G to be in the view matrix
//usage drawG(mv, red[i]);
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

//draws the letter O using the cube class in shapes
//pre O is not in the view matrix
//post class cube allows the O to be in the view matrix
//usage drawO(mv, red[i]);
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

//draws the letter Z using the cube class in shapes
//pre Z is not in the view matrix
//post class cube allows the Z to be in the view matrix
//usage drawZ(mv, red[i]);
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

//draws the letter A using the cube class in shapes
//pre A is not in the view matrix
//post class cube allows the A to be in the view matrix
//usage drawA(mv, red[i]);
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

//draws the letter S using the cube class in shapes
//pre S is not in the view matrix
//post class cube allows the S to be in the view matrix
//usage drawS(mv, red[i]);
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

//draws the letters on the backboard using private functions drawGOZAGS respectively
//pre the backboard is plain white with no letters
//post the backboard has GO ZAGS in it and can change colors between the vec 4 red[]
//variable lightupbackboard depending on the state of the the letters can be red or yellow
//usage drawOnBackBoard(mv);
void BBallCourt::drawOnBackBoard(mat4& mv)
{
    int i;
    vec4 red[2];
    red[0] = vec4(4,0,0,1);
    red[1] = vec4(4, 0, 4, 1);
    if(lightUpBackBoard)
    {
        i = 1;
    } else {
        i = 0;
    }


    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(1.5,15,-11.9);

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(-5,0,0);
    drawG(mv, red[i]);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(-3.5,0,0);
    drawO(mv, red[i]);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(0,0,0);
    drawZ(mv, red[i]);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(1,0,0);
    drawA(mv, red[i]);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(3.2,0,0);
    drawG(mv, red[i]);
    mv = mvMatrixStack.popMatrix();

    mvMatrixStack.pushMatrix(mv);
    mv = mv * Translate(4.5,0,0);
    drawS(mv, red[i]);
    mv = mvMatrixStack.popMatrix();
    mv = mvMatrixStack.popMatrix();

}

//makes a set of blocked bleachers according to the length and width of the rectangle that is the gap in the middle.
//pre bleachers have not been created in the matrix view
//post bleachers are now in the matrix view Scaled to (seatLength, 1, 1) and translated(width,yLevel, length) height
//usage makeBleachers(mv, 34, 40, 5, 50, color);
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


//draws lines on the court so it looks like a basketball court free throw line
//pre lines were not on the court
//post cube class is used to draw the lines here in red on the matrix view
//usage drawCourtLines(mv);
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

// changes the color of the letters on the board to apear as though they are lighting up
//pre public bool variaable lightupback board is either true or false
//post public bool variable lightUpBackBoard is = to onOff
//usage court.highlightBoard(on);
void BBallCourt::highlightBoard(bool onOff)
{
    lightUpBackBoard = onOff;
}

//creates the basic court of brown using shapes.h and Cube class
//pre couurt does not exist
//post court does exist relative to the eye frame
//usage drawCourt(mv);
void BBallCourt::drawBBallCourt(mat4& mv)
{
    vec4 color[3];

    color[0] = vec4(1,1,1,0);
    color[1] = vec4(0,0,1,0);
    color[2] = vec4(1,0,0,0);

    mvMatrixStack.pushMatrix(mv);

    mv = mv * Translate(0, 0, -12);
    //mv = mv * RotateX(-20);

    glUniformMatrix4fv( model_view, 1, GL_TRUE, mv );

    drawCourt(mv);
    drawCourtLines(mv);
    drawBackBoard(mv);
    drawOnBackBoard(mv);

    int length = 40;
    int width = 36;
    int yLevel = -4;
    for (int i = 0; i < 10; i++, length += 5, width += 5, yLevel++)
    {
        makeBleachers(mv, length, width, yLevel, 200, color[1]);
    }

    mvMatrixStack.pushMatrix(mv);

}

