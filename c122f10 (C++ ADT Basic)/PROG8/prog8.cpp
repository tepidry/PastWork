//@description:  This
//@              
//@              
//@              
//@file prog8.cpp
//@author Ryan Draper(draper)
//@date 11/01/2010

#include "cstack.h"
#include <iostream>
using namespace std;

const int MAXSIZE = 100;

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintNewLines(int num);

//@checks if symbol is an open parenthesis
//@pre symbol is assigned
//@post if symbol is an open parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '(' else false
//@usage if (IsOpen(symbol))
bool IsOpen(ItemType symbol);

//@checks if symbol is the newline 
//@pre symbol is assigned
//@post if symbol is a newline, it returns true
//      else it returns false
//@param symbol
//@usage if (isEndOfLine(symbol))
bool EndOfLine(char symbol);

//@checks if symbol is a '#' to denote end
//@pre symbol is assigned
//@post if symbol is a pound sign, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '#' else false
//@usage if (IsAtEnd(symbol))
bool AtEnd(ItemType symbol);

//@return true if the choice entered by user is correct
//@pre option is assigned
//@post if symbol is a s,c,e,or x it returns true
//@     else return false. and option is entered into the cin buffer
//@param option
//@return true if symbol is not 'x' else false. and passes option by reference
//@usage while (Option(choice))
bool RightOption(char option);

//@returns what type of precedence the operater in ch has
//@pre ch is a character of an operator
//@post return 2 if the ch is '*' or '/' else it return a 1
//@param ch is the operator
//@usage  while(not operator_stack.IsEmpty() and not IsOpen(ReturnTop(operator_stack)) 
//@       and Precedence(ch) <= Precedence(ReturnTop(operator_stack)))
int Precedence(char ch);

//@prints the option menu
//@post option menu is output
//@usage  PrintOptionMenu();
void PrintOptionMenu();

//@Takes at max three characters from PF_stack and prints them on the screen to 
//@resemble a HP calculator
//@pre PF_stack has to have been atleast created
//@post if the stack is empty then it prints out the HP calc with nothing in the arguments
//@     if the stack is not it takes at most the top three and prints them out on the 
//@     HP calc out put.
//@param PF_stack
//@usage PrintOptionS(PF_stack);
void PrintOptionS(Stack PF_stack);

//@this will makes sure the character ch is no more than '9' and less then '0' if it is it will pass by reference '0';
//@pre character ch is assigned a value by enter input
//@post character ch is the same if it is between character '0' or '9' on the ascii table other wise it gets 
//@     returned a '0'
//@param ch
//@usage OverunderLoad(ch);
void OverUnderLoad(char& ch);

//@takes the user input making sure it is both correct and not 'x' to signify exit
//@pre option is assigned
//@post if symbol is a x, it returns false
//      else it returns true. and option is entered into the cin buffer
//@param option
//@return true if symbol is not 'x' else false. and passes option by reference
//@usage while (Option(choice))
bool Option(char& option);

//@initiates function ExecuteS and PrintOptionS both it takes in character by character into the cin
//@buffer through ch
//@post both does expression via post fix and prints them out in the HP calculator style in function 
//@     PrintOptionS
//@usage OptionS();
void OptionS();

//@returns the character that is on top of the stack
//@pre stack is assigned
//@post if stack is not empty returns the top else returns ' '
//@param stack
//@usage  mid = ReturnTop(PF_stack);
char ReturnTop(Stack stack);

//@Acts like an HP calculator using a stack and postfix input design to do basic calculator functions
//@pre PF_stack is assign and character ch is in the cin buffer
//@post prints out a HP calculator out put and the user input until the character '#' is entered
//@param PF_stack
//@      ch
//@return passes by value the stack and ch that is left in the cin buffer
//@usage ExecuteS(PF_stack, ch);
void ExecuteS(Stack& stack, char& ch);

//@Takes a entire infix expression into the cin buffer and turns it into a post fix expression held in an array
//@pre postFixExp is an araray, and last is an integer 
//@post the infix expression in the cin buffer is turned into a post fix expression in the array postFixExp and
//@     the integer last has the number relating to the last position in the array both are passed by reference
//@param postFixExp
//@      last
//@usage ExecuteC(postFix, last);
void ExecuteC(char postFix[],int& last);

