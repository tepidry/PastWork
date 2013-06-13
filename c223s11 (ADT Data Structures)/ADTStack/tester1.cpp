#include "cstack.h"
#include <iostream>
using namespace std;

int main()
{
   Stack stk;
   bool ok;
   
   stk.Push(3, ok);
   cout << "ok = " << ok << endl;
   stk.Push(2, ok);
   cout << "ok = " << ok << endl;
   stk.Push(1, ok);
   cout << "ok = " << ok << endl;
   
   return 0;
}
