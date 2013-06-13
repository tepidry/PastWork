//@author Ryan Draper(rdraper)
//@date Feb. 15 2013
//@file prog2.cpp

//@description: This program computes the fibonacci sequence three separate ways: the iterative method, by the phi approximation by rounding up, and
//@             by matrix multiplication.  It then displays them all in a wonderfully easy to read format.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;


int main()
{
     double result = 0.0000;
     double resultabs = 0.0000;
     double xn = 0.0000;
     double x = 1.0;

	while (abs(x - xn) > .0005)
     {
          
          xn = x;
          x = (.5) * (x + ((2.0)/x));
          cout << "x -> " << x << endl;
          cout << "abs -> " <<  abs(x - xn) << endl;
         
          
     }
     cout << "here1 ->" << x << endl;
                    
}





