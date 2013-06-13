//@author Ryan Draper(draper)
//@date Feb. 17, 2011
//@file itemtester.cpp
//@description: This program fully tests class CItem which inherits from Ckey.

#include <iostream>
#include <string>
#include <fstream>
#include "citem.h"

using namespace std;

//@opens an external file for reading
//@post if the external file "dictionary.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@makes an Citem that corresponds to the first info fromt the dictionary file
//@pre infile is the dictionary file with abbreviations and meaning
//@post returns a Citem that is in the dictionary file
//@param infile
//@usage Create(itemTest, GetItem(dict));
Citem GetItem(ifstream& infile);

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

//@Creates an instance of Ckey from a file and outputs it to the screen
//@pre Ckey is an existing key
//@post key is filled from file and output to the screen
//@param key
//@usage Create(newItem, GetItem(dict));
void Create(Citem& newItem, Citem item);
   
//@finds whether key1 and key2 are equal
//@pre both keys are existing Ckey objects
//@post outputs whether or not both Ckey's are equal
//@param key1
//@param key2
//@usage Compare(key1, key2);
void Compare(Citem& item1, Citem& item2);
   
int main()
{
   Citem itemTest;
   ifstream dict;
   bool ok;

   OpenInputFile(dict, ok);
   
   PrintLines(3);
   
   PrintMessage ("New String", "empty");
   cout << itemTest;

   PrintMessage ("Copy", "empty");
   Citem newItem(itemTest);
   cout << newItem;

   PrintLines(2);
   Compare(itemTest, newItem);
   
   PrintLines(2);
   ToContinue();  
   
   PrintMessage ("String", "With Item");
   Create(itemTest, GetItem(dict));

   PrintMessage ("Copy", "With Item");
   Create(newItem, itemTest);
   
   PrintLines(2);
   Compare(itemTest, newItem);
   
   PrintLines(2);
   ToContinue();  
   
   PrintMessage("String", "NewItem");
   Create(itemTest, GetItem(dict));
   
   PrintMessage("Copy", "Old Item");
   cout << newItem << endl;
   
   PrintLines(2);
   Compare(itemTest, newItem);
   
   
   PrintLines(3);
   
   return 0;   
}
   
//@finds whether key1 and key2 are equal
//@pre both keys are existing Ckey objects
//@post outputs whether or not both Ckey's are equal
//@param key1
//@param key2
//@usage Compare(key1, key2);
void Compare(Citem& item1, Citem& item2)
{
   if (item1 == item2)
   {
      cout << "The Items are equal.";
   }else if (item1 < item2){
      cout << "The first item is the lesser value." << endl; 
   } else {
      cout << "The second item is the lesser value." << endl; 
   }  
   cout << endl;
}

//@Creates an instance of Citem from a file and outputs it to the screen
//@pre Citem is an existing item
//@post newitem is filled from the opposing Citem and then cout.
//@param newItem
//@param item
//@usage Create(newItem, GetItem(dict));
void Create(Citem& newItem, Citem item)
{
   newItem = item;
   cout << newItem << endl;
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

//@makes an Citem that corresponds to the first info fromt the dictionary file
//@pre infile is the dictionary file with abbreviations and meaning
//@post returns a Citem that is in the dictionary file
//@param infile
//@usage Create(itemTest, GetItem(dict));
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

