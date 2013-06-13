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
   int score, sum;
   int numExams;
   int i;
   float average;
   
   cout << endl << endl;
   
   cout << "Enter number of exams ->";
   cin >> numExams;
   
   i = 0;
   sum = 0;
   
   while (i < numExams);
   {
      cout << "Enter exam" << i + 1 ;
      cin >> score;
      
      sum = sum + score;
      
      i++;
   }
   
   cout << endl << endl;
   
   average = 1.0 sum / numExams;
   
   cout << "Average = " << average << endl;

   return 0;
}
