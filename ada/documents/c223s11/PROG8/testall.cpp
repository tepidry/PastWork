//@author Ryan Draper(draper)
//@date April 14, 2011
//@file testall.cpp
//@description: This program will functions of citem, c234node, and c234tree.

#include <iostream>
#include "citem.h"
#include "c234node.h"
#include "c234tree.h"

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

//@gets input from user for item
//@pre ItemType item is a data object
//@post item is filled with info from user
//@param item
//@usage GetTestSelection(item);
void GetTestSelection(int& item);

//@tests citem methods
//@user selects a for citem test
//@post out put of all test on all methods in Citem class
//@usage TestCitem();
void TestCitem();

//@tests c234node methods
//@user selects a for c234node test
//@post out put of all test on all methods in C234node class
//@usage TestC234node();
void TestC234node();

//@tests c234tree methods
//@user selects a for c234tree test
//@post out put of all test on all methods in C234tree class
//@usage TestC234tree();
void TestC234tree();

//@prints menu for test items
//@post menu is output to screen
//@usage Menu();
void Menu();

int main()
{
   
   int selection;
   
   while (selection != 4)
   {
      Menu();
      GetTestSelection(selection);
      if (selection == 1)
         TestCitem();
      else if (selection == 2)
         TestC234node();
      else if (selection == 3)
         TestC234tree();
      else if (selection != 4)
         cout << "Please enter an appropriate choice from the menu!" << endl;
   }
   
   cout << "Thank You!!" << endl;
   
   PrintLines(3);
   return 0;   
}
//@tests c234tree methods
//@user selects a for c234tree test
//@post out put of all test on all methods in C234tree class
//@usage TestC234tree();
void TestC234tree()
{
   C234tree tree, tree2;
   Citem item;
   char ch;
   bool keepInserting = true;
   
   while (keepInserting)
   {
      cout << "What Item would you like to insert? -> " << endl;
      cin >> item;
      tree.Insert(item);
      cout << "Here is the Tree ->" << endl;
      tree.DisplayTree();
      cout << endl << "Want to do insert again?" << endl;
      cout << "Y for yes, N for no -> " << endl;
      cin >> ch;
      if (ch == 'Y' || ch == 'y') {
         keepInserting = true;
      } else if (ch == 'N' || ch == 'n') {
         keepInserting = false;
      } else { 
         cout << "Your selection was incorrect by default lets try insert again!" << endl;
         keepInserting = true;
      }

   }
}

