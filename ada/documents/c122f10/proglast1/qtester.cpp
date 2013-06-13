//@author Dr Y
//@date Nov 29, 2010
//@file qtester.cpp
//@description: This program fully tests class Que.

#include <iostream>
#include "que.h"
using namespace std;

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

void BuildIt(QItemType& it);

int main()
{
   Que myq;
   QItemType it;
   bool ok;

   BuildIt(it);
   
   PrintLines(3);
   PrintMessage ("copy constructor", "empty");
   Que bq(myq);

   PrintMessage ("IsEmpty", "empty");
   PrintBool (myq.IsEmpty());

   ToContinue();  

   PrintMessage ("Enqueue", "empty");
   myq.Enqueue(it,ok);
   PrintMessage("Enqueue", "after Enqueue of 1");
   cout << myq << endl;
   PrintBool (ok);

   PrintMessage ("IsEmpty", "non-empty");
   PrintBool (myq.IsEmpty());

   ToContinue();
   
   PrintMessage ("Enqueue", "size 1"); 
   cout << myq << endl; 
   myq.Enqueue(it,ok);
   PrintMessage("Enqueue", "after Enqueue of 2");
   cout << myq << endl;
   PrintBool (ok);
 
   PrintMessage ("copy constructor", "size 2");
   Que otherq(myq);
   cout << otherq << endl;

   ToContinue();  
   
   PrintMessage ("Dequeue", "size 2");
   cout << myq << endl;
   myq.Dequeue(ok);
   PrintBool (ok);
   cout << myq << endl;
   PrintMessage ("Dequeue", "size 1");
   myq.Dequeue(ok);
   cout << myq << endl;
   PrintBool (ok);
   
   ToContinue();

   PrintMessage ("Dequeue", "empty");
   myq.Dequeue(ok);
   PrintBool (ok);

   ToContinue();

   PrintMessage(" GetFront", "size 2");
   cout << otherq << endl;
   if (!otherq.IsEmpty())
   {
       otherq.GetFront(it);
       cout << "front = " << it.custNum << endl;
       cout << "front = " << it.arrivalTime << endl;
       cout << "front = " << it.transactionTime << endl;
       cout << otherq << endl;
       PrintBool (ok);
   }
      
   ToContinue();
   
   PrintMessage("GetSize", "size 2");
   cout << otherq << endl;
   cout << "size = " << otherq.GetSize() << endl;
   
   PrintMessage("GetSize", "size 0");
   cout << "size = " << myq.GetSize() << endl;

   PrintLines(3);   
   return 0;   
}

void BuildIt(QItemType& it)
{
   it.custNum = 1;
   it.arrivalTime = 2;
   it.transactionTime = 3;
}

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue()
{
   char ch;
   PrintLines(2);
   cout << "                           Hit <Enter> to continue -> ";
   cin.get(ch);
}

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase)
{
   PrintLines(2);
   cout << "Testing *** " << which << " *** in the " 
        << whatCase << " case";
   PrintLines(2);
}

//@prints the contents of a boolean expression
//@pre ok is assigned
//@post outputs true or false on the screen depending on ok
//@usage PrintBool(q.IsEmpty());
void PrintBool (bool ok)
{
   cout << endl << "          Boolean value is ";
   if (ok)
      cout << "true";
   else
      cout << "false";
   cout << endl;
}  

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
	for (int k = 0; k < num; k++)
		cout << endl;
}

