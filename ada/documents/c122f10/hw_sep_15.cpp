//@file: Homework sep/16
//@author: Ryan Draper(draper)


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//@allows user to input 2 exams
//@post: two exam score will be in exam1 and 2 by return address
//@param: int exam1, exam2;
//@usage: InputExams(exam1, exam2);
void InputExams(int& exam1, int& exam2);

//@calculates the average of the two grades
//@pre: You need two previously entered exam scores 
//@post: returns the average by (exam1 + exam2)/2 by return of value
//@param: double average;
//@usage:  average = CalcAverage(exam1, exam2);
double CalcAverage(int exam1, int exam2);

//@This will allow user to assign a grade to the calculated
//@average.
//@pre: the average must be calculated
//@post: grade is assigned a value return of address.
//@usage: GetGrade(double average, char& grade)
void GetGrade(double average, char& grade);

void PrintInfo(int exam1, int exam2, double average, char grade);

//@This program allows the user to enter to exam scores that
//@will then be found a average of and assign a grade to that average.
//@pre: The user will enter a 2 exam scores
//@post: those scores will then be averaged and found through the average
//@a grade.
//@param:
//@int exam1;
//@double average;
//@char grade;
//@return: 
int main()
{
   int exam1, exam2;
   double average;
   char grade;
	
   InputExams(exam1, exam2);
   //cout << exam1 << endl << exam2 << endl;
   average = CalcAverage(exam1, exam2);
   //cout << average << endl;
   GetGrade(average, grade);
   PrintInfo(exam1, exam2, average, grade);
   
	
   cout << endl << endl;
	
   return 0;
}

//@ gets a high fahrenheit temperature from the user
//@ after a prompt.
//@post: returns a Fahrenheit temperature 
//@usage  highTemp = GetHighFahrenheit();
//@param: int highTemp;
//@returns: highTemp as an integer
void InputExams(int& exam1, int& exam2)
{
	
   cout << "Please enter your first exam score---> ";
   cin >> exam1;
   cout << "Please enter your second exam score--> ";
   cin >> exam2;
	
}

//@calculates the average of the two grades
//@pre: You need two previously entered exam scores 
//@post: returns the average by (exam1 + exam2)/2 by return of value
//@param: double average;
//@usage:  average = CalcAverage(exam1, exam2);
double CalcAverage(int exam1, int exam2)
{
   double average;
   
   average = (exam1 + exam2) / 2;
   
   return average;   
}

//@This will allow user to assign a grade to the calculated
//@average.
//@pre: the average must be calculated
//@post: grade is assigned a value return of address.
//@usage: GetGrade(double average, char& grade)
void GetGrade(double average, char& grade)
{
   if (average > 90)
   {
      grade = 'A';
   } else if (average > 80) {
      grade = 'B';
   } else {
      grade = 'C';
   }
}

void PrintInfo(int exam1, int exam2, double average, char grade)
{
   
   cout << setprecision(2) << fixed << right;
   cout << "Exam1 " << " Exam2 " << " Average " << " Grade" << endl;
   cout << setw(5) << exam1 << setw(7) << exam2;
   cout << setw(9) << average << setw(7) << grade; 
   cout << endl << endl;

}
