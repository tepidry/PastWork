//@author Ryan Draper(draper)
//@date Feb. 17, 2011
//@file keytester.cpp
//@description: This program fully tests class Ckey.

#include <iostream>
#include <string>
#include <fstream>
#include "ckey.h"

using namespace std;

//@opens an external file for reading
//@post if the external file "dictionaryKey.txt" exists, then
//@        it is associated with infile, its
//@     pointer is at the beginning, and fileOk is
//@     true, else fileOk is false
//@param infile
//@param fileOk
//@usage OpenInputFile(infile, fileOk);
void OpenInputFile(ifstream& infile, bool& fileOk);

//@makes an Ckey that corresponds to the first info fromt the Dictionary File
//@pre infile is the dictionary file with abbreviations for texting.
//@post returns a Ckey that is in the dictionary file
//@param infile
//@usage Create(keyTest, GetKey(dict));;
Ckey GetKey(ifstream& infile);

//@allows user to control the scroll of the screen
//@post accepts an enter key from the user
//@usage ToContinue();
void ToContinue();

//@prints a testing message on the screen
//@pre which and whatcase are strings
//@post which and whatcare are output on the screen
//@usage PrintMessage("which event", "empty");
void PrintMessage (const char* which, const char* whatCase);

//@prints a number of newlines
//@pre num is nonnegative
//@post num newlines are output
//@usage PrintLines(3);
void PrintLines (int num);

//@Creates an instance of Ckey from a file and outputs it to the screen
//@pre Ckey is an existing key
//@post newkey is filled from the opposing key
//@param key
//@param newKey
//@usage Create(newKey, keyTest);
void Create(Ckey& newKey, Ckey key);

//@finds whether key1 and key2 are equal
//@pre both keys are existing Ckey objects
//@post outputs whether or not both Ckey's are equal
//@param key1
//@param key2
//@usage Compare(key1, key2);
void Compare(Ckey key1, Ckey key2);
   
int main()
{
   Ckey keyTest;
   ifstream dict;
   bool ok;

   OpenInputFile(dict, ok);
   
   PrintLines(3);
   PrintMessage ("New String", "empty");
   cout << keyTest;

   PrintMessage ("Copy", "empty");
   Ckey newKey(keyTest);
   cout << newKey;

   PrintLines(2);
   Compare(keyTest, newKey);
   
   PrintLines(2);
   ToContinue();  
   
   PrintMessage ("String", "With Item");
   Create(keyTest, GetKey(dict));

   PrintMessage ("Copy", "With Item");
   Create(newKey, keyTest);
   
   PrintLines(2);
   Compare(keyTest, newKey);
   
   PrintLines(2);
   ToContinue();  
   
   PrintMessage("String", "NewItem");
   Create(keyTest, GetKey(dict));
   
   PrintMessage("Copy", "Old Item");
   cout << newKey << endl;
   
   PrintLines(2);
   Compare(keyTest, newKey);
   
   
   PrintLines(3);
   
   return 0;   
}

//@finds whether key1 and key2 are equal
//@pre both keys are existing Ckey objects
//@post outputs whether or not both Ckey's are equal
//@param key1
//@param key2
//@usage Compare(key1, key2);
void Compare(Ckey key1, Ckey key2)
{
   if (key1 == key2)
   {
      cout << "The Items are equal.";
   }else if (key1 < key2){
      cout << "The first item is the lesser value." << endl; 
   } else {
      cout << "The second item is the lesser value." << endl; 
   }  
   cout << endl;
}

//@Creates an instance of Ckey from a file and outputs it to the screen
//@pre Ckey is an existing key
//@post newkey is filled from the opposing key
//@param key
//@param newKey
//@usage Create(newKey, keyTest);
void Create(Ckey& newKey, Ckey key)
{
   newKey = key;
   cout << newKey << endl;
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
   infile.open("dictionarykey.dat");
   if (infile.fail())
   {
      fileOk = false;
      cout << "ERROR: opening input file" << endl;
   } else {
      fileOk = true;
   }
}

//@makes an Ckey that corresponds to the first info fromt the Dictionary File
//@pre infile is the dictionary file with abbreviations for texting.
//@post returns a Ckey that is in the dictionary file
//@param infile
//@usage Create(keyTest, GetKey(dict));;
Ckey GetKey(ifstream& infile)
{
   Ckey event;
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