//@Takes a entire infix expression into the cin buffer and turns it into a post fix expression held in an array
//@post the infix expression in the cin buffer is turned into a post fix expression in the array postFixExp and
//@     the integer last has the number relating to the last position in the array both are passed by reference
//@usage OptionC();
void OptionC();

void OptionE();

//@Does the operation specified on two variables
//@pre first and second are numbers that are characters and op is the operator acting on them
//@post after both characters have be put into integers and operated on they are returned as a char
//@param first
//@      second
//@      op
//@ returns the appropriate character correlating to the integer it was found to be
//@usage PF_stack.Push(DoOperation(operand1, operand2, ch), ok);
char DoOperation(double frst, double Scnd, char op);

//@takes the option the user input and calls the required function
//@pre option is taken from the cin buffer
//@post the correct function is called
//@param option
//@usage  ExecuteOption(choice);
void ExecuteOption(char option);

int main()
{
   char choice, ch;
   
   PrintNewLines(2);
   PrintOptionMenu();
   
   while (Option(choice))
   {
      PrintNewLines(2);
      ExecuteOption(choice);
      PrintNewLines(2);
      PrintOptionMenu();
   }
   
   
}

//@prints the option menu
//@post option menu is output
//@usage  PrintOptionMenu();
void PrintOptionMenu()
{
   cout << "**********************************************" << endl << endl;
   cout << "Your options:" << endl << endl;
   cout << "    s) simulate an HP Calculator of old" << endl << endl;
   cout << "    c) convert an infix expression to postfix" << endl << endl; 
   cout << "    e) evaluate an infix expression" << endl << endl;
   cout << "    x) exits program" << endl << endl;
   cout << "**********************************************" << endl << endl;
}

//@takes the user input making sure it is both correct and not 'x' to signify exit
//@pre option is assigned
//@post if symbol is a x, it returns false
//      else it returns true. and option is entered into the cin buffer
//@param option
//@return true if symbol is not 'x' else false. and passes option by reference
//@usage while (Option(choice))
bool Option(char& option)
{
   cout << "Enter option -> ";
   cin.get(option);  
   if (not RightOption(option))
   {
      cout << "Please enter appropriate option:" << endl;
      Option(option);
   }
   if (option == 'x') {
      return false;
   }
   return true;
}

//@takes the option the user input and calls the required function
//@pre option is taken from the cin buffer
//@post the correct function is called
//@param option
//@usage  ExecuteOption(choice);
void ExecuteOption(char option)
{
   if (option == 's') {
      cin.get(option);
      OptionS();
   } else if (option == 'c') {
      cin.get(option);
      OptionC();
   } else {
      cin.get(option);
      OptionE();
   }
}

//@Takes at max three characters from PF_stack and prints them on the screen to 
//@resemble a HP calculator
//@pre PF_stack has to have been atleast created
//@post if the stack is empty then it prints out the HP calc with nothing in the arguments
//@     if the stack is not it takes at most the top three and prints them out on the 
//@     HP calc out put.
//@param PF_stack
//@usage PrintOptionS(PF_stack);
void PrintOptionS(Stack PF_stack)
{
   bool ok = true;
   char top, mid, bottom;

   top = ReturnTop(PF_stack);
   PF_stack.Pop(ok);

   mid = ReturnTop(PF_stack);
   PF_stack.Pop(ok);

   bottom = ReturnTop(PF_stack);
   PF_stack.Pop(ok);
   
   PrintNewLines(2);
   cout << "3: " << bottom << endl;
   cout << "2: " << mid << endl;
   cout << "1: " << top << endl << endl;
}

//@this will makes sure the character ch is no more than '9' and less then '0' if it is it will pass by reference '0';
//@pre character ch is assigned a value by enter input
//@post character ch is the same if it is between character '0' or '9' on the ascii table other wise it gets 
//@     returned a '0'
//@param ch
//@usage OverunderLoad(ch);
void OverUnderLoad(char& ch)
{
   int check = ch -48;
   if (check > 9)
   {
      cout << endl << "Error: Over Load" << endl ;
      ch = '0';
   } else if (ch < 0) {
      cout << endl << "Error: Under Load" << endl;
      ch = '0';
   }
}

