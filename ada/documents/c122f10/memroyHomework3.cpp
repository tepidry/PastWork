// memory mapping of C++ code
//     functions with parameters that pass by value
//     functions that do or do not return a value
//@ file  memoryPart2

#include <iostream>
using namespace std;

int f(int a);
void g(int& b, double& c);
void h();

int main()
{
   int a, b, d;
   double c, e;
   
   a = 3;
   a = a + 1;
   d = 15.3;
   
   b = f(a);
   g(a, c);
   h();
   
   return 0;
}

int f(int a)
{
   return a * 4;
}

void g(int& b, double& c)
{
   double e = 2.3;
   b = 6;
   c = 2 * b + c * 3;

}

void h()
{
   int w = 10;
   cout << "Hi" << w << endl;
}
   
   
   