//@tests c234node methods
//@user selects a for c234node test
//@post out put of all test on all methods in C234node class
//@usage TestC234node();
void TestC234node()
{
   Citem item, item2, item3;
   C234node node4;
   PrintLines(2);
   PrintMessage ("C234node", "3 Creators and Display");
   cin >> item;
   cin.get();
   C234node node (item, NULL, NULL);
   
   cin >> item2;
   cin.get();
   C234node node2 (item, item2, NULL, NULL, NULL);
   
   cin >> item3;
   cin.get();
   C234node node3 (item, item2, item3, NULL, NULL, NULL, NULL);
   
   cout << "Node 1: singe Item creator" << endl;
   node.DisplayItems();
   PrintLines(2);
   cout << "Node 2: 2 item creator" << endl;
   node2.DisplayItems();
   PrintLines(2);
   cout << "Node 3: 3 item creator" << endl;
   node3.DisplayItems();
   ToContinue();
   PrintLines(2);
   PrintMessage ("C234node", "Copy");
   cout << "Here's the first node -> " << endl;
   node = node3;
   node3.DisplayItems();
   cout << endl << "A Copy of that last node ->" << endl;
   node.DisplayItems();
   ToContinue();
   PrintMessage ("C234node", "CopyRightItems");
   cout << "Lets Copy the right two items of this node -> " << endl;
   node3.DisplayItems();
   node3.CopyRightItems(item2, item3);
   cout << endl << "Here is the middle item -> " << item2 << endl;
   cout << "Here is the right most item -> " << item3 << endl;
   ToContinue();
   PrintMessage("C234node", "RecycleNode()");
   
   cout << endl << "Now lets use Recycle Node()" << endl;
   cout << "pre -> " << endl;
   node.DisplayItems();
   node.RecycleNode();
   cout << endl << "post -> " << endl;
   node.DisplayItems();
   cout << endl << "-- Wow!! --" << endl;
   ToContinue();
   
   PrintMessage("C234node", "IsEmpty");
   
   node4.DisplayItems();
   PrintBool(node4.IsEmpty());
   cout << "True for empty, False for not Empty" ;
   PrintLines(2);
   PrintMessage("C234node", "Is not Empty");
   node2.DisplayItems();
   PrintBool(node2.IsEmpty());
   cout << "True for empty, False for not Empty" ;
   ToContinue();
   
   PrintMessage("C234node", "Is In Node");
   node2.DisplayItems();
   cout << endl << "For Item -> " << item << endl;
   PrintBool(node2.IsInNode(item));
   PrintMessage("C234node", "Is Not In Node");
   node4.DisplayItems();
   cout << endl << "For Item -> " << item << endl;
   PrintBool(node4.IsInNode(item));
   ToContinue();
   
   PrintMessage("C234node", "Insert");
   cout << "To Fully Test Try some of these examples -> " << endl;
   cout << " (2,3,1), (1,2,3), (3,2,1), (1,3,2)" << endl;
   bool keepGoing = true;
   while (keepGoing)
   {
      C234node node5;
      char ch;
      for (int i = 0; i < 3; i++)
      {
         cout << endl;
         cin >> item;
         node5.Insert(item);
         node5.DisplayItems();
      }
      
      cout << endl << "Want to do it again?" << endl;
      cout << "Y for yes, N for no -> " << endl;
      cin >> ch;
      if (ch == 'Y' || ch == 'y') {
         keepGoing = true;
      } else if (ch == 'N' || ch == 'n') {
         keepGoing = false;
      } else { 
         cout << "Your selection was incorrect by default lets try insert again!" << endl;
         keepGoing = true;
      }
   }
   cout << "The C234node methods for Connect Pointer, Return Pointer, Adjust Pointers," << endl; 
   cout << "and GetNextChild are all displayed in C234tree" << endl;
   
}

//@tests citem methods
//@user selects a for citem test
//@post out put of all test on all methods in Citem class
//@usage TestCitem();
void TestCitem()
{
   Citem item, item2;
   PrintLines(2);
   PrintMessage ("Citem", "operator<< and operator >>");
   cin >> item;
   cout << "here's the item entered -> " << item << endl;
   cin.get();
   
   PrintMessage ("Citem", "copy");
   item2 = item;
   cout << "here's a copy of that item-> " << item2 << endl;
   ToContinue();
   PrintMessage ("Citem", "EmptyOut()");
   cout << "here's the item entered before EmptyOut() -> " << item << endl;
   item.EmptyOut();
   cout << "here's the item entered after EmptyOut() -> " << item << endl;
   PrintMessage ("Citem", "Empty()");
   
   cout << "+++if true item is empty, else not empty++" << endl;
   PrintBool(item.IsEmpty());
   PrintMessage ("Citem", "Not Empty()");
   cout << "+++if true item is empty, else not empty++" << endl;
   PrintBool(item2.IsEmpty());
   ToContinue();
   PrintLines(3);
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

//@prints menu for test items
//@post menu is output to screen
//@usage Menu();
void Menu()
{
   PrintLines(2);
   cout << " Please Choose One Of The Following-> " << endl;
   cout << " 1)Test Class Citem" << endl;
   cout << " 2)Test Class C234node" << endl;
   cout << " 3)Test Class C234tree" << endl;
   cout << " 4)EXIT!!" << endl; 
   PrintLines(3);  
}

//@gets input from user for item
//@pre ItemType item is a data object
//@post item is filled with info from user
//@param item
//@usage GetTestSelection(item);
void GetTestSelection(int& item)
{
   cout << "Please Select Test -> ";
   cin >> item;
}
