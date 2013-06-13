//authors :   Ryan Draper, Jaimie Haddock
//date:       December 3, 2012
//file:       ScoreBoard.h

//this class makes a score board using the idea of a seven segment display
//       ___a__
//      |       |           0 = a,b,c,e,f,g
//     b|       |c          1 = c,f
//       ---d---            2 = a,c,d,e,g
//      |       |           etc...
//     e|       |f
//       ---g---
// ADT ScoreBoard
//      data object:	Simulates a seven segment display 
//      operations:	Create, Destroy, drawScoreBoard, clearScoreBoard, addPointToScore

#ifndef SCOREBOARD_H_INCLUDED
#define SCOREBOARD_H_INCLUDED

#include "mat.h"



class ScoreBoard
{
    public:

	//creates the instance of scoreboard class
	//pre scoreboard does not exist 
	//post scoreboard does exist
	//usage ScoreBoard myScore();
        ScoreBoard();

	//deconstructor for score board class
	//pre ScoreBoard instance exists
	//post ScoreBoard instance does not exist
        virtual ~ScoreBoard();	

	//makes the scoreboard on the top right hand corner of the view displaying the public variable score 0-9
	//pre scoreboard was not in view plane
	//post scoreboard using shapes cube exists in top right of view
	//param mv
	//usage myScore.drawScoreBoard(mv);
        void drawScoreBoard(mat4& mv);

	//changes the color on the score board to 0
	//pre score board will be displaying whatever the public variable score is 0-9
	//post scoreboard and public variable score are 0
	//param mv
	//usage myScore.clearScoreBoard(mv);
        void clearScoreBoard(mat4&mv);

	//increments the value of score by 1 mod 10
	//pre score is a public variable holding a single integer 0-9
	//post score is a public vairable increased by one md 10
	//usage myScore.addPointToScore();
        void addPointToScore();

        int score;
        vec4 zeroGrayOneYellow[2];
        bool onOff;

    protected:

    private:

	//changes the color of the appropriate points on the seven segment display to show 0
	//pre score board exists in the matrix view
	//post 0 is displayed on the seven segment display
	//param mv
	//usage displayZero(mv);
        void displayZero(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 1
	//pre score board exists in the matrix view
	//post 1 is displayed on the seven segment display
	//param mv
	//usage displayOne(mv);
        void displayOne(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 2
	//pre score board exists in the matrix view
	//post 2 is displayed on the seven segment display
	//param mv
	//usage displayTwo(mv);
        void displayTwo(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 3
	//pre score board exists in the matrix view
	//post 3 is displayed on the seven segment display
	//param mv
	//usage displayThree(mv);
        void displayThree(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 4
	//pre score board exists in the matrix view
	//post 4 is displayed on the seven segment display
	//param mv
	//usage displayFour(mv);
        void displayFour(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 5
	//pre score board exists in the matrix view
	//post 5 is displayed on the seven segment display
	//param mv
	//usage displayfive(mv);
        void displayFive(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 6
	//pre score board exists in the matrix view
	//post 6 is displayed on the seven segment display
	//param mv
	//usage displaySix(mv);
        void displaySix(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 7
	//pre score board exists in the matrix view
	//post 7 is displayed on the seven segment display
	//param mv
	//usage displaySeven(mv);
        void displaySeven(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 8
	//pre score board exists in the matrix view
	//post 9 is displayed on the seven segment display
	//param mv
	//usage displayNine(mv);
        void displayEight(mat4& mv);

	//changes the color of the appropriate points on the seven segment display to show 9
	//pre score board exists in the matrix view
	//post 9 is displayed on the seven segment display
	//param mv
	//usage displayine(mv);
        void displayNine(mat4& mv);

	//draws the 'a' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre a exists
	//post a is either dark or bright yellow
	//param mv
	//	onOff
	//usage aToggle(mv, onOff);
        void aToggle(mat4& mv, bool onOff);

	//draws the 'b' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'b' exists
	//post 'b' is either dark or bright yellow
	//param mv
	//	onOff
	//usage bToggle(mv, onOff);
        void bToggle(mat4& mv, bool onOff);

	//draws the 'c' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'c' exists
	//post 'c' is either dark or bright yellow
	//param mv
	//	onOff
	//usage cToggle(mv, onOff);
        void cToggle(mat4& mv, bool onOff);

	//draws the 'd' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'd' exists
	//post 'd' is either dark or bright yellow
	//param mv
	//	onOff
	//usage dToggle(mv, onOff);
        void dToggle(mat4& mv, bool onOff);

	//draws the 'e' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'e' exists
	//post 'e' is either dark or bright yellow
	//param mv
	//	onOff
	//usage eToggle(mv, onOff);
        void eToggle(mat4& mv, bool onOff);

	//draws the 'f' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'f' exists
	//post 'f' is either dark or bright yellow
	//param mv
	//	onOff
	//usage fToggle(mv, onOff);
        void fToggle(mat4& mv, bool onOff);

	//draws the 'g' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'g' exists
	//post 'g' is either dark or bright yellow
	//param mv
	//	onOff
	//usage gToggle(mv, onOff);
        void gToggle(mat4& mv, bool onOff);

	//draws the 'g' location on the seven segment display either dark or bright yellow depending on the bool onOff
	//pre 'g' exists
	//post 'g' is either dark or bright yellow
	//param mv
	//	onOff
	//usage gToggle(mv, onOff);
        void makeBar(mat4& mv, bool onOff);

};



#endif // SCOREBOARD_H_INCLUDED