//@prints a number of newlines
//@pre num is assigned, num >= 0
//@post num newlines are output
//@param num  the number of newlines desired
//@usage  printNewLines(3);
void PrintNewLines(int num)
{
   for (int k = 0; k < num; k++)
   {
      cout << endl;
   }
}

//@checks if symbol is an open parenthesis
//@pre symbol is assigned
//@post if symbol is an open parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '(' else false
//@usage if (IsOpen(symbol))
bool IsOpen(ItemType symbol)
{
   return (symbol == '(');
}

//@return true if the choice entered by user is correct
//@pre option is assigned
//@post if symbol is a s,c,e,or x it returns true
//@     else return false. and option is entered into the cin buffer
//@param option
//@return true if symbol is not 'x' else false. and passes option by reference
//@usage while (Option(choice))
bool RightOption(char option)
{
   return (option == 's' || option == 'c' || option == 'e' || option == 'x');
}

//@checks if symbol is a closed parenthesis
//@pre symbol is assigned
//@post if symbol is a closed parenthesis, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is ')' else false
//@usage if (IsClosed(symbol))
bool IsClosed(ItemType symbol)
{
   return (symbol == ')');
}

//@checks if symbol is the newline 
//@pre symbol is assigned
//@post if symbol is a newline, it returns true
//      else it returns false
//@param symbol
//@usage if (isEndOfLine(symbol))
bool EndOfLine(char symbol)
{
   return (symbol == '\n');
}

