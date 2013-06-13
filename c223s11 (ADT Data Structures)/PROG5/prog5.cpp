//@author Ryan Draper(draper)
//@date March 4, 2011
//@file prog5.cpp
//@description: This is a program that is a acronym Dictionary that can do the following options
//@             "(f) Find item in the Tree" 
//@             "(i) Insert item into Tree" 
//@             "(l) List items in the Tree"
//@             "(p) Print the Tree" 
//@             "(r) Rebalance the Tree" 
//@             "(s) Save to file" 
//@             "(e) Exit" 


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "cbstree.h"
#include "cexception.h"
#include "ctype.h"

using namespace std;

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& ok);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@      testItem
//@usage Insert(cbsTest, testItem)
void Insert(cbstree& cbsTest);

//@tests retrieve in class cbstree
//@pre cbstree and Citem are existing objects with testItem assigned a string from a file
//@post the string is entered into the tree if there is memory and it doesn't already have the
//@     item in it
//@param cbsTest
//@      testItem
//@usage Search(cbsTest, testItem);
void Search(cbstree& cbsTest);

//@Gets the option from the user
//@pre option is a char and bool is false
//@post option holds a character selected according to the menu and
//@     ok is false if the user chose 'e', 'E' for exit.
//@param option
//@      ok
//@usage optionSelect(option, exit);
void optionSelect(char& option, bool& ok);

//@checks to see if the users wanted to exit the program
//@pre ch is a user selected char and ok = false
//@post if ch is a 'e', 'E' then ok equals false 
//@return ch is returned by referenct as a lowercase character
//@param ch
//@      ok
//@usage checkOption(option, ok);
void checkOption(char& option, bool& ok);

//@prints out the menu
//@post the menu and the prompt has been printed to the screen
//@usage Menu();
void Menu();

//@saves tree to a file and rebalances it in cbstree
//@pre tree is a existing cbstree
//@post tree has been written to a file and rebalanced to minimun height
//@param tree
//@usage Rebalance(tree);
void Rebalance(cbstree& tree);

//@executes the option chosen by the user
//@pre option is a user input and tree is a cbstree
//@post option has been executed and cbstree has 
//@been acted upon according to that option
//@return tree has been passed by reference 
//@param option
//@      tree
//@usage execute(option, tree);
void execute(char option, cbstree& tree);

//@writes tree to file dictionary.dat
//@pre tree is an existing tree
//@post file dictionary.dat holds the information from tree
//@param tree
//@usage Save(tree);
void Save(cbstree tree);

//@prints a header for the keys and items to be printed and does a 
//@in order traversal to be printed
//@pre the tree is a existing cbstree
//@post the dictionary printed in a list from the tree with a header
//@param tree
//@usage List(tree);
void List(cbstree tree);

int main()
{
   cbstree tree;
   ifstream cbinDict;
   Ckey catchTest;
   bool file;
   bool exit = false;
   char option;

   OpenInputFile(cbinDict, file);
   tree.rebalance(cbinDict);
   cbinDict.close();
	
   while(not exit)
   { 
      optionSelect(option, exit);
      execute(option, tree);
   }
 
   return 0;   
}

//@prints out the menu
//@post the menu and the prompt has been printed to the screen
//@usage Menu();
void Menu()
{
   PrintLines(2);
   cout << "+++++++++++++ SELECT AN OPTION +++++++++++++" << endl;
   cout << "(f) Find item in the Tree" << endl;
   cout << "(i) Insert item into Tree" << endl;
   cout << "(l) List items in the Tree" << endl;
   cout << "(p) Print the Tree" << endl;
   cout << "(r) Rebalance the Tree" << endl;
   cout << "(s) Save to file" << endl;
   cout << "(e) Exit" << endl;
   cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
   cout << "Enter Option -> ";
  
}

//@prints a header for the keys and items to be printed and does a 
//@in order traversal to be printed
//@pre the tree is a existing cbstree
//@post the dictionary printed in a list from the tree with a header
//@param tree
//@usage List(tree);
void List(cbstree tree)
{
   cout << "++++++DICTIONARY++++++" << endl << endl;
   cout << "Acronym   |    Meaning" << endl << endl;
   tree.inorderTraverse();
}

