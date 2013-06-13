//@date Wed Jan 13
//@author ryan draper
//@file    simpletypes.cpp
//@description: This program shows the translation of a simple
//       Python program with assignment statements into
//       an equivalent C++ program.

/* in Python we would have the following code
def main():
    numExams = 5
    cost = 20325.76
    sum = 1.3 + 4.6
    grade = 'A'
    isFound = False
main()
*/
// translating the above into C++ code

#include <iostream>
using namespace std;

int main()
{
   int numExams;
   float cost;
   double sum;
   char grade;
   bool isFound;
   
   numExams = 5;
   cost = 20325.76;
   sum = 1.3 + 4.6;
   grade = 'A';
   isFound = false;
   
   cout << "Number of Exams-> " << numExams << endl;
   cout << "The Cost--------> " << cost << endl;
   cout << "The Sum Total---> " << sum << endl;
   cout << "The Grade-------> " << grade << endl;
   cout << "What is Found---> " << isFound << endl;
   
   
   return 0;
}

// In Python the type of a variable (the amount of memory used
//and how the bits are coded) were inferred from the assignment 
//statement itself.
//  In C++ we must declare the type of a variable BEFORE the
//assignment statement. However, the assignment statement itself
//is the same as in Python except that we must end it with a 
//semi-colon
