// memory mapping of C++ code
//     functions with parameters that pass by value
//     functions that do or do not return a value
//@ file  memoryPart2

#include <iostream>
using namespace std;

int f(int a);
double g(int b, double c);
void h();

int main()
{
   int a, b, d;
   double c, e;
   
   a = 3;
   a = 2;
   d = 15.3;
   
   c = f(a);
   e = g(a, a);
   h();
   
   return 0;
}

int f(int a)
{
   return a * 4;
}

double g(int b, double c)
{
   double j;
   j = 2 * b + c * 3;
   return j;
}

void h()
{
   int w = 10;
   cout << "Hi" << w << endl;
}
   
   
   