//@checks if symbol is the newline 
//@pre symbol is assigned
//@post if symbol is a newline, it returns true
//      else it returns false
//@param symbol
//@usage if (isEndOfLine(symbol))
bool IsAnOperator(ItemType symbol)
{
   return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

//@checks if symbol is a '#' to denote end
//@pre symbol is assigned
//@post if symbol is a pound sign, it returns true
//      else it returns false
//@param symbol
//@return true if symbol is '#' else false
//@usage if (IsAtEnd(symbol))
bool AtEnd(ItemType symbol)
{
   return (symbol == '#');
}

//@returns the character that is on top of the stack
//@pre stack is assigned
//@post if stack is not empty returns the top else returns ' '
//@param stack
//@usage  mid = ReturnTop(PF_stack);
char ReturnTop(Stack stack)
{
   char top;
   bool ok = true;
   
   if (not stack.IsEmpty()) {
      stack.GetTop(top, ok);
      return top;
   } else {
      return ' ';         
   }
}

//@returns what type of precedence the operater in ch has
//@pre ch is a character of an operator
//@post return 2 if the ch is '*' or '/' else it return a 1
//@param ch is the operator
//@usage  while(not operator_stack.IsEmpty() and not IsOpen(ReturnTop(operator_stack)) 
//@       and Precedence(ch) <= Precedence(ReturnTop(operator_stack)))
int Precedence(char ch)
{
   if (ch == '*' || ch == '/')
   {
      return 2;
   } else {
      return 1;
   }
}

//@Does the operation specified on two variables
//@pre first and second are numbers that are characters and op is the operator acting on them
//@post after both characters have be put into integers and operated on they are returned as a char
//@param first
//@      second
//@      op
//@ returns the appropriate character correlating to the integer it was found to be
//@usage PF_stack.Push(DoOperation(operand1, operand2, ch), ok);
char DoOperation(char first, char second, char op)
{
   int op1 = first - 48; 
   int op2 = second - 48;
   
   
   
   if (op == '+') {
      return char(op1 + op2) + 48;
   } else if (op == '-') {
      return char(op1 - op2) + 48;
   } else if (op == '*') {
      return char(op1 * op2) + 48;
   } else {
      return char(op1 / op2) + 48;
   }
}

//@Takes a entire infix expression into the cin buffer and turns it into a post fix expression held in an array
//@pre postFixExp is an araray, and last is an integer 
//@post the infix expression in the cin buffer is turned into a post fix expression in the array postFixExp and
//@     the integer last has the number relating to the last position in the array both are passed by reference
//@param postFixExp
//@      last
//@usage ExecuteC(postFix, last);
void ExecuteC(char postFixExp[],  int& last)
{
   Stack operator_stack;
   bool ok = true;
   char ch;
   
   
   cout << "Please Enter Infix Expression-> ";
   cin.get(ch);
   while (not EndOfLine(ch))
   {
      switch (ch)
      {  
         case '9': case '8': case '7': case '6': case '5': case '4': 
         case '3': case '2': case '1': case '0':
            postFixExp[last] = ch;
            last++;
            break;

         case '(':
            operator_stack.Push(ch, ok);
            break;

         case ')':
            while (not IsOpen(ReturnTop(operator_stack)))
            {
               postFixExp[last] = ReturnTop(operator_stack);
               last++;
               operator_stack.Pop(ok);
            }
            operator_stack.Pop(ok);
            break;

         case '+': case '-': case '/': case '*':
            while(not operator_stack.IsEmpty() and not IsOpen(ReturnTop(operator_stack)) 
            and Precedence(ch) <= Precedence(ReturnTop(operator_stack)))
            {
               postFixExp[last] = ReturnTop(operator_stack);
               last++;
               operator_stack.Pop(ok);         
            } 
            operator_stack.Push(ch, ok);
            break;
      }
   cin.get(ch);
   }
   while (not operator_stack.IsEmpty())
   {
      postFixExp[last] = ReturnTop(operator_stack);
      operator_stack.Pop(ok);
   } 
}

//@Acts like an HP calculator using a stack and postfix input design to do basic calculator functions
//@pre PF_stack is assign and character ch is in the cin buffer
//@post prints out a HP calculator out put and the user input until the character '#' is entered
//@param PF_stack
//@      ch
//@return passes by value the stack and ch that is left in the cin buffer
//@usage ExecuteS(PF_stack, ch);
void ExecuteS(Stack& PF_stack, char& ch)
{
   bool ok = true;
   char operand1, operand2, result;
   
   if (IsAnOperator(ch) and ok) {
      PF_stack.GetTop(operand2, ok);
      PF_stack.Pop(ok);
      PF_stack.GetTop(operand1, ok);
      PF_stack.Pop(ok);
      result = DoOperation(operand1, operand2, ch);
      OverUnderLoad(result);
      PF_stack.Push(result, ok);
   } else if (ok and not EndOfLine(ch)) {
      PF_stack.Push (ch, ok);
   } 
}

//@initiates function ExecuteS and PrintOptionS both it takes in character by character into the cin
//@buffer through ch
//@post both does expression via post fix and prints them out in the HP calculator style in function 
//@     PrintOptionS
//@usage OptionS();
void OptionS()
{
   Stack PF_stack;
   char ch;
   
   PrintOptionS(PF_stack);
   cin.get(ch);
   while (not AtEnd(ch))
   {
      ExecuteS(PF_stack, ch);
      PrintOptionS(PF_stack);
      cin.get(ch);
      cin.get(ch);
   }
   cin.get(ch);
}

//@Takes a entire infix expression into the cin buffer and turns it into a post fix expression held in an array
//@post the infix expression in the cin buffer is turned into a post fix expression in the array postFixExp and
//@     the integer last has the number relating to the last position in the array both are passed by reference
//@usage OptionC();
void OptionC()
{
   char postFixExp[MAXSIZE];
   int last = 0;
   
   ExecuteC(postFixExp, last);
   cout << "The Post Fix Expression is : ";
   for (int i = 0; i <= last; i++)
   {
      cout << postFixExp[i];
   }
   PrintNewLines(2);
}

//@takes an infix expression entered by the user into the cin buffer which is then turned into a post
//@fix expression held in a character array "postFix[]" and that is then solved
//@post out puts the post fix of a users enter infix and solves the expression
//@ usage OptionE();
void OptionE()
{
   Stack convert_stack;
   char postFix[MAXSIZE];
   char ch, result;
   int last = 0;
   
   ExecuteC(postFix, last);
   cout << "The Post Fix Expression is : ";
   for (int i = 0; i <= last; i++)
   {
      cout << postFix[i];
   }
   PrintNewLines(1);
   for (int count = 0; count <= last; count++)
   {
      ch = postFix[count];
      ExecuteS(convert_stack, postFix[count]);
   } 
   cout << "The Answer is = ";
   result = ReturnTop(convert_stack);
   OverUnderLoad(result);
   cout << result;
   PrintNewLines(2);
}