//@executes the option chosen by the user
//@pre option is a user input and tree is a cbstree
//@post option has been executed and cbstree has 
//@been acted upon according to that option
//@return tree has been passed by reference 
//@param option
//@      tree
//@usage execute(option, tree);
void execute(char option, cbstree& tree)
{
   PrintLines(2);
   switch (option)
   {
      case 'f':
         Search(tree);
         break;
      case 'i':      
         Insert(tree);
         break;
      case 'l':
         List(tree);
         break;
      case 'p':
         tree.prettyDisplay();
         break;
      case 'r':
         Rebalance(tree);
         break;
      case 's':
         Save(tree);
         break;
      case 'e':
         Save(tree);
         break;
      default :
         cout << "+++ Please reenter your Option choice +++" << endl;
   }
   
}

//@writes tree to file dictionary.dat
//@pre tree is an existing tree
//@post file dictionary.dat holds the information from tree
//@param tree
//@usage Save(tree);
void Save(cbstree tree)
{
   ofstream outfile;
   
   outfile.open("dictionary.dat");
   tree.outputTree(outfile);
   cout << "Save Complete!" << endl << endl;
   outfile.close();
}

//@Gets the option from the user
//@pre option is a char and bool is false
//@post option holds a character selected according to the menu and
//@     ok is false if the user chose 'e', 'E' for exit.
//@param option
//@      ok
//@usage optionSelect(option, exit);
void optionSelect(char& option, bool& ok)
{
 	Menu();
   cin.get(option);
   cin.ignore(100, '\n');
   checkOption(option, ok);
}

//@checks to see if the users wanted to exit the program
//@pre ch is a user selected char and ok = false
//@post if ch is a 'e', 'E' then ok equals false 
//@return ch is returned by referenct as a lowercase character
//@param ch
//@      ok
//@usage checkOption(option, ok);
void checkOption(char& ch, bool& ok)
{
   ch = tolower(ch);
   if (ch == 'e') {
	    ok = true;
	    PrintLines(2);
	    cout << "!!!!!Thank You!!!!!";
	    PrintLines(2);
   } 
}

//@saves tree to a file and rebalances it in cbstree
//@pre tree is a existing cbstree
//@post tree has been written to a file and rebalanced to minimun height
//@param tree
//@usage Rebalance(tree);
void Rebalance(cbstree& tree)
{
   Save(tree);
   ifstream infile;
   bool fileOk;
   
   OpenInputFile(infile, fileOk);
   if (fileOk)
   {
      try
      {
         tree.rebalance(infile);
         cout << "Rebalance Complete!" << endl << endl;
      }
      catch (cexception ex)
      {
         cout << ex.what() << endl;
      }
   }
   infile.close();
}

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@usage Insert(cbsTest)
void Insert(cbstree& cbsTest)
{
   Citem item;
   
   PrintLines(2);
   cin >> item;
   try
   {
      cbsTest.insert(item);
   }
   catch (cexception ex)
   {
      cout << ex.what() << endl;  
   }
}

//@tests retrieve in class cbstree
//@pre cbstree and Citem are existing objects with testItem assigned a string from a file
//@post the string is entered into the tree if there is memory and it doesn't already have the
//@     item in it
//@param cbsTest
//@      testItem
//@usage Search(cbsTest, testItem);
void Search(cbstree& cbsTree)
{
   Ckey searchKey;
   Citem item;
   
   PrintLines(2);
   
   cin >> searchKey;
   
   PrintLines(2);
   try
   {
      cbsTree.retrieve(searchKey, item);
      cout << "The Dictionary has returned the meaning. ->" << endl << endl;
      cout << item ;
   }
   catch (cexception ex)
   {
      cout << searchKey << " " << ex.what();
   }
}


//@opens an external file for reading and loads
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& ok)
{
   infile.open("dictionary.dat");
   if (infile.fail())
   {
      ok = false;
      PrintLines(2);
      cout << "Error: file does not exist";
      PrintLines(2);
   } else {
      ok = true;
   }
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

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

