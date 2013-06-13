//@author Dr Y
//@date 9/9/10
//@file formatplay.cpp
//@description This program shows how to format output and print a table
// of numbers that are lined up and the use math functions.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
   double num, square, cube, fourth, sine;
   bool notUserIsDone;
   char answer;
   
   cout << endl << endl;
   
   notUserIsDone = true;

   while (notUserIsDone)
   {
      cout << "Enter a number -> ";
      cin >> num;
      cout << endl << endl;
      
      square = num * num;
      cube = num * num * num;
      fourth = pow(num, 4.0);
      sine = sin(num);
      
      cout << "First  Second  " << endl << endl;
      cout << setprecision(3) << fixed << right << showpoint;
   
      cout << setw(7) << num << setw(10) << square << endl;
      cout << setw(7) << cube << setw(10) << fourth << endl;
      cout << setw(7) << sine << setw(10) << sine * sine << endl;
      
      cout << endl << endl;
      
      cout << "Do you want to continue <y or n> ? ";
      cin >> answer; 
      notUserIsDone = (answer == 'y');
      cout << endl << endl;
   }  
}
   
   
