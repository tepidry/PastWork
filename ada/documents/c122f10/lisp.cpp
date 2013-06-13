//@description  This program is a client of Abstract Data Type Stack.
//              It accepts a possible LISP expression from the user. 
//               Using one stack, it determines whether or not
//              it is a valid LISP expression.
//@author  Dr Y
//@file lisp.cpp
//@date March 5, 2010 revised Oct 27, 2010

#include "cstack.h"
#include <iostream>
using namespace std;

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void printNewLines(int num);

//@checks if symbol is an open parenthesis
//@pre symbol is assigned
//@post if symbol is an open parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '(' else false
//@usage if (IsOpen(symbol))
bool isOpen(char symbol);

//@checks if symbol is a closed parenthesis
//@pre symbol is assigned
//@post if symbol is a closed parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is ')' else false
//@usage if (IsClosed(symbol))
bool isClosed(char symbol);

//@checks if symbol is the newline 
//@pre symbol is assigned
//@post if symbol is a newline, it returns true
//      else it returns false
//@param symbol
//@usage if (notEndOfLine(symbol))
bool NotEndOfLine(char symbol);

//@gets a possible LISP expression from the user and checks
//@whether or not it is valid
//@post prints a message as to whether or not an expression is valid
//@usage GetAndCheckExpression();
void getAndCheckExpression();

//@processes one symbol in the possible LISP expression
//@pre stack exists, symbol is assigned, balanced and ok are true
//@post stack may be altered and balanced and ok may be changed to false
//@param stack may contain open parentheses
//@param symbol is from the expression
//@param balanced tells whether the expression has balanced parentheses
//@param ok tells whether Push was successful
//@usage process(LISP_stk, symbol, balanced);
void process (Stack& stack, char symbol, bool& balanced, bool& ok);

int main()
{
   printNewLines(3); 
   getAndCheckExpression();
   printNewLines(3);
   
   return 0;
}

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);      
void printNewLines(int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

//@checks if symbol is an open parenthesis
//@pre symbol is assigned
//@post if symbol is an open parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '(' else false
//@usage if (IsOpen(symbol))
bool isOpen(char symbol)
{
   return (symbol == '(');
}

//@checks if symbol is a closed parenthesis
//@pre symbol is assigned
//@post if symbol is a closed parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is ')' else false
//@usage if (IsClosed(symbol))
bool isClosed(char symbol)
{
   return (symbol == ')');
}

//@checks if symbol is the newline 
//@pre symbol is assigned
//@post if symbol is a newline, it returns true
//      else it returns false
//@param symbol
//@usage if (isEndOfLine(symbol))
bool NotEndOfLine(char symbol)
{
   return (symbol != '\n');
}

//@gets a possible LISP expression from the user and checks
//@whether or not it is valid
//@post prints a message as to whether or not an expression is valid
//@usage GetAndCheckExpression();
void getAndCheckExpression()
{
   Stack LISP_stack;
   char symbol;
   bool balanced = true;
   bool ok = true;
   
   cout << "Enter an expression and press return -> ";
   cin.get(symbol);
   while (balanced and notEndOfLine(symbol) and ok)
   {
      process(LISP_stack, symbol, balanced, ok);
      cin.get(symbol);
   }
   if (!ok)
   {
      cout << "problem with the stack -- FULL" << endl;
      cout << "Algorithm aborted" << endl;
   } else {
      if (balanced and LISP_stack.IsEmpty())
      {
         cout << "Expression is a valid" << endl;
      } else {
         cout << "Expression is not valid" << endl;
      }
   }
}

//@processes one symbol in the possible LISP expression
//@pre stack exists, symbol is assigned, balanced and ok are true
//@post stack may be altered and balanced and ok may be changed to false
//@param stack may contain open parentheses
//@param symbol is from the expression
//@param balanced tells whether the expression has balanced parentheses
//@param ok tells whether Push was successful
//@usage process(LISP_stk, symbol, balanced);
void process (Stack& stack, char symbol, bool& balanced, bool& ok)
{
   if (isOpen(symbol))
   {
      stack.Push(symbol, ok);
   } else if (isClosed(symbol)) {
      if (stack.IsEmpty())
      {
         balanced = false;
      } else {
         stack.Pop(ok);
      }
   }
}
   
