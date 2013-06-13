//@author: Dr. Y
//@date: September 2, 2010
//@file: gradeversion1.cpp

//@description: This program allows the user to enter two exam scores,
//              compute the average, and print out the exam scores and
//              the average.

#include <iostream>
using namespace std;

int main()
{
   int score1, score2;
   float average;
   
   cout << endl << endl;
   
   cout << "Enter exam 1 -> ";
   cin >> score1;
   cout << "Enter exam 2 -> ";
   cin >> score2;
   
   cout << endl << endl;
   
   average = (score1 + score2) / 2.0;
   
   cout << "Exam 1 -----------> " << score1 << endl;
   cout << "Exam 2 -----------> " << score2<<endl;
   cout << endl;
   cout << "Average Score-----> " << average << endl;
   cout << endl << endl;

   return 0;
}
