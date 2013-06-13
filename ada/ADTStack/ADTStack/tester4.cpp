#include "cstack.h"
#include <iostream>
using namespace std;

void printNewLines(int num);
void printBool(bool ok);
void print(StackType stk);

int main()
{
   Stack stk;
   bool ok;
   
   printNewLines(3);
   stk.Push(3, ok);
   printBool(ok);
   stk.Push(2, ok);
   printBool(ok);
   stk.Push(1, ok);
   printBool(ok);
   print(stk);
   
   printNewLines(3);
   ItemType topItem;
   stk.GetTop(topItem, ok);
   cout << "top = " << topItem << endl;
   printBool(ok);
   stk.Pop(ok);
   print(stk);
   
   Stack emptyStk;
   emptyStk.GetTop(topItem, ok);
   cout << "empty stack after GetTop " << endl;
   printBool(ok);
   emptyStk.Pop(ok);
   cout << "empty stack after Pop" << endl;
   printBool(ok);
   
   printNewLines(3);
   Stack secstk(stk);
 
   return 0;
}

void printNewLines(int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

void printBool(bool ok)
{
   cout << "ok = ";
   if (ok)
      cout << "true";
   else
      cout << "false";
   cout << endl;
}

void print(StackType stk)
{
   bool ok;
   ItemType topItem;
   cout << "Top -> ";
   while(!stk.IsEmpty())
   {
      stk.GetTop(topItem, ok);
      cout << topItem << ", ";
      stk.Pop(ok);
   }
}
