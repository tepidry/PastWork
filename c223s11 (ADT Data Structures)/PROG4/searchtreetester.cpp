//@author Ryan Draper(draper)
//@date Feb. 23, 2011
//@file searchtreetester.cpp
//@description: This program fully tests class cbintree outputs.

#include <iostream>
#include <string>
#include <fstream>
#include "cbstree.h"
#include "cexception.h"

using namespace std;

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("Enqueue", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@Creates an instance of Citem from a file and outputs it to the screen
//@pre Citem is an existing key
//@post item is filled from file
//@param key
//@usage 
void Create(Citem& newItem, Citem item);

//@makes an itemType that corresponds to the first info fromt the arrivalFile
//@pre infile is the arrivalFile with arrival times and transaction times to be acted upon
//@post returns a ItemType that is in the arrivalFile
//@param infile
//@usage PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
Citem GetItem(ifstream& infile);

//@This will create a tree from the file to cbsTest inserting from the file as long as the index <4
//@pre cbsDict is the file containing the dictionary cbsTree is a existing binary tree, and index is an int
//@post if index is below 4 then a new item is inserted into the binary tree and that item from the file is 
//@     then retrieved if it is not in the tree the catch using cexception 
//@param cbsDict
//@      cbsTest
//@      index
//@TestTree(cbsDict, cbsTest, i);
void TestTree(ifstream& cbsDict, cbstree& cbsTest, int index);

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@      testItem
//@usage Insert(cbsTest, testItem)
void Insert(cbstree& cbsTest, Citem testItem);

//@tests retrieve in class cbstree
//@pre cbstree and Citem are existing objects with testItem assigned a string from a file
//@post the string is entered into the tree if there is memory and it doesn't already have the
//@     item in it
//@param cbsTest
//@      testItem
//@usage Search(cbsTest, testItem);
void Search(cbstree& cbsTest, Citem& testItem);

int main()
{
   cbstree cbsTest;
   ifstream cbsDict;
   Ckey catchTest;
   bool ok;

   OpenInputFile(cbsDict, ok);
   if (ok) {
      for (int i = 0; i <= 7; i++)
      {
         PrintLines(2);
         TestTree(cbsDict, cbsTest, i);
         ToContinue();
      }
   }
   
   return 0;   
}

//@This will insert an item into the cbstree
//@pre cbstree is a existing tree and testItem is a existing item with memory
//@post cbstree will have the item in teh correct place
//@param cbsTest
//@      testItem
//@usage Insert(cbsTest, testItem)
void Insert(cbstree& cbsTest, Citem testItem)
{
   cout << "*** " << testItem << " *** is being inserted." << endl;
   try
   {
      cbsTest.insert(testItem);
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
void Search(cbstree& cbsTest, Citem& testItem)
{
   Ckey testKey = testItem;
   
   PrintMessage("Search", "In Tree");
   cout << "Searched in Tree for ->" << testKey << endl << endl;
   cbsTest.inorderTraverse();
   PrintLines(2);
   try
   {
      cbsTest.retrieve(testKey, testItem);
      cout << testKey << " is in Tree!";
   }
   catch(cexception ex)
   {
      cout << ex.what() << endl;
   }
}

//@This will create a tree from the file to cbsTest inserting from the file as long as the index <4
//@pre cbsDict is the file containing the dictionary cbsTree is a existing binary tree, and index is an int
//@post if index is below 4 then a new item is inserted into the binary tree and that item from the file is 
//@     then retrieved if it is not in the tree the catch using cexception 
//@param cbsDict
//@      cbsTest
//@      index
//@TestTree(cbsDict, cbsTest, i);
void TestTree(ifstream& cbsDict, cbstree& cbsTest, int index)
{
   Citem testItem;
   
   Create(testItem, GetItem(cbsDict));
   
   if (index < 6) {
      Insert(cbsTest, testItem);
   }
      
   Search(cbsTest, testItem);
   
   if (index == 3)
      Insert(cbsTest, testItem);
}

//@Creates an instance of Ckey from a file and outputs it to the screen
//@pre Ckey is an existing key
//@post key is filled from file and output to the screen
//@param key
//@usage 
void Create(Citem& newItem, Citem item)
{
   newItem = item;
}

//@opens an external file for reading
//@post if the external file "in.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk)
{
   infile.open("dictionary.dat");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR: opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@makes an itemType that corresponds to the first info fromt the arrivalFile
//@pre infile is the arrivalFile with arrival times and transaction times to be acted upon
//@post returns a ItemType that is in the arrivalFile
//@param infile
//@usage PutIntoEventList(ArrivalFromEventFile(arrivalFile), eventList, ok);
Citem GetItem(ifstream& infile)
{
   Citem event;
   bool ok;
   
   infile >> event;

   return event;
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

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num)
{
   for (int k = 0; k < num; k++)
      cout << endl;
}

