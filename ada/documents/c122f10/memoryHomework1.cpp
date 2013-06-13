// memory mapping of C++ code
//     functions with parameters that pass by value
//     functions that do or do not return a value
//@ file: memoryPart1

#include <iostream>
using namespace std;

int f(int a);
double g(int b, double c);
void h();

int main()
{
   int a, b, c;
   double d, e;
   
   a = 3 + 5.21;
   b = 4 / 3;
   d = 5 * 2.5 - 3.1 * 4 + 1 ;
   
   c = f(b);
   e = g(a, d);
   h();
   
   return 0;
}

int f(int a)
{
   int d = 2;
   return a * d;
}

double g(int b, double c)
{
   double e;
   e = 6;
   e = 2 * b + c / 4;
   return b;
}

void h()
{
   int s = 0;
   for (int i = 0; i < 4; i++)
      s = s + i;
   cout << s << endl;
}

   
   
