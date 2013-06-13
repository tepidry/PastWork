//@author    Dr Y
//@file  gradehwarray.cpp
//@date  9/16/10

//@description This program allows the user to input any number
//@            of exams (up to a limit),
//@            calculate the average, and
//@            print a report of the exams and average.

//EDUCATIONAL NOTE: Study prototypes with array parameters carefully
//                  Study calls of functions with array parameters carefully
//                  Study documentation with array parameters carefully

#include <iomanip>
#include <iostream>
using namespace std;

const int MAXSIZE = 10;                      // proper place for all const in all CAPS

//@allows the user to enter the desired number of exams
//@post returns the number entered by the user
//@     the value is in the range [0, 10]
//@usage  numExams = GetNumberExams();
int GetNumberExams();

//@allows the user to input a number of exams
//@pre numberExams is assigned a value >= 0
//@post scores[0..numberExams-1] has been assigned
//@param scores -- the list of exam scores
//@param numExams -- the number of exams
//@usage InputExams(exams, numExams);void InputExams(int scores[], int numberExams);
void InputExams(int scores[], int numberExams);

//@finds the average of the exams
//@pre exams[0..numExams-1] have been assigned
//@post returns the average of exams[0..numExams-1]
//@param exams
//@param numExams
//@usage average = FindAverage(exams, numExams);
double FindAverage(int exams[], int numExams);

//@prints a grade report of exams and average
//@pre exams[0..numExams-1], average are all assigned
//@post outputs exams[0..numExams-1], average
//@param exams
//@param average
//@param numExams
//@usage PrintReport(exam1, exam2, average, grade);
void PrintReport (int exams[], int numExams, double average);

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(30;
void PrintNewLines(int num);

int main()
{
   int exams[MAXSIZE];
   double average;
   int numberOfExams;
   
   PrintNewLines(3);
   numberOfExams = GetNumberExams();
   PrintNewLines(2);
   InputExams(exams, numberOfExams);
   PrintNewLines(2);
   
   average = FindAverage(exams, numberOfExams);
   
   PrintReport (exams, numberOfExams, average);
   PrintNewLines(3);
      
   return 0;
}

//@allows the user to enter the desired number of exams
//@post returns the number entered by the user
//@     the value is in the range [0, 10]
//@usage  numExams = GetNumberExams();
int GetNumberExams()
{
   int numExams;
   cout << "Enter the number of exams (<= 10) -> ";
   cin >> numExams;
   while (numExams < 0 || numExams > 10)
   {
      cout << "Enter the number of exams 0 <= num <= 10) -> ";
      cin >> numExams;
   }
      
   return numExams;
}

//@allows the user to input a number of exams
//@pre numberExams is assigned a value >= 0
//@post scores[0..numberExams-1] has been assigned
//@param scores -- the list of exam scores
//@param numExams -- the number of exams
//@usage InputExams(exams, numExams);
void InputExams(int scores[], int numberExams) 
{
   for (int i = 0; i < numberExams; i++)
   {
      cout << "Enter exam " << i + 1 << " --> ";
      cin >> scores[i];
   }
}

//@finds the average of the exams
//@pre exams[0..numExams-1] have been assigned
//@post returns the average of exams[0..numExams-1]
//@param exams
//@param numExams
//@usage average = FindAverage(exams, numExams);
double FindAverage(int exams[], int numExams)
{
   int sum = 0;
   double average;
   
   for (int i = 0; i < numExams; i++)
   {
      sum = sum + exams[i];
   }
   average = sum * 1.0 / numExams;
   return average;
}

//@prints a grade report of exams and average
//@pre exams[0..numExams-1], average are all assigned
//@post outputs exams[0..numExams-1], average
//@param exams
//@param average
//@param numExams
//@usage PrintReport(exam1, exam2, average, grade);
void PrintReport (int exams[], int numExams, double average)
{
   for (int i = 0; i < numExams; i++)
   {
      cout << "Exam " << setw(3) << i + 1 << " --> "<<  setw(6) << exams[i] << endl;
   }
   cout << "-------------------" << endl;
   cout << "Average ---> " << setprecision(1) << fixed << setw(8) 
        << average << endl;
}

//@prints a number of new lines
//@pre num is assigned
//@post outputs num newlines
//@param num -- the number of desired newlines
//@usage PrintNewLines(30;
void PrintNewLines(int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << endl;
   }
}

